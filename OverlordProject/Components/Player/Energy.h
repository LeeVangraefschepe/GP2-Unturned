#pragma once
class Food;

class Energy : public BaseComponent
{
public:
	enum Events
	{
		consume = 0,
		fail,
		regen,
	};

	Energy(Food* pFood, float maxEnergy, float regenCooldown);
	~Energy() override = default;

	Energy(const Energy& other) = delete;
	Energy(Energy&& other) noexcept = delete;
	Energy& operator=(const Energy& other) = delete;
	Energy& operator=(Energy&& other) noexcept = delete;

	void Initialize(const SceneContext&) override;
	void Update(const SceneContext&) override;

	bool ConsumeEnergy(float amount);

	Subject<Energy>* GetSubject() const { return m_subject.get(); }
	float GetMaxEnergy() const { return m_maxEnergy; }
	float GetEnergy() const { return m_currentEnergy; }
private:
	Food* m_pFood;
	std::unique_ptr<Subject<Energy>> m_subject = std::make_unique<Subject<Energy>>();
	float m_maxEnergy;
	float m_currentEnergy;

	float m_maxRegenCooldown;
	float m_currentRegenCooldown;
};
