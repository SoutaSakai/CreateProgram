#include "..\..\scene_manager.h"
#include "..\scene_id.h"
#include "title.h"
#include "vivid.h"

const float		Title::m_button_width		= 310.0f;
const float		Title::m_button_height		= 80.0f;
const float		Title::m_button_distance	= 50.0f;
const int		Title::m_max_button			= 3;

Title::Title(void)
{
}

void Title::Initialize(void)
{
	m_ButtonPosition = new vivid::Vector2[m_max_button];
	m_CurrentSelect = ButtonNumber::DUMMY;
}

void Title::Update(void)
{
	namespace keyboard = vivid::keyboard;

	if (keyboard::Trigger(keyboard::KEY_ID::RETURN))
	{
		if (m_CurrentSelect != ButtonNumber::DUMMY)
		{
			switch (m_CurrentSelect)
			{
			case ButtonNumber::TWO:
				SceneManager::GetInstance().SetMaxPlayer(2);
				break;
			case ButtonNumber::THREE:
				SceneManager::GetInstance().SetMaxPlayer(3);
				break;
			case ButtonNumber::FOUR:
				SceneManager::GetInstance().SetMaxPlayer(4);
				break;
			default:
				break;
			}

			SceneManager::GetInstance().Change_scene(SCENE_ID::CHARACTERSELECT);
		}
	}

//#ifdef VIVID_DEBUG
	// Zキーでシーン変更
	if (keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::CHARACTERSELECT);
//#endif
}

void Title::Draw(void)
{
	vivid::DrawTexture("data\\background.png", vivid::Vector2(0.0f, 0.0f));
	vivid::DrawTexture("data\\titlelogo.png", vivid::Vector2(270.0f, 150.0f));
	vivid::DrawTexture("data\\two_player.png", vivid::Vector2(32.0f, 450.0f));
	vivid::DrawTexture("data\\three_player.png", vivid::Vector2(420.0f, 450.0f));
	vivid::DrawTexture("data\\four_player.png", vivid::Vector2(810.0f, 450.0f));

#ifdef VIVID_DEBUG
	vivid::DrawText(24, "title", vivid::Vector2(0.0f, 0.0f));
#endif
}

void Title::Finalize(void)
{
}