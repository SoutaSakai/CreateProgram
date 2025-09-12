#include "feed.h"

const float	Feed::m_width	= 50.0f;
const float	Feed::m_height	= 50.0f;

// コンストラクタ
Feed::Feed(void)
	: m_Position(vivid::Vector2(0.0f,0.0f))
	, m_ActiveFlag(true)
	, m_Id(FEED_ID::LURE)
	, m_Hit(false)
{
}

// 初期化
void Feed::Initialize(const vivid::Vector2& current_pos, FISHER_LEVEL level)
{
	m_Position.x = current_pos.x;
	m_Position.y = current_pos.y;

	m_ActiveFlag = true;

	m_Hit = false;

	SetId(level);
}

// 更新
void Feed::Update(void)
{
}

// 描画
void Feed::Draw(void)
{
	if (m_ActiveFlag)
	{
		switch (m_Id)
		{
		case FEED_ID::LURE:		vivid::DrawTexture("data\\feed_lure.png", m_Position);	break;
		case FEED_ID::WORM:		vivid::DrawTexture("data\\feed_worm.png", m_Position);	break;
		case FEED_ID::MEET:		vivid::DrawTexture("data\\feed_meet.png", m_Position);	break;
		case FEED_ID::GOLD:		vivid::DrawTexture("data\\feed_gold.png", m_Position);	break;
		}
	}
}

// 解放
void Feed::Finalize(void)
{
}

// アクティブフラグを返す
bool Feed::GetActive(void)
{
	return m_ActiveFlag;
}

// アクティブフラグに代入
void Feed::SetActive(bool active)
{
	m_ActiveFlag = active;
}

// 半径を返す
float Feed::GetRadius(void)
{
	return m_height / 2.0f;
}

// 中心座標を返す
vivid::Vector2 Feed::GetCenterPos(void)
{
	return m_Position + vivid::Vector2(m_width / 2.0f, m_height / 2.0f);
}

// 位置を返す
vivid::Vector2 Feed::GetPosition(void)
{
	return m_Position;
}

void Feed::SetPosition(vivid::Vector2 position)
{
	m_Position = position;
}

FEED_ID Feed::GetId(void)
{
	return m_Id;
}

bool Feed::GetHit(void)
{
	return m_Hit;
}

void Feed::SetHit(bool hit)
{
	m_Hit = hit;
}

void Feed::SetId(FISHER_LEVEL level)
{
	int ran = rand() % ((int)FEED_ID::MAX * 25);

	switch (level)
	{
	case FISHER_LEVEL::LOW:
		if (ran < 40)
		{
			m_Id = FEED_ID::LURE;
		}
		else if (ran < 75)
		{
			m_Id = FEED_ID::WORM;
		}
		else if (ran < 98)
		{
			m_Id = FEED_ID::MEET;
		}
		else
		{
			m_Id = FEED_ID::GOLD;
		}
		break;
	case FISHER_LEVEL::MIDDLE:
		if (ran < 35)
		{
			m_Id = FEED_ID::LURE;
		}
		else if (ran < 75)
		{
			m_Id = FEED_ID::WORM;
		}
		else if (ran < 90)
		{
			m_Id = FEED_ID::MEET;
		}
		else
		{
			m_Id = FEED_ID::GOLD;
		}
		break;
	case FISHER_LEVEL::HIGH:
		if (ran < 38)
		{
			m_Id = FEED_ID::WORM;
		}
		else if (ran < 75)
		{
			m_Id = FEED_ID::MEET;
		}
		else
		{
			m_Id = FEED_ID::GOLD;
		}
		break;
	case FISHER_LEVEL::HIGHEST:
		if (ran < 10)
		{
			m_Id = FEED_ID::WORM;
		}
		else if (ran < 60)
		{
			m_Id = FEED_ID::MEET;
		}
		else
		{
			m_Id = FEED_ID::GOLD;
		}
		break;
	default:
		break;
	}


}
