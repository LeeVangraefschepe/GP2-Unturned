#include "stdafx.h"
#include "Health.h"

Health::Health(float maxHealth):
m_maxHealth(maxHealth)
{
	m_currentHealth = m_maxHealth;
}

void Health::Initialize(const SceneContext&)
{
}

bool Health::Damage(float amount)
{
	m_currentHealth -= amount;
	if (Died())
	{
		m_subject->Notify(damage, this);
		m_subject->Notify(died, this);
		m_currentHealth = 0.f;
		return true;
	}
	m_subject->Notify(damage, this);
	return false;
}

bool Health::Died() const
{
	return m_currentHealth <= 0.f;
}