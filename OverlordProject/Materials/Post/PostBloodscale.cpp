#include "stdafx.h"
#include "PostBloodscale.h"

PostBloodscale::PostBloodscale() :
	PostProcessingMaterial(L"Effects/Post/Bloodscale.fx")
{
}

void PostBloodscale::SetAmount(float amount) const
{
	m_pBaseEffect->GetVariableByName("gEffectIntensity")->AsScalar()->SetFloat(amount);
}

void PostBloodscale::Initialize(const GameContext&)
{
	m_pBaseEffect->GetVariableByName("gEffectIntensity")->AsScalar()->SetFloat(0.f);
}