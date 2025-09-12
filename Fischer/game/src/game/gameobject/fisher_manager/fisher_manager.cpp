#include "fisher_manager.h"
#include "..\feed_manager\feed_manager.h"
#include "..\player_manager\player_manager.h"
#include "fisherstate.h"

const float			FisherManager::m_change_time	= 4;	// 釣り人の状態更新時間
const float			FisherManager::m_move_time		= 1;	// 釣り人の動作更新時間
const int			FisherManager::m_width			= 50;
const int			FisherManager::m_height			= 50;

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

	m_StateTimer = new float[m_Max];
	m_MoveTimer = new float[m_Max];

	// 餌管理クラスの初期化
	FeedManager::GetInstance().Initialize(m_Max);

	// 釣り人のオブジェクト配列の最大値設定
	m_Fishers = new Fisher[m_Max];

	// 釣り人の間隔
	m_Distance = vivid::WINDOW_WIDTH / m_Max - m_width;

	// 釣り人と餌の位置の初期化
	for (int i = 0; i < m_Max; ++i)
	{
		// 釣り人のX座標の計算
		float XPos = i * (m_width + m_Distance);

		// 釣り人の初期化
		m_Fishers[i].Initialize(XPos);

		// 餌の初期化
		FeedManager::GetInstance().SetPosition(vivid::Vector2(XPos, 0.0f), m_Fishers[i].GetMoveState(), i);

		//// 餌の生成
		//FeedManager::GetInstance().Create(m_Fishers[i].GetPosition(), i);

		// 釣り人の状態更新タイマーの初期化
		m_StateTimer[i] = 0;

		m_MoveTimer[i] = 0;

		// 釣り人の状態をランダムに更新（初期化）
		m_Fishers[i].FisherRandState();
	}

	//m_StateTimer = 0.0f;

	//m_MoveTimer = 0.0f;

}

// 更新
void FisherManager::Update(void)
{
	/* 釣り人の更新 */
	for (int i = 0; i < m_Max; ++i)
	{
		if (!m_Fishers[i].GetMoveFlag())
		{
			// タイマーが既定時間を超えたときに状態を更新
			if (m_StateTimer[i] > m_change_time)
			{
				// タイマーのリセット
				m_StateTimer[i] = 0.0f;

				// 乱数による状態の更新
				m_Fishers[i].FisherRandState();
			}
		}
		else
		{
			// 動きの更新
			if (m_MoveTimer[i] > m_move_time)
			{
				// タイマーのリセット
				m_MoveTimer[i] = 0.0f;

				switch (m_Fishers[i].GetMoveState())
				{
				case FISHER_MOVE::WAIT:
					m_Fishers[i].SetMoveState(FISHER_MOVE::FISHING);
					break;
				case FISHER_MOVE::FISHING:
					if (FeedManager::GetInstance().GetActive(i))
					{
						m_Fishers[i].SetMoveFlag(false);

						FeedManager::GetInstance().SetPosition(m_Fishers[i].GetPosition(), m_Fishers[i].GetMoveState(), i);

						m_Fishers[i].SetMoveState(FISHER_MOVE::WAIT);

					}
					else
					{
						FeedManager::GetInstance().Create(m_Fishers[i].GetPosition(), m_Fishers[i].GetLevel(), i);

						m_Fishers[i].SetMoveState(FISHER_MOVE::ATTACH);
					}
					break;
				case FISHER_MOVE::ATTACH:

					FeedManager::GetInstance().SetPosition(m_Fishers[i].GetPosition(), m_Fishers[i].GetMoveState(), i);

					m_Fishers[i].SetMoveState(FISHER_MOVE::FISHING);

					break;
				default:
					break;
				}
			}

			if (m_Fishers[i].GetState() == FISHER_STATE::CAUTION)
			{
				for (int j = 0; j < playermanager::GetInstance().GetMaxPlayer(); j++)
				{
					playermanager::GetInstance().SetControlFlag(false, j);

					if (playermanager::GetInstance().GetFishedFlag(j))
					{
						playermanager::GetInstance().SetMovePosition(m_Fishers[i].GetPosition(), m_Fishers[i].GetMoveState(), j);
					}
				}
			}
		}

		m_Fishers[i].Update();
	}

	for (int i = 0; i < m_Max; i++)
	{
		// タイマーの更新
		m_StateTimer[i] += vivid::GetDeltaTime();
		m_MoveTimer[i] += vivid::GetDeltaTime();
	}

	//// タイマーの更新
	//m_StateTimer += vivid::GetDeltaTime();
	//m_MoveTimer += vivid::GetDeltaTime();

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

bool FisherManager::GetMoveFlag(int num)
{
	return m_Fishers[num].GetMoveFlag();
}

void FisherManager::SetMoveFlag(int num, bool flag)
{
	m_Fishers[num].SetMoveFlag(flag);
}

FISHER_STATE FisherManager::GetState(int num)
{
	return m_Fishers[num].GetState();
}

FISHER_MOVE FisherManager::GetMove(int num)
{
	return m_Fishers[num].GetMoveState();
}

vivid::Vector2 FisherManager::GetPosition(int num)
{
	return m_Fishers[num].GetPosition();
}
