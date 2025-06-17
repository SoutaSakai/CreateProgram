#include "feedmanager.h"
#include "feed/feed.h"

FeedManager& FeedManager::GetInstance(void)
{
	static FeedManager	instance;

	return instance;
}

void FeedManager::Initialize()
{
}

void FeedManager::Update(void)
{
	// �e�a�I�u�W�F�N�g�̍X�V
	FEED_LIST::iterator	it = Feeds.begin();
	FEED_LIST::iterator	end = Feeds.end();

	while (it != end)
	{
		// �s�����ȃf�[�^�̍폜
		if (!(*it)->IsActive())
		{
			(*it)->Finalize();

			delete (*it);

			it = Feeds.erase(it);

			continue;
		}

		(*it)->Update();

		++it;
	}
}

void FeedManager::Draw(void)
{
	FEED_LIST::iterator it = Feeds.begin();
	FEED_LIST::iterator end = Feeds.end();

	while (it != end)
	{
		(*it)->Draw();

		++it;
	}
}

void FeedManager::Finalize(void)
{
	FEED_LIST::iterator it = Feeds.begin();
	FEED_LIST::iterator end = Feeds.end();

	while (it != end)
	{
		(*it)->Finalize();

		delete (*it);

		++it;
	}

	Feeds.clear();
}

bool FeedManager::CheckHit(vivid::Vector2 mouth_center_pos, float mouth_radius)
{
	bool check = false;

		// it�̉a�͈͓̔����̔���
		check = (*it)->GetRadius() + mouth_radius > sqrt(pow((*it)->GetCenterPos().x - mouth_center_pos.x, 2) + pow((*it)->GetCenterPos().y - mouth_center_pos.y, 2));

	return false;
}

void FeedManager::CreateFeed(vivid::Vector2 fisher_position, int max_fisher)
{
	if (Feeds.size() >= max_fisher) return;

	Feed*	feed = nullptr;

	feed = new Feed();

	if (!feed) return;

	vivid::Vector2 Feed_position = { fisher_position.x + 115.0f, fisher_position.y + 465.0f };

	feed->Initialize(Feed_position);

	Feeds.push_back(feed);
}
