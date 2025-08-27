#include "..\..\scene_manager.h"
#include "characterselect.h"

const int	CharacterSelect::m_max_character	= 9;	// キャラクターの最大数
const int	CharacterSelect::m_max_player		= 4;	// プレイヤーの最大数
const int	CharacterSelect::m_distance			= 20;	// 表示間隔

CharacterSelect::CharacterSelect(void)
{
}

void CharacterSelect::Initialize(void)
{
	m_CharacterPosition = new vivid::Vector2[m_max_character];
	m_SelectPosition = new vivid::Vector2[m_max_player];

	for (int i = 0; i < m_max_character; ++i)
	{
		if (i < 5)
		{
			m_CharacterPosition[i] = vivid::Vector2(vivid::WINDOW_WIDTH / 6 * (i + 1) - 150.0f / 2, 110.0f);
		}
		else if (i < m_max_character)
		{
			m_CharacterPosition[i] = vivid::Vector2(vivid::WINDOW_WIDTH / 5 * (i - 4) - 150.0f / 2, 310.0f);
		}
	}

	m_SelectPosition[0] = vivid::Vector2{ vivid::WINDOW_WIDTH / 6 - 220.0f / 2, 100.0f };
}

void CharacterSelect::Update(void)
{
//#ifdef VIVID_DEBUG
	// Zキーでシーン変更
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::GAMEMAIN);
//#endif
}

void CharacterSelect::Draw(void)
{
	// 背景の描画
	vivid::DrawTexture("data\\background.png", vivid::Vector2::ZERO);

	/* 人数分の選択したキャラクターの枠の描画 */
	vivid::Rect rect = { 0.0f, 0.0f, 250.0f, 300.0f };

	for (int i = 0; i < m_max_player; ++i)
	{
		vivid::Vector2 scale = { 1.0f,  1.0f };

		if (i < 2)
		{
			scale.x *= -1.0f;
		}

		// 選択したキャラクターの枠（岩）の描画
		vivid::DrawTexture("data\\rock.png",
			vivid::Vector2(vivid::WINDOW_WIDTH / 5 * (i + 1) - 250.0f / 2, vivid::WINDOW_HEIGHT - 300.0f), 0xffffffff, rect, vivid::Vector2(125.0f, 150.0f), scale, 0.0f);
	}

	// キャラ選択枠の描画
	vivid::DrawTexture("data\\box.png", m_SelectPosition[0]);

	// 魚仮描画
	for (int i = 0; i < m_max_character; ++i)
	{
		vivid::DrawTexture("data\\ActiveTuna.png", m_CharacterPosition[i]);
	}


#ifdef VIVID_DEBUG

	vivid::DrawText(24, "characterselect", vivid::Vector2(0.0f, 0.0f));
	vivid::DrawLine(vivid::Vector2(vivid::WINDOW_WIDTH / 6.0f, vivid::WINDOW_HEIGHT / 5.0f), vivid::Vector2(vivid::WINDOW_WIDTH / 6.0f + 105.0f, vivid::WINDOW_HEIGHT / 5.0f), 0xffffffff);
	vivid::DrawLine(vivid::Vector2(vivid::WINDOW_WIDTH / 6.0f * 2, vivid::WINDOW_HEIGHT / 5.0f), vivid::Vector2(vivid::WINDOW_WIDTH / 6.0f * 2 - 105.0f, vivid::WINDOW_HEIGHT / 5.0f), 0xffffffff);
#endif
}

void CharacterSelect::Finalize(void)
{
}
