#include "stdafx.h"
#include "StatsDisplay.h"

StatsDisplay::StatsDisplay(Health* health):
	m_health(health)
{
	m_health->GetSubject()->AddObserver(this);
}

StatsDisplay::~StatsDisplay()
{
	if (m_health)
	{
		m_health->GetSubject()->RemoveObserver(this);
	}
}

void StatsDisplay::Initialize(const SceneContext&)
{
}

void StatsDisplay::OnNotify(unsigned eventId, Health*)
{
	switch (static_cast<Health::Events>(eventId))
	{
	case Health::damage:
		std::cout << "Player took damage healt: " << m_health->GetHealth() << "\n";
		break;
	case Health::died:
		std::cout << "Player died\n";
		break;
	}
}

void StatsDisplay::OnDestroy()
{
	m_health = nullptr;
}
