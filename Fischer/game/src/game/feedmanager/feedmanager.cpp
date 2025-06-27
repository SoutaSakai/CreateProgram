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
	for (int i = 0; i < 4; ++i)
	{
		// �s�����ȃf�[�^�̍폜
		if (!Active_flag[i])
		{
			Feeds[i]->Finalize();

			continue;
		}

		Feeds[i]->Update();
	}
}

void FeedManager::Draw(void)
{
	for (int i = 0; i < 4; ++i)
	{
		Feeds[i]->Draw();
	}
}

void FeedManager::Finalize(void)
{
	for (int i = 0; i < 4; ++i)
	{
		Feeds[i]->Finalize();
	}
}

bool FeedManager::CheckHit(vivid::Vector2 mouth_center_pos, float mouth_radius, int number)
{
	bool check = false;
	
	// �����a�͈͓̔����̔���
	check = Feeds[number]->GetRadius() + mouth_radius > sqrt(pow(Feeds[number]->GetCenterPos().x - mouth_center_pos.x, 2) + pow(Feeds[number]->GetCenterPos().y - mouth_center_pos.y, 2));

	return check;
}

void FeedManager::CreateFeed(vivid::Vector2 fisher_position, int max_fisher, int number)
{
	Feed*	feed = nullptr;

	feed = new Feed();

	if (!feed) return;

	vivid::Vector2 Feed_position = { fisher_position.x + 115.0f, fisher_position.y + 465.0f };

	feed->Initialize(Feed_position);

	Feeds[number] = feed;
}
