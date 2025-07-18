#include "feed_manager.h"
#include "feed/feed.h"

FeedManager& FeedManager::GetInstance(void)
{
	static FeedManager	instance;

	return instance;
}

// 初期化
void FeedManager::Initialize(int max)
{
	m_Max = max;

	m_Feeds = new Feed[m_Max];

	m_Range = vivid::Vector2(115.0f, 465.0f);
}

// 更新
void FeedManager::Update(void)
{
	if (m_Max <= 0)	return;

	// 各餌オブジェクトの更新
	for (int i = 0; i < m_Max; i++)
	{
		// 不活性なデータの初期化
		if (!m_Feeds[i].IsActive())
		{
			m_Feeds[i].Finalize();

			continue;
		}

		// 餌の更新
		m_Feeds[i].Update();
	}
}

// 描画
void FeedManager::Draw(void)
{
	if (m_Max <= 0)	return;

	// 各餌オブジェクトの描画
	for (int i = 0; i < m_Max; i++)
	{
		if (m_Feeds[i].IsActive())
			m_Feeds[i].Draw();
	}
}

// 解放
void FeedManager::Finalize(void)
{
	if (m_Max <= 0)	return;

	// 各餌オブジェクトの解放
	for (int i = 0; i < m_Max; i++)
	{
		m_Feeds[i].Finalize();

		delete[] m_Feeds;
	}
}

// プレイヤーの口とのアタリ判定
bool FeedManager::CheckHit(vivid::Vector2 mouth_center_pos, float mouth_radius, int number)
{	
	// 口が餌の範囲内かの判定
	bool check = m_Feeds[number].GetRadius() + mouth_radius > sqrt(pow(m_Feeds[number].GetCenterPos().x - mouth_center_pos.x, 2) + pow(m_Feeds[number].GetCenterPos().y - mouth_center_pos.y, 2));

	return check;
}

// 餌の生成
void FeedManager::Create(vivid::Vector2 fisher_position, int number)
{
	//Feed*	feed = nullptr;

	//feed = new Feed();

	//if (!feed) return;

	//vivid::Vector2 Feed_position = { fisher_position.x + m_range.x, fisher_position.y + m_range.y };

	//feed->Initialize(Feed_position);

	//m_Feeds[number] = feed;
}

void FeedManager::Destroy(int number)
{
	m_Feeds[number].InActive(false);
}

void FeedManager::SetPosition(vivid::Vector2 fisher_position, int number)
{
	vivid::Vector2 Feed_position = { fisher_position.x + m_Range.x, fisher_position.y + m_Range.y };

	m_Feeds[number].Initialize(Feed_position);
}

FeedManager::FeedManager(void)
	: m_Max(0)
{
}

