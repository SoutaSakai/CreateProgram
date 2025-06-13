#include "..\..\..\scene_manager.h"
#include "..\scene_id.h"
#include "gamemain.h"
#include "vivid.h"

GAMEMAIN::GAMEMAIN(void)
{
}

void GAMEMAIN::Initialize(void)
{
}

void GAMEMAIN::Update(void)
{
#ifdef VIVID_DEBUG
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SCENE_MANAGER::GetInstance().Change_scene(SCENE_ID::RESULT);
#endif
}

void GAMEMAIN::Draw(void)
{
#ifdef VIVID_DEBUG
	vivid::DrawText(24, "gamemain", vivid::Vector2(0.0f, 0.0f));
#endif
}

void GAMEMAIN::Finalize(void)
{
}
