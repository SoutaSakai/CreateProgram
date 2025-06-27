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

	bool CheckHit(vivid::Vector2, float, int);

	void CreateFeed(vivid::Vector2, int, int);



private:
	Feed*	Feeds[5];
	bool	Active_flag[5];

	FeedManager(void) = default;
	~FeedManager(void) = default;
	FeedManager(const FeedManager& rhs) = delete;
	FeedManager& operator=(const FeedManager& rhs) = delete;
};