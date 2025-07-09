#include "feed.h"

const float	Feed::m_width	= 36.0f;
const float	Feed::m_height	= 40.0f;

// コンストラクタ
Feed::Feed(void)
	: m_Position(vivid::Vector2(0.0f,0.0f))
	, m_ActiveFlag(true)
{
}

// 初期化
void Feed::Initialize(const vivid::Vector2& current_pos)
{
	m_Position.x = current_pos.x;
	m_Position.y = current_pos.y;
	m_ActiveFlag = true;
}

// 更新
void Feed::Update(void)
{
}

// 描画
void Feed::Draw(void)
{
	vivid::DrawTexture("data\\ball.png", m_Position);
}

// 解放
void Feed::Finalize(void)
{
	m_Position = vivid::Vector2(0.0f, 0.0f);
}

// アクティブフラグを返す
bool Feed::IsActive(void)
{
	return m_ActiveFlag;
}

// アクティブフラグに代入
void Feed::InActive(bool active)
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
	return m_Position + vivid::Vector2(18.0f, 20.0f);
}

float Feed::GetPos(void)
{
	return m_Position.y;
}
