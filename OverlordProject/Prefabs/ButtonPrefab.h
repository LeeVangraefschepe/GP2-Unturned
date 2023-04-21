#pragma once
class ButtonPrefab final : public GameObject
{
public:
	ButtonPrefab(const std::wstring& texture, XMFLOAT2 dimensions);
	~ButtonPrefab() override = default;

	ButtonPrefab(const ButtonPrefab& other) = delete;
	ButtonPrefab(ButtonPrefab&& other) noexcept = delete;
	ButtonPrefab& operator=(const ButtonPrefab& other) = delete;
	ButtonPrefab& operator=(ButtonPrefab&& other) noexcept = delete;
protected:
	void Initialize(const SceneContext&) override;
	void Update(const SceneContext&) override;
private:
	SpriteComponent* m_pSpriteComp;
	SpriteFont* m_pFont;
	XMFLOAT2 m_dimensions;
};