#pragma once
#include "vivid.h"
#include "fisher/fisher.h"
#include "fisherstate.h"

class FisherManager
{
public:

	// インスタンスを取得
	static FisherManager& GetInstance(void);

	// 初期化
	void Initialize(void);

	// 更新
	void Update(void);

	// 描画
	void Draw(void);

	// 解放
	void Finalize(void);

	// 釣り人の人数を返す
	int GetMax(void);

	bool GetMoveFlag(int);
	void SetMoveFlag(int, bool);

	FISHER_STATE GetState(int);
	FISHER_MOVE GetMove(int);

	vivid::Vector2 GetPosition(int);
private:
	static const float	m_change_time;	// 釣り人の状態更新時間
	static const float	m_move_time;	// 釣り人の動作更新時間
	static const int	m_width;
	static const int	m_height;

	int					m_Max;			// 釣り人の人数
	float*				m_StateTimer;	// 釣り人の状態更新タイマー
	float*				m_MoveTimer;	// 釣り人の状態更新タイマー
	float				m_Distance;		// 釣り人の間隔

	Fisher			*m_Fishers;			// 釣り人のオブジェクト配列

	// コンストラクタ
	FisherManager(void) = default;
	// デストラクタ
	~FisherManager(void) = default;
	// コピーコンストラクタ
	FisherManager(const FisherManager& rhs) = delete;
	// 代入演算子
	FisherManager& operator=(const FisherManager& rhs) = delete;
};