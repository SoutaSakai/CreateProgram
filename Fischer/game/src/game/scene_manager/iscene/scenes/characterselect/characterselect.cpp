#include "..\..\..\scenemanager.h"
#include "characterselect.h"

CharacterSelect::CharacterSelect(void)
{
}

void CharacterSelect::Initialize(void)
{
	for (int i = 0; i < 9; ++i)
	{
		if (i < 5)
		{
			fish_position[i] = vivid::Vector2(vivid::WINDOW_WIDTH / 6 * (i + 1) - 150.0f / 2, 110.0f);
		}
		else if (i < 9)
		{
			fish_position[i] = vivid::Vector2(vivid::WINDOW_WIDTH / 5 * (i - 4) - 150.0f / 2, 310.0f);
		}
	}

	select_position[0] = vivid::Vector2{ vivid::WINDOW_WIDTH / 6 - 220.0f / 2, 100.0f };
}

void CharacterSelect::Update(void)
{
//#ifdef VIVID_DEBUG
	// ZƒL[‚ÅƒV[ƒ“•ÏX
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::GAMEMAIN);
//#endif
}

void CharacterSelect::Draw(void)
{
	// ”wŒi‚Ì•`‰æ
	vivid::DrawTexture("data\\background.png", vivid::Vector2::ZERO);

	vivid::Rect rect = { 0.0f, 0.0f, 250.0f, 300.0f };

	/* l”•ª‚Ì‘I‘ð‚µ‚½ƒLƒƒƒ‰ƒNƒ^[‚Ì˜g‚Ì•`‰æ */
	for (int i = 0; i < 4; ++i)
	{
		vivid::Vector2 scale = { 1.0f,  1.0f };

		if (i < 2)
		{
			scale.x *= -1.0f;
		}

		// ‘I‘ð‚µ‚½ƒLƒƒƒ‰ƒNƒ^[‚Ì˜giŠâj‚Ì•`‰æ
		vivid::DrawTexture("data\\rock.png",
			vivid::Vector2(vivid::WINDOW_WIDTH / 5 * (i + 1) - 250.0f / 2, vivid::WINDOW_HEIGHT - 300.0f), 0xffffffff, rect, vivid::Vector2(125.0f, 150.0f), scale, 0.0f);
	}
	// ƒLƒƒƒ‰‘I‘ð˜g‚Ì•`‰æ
	vivid::DrawTexture("data\\box.png", select_position[0]);

	// ‹›‰¼•`‰æ
	for (int i = 0; i < 9; ++i)
	{
		vivid::DrawTexture("data\\Tuna.png", fish_position[i]);
	}


#ifdef VIVID_DEBUG

	vivid::DrawText(24, "characterselect", vivid::Vector2(0.0f, 0.0f));

#endif
}

void CharacterSelect::Finalize(void)
{
}
