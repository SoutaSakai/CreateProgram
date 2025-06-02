#include "fishermanager.h"

const int FisherManager::Max_Fisher = 5;					// 釣り人の人数
const vivid::Vector2 FisherManager::Fisher_Pos[Max_Fisher]	// 釣り人の座標
= { {0 * Fisher_WIDTH + 0 * Fisher_Distance,0},
	{1 * Fisher_WIDTH + 1 * Fisher_Distance,0},
	{2 * Fisher_WIDTH + 2 * Fisher_Distance,0},
	{3 * Fisher_WIDTH + 3 * Fisher_Distance,0},
	{4 * Fisher_WIDTH + 4 * Fisher_Distance,0} };
const float FisherManager::Fisher_WIDTH = 150;		// 釣り人の幅
const float FisherManager::Fisher_HEIGHT = 720;		// 釣り人の高さ
const float FisherManager::Fisher_Distance = 110;	// 釣り人の間隔
const float FisherManager::Fisher_Time = 4.0f;		// 釣り人の状態更新時間
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
	Fisher_timer = 0;

	srand((unsigned int)time(nullptr));

	FisherRandState();
}

// 更新
void FisherManager::Update(void)
{
	if (Fisher_timer > Fisher_Time)
	{
		Fisher_timer = 0.0f;

		FisherRandState();
	}

	Fisher_timer += vivid::GetDeltaTime();
}

// 描画
void FisherManager::Draw(void)
{
	for (int i = 0; i < Max_Fisher; i++)
	{
		if (Fisher_state[i] == (int)FISHER_STATE::RELUX)
			vivid::DrawTexture("data\\reluxfisher.png", Fisher_Pos[i]);
		else if (Fisher_state[i] == (int)FISHER_STATE::CAUTION)
			vivid::DrawTexture("data\\cautionfisher.png", Fisher_Pos[i]);
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

	for (int i = 0; i < Max_Fisher; ++i)
	{
		random = rand() % 100 + 1;

		if (random > 0 && random <= 50)
			Fisher_state[i] = (int)FISHER_STATE::RELUX;
		else if (random > 50 && random <= 100)
			Fisher_state[i] = (int)FISHER_STATE::CAUTION;
	}
}
