#include "game.h"
#include "scene_manager\scene_manager.h"

/**
 *	@brief	プログラム開始時に1度だけ呼ばれる。
 *			ゲームに必要なデータの初期化を行う。
 */
void Initialize_game(void)
{
	SCENE_MANAGER::GetInstance().Initialize();
}

/**
 *	@brief	プログラムの実行中に継続的に呼び出される。
 *			1フレームごとのゲームの更新
 */
void Update_game(void)
{
	SCENE_MANAGER::GetInstance().Update();
}

/**
 *	@brief	プログラムの実行中に継続的に呼び出される。
 *			1フレームごとの描画
 */
void Draw_game(void)
{
	SCENE_MANAGER::GetInstance().Draw();
}

/**
 *	@brief	プログラムの終了時に1度だけ呼ばれる。
 */
void Finalize_game(void)
{
	SCENE_MANAGER::GetInstance().Finalize();
}