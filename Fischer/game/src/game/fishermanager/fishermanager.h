#pragma once
#include "vivid.h"
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

private:
	void FisherRandState(void);			// 釣り人の状態をランダムに更新

	static const int			m_max;			// 釣り人の人数
	static const float			m_change_time;	// 釣り人の状態更新時間

	float			m_Timer;			// 釣り人の状態更新タイマー

	// コンストラクタ
	FisherManager(void) = default;
	// デストラクタ
	~FisherManager(void) = default;
	// コピーコンストラクタ
	FisherManager(const FisherManager& rhs) = delete;
	// 代入演算子
	FisherManager& operator=(const FisherManager& rhs) = delete;
};