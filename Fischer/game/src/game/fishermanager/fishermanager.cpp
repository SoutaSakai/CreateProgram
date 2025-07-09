#include "fishermanager.h"
#include "..\feedmanager\feedmanager.h"

const int FisherManager::m_max		= 5;		// 釣り人の人数
const float FisherManager::m_change_time	= 4.0f;						// 釣り人の状態更新時間

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
	m_Timer = 0;

	// FeedManagerの初期化
	FeedManager::GetInstance().Initialize(m_max);

	// 釣り人と餌の位置の初期化
	for (int i = 0; i < m_max; ++i)
	{
		m_Position[i].x = i * (m_width + m_distance);
		m_Position[i].y = 0.0f;

		// 餌の生成
		FeedManager::GetInstance().Create(m_Position[i], i);
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
	if (m_Timer > m_change_time)
	{
		// タイマーのリセット
		m_Timer = 0.0f;

		// 状態の更新
		FisherRandState();
	}
	
	// タイマーの更新
	m_Timer += vivid::GetDeltaTime();

	/* 餌の更新 */
	FeedManager::GetInstance().Update();
}

// 描画
void FisherManager::Draw(void)
{
	/* 状態の判定による釣り人の描画 */
	for (int i = 0; i < m_max; i++)
	{
		if (m_State[i] == (int)FISHER_STATE::RELUX)
			vivid::DrawTexture("data\\reluxfisher.png", m_Position[i]);	// リラックス状態の描画
		else if (m_State[i] == (int)FISHER_STATE::CAUTION)
			vivid::DrawTexture("data\\cautionfisher.png", m_Position[i]); // 注視状態の描画
	}

	// 餌の描画
	FeedManager::GetInstance().Draw();
}

// 解放
void FisherManager::Finalize(void)
{
}

// 釣り人の最大値を返す
int FisherManager::GetMax(void)
{
	return m_max;
}

// 釣り人の状態をランダムに更新
void FisherManager::FisherRandState(void)
{
	/* 乱数による状態の更新 */
	for (int i = 0; i < m_max; ++i)
	{
		// 乱数を得る
		int random = rand() % 100 + 1;

		if (random > 0 && random <= 50)
			m_State[i] = (int)FISHER_STATE::RELUX;		// リラックス状態に更新
		else if (random > 50 && random <= 100)
			m_State[i] = (int)FISHER_STATE::CAUTION;	// 注視状態に更新
	}
}
