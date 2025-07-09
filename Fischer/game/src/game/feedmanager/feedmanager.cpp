#include "feedmanager.h"
#include "feed/feed.h"

const vivid::Vector2	FeedManager::m_range = { 115.0f, 465.0f };		// 釣り人から餌までの距離

FeedManager& FeedManager::GetInstance(void)
{
	static FeedManager	instance;

	return instance;
}

// 初期化
void FeedManager::Initialize(int max)
{
	m_max = max;
}

// 更新
void FeedManager::Update(void)
{
	if (m_max <= 0)	return;

	// 各餌オブジェクトの更新
	for (int i = 0; i < m_max; i++)
	{
		// 不活性なデータの削除
		if (!m_Feeds[i]->IsActive())
		{
			m_Feeds[i]->Finalize();

			//vivid::DrawText(40, std::to_string(m_Feeds[i]->GetPos()), vivid::Vector2(100.0f, 0.0f));

			//Feed* feed = nullptr;
			//m_Feeds[i] = feed;

			continue;
		}

		// 餌の更新
		m_Feeds[i]->Update();
	}
}

// 描画
void FeedManager::Draw(void)
{
	if (m_max <= 0)	return;

	// 各餌オブジェクトの描画
	for (int i = 0; i < m_max; i++)
	{
		m_Feeds[i]->Draw();
	}
}

// 解放
void FeedManager::Finalize(void)
{
	if (m_max <= 0)	return;

	// 各餌オブジェクトの解放
	for (int i = 0; i < m_max; i++)
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
void FeedManager::Create(vivid::Vector2 fisher_position, int number)
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

FeedManager::FeedManager(void)
	: m_max(0)
{
}

