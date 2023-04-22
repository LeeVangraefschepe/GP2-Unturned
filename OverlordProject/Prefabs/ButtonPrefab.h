#pragma once
class ButtonPrefab final : public GameObject
{
public:
	ButtonPrefab(const std::wstring& texture, XMFLOAT2 dimensions);
	~ButtonPrefab() override = default;

	bool IsClicked() const { return m_isClicked;  }
	void Reset() { m_isClicked = false; }

	ButtonPrefab(const ButtonPrefab& other) = delete;
	ButtonPrefab(ButtonPrefab&& other) noexcept = delete;
	ButtonPrefab& operator=(const ButtonPrefab& other) = delete;
	ButtonPrefab& operator=(ButtonPrefab&& other) noexcept = delete;
protected:
	void Initialize(const SceneContext&) override;
	void Update(const SceneContext&) override;
private:
	SpriteComponent* m_pSpriteComp;
	XMFLOAT2 m_dimensions;
	bool m_isClicked{};
};