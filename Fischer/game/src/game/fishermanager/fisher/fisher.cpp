#include "fisher.h"
#include "..\..\fishermanager\fishermanager.h"
#include "..\..\feedmanager\feedmanager.h"
#include "..\fisherstate.h"


Fisher::Fisher(void)
	: m_State(0)
	, m_FeedActiveFlag(true)
{
}

void Fisher::Initialize(float xpos)
{
	// 位置の初期化
	m_Position.x = xpos;
	m_Position.y = 0.0f;
	
	// 描画範囲の初期化
	m_Rect = vivid::Rect{ 0, 0, (int)FisherManager::GetInstance().GetWidth(), (int)FisherManager::GetInstance().GetHeight() };
}

void Fisher::Update(void)
{
}

void Fisher::Draw(void)
{
	if (m_State == (int)FISHER_STATE::RELUX)
		// リラックス状態の描画
		vivid::DrawTexture("data\\reluxfisher.png", m_Position);
	else if (m_State == (int)FISHER_STATE::CAUTION)
		// 注視状態の描画
		vivid::DrawTexture("data\\cautionfisher.png", m_Position);
}

void Fisher::Finalize(void)
{
}

vivid::Vector2 Fisher::GetPosition(void)
{
	return m_Position;
}

// 釣り人の状態をランダムに更新
void Fisher::FisherRandState(void)
{
	// 乱数を得る
	int random = rand() % 100 + 1;

	if (random > 0 && random <= 50)
		// リラックス状態に更新
		m_State = (int)FISHER_STATE::RELUX;
	else if (random > 50 && random <= 100)
		// 注視状態に更新
		m_State = (int)FISHER_STATE::CAUTION;
}
