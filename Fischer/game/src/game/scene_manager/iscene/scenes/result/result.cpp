#include "..\..\..\scene_manager.h"
#include "..\scene_id.h"
#include "result.h"
#include "vivid.h"

RESULT::RESULT(void)
{
}

void RESULT::Initialize(void)
{
}

void RESULT::Update(void)
{
#ifdef VIVID_DEBUG
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SCENE_MANAGER::GetInstance().Change_scene(SCENE_ID::TITLE);
#endif
}

void RESULT::Draw(void)
{
#ifdef VIVID_DEBUG
	vivid::DrawText(24, "result", vivid::Vector2(0.0f, 0.0f));
#endif
}

void RESULT::Finalize(void)
{
}
