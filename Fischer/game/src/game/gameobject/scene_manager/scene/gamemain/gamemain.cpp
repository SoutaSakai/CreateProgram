#include "..\..\scene_manager.h"
#include "gamemain.h"
#include "..\..\..\fisher_manager\fisher_manager.h"
#include"..\..\..\character_manager/character_manager.h"
#include"..\..\..\character_manager/characterID.h"
#include"..\..\..\player_manager/player_manager.h"
//#include "..\scene_id.h"
//#include "vivid.h"

const int		Gamemain::m_max_player = 1;
const int		Gamemain::m_max_fish = 3;
const float		Gamemain::m_water_surface = 165.0f;

Gamemain::Gamemain(void)
{
}

void Gamemain::Initialize(void)
{
	m_UseCharacter = new UseCharacter[m_max_player];
	for (int i = 0; i < m_max_player; i++)
	{
		m_UseCharacter[i].Character = new CHARACTER_ID[m_max_fish];
	}

	FisherManager::GetInstance().Initialize();

	for (int i = 0; i < m_max_player; i++)
	{
		for (int k = 0; k < m_max_fish; k++)
		{
			playermanager::GetInstance().GetUseCharacter(m_UseCharacter[i].Character[k], i, k);
		}
	}

	playermanager::GetInstance().Initialize(m_max_player);
}

void Gamemain::Update(void)
{

	FisherManager::GetInstance().Update();
	
	playermanager::GetInstance().Update();

//#ifdef VIVID_DEBUG
	// Zキーでシーン変更
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::RESULT);
//#endif
}

void Gamemain::Draw(void)
{
	vivid::DrawTexture("data\\background.png", vivid::Vector2(0.0f, m_water_surface));

	FisherManager::GetInstance().Draw();

	playermanager::GetInstance().Draw();

#ifdef VIVID_DEBUG
	vivid::DrawText(24, "gamemain", vivid::Vector2(0.0f, 0.0f));
#endif
}

void Gamemain::Finalize(void)
{
}
