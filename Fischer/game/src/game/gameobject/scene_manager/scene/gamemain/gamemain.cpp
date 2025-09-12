#include "..\..\scene_manager.h"
#include "gamemain.h"
#include "..\..\..\fisher_manager\fisher_manager.h"
#include"..\..\..\character_manager/character_manager.h"
#include "..\..\..\character_manager\characterID.h"
#include"..\..\..\player_manager/player_manager.h"
#include "..\..\..\score_manager\score_manager.h"
#include "..\..\..\time_manager\time_manager.h"
#include "..\title\title.h"
//#include "..\scene_id.h"
//#include "vivid.h"

const int		Gamemain::m_max_fish = 3;
const float		Gamemain::m_water_surface = 165.0f;
const int		Gamemain::m_max_round = 3;
//仮
static const int MaxPlayer = 2;

CHARACTER_ID UseCharacter[MaxPlayer][3] =
{ {CHARACTER_ID::SHARK,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY},
	{CHARACTER_ID::TUNA,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY}/*,
	{CHARACTER_ID::SHARK,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY},
	{CHARACTER_ID::TURTLE,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY}*/
};

Gamemain::Gamemain(void)
{
}

void Gamemain::Initialize(void)
{
	m_CurrentRound = 1;
	m_BlackFlag = false;
	m_BlackColor = 0x00000000;

	FisherManager::GetInstance().Initialize();

	for (int i = 0; i < MaxPlayer; i++)
	{
		for (int k = 0; k < m_max_fish; k++)
		{
			playermanager::GetInstance().GetUseCharacter(UseCharacter[i][k], i, k);
		}
	}

	playermanager::GetInstance().Initialize(MaxPlayer);

	ScoreManager::GetInstance().Initialize();

	CTimeManager::GetInstance().Initialize();

	m_Rect = { 0,0,310,80 };
	m_Anchor = { 160,40 };
	m_Scale = { 1.3,1.3 };
	m_ButtonPosition = { vivid::WINDOW_WIDTH / 2 - 160,vivid::WINDOW_HEIGHT / 2 - 40 };
}

void Gamemain::Update(void)
{
	//仮
	vivid::DrawTexture("data\\background.png", vivid::Vector2(0.0f, m_water_surface));
	namespace keyboard = vivid::keyboard;

	CTimeManager::GetInstance().Update();

	ScoreManager::GetInstance().Update();

	FisherManager::GetInstance().Update();

	playermanager::GetInstance().Update();

	if (CTimeManager::GetInstance().GetTimer() <= 1)
	{
		//RETURNはエンター
		if (keyboard::Button(keyboard::KEY_ID::RETURN))
		{
			m_BlackFlag = true;

			SceneManager::GetInstance().Change_scene(SCENE_ID::RESULT);
		}
	}

	if (m_BlackFlag)
	{
		ChangeRound();
	}

//#ifdef VIVID_DEBUG
	// Zキーでシーン変更
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::RESULT);
//#endif
}

void Gamemain::Draw(void)
{
	//vivid::DrawTexture("data\\background.png", vivid::Vector2(0.0f, m_water_surface));

	ScoreManager::GetInstance().Draw();

	CTimeManager::GetInstance().Draw();

	FisherManager::GetInstance().Draw();

	playermanager::GetInstance().Draw();

	if (CTimeManager::GetInstance().GetTimer() <= 1)
	{
		vivid::DrawTexture("data\\result_button.png", m_ButtonPosition, 0xffffffff, m_Rect, m_Anchor, m_Scale);
	}

	vivid::DrawTexture("data\\black.png", vivid::Vector2::ZERO, m_BlackColor);

#ifdef VIVID_DEBUG
	vivid::DrawText(24, "gamemain", vivid::Vector2(0.0f, 0.0f));
#endif
}

void Gamemain::Finalize(void)
{
}

void Gamemain::ChangeRound(void)
{
	m_BlackColor += 0x01000000;
}
