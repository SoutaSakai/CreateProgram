#include "scene_manager.h"
#include "iscene\scenes\title\title.h"
#include "iscene\scenes\gamemain\gamemain.h"
#include "iscene\scenes\result\result.h"

// クラスオブジェクトの取得
SCENE_MANAGER& SCENE_MANAGER::GetInstance(void)
{
	static SCENE_MANAGER instance;

	return instance;
}

// 初期化
void SCENE_MANAGER::Initialize(void)
{
	// タイトルに切り替える
	Change_scene(SCENE_ID::TITLE);
}

// 更新
void SCENE_MANAGER::Update(void)
{
	// シーンの切り替わり確認
	if (Current_scene_id != Next_scene_id)
		Change(); // 切り替え関数

	// シーンの更新
	Iscene->Update();
}

// 描画
void SCENE_MANAGER::Draw(void)
{
	// シーンの描画
	Iscene->Draw();
}

// 解放
void SCENE_MANAGER::Finalize(void)
{
	// シーンの解放
	Iscene->Finalize();

	// シーンオブジェクトの削除
	delete Iscene;

	Iscene = nullptr;
}

// シーンの切り替え（要求）
void SCENE_MANAGER::Change_scene(SCENE_ID next_scene)
{
	Next_scene_id = next_scene;
}

// シーンの切り替え（実際の動作）
void SCENE_MANAGER::Change(void)
{
	if (Iscene != nullptr)
	{
		// 現在動いているシーンを終わらせる
		Iscene->Finalize();

		delete Iscene;

		Iscene = nullptr;
	}

	// 新しいシーンを作成する
	switch (Next_scene_id)
	{
	case SCENE_ID::TITLE:
		Iscene = new TITLE();
		break;
	case SCENE_ID::GAMEMAIN:
		Iscene = new GAMEMAIN();
		break;
	case SCENE_ID::RESULT:
		Iscene = new RESULT();
		break;
	}

	// ヌルチェックを行う、問題なければ初期化を呼ぶ
	if (Iscene)
		Iscene->Initialize();

	// シーンIDを合わせる
	Current_scene_id = Next_scene_id;
}

// コンストラクタ
SCENE_MANAGER::SCENE_MANAGER(void)
	: Current_scene_id(SCENE_ID::DUMMY)
	, Next_scene_id(SCENE_ID::DUMMY)
	, Iscene(nullptr)
{
}

// コピーコンストラクタ
SCENE_MANAGER::SCENE_MANAGER(const SCENE_MANAGER& rhs)
{
	(void)rhs;
}

// ムーブコンストラクタ
SCENE_MANAGER::SCENE_MANAGER(SCENE_MANAGER&& rhs)
{
	(void)rhs;
}

// デストラクタ
SCENE_MANAGER::~SCENE_MANAGER(void)
{
}

// 代入演算子
SCENE_MANAGER& SCENE_MANAGER::operator=(const SCENE_MANAGER& rhs)
{
	(void)rhs;

	return *this;
}


/*#include "vivid.h"
#include "scenemanager.h"
#include "scenes\title\title.h"
#include "scenes\gamemain\gamemain.h"
#include "scenes\result\result.h"

TITLE		title;
GAMEMAIN	gamemain;
RESULT		result;


SCENE_MANAGER::SCENE_MANAGER(void)
	: Current_scene(Scene_id::DUMMY)
{
}

void SCENE_MANAGER::Initialize(void)
{
	Change_scene(Scene_id::TITLE);
}

void SCENE_MANAGER::Update(void)
{
	switch (Current_scene)
	{
	case Scene_id::DUMMY:
		break;
	case Scene_id::TITLE:
		title.Update();
		break;
	case Scene_id::GAMEMAIN:
		gamemain.Update();
		break;
	case Scene_id::RESULT:
		result.Update();
		break;
	}
}

void SCENE_MANAGER::Draw(void)
{
	switch (Current_scene)
	{
	case Scene_id::DUMMY:
		break;
	case Scene_id::TITLE:
		title.Draw();
		break;
	case Scene_id::GAMEMAIN:
		gamemain.Draw();
		break;
	case Scene_id::RESULT:
		result.Draw();
		break;
	}
}

void SCENE_MANAGER::Finalize(void)
{
}

void SCENE_MANAGER::Change_scene(Scene_id next_scene)
{
	Current_scene = next_scene;
}*/
