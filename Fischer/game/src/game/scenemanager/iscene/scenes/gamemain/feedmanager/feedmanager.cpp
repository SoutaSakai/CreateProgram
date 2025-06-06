#include "feedmanager.h"

const float	FeedManager::Feed_radius = 25.0f;
const int	FeedManager::Feed_max = 4;

FeedManager& FeedManager::GetInstance(void)
{
	static FeedManager	instance;

	return instance;
}

void FeedManager::Initialize(vivid::Vector2 fisher_pos, int i)
{
	Feed_pos[i].x = fisher_pos.x + 95.0f;
	Feed_pos[i].y = 430.0f;
}

void FeedManager::Update(void)
{
}

void FeedManager::Draw(void)
{
}

void FeedManager::Finalize(void)
{
}

bool FeedManager::CheckHit(vivid::Vector2 mouth_center_pos, float mouth_radius)
{
	return false;
}

void FeedManager::CreateFeed(void)
{
}
