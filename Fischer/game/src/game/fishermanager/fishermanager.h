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

	// 餌を食べられた時の処理
	void CaughtFeed(void);

private:
	// 釣り人の状態をランダムに更新
	void FisherRandState(void);

	// 釣り人の人数
	static const int m_max;
	// 釣り人の状態更新時間
	static const float m_change_time;
	// 釣り人の幅
	static const float m_width;
	// 釣り人の高さ
	static const float m_height;
	// 釣り人の間隔
	static const float m_distance;
	// 釣り人の描画範囲
	static const vivid::Rect m_rect;

	// 釣り人の状態の管理
	int m_State[5];
	// 釣り人の状態更新タイマー
	float m_Timer;
	// 釣り人の座標
	vivid::Vector2 m_Position[5];


	// コンストラクタ
	FisherManager(void) = default;
	// デストラクタ
	~FisherManager(void) = default;
	// コピーコンストラクタ
	FisherManager(const FisherManager& rhs) = delete;
	// 代入演算子
	FisherManager& operator=(const FisherManager& rhs) = delete;
};