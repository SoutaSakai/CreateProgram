#include "Mirrormoray.h"

const int		CMirrormoray::m_MaxDecoy			= 1;
const float		CMirrormoray::m_Range				= 200;

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
	float angle = (rand() % 361 - 180) * 3.14f / 180.f; 
	m_Angle.x = cos(angle);
	m_Angle.y = sin(angle);

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
	//デコイの角度が正の値で一番上に行ったとき
	if (pos.y <= 165 && vivid::keyboard::Button(vivid::keyboard::KEY_ID::W))
	{
		vivid::DrawText(40, "W", vivid::Vector2(640, 0));
		m_Position.x = cos(atan2(m_Angle.y, m_Angle.x)) * m_Range + pos.x;
		m_Position.y -= CharacterManager::GetInstance().CharacterSpeed(CHARACTER_ID::MIRRORMORAYELL);

		//デコイが一番上に行ったら
		if (m_Position.y <= 165 && m_Angle.y > 0)
		{
			//角度を反転させる
			m_Angle.y *= -1;
		}
	}
	else if(pos.y + m_height >= vivid::WINDOW_HEIGHT && vivid::keyboard::Button(vivid::keyboard::KEY_ID::S))
	{
		vivid::DrawText(40, "S", vivid::Vector2(640, 0));
		m_Position.x = cos(atan2(m_Angle.y, m_Angle.x)) * m_Range + pos.x;
		m_Position.y += CharacterManager::GetInstance().CharacterSpeed(CHARACTER_ID::MIRRORMORAYELL);

		if (m_Position.y + m_height >= vivid::WINDOW_HEIGHT && m_Angle.y < 0)
		{
			m_Angle.y *= -1;
		}
	}
	else if (pos.x <= 0 && vivid::keyboard::Button(vivid::keyboard::KEY_ID::A))
	{
		vivid::DrawText(40, "A", vivid::Vector2(640, 0));
		m_Position.x -= CharacterManager::GetInstance().CharacterSpeed(CHARACTER_ID::MIRRORMORAYELL);
		m_Position.y = sin(atan2(m_Angle.y, m_Angle.x)) * m_Range + pos.y;

		if (m_Position.x <= 0 && m_Angle.x > 0) 
		{
			//角度を反転させる
			m_Angle.x *= -1;
		}
	}
	else if (pos.x + m_width >= vivid::WINDOW_WIDTH && vivid::keyboard::Button(vivid::keyboard::KEY_ID::D))
	{
		vivid::DrawText(40, "D", vivid::Vector2(640, 0));
		m_Position.x += CharacterManager::GetInstance().CharacterSpeed(CHARACTER_ID::MIRRORMORAYELL);
		m_Position.y = sin(atan2(m_Angle.y, m_Angle.x)) * m_Range + pos.y;

		if (m_Position.x + m_width >= vivid::WINDOW_WIDTH && m_Angle.x < 0)
		{
			//角度を反転させる
			m_Angle.x *= -1;
		}
	}
	else
	{
		//角度から座標を求める
		m_Position.x = cos(atan2(m_Angle.y,m_Angle.x)) * m_Range + pos.x;
		m_Position.y = sin(atan2(m_Angle.y, m_Angle.x)) * m_Range + pos.y;
	}


	//画面外処理
	if (m_Position.x <= 0)									m_Position.x = 0;								//左方向
	if (m_Position.x + m_width >= vivid::WINDOW_WIDTH)		m_Position.x = vivid::WINDOW_WIDTH - m_width;	//右方向
	if (m_Position.y <= 165)								m_Position.y = 165;								//上方向
	if (m_Position.y + m_height >= vivid::WINDOW_HEIGHT)	m_Position.y = vivid::WINDOW_HEIGHT - m_height;	//下方向

	vivid::DrawText(40, std::to_string( m_Angle.x), vivid::Vector2(600, 0));
	vivid::DrawTexture(m_FilePath, m_Position, 0xffff0000, m_Rect, m_Anchor , vivid::Vector2(scalex, 1.0f),angle);
}

void CMirrormoray::Finalize(void)
{
}
