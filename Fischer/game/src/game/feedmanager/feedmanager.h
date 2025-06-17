#pragma once
#include <list>
#include "vivid.h"

class Feed;

class FeedManager
{
public:
	static FeedManager& GetInstance(void);

	void Initialize(void);

	void Update(void);

	void Draw(void);

	void Finalize(void);

	bool CheckHit(vivid::Vector2 mouth_center_pos, float mouth_radius);

	void CreateFeed(vivid::Vector2, int);

private:
	using FEED_LIST = std::list <Feed*>;
	FEED_LIST		Feeds;

	FeedManager(void) = default;
	~FeedManager(void) = default;
	FeedManager(const FeedManager& rhs) = delete;
	FeedManager& operator=(const FeedManager& rhs) = delete;
};