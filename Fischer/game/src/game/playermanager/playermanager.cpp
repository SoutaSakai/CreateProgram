#include "playermanager.h"
#include "..\feedmanager\feedmanager.h"
#include "..\fishermanager\fishermanager.h"

PlayerManager& PlayerManager::GetInstance(void)
{
	static PlayerManager	instance;

	return instance;
}

void PlayerManager::Initialize(void)
{
}

void PlayerManager::Update(void)
{
	if (FeedManager::GetInstance().CheckHit(vivid::Vector2(135.0f, 480.0f), 40.0f) && vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Q))
		FisherManager::GetInstance().CaughtFeed();
}

void PlayerManager::Draw(void)
{
}

void PlayerManager::Finalize(void)
{
}
