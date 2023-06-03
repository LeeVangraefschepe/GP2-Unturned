#pragma once
#include "Inventory.h"

class WeaponSlot : public BaseComponent
{
public:
	enum Events
	{
		Swap,
		Use
	};

	WeaponSlot(Inventory* inventory);
	~WeaponSlot() override = default;

	WeaponSlot(const WeaponSlot& other) = delete;
	WeaponSlot(WeaponSlot&& other) noexcept = delete;
	WeaponSlot& operator=(const WeaponSlot& other) = delete;
	WeaponSlot& operator=(WeaponSlot&& other) noexcept = delete;

	Subject<WeaponSlot>* GetSubject() const { return m_subject.get(); }
	Item GetSelectedItem() const;

	void Initialize(const SceneContext& sceneContext) override;
	void Update(const SceneContext&) override;
	void Draw(const SceneContext&) override;
private:
	Inventory* m_inventory{};
	int m_currentSlot{};

	SpriteFont* m_pFont{};
	void Fire();

	std::unique_ptr<Subject<WeaponSlot>> m_subject = std::make_unique<Subject<WeaponSlot>>();
};

