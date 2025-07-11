#include "Mirrormoray.h"

const int		CMirrormoray::m_MaxDecoy			= 1;
const float		CMirrormoray::m_Range				= 100;

const float		CMirrormoray::m_width				= CharacterManager::GetInstance().CharacterWIDTH (CHARACTER_ID::MIRRORMORAYELL);
const float		CMirrormoray::m_height				= CharacterManager::GetInstance().CharacterHEIGHT(CHARACTER_ID::MIRRORMORAYELL);

CMirrormoray::CMirrormoray(void)
	:m_Anchor(vivid::Vector2::ZERO)
{
}

void CMirrormoray::Initialize(int playernumber)
{
	m_PlayerNumber = playernumber;

	//ランダムで角度を決める
	m_Angle = (rand() % 360) * 3.14f / 180.f;	

	//ファイルパス取得
	m_FilePath = CharacterManager::GetInstance().CharacterFilePath(CHARACTER_ID::MIRRORMORAYELL);

	//Rect取得
	m_Rect = CharacterManager::GetInstance().CharacterRect(CHARACTER_ID::MIRRORMORAYELL);

	//Anchor
	m_Anchor.x = m_width / 2;
	m_Anchor.y = m_height / 2;
}

void CMirrormoray::Update(vivid::Vector2 pos, float angle, float scalex)
{
	pos.x += m_width / 2;
	pos.y += m_height / 2;

	m_Position.x = cos(m_Angle) * m_Range + pos.x;
	m_Position.y = sin(m_Angle) * m_Range + pos.y;

	m_Position.x -= m_width / 2;
	m_Position.y -= m_height / 2;

	vivid::DrawTexture(m_FilePath, m_Position, 0xffffffff, m_Rect, m_Anchor , vivid::Vector2(scalex, 1.0f),angle);
}

void CMirrormoray::Finalize(void)
{
}
