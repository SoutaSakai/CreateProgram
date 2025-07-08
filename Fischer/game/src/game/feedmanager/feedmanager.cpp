#include "feedmanager.h"
#include "feed/feed.h"

const vivid::Vector2	FeedManager::m_range = { 115.0f, 465.0f };		// 釣り人から餌までの距離
const int				FeedManager::m_max = 5;							// 餌の最大値

FeedManager& FeedManager::GetInstance(void)
{
	static FeedManager	instance;

	return instance;
}

// 初期化
void FeedManager::Initialize()
{
}

// 更新
void FeedManager::Update(void)
{
	// 各餌オブジェクトの更新
	for (int i = 0; i < 4; ++i)
	{
		// 不活性なデータの削除
		if (!m_Feeds[i]->IsActive())
		{
			m_Feeds[i]->Finalize();

			continue;
		}

		// 餌の更新
		m_Feeds[i]->Update();
	}
}

// 描画
void FeedManager::Draw(void)
{
	for (int i = 0; i < 4; ++i)
	{
		m_Feeds[i]->Draw();
	}
}

// 解放
void FeedManager::Finalize(void)
{
	for (int i = 0; i < 4; ++i)
	{
		m_Feeds[i]->Finalize();
	}
}

// プレイヤーの口とのアタリ判定
bool FeedManager::CheckHit(vivid::Vector2 mouth_center_pos, float mouth_radius, int number)
{	
	// 口が餌の範囲内かの判定
	bool check = m_Feeds[number]->GetRadius() + mouth_radius > sqrt(pow(m_Feeds[number]->GetCenterPos().x - mouth_center_pos.x, 2) + pow(m_Feeds[number]->GetCenterPos().y - mouth_center_pos.y, 2));

	return check;
}

// 餌の生成
void FeedManager::Create(vivid::Vector2 fisher_position, int max_fisher, int number)
{
	Feed*	feed = nullptr;

	feed = new Feed();

	if (!feed) return;

	vivid::Vector2 Feed_position = { fisher_position.x + m_range.x, fisher_position.y + m_range.y };

	feed->Initialize(Feed_position);

	m_Feeds[number] = feed;
}

void FeedManager::Destroy(int number)
{
	m_Feeds[number]->InActive(false);
}

