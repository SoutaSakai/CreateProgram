#include "Octopus.h"

const float			COctopus::m_AbilityTime			= 1.5f;
const std::string	COctopus::m_FilePath			= "data\\ink.png";
const float			COctopus::m_ScaleSpeed			= 0.03f;
const unsigned int	COctopus::m_TransparencySpeed	= 0x01000000;

const int			COctopus::m_InkWidth		= 300/*vivid::GetTextureWidth(m_FilePath)*/;
const int			COctopus::m_InkHeight		= 300/*vivid::GetTextureHeight(m_FilePath)*/;

COctopus::COctopus(void)
{
	
}

void COctopus::Initialize(int playernumber, vivid::Vector2 positon, vivid::Vector2 scale)
{
	m_PlayerNumber = playernumber;

	m_Position.x = positon.x + CharacterManager::GetInstance().CharacterWIDTH (CHARACTER_ID::OCTOPUS);
	m_Position.y = positon.y + CharacterManager::GetInstance().CharacterHEIGHT(CHARACTER_ID::OCTOPUS) / 2 - m_InkHeight / 2;

	m_Color = 0xffffffff;

	m_Rect = { 0,0,m_InkWidth ,m_InkHeight };
	m_Anchor = vivid::Vector2(0.0f, m_InkHeight / 2);
	m_Scale = vivid::Vector2::ZERO;

	m_Timer = 0;
}

void COctopus::Update(void)
{
	//vivid::DrawText(40, std::to_string(m_Scale.x), vivid::Vector2(vivid::WINDOW_WIDTH / 2, vivid::WINDOW_HEIGHT / 2), 0xffffffff);

	if (m_Scale.x < 1.0f)
	{
		m_Scale.x += m_ScaleSpeed;
		m_Scale.y += m_ScaleSpeed;
	}
	else if(m_Timer <= m_AbilityTime)
	{
		m_Timer += vivid::GetDeltaTime();
	}
	else
	{
		m_Color -= 0x01000000;

		if (m_Color <= 0x00ffffff)
		{
			playermanager::GetInstance().ChangeSkilFlagFalse(m_PlayerNumber);
		}
	}
	vivid::DrawTexture(m_FilePath, m_Position, m_Color, m_Rect, m_Anchor, m_Scale);
}

void COctopus::Finalize(void)
{
}
