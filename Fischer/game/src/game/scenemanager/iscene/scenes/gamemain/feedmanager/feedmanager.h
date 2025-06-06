#pragma once
#include "vivid.h"

class FeedManager
{
public:
	static FeedManager& GetInstance(void);

	void Initialize(vivid::Vector2, int);

	void Update(void);

	void Draw(void);

	void Finalize(void);

	bool CheckHit(vivid::Vector2 mouth_center_pos, float mouth_radius);

	void CreateFeed(void);

private:
	static const float	Feed_radius;
	static const int	Feed_max;

	vivid::Vector2	Feed_pos[4];

	FeedManager(void) = default;
	~FeedManager(void) = default;
	FeedManager(const FeedManager& rhs) = delete;
	FeedManager& operator=(const FeedManager& rhs) = delete;
};