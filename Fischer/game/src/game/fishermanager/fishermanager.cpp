#include "fishermanager.h"
#include "..\feedmanager\feedmanager.h"

const float			FisherManager::m_width = 150.0f;		// 釣り人の幅
const float			FisherManager::m_height = 720.0f;		// 釣り人の高さ
const float			FisherManager::m_change_time = 4.0f;	// 釣り人の状態更新時間

// インスタンスを取得
FisherManager& FisherManager::GetInstance(void)
{
	static FisherManager instance;

	return instance;
}

// 初期化
void FisherManager::Initialize(void)
{
	// 釣り人の人数
	m_Max = 5;

	// 餌管理クラスの初期化
	FeedManager::GetInstance().Initialize(m_Max);

	// 釣り人のオブジェクト配列の最大値設定
	m_Fishers = new Fisher[m_Max];

	// 釣り人の間隔
	m_Distance = (vivid::WINDOW_WIDTH - m_width * m_Max) / (m_Max - 1);

	// 釣り人と餌の位置の初期化
	for (int i = 0; i < m_Max; ++i)
	{
		// 釣り人のX座標の計算
		float XPos = i * (m_width + m_Distance);

		// 釣り人の初期化
		m_Fishers[i].Initialize(XPos);

		FeedManager::GetInstance().SetPosition(vivid::Vector2(XPos, 0.0f), i);

		//// 餌の生成
		//FeedManager::GetInstance().Create(m_Fishers[i].GetPosition(), i);
	}

	// 釣り人の状態更新タイマーの初期化
	m_Timer = 0;

	// 釣り人の状態をランダムに更新（初期化）
	for (int i = 0; i < m_Max; ++i)
	{
		m_Fishers[i].FisherRandState();
	}
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

		// 乱数による状態の更新
		for (int i = 0; i < m_Max; ++i)
		{
			// 状態の更新
			m_Fishers[i].FisherRandState();
		}
	}
	
	// タイマーの更新
	m_Timer += vivid::GetDeltaTime();

	// 餌の更新
	FeedManager::GetInstance().Update();
}

// 描画
void FisherManager::Draw(void)
{
	/* 状態の判定による釣り人の描画 */
	for (int i = 0; i < m_Max; i++)
	{
		m_Fishers[i].Draw();
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
	return m_Max;
}

// 釣り人の幅を返す
float FisherManager::GetWidth(void)
{
	return m_width;
}

// 釣り人の高さを返す
float FisherManager::GetHeight(void)
{
	return m_height;
}
