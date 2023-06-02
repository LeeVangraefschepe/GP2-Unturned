#pragma once
class PostBloodscale : public PostProcessingMaterial
{
public:
	PostBloodscale();
	void SetAmount(float amount) const;
	~PostBloodscale() override = default;
	PostBloodscale(const PostBloodscale& other) = delete;
	PostBloodscale(PostBloodscale&& other) noexcept = delete;
	PostBloodscale& operator=(const PostBloodscale& other) = delete;
	PostBloodscale& operator=(PostBloodscale&& other) noexcept = delete;

protected:
	void Initialize(const GameContext& /*gameContext*/) override;
};

