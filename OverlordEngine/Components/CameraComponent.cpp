#include "stdafx.h"
#include "CameraComponent.h"

CameraComponent::CameraComponent() :
	m_FarPlane(2500.0f),
	m_NearPlane(0.1f),
	m_FOV(XM_PIDIV4),
	m_Size(25.0f),
	m_PerspectiveProjection(true)
{
	XMStoreFloat4x4(&m_Projection, XMMatrixIdentity());
	XMStoreFloat4x4(&m_View, XMMatrixIdentity());
	XMStoreFloat4x4(&m_ViewInverse, XMMatrixIdentity());
	XMStoreFloat4x4(&m_ViewProjection, XMMatrixIdentity());
	XMStoreFloat4x4(&m_ViewProjectionInverse, XMMatrixIdentity());
}

void CameraComponent::Update(const SceneContext& sceneContext)
{
	// see https://stackoverflow.com/questions/21688529/binary-directxxmvector-does-not-define-this-operator-or-a-conversion
	using namespace DirectX;

	XMMATRIX projection{};

	if (m_PerspectiveProjection)
	{
		projection = XMMatrixPerspectiveFovLH(m_FOV, sceneContext.aspectRatio, m_NearPlane, m_FarPlane);
	}
	else
	{
		const float viewWidth = (m_Size > 0) ? m_Size * sceneContext.aspectRatio : sceneContext.windowWidth;
		const float viewHeight = (m_Size > 0) ? m_Size : sceneContext.windowHeight;
		projection = XMMatrixOrthographicLH(viewWidth, viewHeight, m_NearPlane, m_FarPlane);
	}

	const XMVECTOR worldPosition = XMLoadFloat3(&GetTransform()->GetWorldPosition());
	const XMVECTOR lookAt = XMLoadFloat3(&GetTransform()->GetForward());
	const XMVECTOR upVec = XMLoadFloat3(&GetTransform()->GetUp());

	const XMMATRIX view = XMMatrixLookAtLH(worldPosition, worldPosition + lookAt, upVec);
	const XMMATRIX viewInv = XMMatrixInverse(nullptr, view);
	const XMMATRIX viewProjectionInv = XMMatrixInverse(nullptr, view * projection);

	XMStoreFloat4x4(&m_Projection, projection);
	XMStoreFloat4x4(&m_View, view);
	XMStoreFloat4x4(&m_ViewInverse, viewInv);
	XMStoreFloat4x4(&m_ViewProjection, view * projection);
	XMStoreFloat4x4(&m_ViewProjectionInverse, viewProjectionInv);

	Set3DSoundAttributes(sceneContext);
}

void CameraComponent::SetActive(bool active)
{
	if (m_IsActive == active) return;

	const auto pGameObject = GetGameObject();
	ASSERT_IF(!pGameObject, L"Failed to set active camera. Parent game object is null");

	if (!pGameObject) return; //help the compiler... (C6011)
	const auto pScene = pGameObject->GetScene();
	ASSERT_IF(!pScene, L"Failed to set active camera. Parent game scene is null");

	m_IsActive = active;
	pScene->SetActiveCamera(active?this:nullptr); //Switch to default camera if active==false
}

GameObject* CameraComponent::Pick(CollisionGroup ignoreGroups) const
{
	const auto& sceneContext = GetGameObject()->GetScene()->GetSceneContext();

	const float halfWidth{ sceneContext.windowWidth / 2.0f };
	const float halfHeight{ sceneContext.windowHeight / 2.0f };
	const POINT& mousePos{ InputManager::GetMousePosition() };

	//NDC space
	const XMFLOAT2 ndcPosition
	{
		(static_cast<float>(mousePos.x) - halfWidth) / halfWidth,
		(halfHeight - static_cast<float>(mousePos.y)) / halfHeight
	};

	const auto& viewProjInv{ XMLoadFloat4x4(&GetViewProjectionInverse()) };

	//Create base ray direction
	const XMVECTOR rayStart{ XMVector3TransformCoord(XMVECTOR{ ndcPosition.x, ndcPosition.y, 0.0f }, viewProjInv) };
	const XMVECTOR rayEnd{ XMVector3TransformCoord(XMVECTOR{ ndcPosition.x, ndcPosition.y, 1.0f }, viewProjInv) };

	//Convert to XMFLOAT3
	XMFLOAT3 rayStartF{};
	XMStoreFloat3(&rayStartF, rayStart);
	XMFLOAT3 rayEndF{};
	XMStoreFloat3(&rayEndF, rayEnd);

	//Convert the PxVec3
	const PxVec3 rayOrigin{ rayStartF.x, rayStartF.y, rayStartF.z };
	const PxVec3 rayDirection{ rayEndF.x - rayOrigin.x, rayEndF.y - rayOrigin.y, rayEndF.z - rayOrigin.z };

	//Filter for ignore groups
	PxQueryFilterData filterData{};
	filterData.data.word0 = ~static_cast<UINT>(ignoreGroups);

	//Raycast
	if (PxRaycastBuffer hit{}; GetGameObject()->GetScene()->GetPhysxProxy()->Raycast(rayOrigin, rayDirection.getNormalized(), PX_MAX_F32, hit, PxHitFlag::eDEFAULT, filterData))
	{
		return static_cast<BaseComponent*>(hit.block.actor->userData)->GetGameObject();
	}

	return nullptr;
}

void CameraComponent::Set3DSoundAttributes(const SceneContext& sceneContext)
{
	//Convert to FMOD UGH
	const auto pCamTransform{ GetTransform() };
	const auto pos = FmodHelper::ToFmod(pCamTransform->GetWorldPosition());
	const auto forward = FmodHelper::ToFmod(pCamTransform->GetForward());
	const auto up = FmodHelper::ToFmod(pCamTransform->GetUp());

	//Calc velocity prev frame
	FMOD_VECTOR vel{};
	const float deltaT = sceneContext.pGameTime->GetElapsed();
	vel.x = (pos.x - m_PrevCamPos.x) / deltaT;
	vel.y = (pos.y - m_PrevCamPos.y) / deltaT;
	vel.z = (pos.z - m_PrevCamPos.z) / deltaT;
	m_PrevCamPos = pos;

	//Set the attributes for the listener
	SoundManager::Get()->GetSystem()->set3DListenerAttributes(0, &pos, &vel, &forward, &up);
}