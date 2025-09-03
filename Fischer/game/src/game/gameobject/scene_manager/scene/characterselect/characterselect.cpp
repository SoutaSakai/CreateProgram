#include "characterselect.h"
#include "..\..\scene_manager.h"
#include "..\..\..\character_manager\character_manager.h"

const int	CharacterSelect::m_flame_width		= 220;	// 選択枠の幅
const int	CharacterSelect::m_flame_height		= 100;	// 選択枠の高さ
const int	CharacterSelect::m_max_character	= (int)CHARACTER_ID::MAX - 1;
const int	CharacterSelect::m_max_player		= 4;	// プレイヤーの最大数
const int	CharacterSelect::m_distance			= 20;	// 表示間隔

CharacterSelect::CharacterSelect(void)
{
}

void CharacterSelect::Initialize(void)
{
	m_CharacterPosition = new vivid::Vector2[m_max_character];
	m_FlamePosition = new vivid::Vector2[m_max_player];
	m_CullentSelect = new CHARACTER_ID[m_max_player];

	for (int i = 0; i < m_max_character; ++i)
	{
		if (i < 5)
		{
			m_CharacterPosition[i] = vivid::Vector2(vivid::WINDOW_WIDTH / 10 * (i * 2 + 1) - 150.0f / 2, 110.0f);
		}
		else if (i < m_max_character)
		{
			m_CharacterPosition[i] = vivid::Vector2(vivid::WINDOW_WIDTH / 5 * (i - 4) - 150.0f / 2, 310.0f);
		}
	}

	for (int i = 0; i < m_max_player; ++i)
	{
		m_CullentSelect[i] = CHARACTER_ID::DUMMY;

		m_FlamePosition[i].x = GetFlamePosition(0).x;
		m_FlamePosition[i].y = GetFlamePosition(0).y;
	}
}

void CharacterSelect::Update(void)
{


	Keyboard();

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
	vivid::DrawTexture("data\\select_flame.png", m_FlamePosition[0]);

	// 魚仮描画
	for (int i = 0; i < m_max_character; ++i)
	{
		vivid::DrawTexture("data\\tuna.png", m_CharacterPosition[i]);
	}


#ifdef VIVID_DEBUG
	vivid::DrawText(24, "characterselect", vivid::Vector2(0.0f, 0.0f));
	//vivid::DrawLine(vivid::Vector2(vivid::WINDOW_WIDTH / 6.0f, vivid::WINDOW_HEIGHT / 5.0f), vivid::Vector2(vivid::WINDOW_WIDTH / 6.0f + 105.0f, vivid::WINDOW_HEIGHT / 5.0f), 0xffffffff);
	//vivid::DrawLine(vivid::Vector2(vivid::WINDOW_WIDTH / 6.0f * 2, vivid::WINDOW_HEIGHT / 5.0f), vivid::Vector2(vivid::WINDOW_WIDTH / 6.0f * 2 - 105.0f, vivid::WINDOW_HEIGHT / 5.0f), 0xffffffff);
#endif
}

void CharacterSelect::Finalize(void)
{
}

void CharacterSelect::Keyboard(void)
{
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::D) || vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::RIGHT))
	{

	}
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::A) || vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::LEFT))
	{

	}
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::W) || vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::UP))
	{

	}
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::S) || vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::DOWN))
	{

	}
}

vivid::Vector2 CharacterSelect::GetFlamePosition(int num)
{
	float CenterPositionX = m_CharacterPosition[num].x + CharacterManager::GetInstance().CharacterWIDTH(CHARACTER_ID::TUNA) / 2.0f;
	float CenterPositionY = m_CharacterPosition[num].y + CharacterManager::GetInstance().CharacterHEIGHT(CHARACTER_ID::TUNA) / 2.0f;

	float FlamePositionX = CenterPositionX - m_flame_width / 2.0f;
	float FlamePositionY = CenterPositionY - m_flame_height / 2.0f;

	return vivid::Vector2(FlamePositionX, FlamePositionY);
}
