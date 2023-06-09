#include "stdafx.h"
#include "ParticleEmitterComponent.h"
#include "Misc/ParticleMaterial.h"

ParticleMaterial* ParticleEmitterComponent::m_pParticleMaterial{};

ParticleEmitterComponent::ParticleEmitterComponent(const std::wstring& assetFile, const ParticleEmitterSettings& emitterSettings, UINT particleCount) :
	m_ParticlesArray(new Particle[particleCount]),
	m_ParticleCount(particleCount), //How big is our particle buffer?
	m_MaxParticles(particleCount), //How many particles to draw (max == particleCount)
	m_AssetFile(assetFile),
	m_EmitterSettings(emitterSettings)
{
	m_enablePostDraw = true; //This enables the PostDraw function for the component
}

ParticleEmitterComponent::~ParticleEmitterComponent()
{
	SafeDelete(m_ParticlesArray);
	SafeRelease(m_pVertexBuffer);
}

void ParticleEmitterComponent::Initialize(const SceneContext& sceneContext)
{
	if (!m_pParticleMaterial)
	{
		m_pParticleMaterial = MaterialManager::Get()->CreateMaterial<ParticleMaterial>();
	}
	if (!m_pVertexBuffer)
	{
		CreateVertexBuffer(sceneContext);
	}
	if (!m_pParticleTexture)
	{
		m_pParticleTexture = ContentManager::Load<TextureData>(m_AssetFile);
	}
}

void ParticleEmitterComponent::CreateVertexBuffer(const SceneContext& sceneContext)
{
	SafeRelease(m_pVertexBuffer);

	D3D11_BUFFER_DESC bufferDesc = {};
	bufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	bufferDesc.ByteWidth = m_ParticleCount * sizeof(VertexParticle);
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	bufferDesc.MiscFlags = 0;

	const HRESULT hr = sceneContext.d3dContext.pDevice->CreateBuffer(&bufferDesc, nullptr, &m_pVertexBuffer);
	HANDLE_ERROR(hr);
}

