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
	m_Angle = (rand() % 360) * 3.14f / 180.f; 
	m_PositionAngle.x = cos(m_Angle);
	m_PositionAngle.y = sin(m_Angle);

	//ファイルパス取得
	m_FilePath = CharacterManager::GetInstance().CharacterFilePath(CHARACTER_ID::MIRRORMORAYELL);

	//Rect取得
	m_Rect = CharacterManager::GetInstance().CharacterRect(CHARACTER_ID::MIRRORMORAYELL);

	//Anchor
	m_Anchor.x = m_width / 2;
	m_Anchor.y = m_height / 2;

	//スピード
	m_Speed = CharacterManager::GetInstance().CharacterSpeed(CHARACTER_ID::MIRRORMORAYELL);

	//距離
	m_Distance = m_Range;
}

void CMirrormoray::Update(vivid::Vector2 pos, float angle, float scalex)
{
	m_directionAngle = angle;

	vivid::Vector2 destination = {0,0};

	//スティックの入力
	vivid::Vector2 ControllerPos = vivid::controller::GetAnalogStickLeft((vivid::controller::DEVICE_ID)m_PlayerNumber);

	//上方向
	if (pos.y <= 165 && ControllerPos.y < 0)
	{
		destination.y = m_Position.y - m_Speed;

		m_Position.x = cos(atan2(m_PositionAngle.y, m_PositionAngle.x)) * m_Distance + pos.x;
		m_Position.y -= m_Speed;

		//デコイが一番上に行ったら
		if (m_Position.y <= 165 && m_PositionAngle.y > 0)
		{
			//角度を反転させる
			m_PositionAngle.y *= -1;
		}
	}
	//下方向
	else if(pos.y + m_height >= vivid::WINDOW_HEIGHT && ControllerPos.y > 0)
	{
		m_Position.x = cos(atan2(m_PositionAngle.y, m_PositionAngle.x)) * m_Distance + pos.x;
		m_Position.y += m_Speed;

		if (m_Position.y + m_height >= vivid::WINDOW_HEIGHT && m_PositionAngle.y < 0)
		{
			m_PositionAngle.y *= -1;
		}
	}
	//左方向
	else if (pos.x <= 0 && ControllerPos.x < 0)
	{
		m_Position.x -= m_Speed;
		m_Position.y = sin(atan2(m_PositionAngle.y, m_PositionAngle.x)) * m_Distance + pos.y;

		if (m_Position.x <= 0 && m_PositionAngle.x > 0)
		{
			//角度を反転させる
			m_PositionAngle.x *= -1;
		}
	}
	//右方向
	else if (pos.x + m_width >= vivid::WINDOW_WIDTH && ControllerPos.x > 0)
	{
		
		m_Position.x += m_Speed;
		m_Position.y = sin(atan2(m_PositionAngle.y, m_PositionAngle.x)) * m_Distance + pos.y;

		if (m_Position.x + m_width >= vivid::WINDOW_WIDTH && m_PositionAngle.x < 0)
		{
			//角度を反転させる
			m_PositionAngle.x *= -1;
		}
	}
	else
	{
		//角度から座標を求める
		m_Position.x = cos(atan2(m_PositionAngle.y, m_PositionAngle.x)) * m_Distance + pos.x;
		m_Position.y = sin(atan2(m_PositionAngle.y, m_PositionAngle.x)) * m_Distance + pos.y;
	}


	//画面外処理
	if (m_Position.x <= 0)									m_Position.x = 0;								//左方向
	if (m_Position.x + m_width >= vivid::WINDOW_WIDTH)		m_Position.x = vivid::WINDOW_WIDTH - m_width;	//右方向
	if (m_Position.y <= 165)								m_Position.y = 165;								//上方向
	if (m_Position.y + m_height >= vivid::WINDOW_HEIGHT)	m_Position.y = vivid::WINDOW_HEIGHT - m_height;	//下方向

	vivid::DrawTexture(m_FilePath, m_Position, 0xffff0000, m_Rect, m_Anchor , vivid::Vector2(scalex, 1.0f),angle);
}

void CMirrormoray::Finalize(void)
{
}

vivid::Vector2 CMirrormoray::GetDecoyPos(void)
{
	return m_Position;
}

float CMirrormoray::GetDecoyAngle(void)
{
	return m_directionAngle;
}
