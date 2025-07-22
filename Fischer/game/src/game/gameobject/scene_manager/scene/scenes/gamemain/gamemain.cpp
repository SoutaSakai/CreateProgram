#include "..\..\..\scene_manager.h"
#include "gamemain.h"
#include "..\..\..\..\fisher_manager\fisher_manager.h"
#include"../../../../character_manager/character_manager.h"
#include"../../../../character_manager/characterID.h"
#include"../../../../player_manager/player_manager.h"
//#include "..\scene_id.h"
//#include "vivid.h"

//仮
static const int MaxPlyer = 1;

const float		Gamemain::water_surface = 165.0f;

CHARACTER_ID UseCharacter[MaxPlyer][3] =
{ {CHARACTER_ID::TUNA,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY}/*,*/
	//{CHARACTER_ID::ELSCTRICEEL,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY},
	//{CHARACTER_ID::SHARK,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY},
	//{CHARACTER_ID::TURTLE,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY}
};

Gamemain::Gamemain(void)
{
}

void Gamemain::Initialize(void)
{
	FisherManager::GetInstance().Initialize();

	//仮
	for (int i = 0; i < MaxPlyer; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			playermanager::GetInstance().GetUseCharacter(UseCharacter[i][k], i, k);
		}
	}

	playermanager::GetInstance().Initialize(MaxPlyer);

}

void Gamemain::Update(void)
{

	FisherManager::GetInstance().Update();
	
	playermanager::GetInstance().Update();

#ifdef VIVID_DEBUG
	// Zキーでシーン変更
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::RESULT);
#endif
}

void Gamemain::Draw(void)
{
	vivid::DrawTexture("data\\background.png", vivid::Vector2(0.0f, water_surface));

	FisherManager::GetInstance().Draw();

	playermanager::GetInstance().Draw();

#ifdef VIVID_DEBUG
	vivid::DrawText(24, "gamemain", vivid::Vector2(0.0f, 0.0f));
#endif
}

void Gamemain::Finalize(void)
{
}
