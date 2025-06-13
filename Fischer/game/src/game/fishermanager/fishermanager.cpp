#include "fishermanager.h"
#include "..\feedmanager\feedmanager.h"

const int FisherManager::Max_Fisher = 4;		// 釣り人の人数
const float FisherManager::Fisher_WIDTH = 150;	// 釣り人の幅
const float FisherManager::Fisher_HEIGHT = 720;	// 釣り人の高さ
const float FisherManager::Fisher_Distance		// 釣り人の間隔
				= (vivid::WINDOW_WIDTH - Fisher_WIDTH * Max_Fisher) / (Max_Fisher - 1);
const float FisherManager::Fisher_Time = 4.0f;	// 釣り人の状態更新時間
const vivid::Rect FisherManager::Fisher_Rect = { 0,0,Fisher_WIDTH,Fisher_HEIGHT };	// 釣り人の描画範囲

// インスタンスを取得
FisherManager& FisherManager::GetInstance(void)
{
	static FisherManager instance;

	return instance;
}

// 初期化
void FisherManager::Initialize(void)
{
	// 釣り人の状態更新タイマーの初期化
	Fisher_timer = 0;

	// 釣り人と餌の位置の初期化
	for (int i = 0; i < Max_Fisher; ++i)
	{
		Fisher_Pos[i].x = i * (Fisher_WIDTH + Fisher_Distance);
		Fisher_Pos[i].y = 0.0f;
	}

	// 餌の初期化
	FeedManager::GetInstance().Initialize();

	// 釣り人の状態をランダムに更新（初期化）
	FisherRandState();
}

// 更新
void FisherManager::Update(void)
{
	/* 釣り人の更新 */
	// タイマーが既定時間を超えたときに状態を更新
	if (Fisher_timer > Fisher_Time)
	{
		// タイマーのリセット
		Fisher_timer = 0.0f;

		// 状態の更新
		FisherRandState();
	}

	// タイマーの更新
	Fisher_timer += vivid::GetDeltaTime();


	/* 餌の更新 */
	FeedManager::GetInstance().Update();
}

// 描画
void FisherManager::Draw(void)
{
	/* 判定による釣り人の描画 */
	for (int i = 0; i < Max_Fisher; i++)
	{
		if (Fisher_state[i] == (int)FISHER_STATE::RELUX)
			vivid::DrawTexture("data\\reluxfisher.png", Fisher_Pos[i]);	// リラックス状態の描画
		else if (Fisher_state[i] == (int)FISHER_STATE::CAUTION)
			vivid::DrawTexture("data\\cautionfisher.png", Fisher_Pos[i]); // 注視状態の描画
	}
}

// 解放
void FisherManager::Finalize(void)
{
}

// 釣り人の状態をランダムに更新
void FisherManager::FisherRandState(void)
{
	int random = 0;

	/* 乱数による状態の更新 */
	for (int i = 0; i < Max_Fisher; ++i)
	{
		// 乱数を得る
		random = rand() % 100 + 1;

		if (random > 0 && random <= 50)
			Fisher_state[i] = (int)FISHER_STATE::RELUX;		// リラックス状態に更新
		else if (random > 50 && random <= 100)
			Fisher_state[i] = (int)FISHER_STATE::CAUTION;	// 注視状態に更新
	}
}