void ParticleEmitterComponent::Update(const SceneContext& sceneContext)
{
	const float deltaTime = sceneContext.pGameTime->GetElapsed();
	const float averageEnergy = (m_EmitterSettings.maxEnergy + m_EmitterSettings.minEnergy) / 2.0f;
	const float particleInterval = averageEnergy / static_cast<float>(m_ParticleCount);

	m_LastParticleSpawn += deltaTime;

	m_ActiveParticles = 0;

	// Step b: Map the vertex buffer for writing
	D3D11_MAPPED_SUBRESOURCE mappedResource = {};
	const HRESULT hr = sceneContext.d3dContext.pDeviceContext->Map(m_pVertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	HANDLE_ERROR(hr);

	// Step c: Cast the mapped pointer to a ParticleVertex pointer
	auto* pBuffer = static_cast<VertexParticle*>(mappedResource.pData);

	// Step e: Iterate the Particle Array and update the buffer data
	for (unsigned i = 0; i < m_ParticleCount; ++i)
	{
		Particle& particle{ m_ParticlesArray[i] };

		if (particle.isActive) UpdateParticle(particle, deltaTime);

		if (!particle.isActive && m_LastParticleSpawn >= particleInterval)
		{
			SpawnParticle(particle);
			m_LastParticleSpawn -= particleInterval;
		}

		if (particle.isActive)
		{
			pBuffer[m_ActiveParticles] = particle.vertexInfo;

			++m_ActiveParticles;
		}
	}

	// Step f: Unmap the vertex buffer
	sceneContext.d3dContext.pDeviceContext->Unmap(m_pVertexBuffer, 0);
}

void ParticleEmitterComponent::UpdateParticle(Particle& p, float elapsedTime) const
{
	if (!p.isActive) { return; }

	p.currentEnergy -= elapsedTime;
	if (p.currentEnergy <= 0.f) { p.isActive = false; return; }

	XMStoreFloat3(&p.vertexInfo.Position, XMLoadFloat3(&p.vertexInfo.Position) + XMLoadFloat3(&m_EmitterSettings.velocity) * elapsedTime);

	const float lifePerc = p.currentEnergy / p.totalEnergy;
	constexpr float fadeDelay{ 2.0f };
	p.vertexInfo.Color.w = m_EmitterSettings.color.w * lifePerc * fadeDelay;

	p.vertexInfo.Size = p.initialSize * (1.f + (p.sizeChange - 1.f) * (1.f - lifePerc));
}

void ParticleEmitterComponent::SpawnParticle(Particle& p)
{
	p.isActive = true;
	p.currentEnergy = MathHelper::randF(m_EmitterSettings.minEnergy, m_EmitterSettings.maxEnergy);
	p.totalEnergy = p.currentEnergy;

	const XMVECTOR randomVec
	{
		XMVector3Normalize(
  {
			MathHelper::randF(-1.0f, 1.0f),
			MathHelper::randF(-1.0f, 1.0f),
			MathHelper::randF(-1.0f, 1.0f)
		})
	};
	const float randomRange{ MathHelper::randF(m_EmitterSettings.minEmitterRadius, m_EmitterSettings.maxEmitterRadius) };
	XMStoreFloat3(&p.vertexInfo.Position, XMLoadFloat3(&GetTransform()->GetWorldPosition()) + randomVec * randomRange);

	p.initialSize = MathHelper::randF(m_EmitterSettings.minSize, m_EmitterSettings.maxSize);
	p.vertexInfo.Size = p.initialSize;

	p.sizeChange = MathHelper::randF(m_EmitterSettings.minScale, m_EmitterSettings.maxScale);

	p.vertexInfo.Rotation = MathHelper::randF(-XM_PI, XM_PI);

	p.vertexInfo.Color = m_EmitterSettings.color;
}

void ParticleEmitterComponent::PostDraw(const SceneContext& sceneContext)
{
	m_pParticleMaterial->SetVariable_Matrix(L"gWorldViewProj", sceneContext.pCamera->GetViewProjection());
	m_pParticleMaterial->SetVariable_Matrix(L"gViewInverse", sceneContext.pCamera->GetViewInverse());
	m_pParticleMaterial->SetVariable_Texture(L"gParticleTexture", m_pParticleTexture);

	auto& technique = m_pParticleMaterial->GetTechniqueContext();

	ID3D11DeviceContext* deviceContext{ sceneContext.d3dContext.pDeviceContext };

	// Set the InputLayout
	deviceContext->IASetInputLayout(technique.pInputLayout);

	// Set the PrimitiveTopology
	deviceContext->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_POINTLIST);

	// Set the VertexBuffer
	constexpr UINT offset{}, startSlot{}, nrBuffers{ 1 };
	constexpr UINT stride{ sizeof(VertexParticle) };
	deviceContext->IASetVertexBuffers(startSlot, nrBuffers, &m_pVertexBuffer, &stride, &offset);

	D3DX11_TECHNIQUE_DESC techDesc;
	technique.pTechnique->GetDesc(&techDesc);
	for (unsigned int p = 0; p < techDesc.Passes; ++p)
	{
		// Apply the pass
		technique.pTechnique->GetPassByIndex(p)->Apply(0, deviceContext);
		// Draw the vertices! (The number of vertices we want to draw is equal to m_ActiveParticles
		deviceContext->Draw(m_ActiveParticles, 0);
	}
}

void ParticleEmitterComponent::DrawImGui()
{
	if (ImGui::CollapsingHeader("Particle System"))
	{
		ImGui::SliderUInt("Count", &m_ParticleCount, 0, m_MaxParticles);
		ImGui::InputFloatRange("Energy Bounds", &m_EmitterSettings.minEnergy, &m_EmitterSettings.maxEnergy);
		ImGui::InputFloatRange("Size Bounds", &m_EmitterSettings.minSize, &m_EmitterSettings.maxSize);
		ImGui::InputFloatRange("Scale Bounds", &m_EmitterSettings.minScale, &m_EmitterSettings.maxScale);
		ImGui::InputFloatRange("Radius Bounds", &m_EmitterSettings.minEmitterRadius, &m_EmitterSettings.maxEmitterRadius);
		ImGui::InputFloat3("Velocity", &m_EmitterSettings.velocity.x);
		ImGui::ColorEdit4("Color", &m_EmitterSettings.color.x, ImGuiColorEditFlags_NoInputs);
	}
}