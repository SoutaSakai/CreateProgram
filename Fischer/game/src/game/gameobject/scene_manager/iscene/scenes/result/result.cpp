#include "..\..\..\scene_manager.h"
#include "..\scene_id.h"
#include "result.h"
#include "vivid.h"

Result::Result(void)
{
}

void Result::Initialize(void)
{
}

void Result::Update(void)
{
//#ifdef VIVID_DEBUG
	// Zキーでシーン変更
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::TITLE);
//#endif
}

void Result::Draw(void)
{
#ifdef VIVID_DEBUG
	vivid::DrawText(24, "result", vivid::Vector2(0.0f, 0.0f));
#endif
}

void Result::Finalize(void)
{
}
