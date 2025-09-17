#include "..\..\scene_manager.h"
#include "..\scene_id.h"
#include "title.h"
#include "vivid.h"
#include "..\..\..\player_manager\player_manager.h"
#include "..\..\..\maxplayer_manager\maxplayer_manager.h"

const int				Title::m_button_width		= 310;
const int				Title::m_button_height		= 80;
const int				Title::m_button_distance	= 50;
const int				Title::m_max_button			= 3;
const vivid::Vector2	Title::m_default_scale		= { 1.0f, 1.0f };
const vivid::Vector2	Title::m_max_scale			= { 1.3f, 1.3f };
const vivid::Rect		Title::m_rect				= { 0,0,m_button_width, m_button_height };
const vivid::Vector2	Title::m_anchor				= { m_button_width / 2,m_button_height / 2 };
const vivid::Vector2	Title::m_logo_position		= { vivid::WINDOW_WIDTH / 2.0f - 370.0f, vivid::WINDOW_HEIGHT / 5.0f };

const vivid::controller::DEVICE_ID Title::m_DeviceID[] =
{
	vivid::controller::DEVICE_ID::PLAYER1,
	vivid::controller::DEVICE_ID::PLAYER2,
	vivid::controller::DEVICE_ID::PLAYER3,
	vivid::controller::DEVICE_ID::PLAYER4,
};

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
	m_ControllerTime = 0;
}

void Title::Update(void)
{
	Keyboard();

	controller();

//#ifdef VIVID_DEBUG
	// Zキーでシーン変更
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::CHARACTERSELECT);
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
	return	m_MaxPlayer;
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

			CMaxPlayerManager::GetInstance().SetMaxPlayer(m_MaxPlayer);
			SceneManager::GetInstance().Change_scene(SCENE_ID::CHARACTERSELECT);
		}
	}
}

void Title::controller(void)
{
	vivid::Vector2 controllerpos = { 0,0 };

	//タイマー更新
	++m_ControllerTime;

	for (int i = 0; i < (int)vivid::controller::DEVICE_ID::MAX; i++)
	{
		controllerpos = vivid::controller::GetAnalogStickLeft(m_DeviceID[i]);

		//タイマー比較
		if (m_ControllerTime >= 10)
		{
			if (controllerpos.x <= -0.3)
			{
				if ((int)m_CurrentSelect == 0)
					m_CurrentSelect = ButtonNumber::TWO;
				else if ((int)m_CurrentSelect > 1)
					m_CurrentSelect = ButtonNumber((int)m_CurrentSelect - 1);
			}
			if (controllerpos.x >= 0.3)
			{
				if ((int)m_CurrentSelect == 0)
					m_CurrentSelect = ButtonNumber::FOUR;
				else if ((int)m_CurrentSelect < 3)
					m_CurrentSelect = ButtonNumber((int)m_CurrentSelect + 1);
			}
		}

		if (vivid::controller::Trigger(m_DeviceID[i], vivid::controller::BUTTON_ID::A))
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

				CMaxPlayerManager::GetInstance().SetMaxPlayer(m_MaxPlayer);
				SceneManager::GetInstance().Change_scene(SCENE_ID::CHARACTERSELECT);
			}
		}
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

	//タイマー比較
	if (m_ControllerTime >= 10)
		m_ControllerTime = 0;
}