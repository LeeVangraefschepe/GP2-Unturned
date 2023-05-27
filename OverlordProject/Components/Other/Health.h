#pragma once
class Health : public BaseComponent
{
public:
	enum Events
	{
		damage = 0,
		died
	};

	Health(float maxHealth);
	~Health() override = default;

	Health(const Health& other) = delete;
	Health(Health&& other) noexcept = delete;
	Health& operator=(const Health& other) = delete;
	Health& operator=(Health&& other) noexcept = delete;

	void Initialize(const SceneContext&) override;

	bool Damage(float amount);
	bool Died() const;

	Subject<Health>* GetSubject() const { return m_subject.get(); }
	float GetMaxHealth() const { return m_maxHealth; }
	float GetHealth() const { return m_currentHealth; }
private:
	std::unique_ptr<Subject<Health>> m_subject = std::make_unique<Subject<Health>>();
	float m_maxHealth;
	float m_currentHealth;
};