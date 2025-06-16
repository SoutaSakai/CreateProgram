#include "..\..\..\scene_manager.h"
#include "characterselect.h"
#include "vivid.h"

CHARACTERSELECT::CHARACTERSELECT(void)
{
}

void CHARACTERSELECT::Initialize(void)
{
}

void CHARACTERSELECT::Update(void)
{
#ifdef VIVID_DEBUG
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SCENE_MANAGER::GetInstance().Change_scene(SCENE_ID::GAMEMAIN);
#endif
}

void CHARACTERSELECT::Draw(void)
{
	vivid::DrawTexture("data\\background.png", vivid::Vector2::ZERO);

	vivid::Rect rect = { 0.0f, 0.0f, 250.0f, 300.0f };

	/* 人数分の選択したキャラクターの枠の描画 */
	for (int i = 0; i < 4; ++i)
	{
		vivid::Vector2 scale = { 1.0f,  1.0f };

		if (i < 2)
		{
			scale.x *= -1.0f;
		}

		// 選択したキャラクターの枠の描画
		vivid::DrawTexture("data\\rock.png",
								vivid::Vector2(vivid::WINDOW_WIDTH / 5 * (i + 1) - 250.0f / 2, vivid::WINDOW_HEIGHT - 300.0f), 0xffffffff, rect, vivid::Vector2(125.0f, 150.0f), scale,0.0f);
	}

#ifdef VIVID_DEBUG
	vivid::DrawText(24, "characterselect", vivid::Vector2(0.0f, 0.0f));
	for (int i = 0; i < 2; ++i)
	{
		if (i == 0)
		{
			for (int j = 0; j < 5; ++j)
			{
				vivid::DrawTexture("data\\Tuna.png", vivid::Vector2(vivid::WINDOW_WIDTH / 6 * (j + 1) - 220.0f / 2, i * 200.0f + 100.0f));
			}
		}
		else
		{
			for (int j = 0; j < 4; ++j)
			{
				vivid::DrawTexture("data\\Tuna.png", vivid::Vector2(vivid::WINDOW_WIDTH / 5 * (j + 1) - 220.0f / 2, i * 200.0f + 100.0f));
			}
		}
	}
#endif
}

void CHARACTERSELECT::Finalize(void)
{
}
