#include "..\..\..\scenemanager.h"
#include "gamemain.h"
#include "..\..\..\..\fishermanager\fishermanager.h"
#include"../../../../charactermanager/charactermanager.h"
#include"../../../../charactermanager/characterID.h"
#include"../../../../playermanager/playermanager.h"
//#include "..\scene_id.h"
//#include "vivid.h"

//‰¼
static const int MaxPlyer = 1;

CHARACTER_ID UseCharacter[MaxPlyer][3] =
<<<<<<< HEAD
{ {CHARACTER_ID::TUNA,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY}/*,
=======
{ {CHARACTER_ID::PORCUPINEFISH,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY}/*,
>>>>>>> 615c34916ced96174630f884514b58980e5f2080
	{CHARACTER_ID::ELSCTRICEEL,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY},
	{CHARACTER_ID::SHARK,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY},
	{CHARACTER_ID::TURTLE,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY}*/
};

GAMEMAIN::GAMEMAIN(void)
{
}

void GAMEMAIN::Initialize(void)
{
	FisherManager::GetInstance().Initialize();

	//‰¼
	for (int i = 0; i < MaxPlyer; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			playermanager::GetInstance().GetUseCharacter(UseCharacter[i][k], i, k);
		}
	}

	playermanager::GetInstance().Initialize(MaxPlyer);
}

void GAMEMAIN::Update(void)
{
	vivid::DrawTexture("data\\seabackground.png", vivid::Vector2(0, 165));

	FisherManager::GetInstance().Update();

	playermanager::GetInstance().Update();
	

#ifdef VIVID_DEBUG
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::RESULT);
#endif
}

void GAMEMAIN::Draw(void)
{

	FisherManager::GetInstance().Draw();

	playermanager::GetInstance().Draw();


#ifdef VIVID_DEBUG
	vivid::DrawText(24, "gamemain", vivid::Vector2(0.0f, 0.0f));
#endif
}

void GAMEMAIN::Finalize(void)
{
}
