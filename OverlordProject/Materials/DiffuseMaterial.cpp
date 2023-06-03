#include "stdafx.h"
#include "DiffuseMaterial.h"

DiffuseMaterial::DiffuseMaterial(): Material<DiffuseMaterial>(L"Effects/PosNormTex3D.fx")
{
}

void DiffuseMaterial::SetDiffuseTexture(const std::wstring& assetFile)
{
	m_pDiffuseTexture = ContentManager::Load<TextureData>(assetFile);
	SetVariable_Texture(L"gDiffuseMap", m_pDiffuseTexture);
}

void DiffuseMaterial::InitializeEffectVariables()
{

}

void DiffuseMaterial::OnUpdateModelVariables(const SceneContext& sceneContext, const ModelComponent*) const
{
	SetVariable_Scalar(L"gLightIntensity", sceneContext.pLights->GetDirectionalLight().intensity);
}
