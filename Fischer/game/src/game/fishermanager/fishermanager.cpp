#include "fishermanager.h"
#include "..\feedmanager\feedmanager.h"

const int FisherManager::Max = 5;			// 釣り人の人数
const float FisherManager::Width = 150.0f;	// 釣り人の幅
const float FisherManager::Height = 720.0f;	// 釣り人の高さ
const float FisherManager::Distance			// 釣り人の間隔
				= (vivid::WINDOW_WIDTH - Width * Max) / (Max - 1);
const float FisherManager::Change_time = 4.0f;	// 釣り人の状態更新時間
const vivid::Rect FisherManager::Rect = { 0,0,Width,Height };	// 釣り人の描画範囲

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
	Timer = 0;

	// 釣り人と餌の位置の初期化
	for (int i = 0; i < Max; ++i)
	{
		Position[i].x = i * (Width + Distance);
		Position[i].y = 0.0f;

		// 餌の生成
		FeedManager::GetInstance().CreateFeed(Position[i], Max, i);	
	}

	// 餌の初期化
	/*FeedManager::GetInstance().Initialize();*/

	// 釣り人の状態をランダムに更新（初期化）
	FisherRandState();
}

// 更新
void FisherManager::Update(void)
{
	/* 釣り人の更新 */
	// タイマーが既定時間を超えたときに状態を更新
	if (Timer > Change_time)
	{
		// タイマーのリセット
		Timer = 0.0f;

		// 状態の更新
		FisherRandState();
	}
	
	// タイマーの更新
	Timer += vivid::GetDeltaTime();


	/* 餌の更新 */
	FeedManager::GetInstance().Update();
}

// 描画
void FisherManager::Draw(void)
{
	/* 状態の判定による釣り人の描画 */
	for (int i = 0; i < Max; i++)
	{
		if (State[i] == (int)FISHER_STATE::RELUX)
			vivid::DrawTexture("data\\reluxfisher.png", Position[i]);	// リラックス状態の描画
		else if (State[i] == (int)FISHER_STATE::CAUTION)
			vivid::DrawTexture("data\\cautionfisher.png", Position[i]); // 注視状態の描画
	}

	// 餌の描画
	FeedManager::GetInstance().Draw();
}

// 解放
void FisherManager::Finalize(void)
{
}

// 餌を食べられた時の処理
void FisherManager::CaughtFeed(void)
{

}

// 釣り人の状態をランダムに更新
void FisherManager::FisherRandState(void)
{
	/* 乱数による状態の更新 */
	for (int i = 0; i < Max; ++i)
	{
		// 乱数を得る
		int random = rand() % 100 + 1;

		if (random > 0 && random <= 50)
			State[i] = (int)FISHER_STATE::RELUX;		// リラックス状態に更新
		else if (random > 50 && random <= 100)
			State[i] = (int)FISHER_STATE::CAUTION;	// 注視状態に更新
	}
}
