#include "fisher.h"
#include "..\..\fisher_manager\fisher_manager.h"
#include "..\..\feed_manager\feed_manager.h"
#include "..\fisherstate.h"

const int	Fisher::m_width = 150;		// 釣り人の幅
const int	Fisher::m_height = 720;		// 釣り人の高さ

Fisher::Fisher(void)
	: m_State(FISHER_STATE::RELUX)
	, m_Move(FISHER_MOVE::WAIT)
{
}

void Fisher::Initialize(float xpos)
{
	// 位置の初期化
	m_Position.x = xpos;
	m_Position.y = 0.0f;
	
	// 描画範囲の初期化
	m_Rect = vivid::Rect{ 0, 0, m_width, m_height };

	m_Move = FISHER_MOVE::WAIT;

	m_MoveFlag = false;
}

void Fisher::Update(void)
{
	if (m_Move == FISHER_MOVE::WAIT/*!m_MoveFlag*/)
	{
		m_Rect.left = m_width * (int)m_State;
		m_Rect.right = m_Rect.left + m_width;
		m_Rect.top = 0;
		m_Rect.bottom = m_height;
	}
	else
	{
		m_Rect.left = 0;
		m_Rect.right = m_width;
		m_Rect.top = m_height * (int)m_Move;
		m_Rect.bottom = m_Rect.top + m_height;
	}
}

void Fisher::Draw(void)
{
	vivid::DrawTexture("data\\fisher.png", m_Position, 0xffffffff, m_Rect);
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
		m_State = FISHER_STATE::RELUX;
	else if (random > 50 && random <= 100)
		// 注視状態に更新
		m_State = FISHER_STATE::CAUTION;
}

// 釣り人の幅を返す
int Fisher::GetWidth(void)
{
	return m_width;
}

// 釣り人の高さを返す
int Fisher::GetHeight(void)
{
	return m_height;
}

FISHER_MOVE Fisher::GetMoveState(void)
{
	return m_Move;
}

void Fisher::SetMoveState(FISHER_MOVE next)
{
	m_Move = next;
}

bool Fisher::GetMoveFlag(void)
{
	return m_MoveFlag;
}

void Fisher::SetMoveFlag(bool flag)
{
	m_MoveFlag = flag;
}

void Fisher::ChangeMove(void)
{

}
