#include "feed_manager.h"
#include "feed/feed.h"
#include "..\player_manager\player_manager.h"

const vivid::Vector2	FeedManager::m_RangeAttach = { 75.0f, 75.0f };
const vivid::Vector2	FeedManager::m_RangeSea = { 115.0f, 465.0f };
const vivid::Vector2	FeedManager::m_RangeFishing = { 105.0f, 75.0f };

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
}

// 更新
void FeedManager::Update(void)
{
	if (m_Max <= 0)	return;

	// 各餌オブジェクトの更新
	for (int i = 0; i < m_Max; i++)
	{
		m_Feeds[i].SetHit(playermanager::GetInstance().CheckHitFeed(&m_Feeds[i]));

		//// 不活性なデータの初期化
		//if (!m_Feeds[i].GetActive())
		//{
		//	m_Feeds[i].Reset();

		//	continue;
		//}

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
	
	if (!check)
		m_Feeds[number].SetActive(false);

	return check;
}

// 餌の生成
void FeedManager::Create(vivid::Vector2 fisher_position, FISHER_LEVEL level,int number)
{
	Feed*	feed = nullptr;

	feed = new Feed();

	if (!feed) return;

	vivid::Vector2 Feed_position = { fisher_position.x + m_RangeAttach.x, fisher_position.y + m_RangeAttach.y };

	feed->Initialize(Feed_position, level);

	m_Feeds[number] = *feed;
}

void FeedManager::Destroy(int number)
{
	m_Feeds[number].SetActive(false);
}

void FeedManager::SetPosition(vivid::Vector2 fisher_position, FISHER_MOVE move, int number)
{
	vivid::Vector2 Feed_position = { 0.0f,0.0f};

	switch (move)
	{
	case FISHER_MOVE::WAIT:
		Feed_position = { fisher_position.x + m_RangeSea.x, fisher_position.y + m_RangeSea.y };
		break;
	case FISHER_MOVE::FISHING:
		Feed_position = { fisher_position.x + m_RangeSea.x, fisher_position.y + m_RangeSea.y };
		break;
	case FISHER_MOVE::ATTACH:
		Feed_position = { fisher_position.x + m_RangeFishing.x, fisher_position.y + m_RangeFishing.y };
		break;
	default:
		break;
	}
	
	m_Feeds[number].SetPosition(Feed_position);
}

vivid::Vector2 FeedManager::GetPosition(int num)
{
	return m_Feeds[num].GetPosition();
}

bool FeedManager::GetHit(int num)
{
	return m_Feeds[num].GetHit();
}

FEED_ID FeedManager::GetFeedID(int num)
{
	return m_Feeds[num].GetId();
}

bool FeedManager::GetActive(int num)
{
	return m_Feeds[num].GetActive();
}

vivid::Vector2 FeedManager::GetRange(FISHER_MOVE current)
{
	switch (current)
	{
	case FISHER_MOVE::WAIT:
		return m_RangeSea;
		break;
	case FISHER_MOVE::FISHING:
		return m_RangeFishing;
		break;
	case FISHER_MOVE::ATTACH:
		return m_RangeAttach;
		break;
	default:
		break;
	}
}

FeedManager::FeedManager(void)
	: m_Max(0)
{
}

