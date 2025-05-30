#include "..\..\..\scenemanager.h"
#include "gamemain.h"
#include "fishermanager\fishermanager.h"
//#include "..\scene_id.h"
//#include "vivid.h"


GAMEMAIN::GAMEMAIN(void)
{
}

void GAMEMAIN::Initialize(void)
{
	FisherManager::GetInstance().Initialize();
}

void GAMEMAIN::Update(void)
{
	FisherManager::GetInstance().Update();
	

#ifdef VIVID_DEBUG
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::RESULT);
#endif
}

void GAMEMAIN::Draw(void)
{
	FisherManager::GetInstance().Draw();


#ifdef VIVID_DEBUG
	vivid::DrawText(24, "gamemain", vivid::Vector2(0.0f, 0.0f));
#endif
}

void GAMEMAIN::Finalize(void)
{
}
