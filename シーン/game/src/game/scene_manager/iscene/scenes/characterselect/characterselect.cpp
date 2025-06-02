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
	vivid::DrawTexture("data\\fence.png", vivid::Vector2(vivid::WINDOW_WIDTH / 2 - 300.0f, 100.0f));

#ifdef VIVID_DEBUG
	vivid::DrawText(24, "characterselect", vivid::Vector2(0.0f, 0.0f));
#endif
}

void CHARACTERSELECT::Finalize(void)
{
}
