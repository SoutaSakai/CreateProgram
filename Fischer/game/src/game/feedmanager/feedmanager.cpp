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
	// �ǂ̉a��H�ׂ����̔���

	return false;
}

void FeedManager::CreateFeed(vivid::Vector2 fisher_position)
{
	Feed*	feed = nullptr;

	feed = new Feed();

	if (!feed) return;

	vivid::Vector2 Feed_position = { fisher_position.x + 120.0f, fisher_position.y + 465.0f };

	feed->Initialize(Feed_position);

	Feeds.push_back(feed);
}
