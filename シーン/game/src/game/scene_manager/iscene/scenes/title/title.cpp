#include "..\..\..\scene_manager.h"
#include "..\scene_id.h"
#include "title.h"
#include "vivid.h"

TITLE::TITLE(void)
{
}

void TITLE::Initialize(void)
{
}

void TITLE::Update(void)
{
#ifdef VIVID_DEBUG
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SCENE_MANAGER::GetInstance().Change_scene(SCENE_ID::GAMEMAIN);
#endif
}

void TITLE::Draw(void)
{
#ifdef VIVID_DEBUG
	vivid::DrawText(24, "title", vivid::Vector2(0.0f, 0.0f));
#endif
}

void TITLE::Finalize(void)
{
}
