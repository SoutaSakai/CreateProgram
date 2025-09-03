#include "scene_manager.h"
#include "scene\title\title.h"
#include "scene\characterselect\characterselect.h"
#include "scene\gamemain\gamemain.h"
#include "scene\result\result.h"

// クラスオブジェクトの取得
SceneManager& SceneManager::GetInstance(void)
{
	static SceneManager instance;

	return instance;
}

// 初期化
void SceneManager::Initialize(void)
{
	// タイトルに切り替える
	Change_scene(SCENE_ID::TITLE);
}

// 更新
void SceneManager::Update(void)
{
	// シーンの切り替わり確認
	if (m_CurrentSceneId != m_NextSceneId)
		Change(); // 切り替え関数

	// シーンの更新
	Iscene->Update();
}

// 描画
void SceneManager::Draw(void)
{
	// シーンの描画
	Iscene->Draw();
}

// 解放
void SceneManager::Finalize(void)
{
	// シーンの解放
	Iscene->Finalize();

	// シーンオブジェクトの削除
	delete Iscene;

	Iscene = nullptr;
}

// シーンの切り替え（要求）
void SceneManager::Change_scene(SCENE_ID next_scene)
{
	m_NextSceneId = next_scene;
}

// 現在のシーンの取得
SCENE_ID SceneManager::GetCullentSceneId()
{
	return m_CurrentSceneId;
}

// シーンの切り替え（実際の動作）
void SceneManager::Change(void)
{
	if (Iscene != nullptr)
	{
		// 現在動いているシーンを終わらせる
		Iscene->Finalize();

		delete Iscene;

		Iscene = nullptr;
	}

	// 新しいシーンを作成する
	switch (m_NextSceneId)
	{
	case SCENE_ID::TITLE:
		Iscene = new Title();
		break;
	case SCENE_ID::CHARACTERSELECT:
		Iscene = new CharacterSelect();
		break;
	case SCENE_ID::GAMEMAIN:
		Iscene = new Gamemain();
		break;
	case SCENE_ID::RESULT:
		Iscene = new Result();
		break;
	}

	// ヌルチェックを行う、問題なければ初期化を呼ぶ
	if (Iscene)
		Iscene->Initialize();

	// シーンIDを合わせる
	m_CurrentSceneId = m_NextSceneId;
}

// コンストラクタ
SceneManager::SceneManager(void)
	: m_CurrentSceneId(SCENE_ID::DUMMY)
	, m_NextSceneId(SCENE_ID::DUMMY)
	, Iscene(nullptr)
{
}

// コピーコンストラクタ
SceneManager::SceneManager(const SceneManager& rhs)
{
	(void)rhs;
}

// ムーブコンストラクタ
SceneManager::SceneManager(SceneManager&& rhs)
{
	(void)rhs;
}

// デストラクタ
SceneManager::~SceneManager(void)
{
}

// 代入演算子
SceneManager& SceneManager::operator=(const SceneManager& rhs)
{
	(void)rhs;

	return *this;
}