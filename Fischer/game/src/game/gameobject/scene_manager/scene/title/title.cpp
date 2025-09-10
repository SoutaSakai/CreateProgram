#include "..\..\scene_manager.h"
#include "..\scene_id.h"
#include "title.h"
#include "vivid.h"
#include "..\..\..\player_manager\player_manager.h"

const int				Title::m_button_width		= 310;
const int				Title::m_button_height		= 80;
const int				Title::m_button_distance	= 50;
const int				Title::m_max_button			= 3;
const vivid::Vector2	Title::m_default_scale		= { 1.0f, 1.0f };
const vivid::Vector2	Title::m_max_scale			= { 1.3f, 1.3f };
const vivid::Rect		Title::m_rect				= { 0,0,m_button_width, m_button_height };
const vivid::Vector2	Title::m_anchor				= { m_button_width / 2,m_button_height / 2 };
const vivid::Vector2	Title::m_logo_position		= { vivid::WINDOW_WIDTH / 2.0f - 370.0f, vivid::WINDOW_HEIGHT / 5.0f };
const int				Title::m_two_player			= 2;
const int				Title::m_three_player		= 3;
const int				Title::m_four_player		= 4;

Title::Title(void)
{
}

void Title::Initialize(void)
{
	m_ButtonPosition = new vivid::Vector2[m_max_button];
	m_ButtonScale = new vivid::Vector2[m_max_button];
	m_CurrentSelect = ButtonNumber::DUMMY;

	for (int i = 0; i < m_max_button; i++)
	{
		m_ButtonPosition[i].x = vivid::WINDOW_WIDTH / (m_max_button * 2) * (i * 2 + 1) - m_button_width / 2.0f;
		m_ButtonPosition[i].y = vivid::WINDOW_HEIGHT / 3.0f * 2.0f;

		m_ButtonScale[i] = vivid::Vector2(1.0f, 1.0f);
	}

	m_MaxPlayer = 0;
}

void Title::Update(void)
{
	Keyboard();

//#ifdef VIVID_DEBUG
	// Zキーでシーン変更
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::GAMEMAIN/*CHARACTERSELECT*/);
//#endif
}

void Title::Draw(void)
{
	vivid::DrawTexture("data\\background.png", vivid::Vector2::ZERO);
	vivid::DrawTexture("data\\title_logo.png", m_logo_position);
	vivid::DrawTexture("data\\two_player.png", m_ButtonPosition[0], 0xffffffff, m_rect, m_anchor, m_ButtonScale[0], 0.0f);
	vivid::DrawTexture("data\\three_player.png", m_ButtonPosition[1], 0xffffffff, m_rect, m_anchor, m_ButtonScale[1], 0.0f);
	vivid::DrawTexture("data\\four_player.png", m_ButtonPosition[2], 0xffffffff, m_rect, m_anchor, m_ButtonScale[2], 0.0f);

#ifdef VIVID_DEBUG
	vivid::DrawText(24, "title", vivid::Vector2(0.0f, 0.0f));
#endif
}

void Title::Finalize(void)
{
}

int Title::GetMaxPlayer(void)
{
	if (m_MaxPlayer == 2)
		return	m_two_player;
	if (m_MaxPlayer == 3)
		return	m_three_player;
	if (m_MaxPlayer == 4)
		return	m_four_player;

	return	0;
}

void Title::Keyboard(void)
{
	namespace keyboard = vivid::keyboard;

	if (keyboard::Trigger(keyboard::KEY_ID::A) || keyboard::Trigger(keyboard::KEY_ID::LEFT))
	{
		if ((int)m_CurrentSelect == 0)
			m_CurrentSelect = ButtonNumber::TWO;
		else if ((int)m_CurrentSelect > 1)
			m_CurrentSelect = ButtonNumber((int)m_CurrentSelect - 1);
	}
	if (keyboard::Trigger(keyboard::KEY_ID::D) || keyboard::Trigger(keyboard::KEY_ID::RIGHT))
	{
		if ((int)m_CurrentSelect == 0)
			m_CurrentSelect = ButtonNumber::FOUR;
		else if ((int)m_CurrentSelect < 3)
			m_CurrentSelect = ButtonNumber((int)m_CurrentSelect + 1);
	}


	if (m_CurrentSelect != ButtonNumber::DUMMY)
	{
		switch (m_CurrentSelect)
		{
		case ButtonNumber::TWO:
			m_ButtonScale[0] = m_max_scale;
			m_ButtonScale[1] = m_default_scale;
			m_ButtonScale[2] = m_default_scale;
			break;
		case ButtonNumber::THREE:
			m_ButtonScale[0] = m_default_scale;
			m_ButtonScale[1] = m_max_scale;
			m_ButtonScale[2] = m_default_scale;
			break;
		case ButtonNumber::FOUR:
			m_ButtonScale[0] = m_default_scale;
			m_ButtonScale[1] = m_default_scale;
			m_ButtonScale[2] = m_max_scale;
			break;
		default:
			break;
		}
	}

	if (keyboard::Trigger(keyboard::KEY_ID::RETURN))
	{
		if (m_CurrentSelect != ButtonNumber::DUMMY)
		{
			switch (m_CurrentSelect)
			{
			case ButtonNumber::TWO:
				m_MaxPlayer = 2;
				break;
			case ButtonNumber::THREE:
				m_MaxPlayer = 3;
				break;
			case ButtonNumber::FOUR:
				m_MaxPlayer = 4;
				break;
			default:
				break;
			}

			SceneManager::GetInstance().Change_scene(SCENE_ID::GAMEMAIN/*CHARACTERSELECT*/);
		}
	}
}
