#include "Lionfish.h"

const std::string		CLionFish::m_filepath		= "data\\smoke.png";
const int				CLionFish::m_width			= 200;
const int				CLionFish::m_height			= 200;

const vivid::Rect		CLionFish::m_rect			= { 0,0,m_width,m_height };
const vivid::Vector2	CLionFish::m_anchor			= vivid::Vector2(m_width / 2,m_height / 2);

const float				CLionFish::m_abilityTime	= 180;
const vivid::Vector2	CLionFish::m_scalespeed		= vivid::Vector2(0.1f,0.1f);

void CLionFish::Intialize(int playernumber, vivid::Vector2 position)
{
	m_position.x = position.x + CharacterManager::GetInstance().CharacterWIDTH(CHARACTER_ID::LIONFISH) / 2 - m_width / 2;
	m_position.y = position.y + CharacterManager::GetInstance().CharacterHEIGHT(CHARACTER_ID::LIONFISH) / 2 - m_height / 2;
	m_scale = vivid::Vector2(0.0f, 0.0f);

	m_playernumber = playernumber;
	m_Color = 0xffffffff;
	m_timer = 0;
}

void CLionFish::Update(void)
{
	if (++m_timer <= m_abilityTime)
	{
		if (m_scale.x < 1.0f)
			m_scale += m_scalespeed;

	}
	else
	{
		m_Color -= 0x01000000;

		if (m_Color <= 0x00ffffff)
		{
			playermanager::GetInstance().ChangeSkilFlagFalse(m_playernumber);
		}
		
	}

	vivid::DrawTexture(m_filepath, m_position, m_Color, m_rect, m_anchor, m_scale);
}

void CLionFish::Draw(void)
{
}

void CLionFish::Finalize(void)
{
}
