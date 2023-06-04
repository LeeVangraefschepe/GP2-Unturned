#pragma once
class ScoreManager : public Singleton<ScoreManager>
{
public:

	void AddScore(int amount) { m_score += amount; }
	void ResetScore() { m_score = 0; }

	int GetScore() const { return m_score; }

	ScoreManager(const ScoreManager& other) = delete;
	ScoreManager(ScoreManager&& other) noexcept = delete;
	ScoreManager& operator=(const ScoreManager& other) = delete;
	ScoreManager& operator=(ScoreManager&& other) noexcept = delete;

protected:
	void Initialize() override;

private:
	friend class OverlordGame;
	friend class Singleton<ScoreManager>;
	ScoreManager() = default;

	int m_score{};
};

