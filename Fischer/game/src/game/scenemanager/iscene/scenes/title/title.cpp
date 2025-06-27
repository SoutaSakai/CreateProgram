#include "..\..\..\scenemanager.h"
#include "..\scene_id.h"
#include "title.h"
#include "vivid.h"

const vivid::Vector2	Title::button_position = { 100.0f, 300.0f };
const float				Title::button_width = 200.0f;
const float				Title::button_height = 50.0f;

Title::Title(void)
{
}

void Title::Initialize(void)
{
}

void Title::Update(void)
{
	namespace keyboard = vivid::keyboard;
	namespace mouse = vivid::mouse;

	// マウスクリックでボタン領域を判定してシーン変更
	vivid::Point mp = mouse::GetCursorPos();	

	if (mouse::Trigger(mouse::BUTTON_ID::LEFT))
	{
		if (mp.x >= button_position.x && mp.x <= button_position.x + button_width &&
			mp.y >= button_position.y && mp.y <= button_position.y + button_height)
		{
			SceneManager::GetInstance().Change_scene(SCENE_ID::CHARACTERSELECT);
		}
	}

//#ifdef VIVID_DEBUG
	// Zキーでシーン変更
	if (keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::CHARACTERSELECT);
//#endif
}

void Title::Draw(void)
{
	vivid::DrawTexture("data\\background.png", vivid::Vector2(0.0f, 0.0f));
	vivid::DrawTexture("data\\titlelogo.png", vivid::Vector2(270.0f, 150.0f));
	vivid::DrawTexture("data\\button.png", vivid::Vector2(32.0f, 450.0f));
	vivid::DrawTexture("data\\button.png", vivid::Vector2(420.0f, 450.0f));
	vivid::DrawTexture("data\\button.png", vivid::Vector2(810.0f, 450.0f));

#ifdef VIVID_DEBUG
	vivid::DrawText(24, "title", vivid::Vector2(0.0f, 0.0f));
#endif
}

void Title::Finalize(void)
{
}

//void InitializeTitle(void)
//{
//}
//
//void UpdateTitle(void)
//{
//	namespace keyboard = vivid::keyboard;
//	namespace mouse = vivid::mouse;
//
//	// Zキーでシーン変更
//	if (keyboard::Trigger(keyboard::KEY_ID::Z))
//		ChangeScene(SCENE_ID::GAMEMAIN);
//
//	// マウスクリックでボタン領域を判定してシーン変更
//	vivid::Point mp = mouse::GetCursorPos();
//
//	// 仮にボタンの座標とサイズを設定（例: x=100, y=300, width=200, height=50）
//	const int buttonX = 100;
//	const int buttonY = 300;
//	const int buttonWidth = 200;
//	const int buttonHeight = 50;
//
//	if (mouse::Trigger(mouse::BUTTON_ID::LEFT)) {
//		if (mp.x >= buttonX && mp.x <= buttonX + buttonWidth &&
//			mp.y >= buttonY && mp.y <= buttonY + buttonHeight) {
//			ChangeScene(SCENE_ID::GAMEMAIN);
//		}
//	}
//}
//
//void DraweTitle(void)
//{
//
//#ifdef VIVID_DEBUG
//	vivid::DrawTexture("data\\turibito.png", vivid::Vector2(0.0f, 0.0f));
//	vivid::DrawTexture("data\\misasa.png", vivid::Vector2(270.0f, 150.0f));
//	vivid::DrawTexture("data\\2pp.png", vivid::Vector2(32.0f, 430.0f));
//	vivid::DrawTexture("data\\3pp.png", vivid::Vector2(420.0f, 430.0f));
//	vivid::DrawTexture("data\\4pp.png", vivid::Vector2(810.0f, 430.0f));
//#endif
//
//#ifdef _DEBUG
//	vivid::DrawText(40, "Title Scene", vivid::Vector2(0.0f, 0.0f));
//#endif
//
//}
//
//void FinalizeeTitle(void)
//{
//}