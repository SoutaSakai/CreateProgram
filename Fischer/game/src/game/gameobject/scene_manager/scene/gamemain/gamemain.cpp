#include "..\..\scene_manager.h"
#include "gamemain.h"
#include "..\..\..\fisher_manager\fisher_manager.h"
#include"..\..\..\character_manager/character_manager.h"
#include"..\..\..\player_manager/player_manager.h"
#include "..\..\..\score_manager\score_manager.h"
#include "..\..\..\time_manager\time_manager.h"
//#include "..\scene_id.h"
//#include "vivid.h"

const int		Gamemain::m_max_fish = 3;
const float		Gamemain::m_water_surface = 165.0f;

Gamemain::Gamemain(void)
{
}

void Gamemain::Initialize(void)
{
	int MaxPlayer = SceneManager::GetInstance().GetMaxPlayer();

	m_UseCharacter = new UseCharacter[MaxPlayer];
	for (int i = 0; i < MaxPlayer; i++)
	{
		m_UseCharacter[i].Character = new CHARACTER_ID[m_max_fish];
	}

	FisherManager::GetInstance().Initialize();

	//CHARACTER_ID UseCharacter[m_max_player][m_max_fish]
	//{ {CHARACTER_ID::TUNA,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY}/*,*/
	////{CHARACTER_ID::ELSCTRICEEL,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY},
	////{CHARACTER_ID::SHARK,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY},
	////{CHARACTER_ID::TURTLE,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY}
	//};

	

	//for (int i = 0; i < MaxPlayer; i++)
	//{
	//	for (int k = 0; k < m_max_fish; k++)
	//	{
	//		playermanager::GetInstance().GetUseCharacter(UseCharacter[i][k], i, k);
	//	}
	//}
	for (int i = 0; i < MaxPlayer; i++)
	{
		for (int k = 0; k < m_max_fish; k++)
		{
			playermanager::GetInstance().GetUseCharacter(m_UseCharacter[i].Character[k], i, k);
		}
	}

	playermanager::GetInstance().Initialize(MaxPlayer);

	ScoreManager::GetInstance().Initialize();

	CTimeManager::GetInstance().Initialize();

	m_Rect = { 0,0,450,100 };
	m_Anchor = { 225,50 };
	m_Scale = { 1.3,1.3 };
	m_ButtonPosition = { vivid::WINDOW_WIDTH / 2 - 225,vivid::WINDOW_HEIGHT / 2 };
}

void Gamemain::Update(void)
{
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
			SceneManager::GetInstance().Change_scene(SCENE_ID::RESULT);
		}
	}

//#ifdef VIVID_DEBUG
	// Zキーでシーン変更
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::RESULT);
//#endif
}

void Gamemain::Draw(void)
{
	vivid::DrawTexture("data\\background.png", vivid::Vector2(0.0f, m_water_surface));

	ScoreManager::GetInstance().Draw();

	CTimeManager::GetInstance().Draw();

	FisherManager::GetInstance().Draw();

	playermanager::GetInstance().Draw();

	if (CTimeManager::GetInstance().GetTimer() <= 1)
	{
		vivid::DrawTexture("data\\button.png", m_ButtonPosition, 0xffffffff, m_Rect, m_Anchor, m_Scale);
		vivid::DrawText(25, "リザルト(ENTERボタンを押してね)", vivid::Vector2(m_ButtonPosition.x + 225 - (25 * 8), m_ButtonPosition.y + 50 - 12.5), 0xffffffff);
	}

#ifdef VIVID_DEBUG
	vivid::DrawText(24, "gamemain", vivid::Vector2(0.0f, 0.0f));
#endif
}

void Gamemain::Finalize(void)
{
}
