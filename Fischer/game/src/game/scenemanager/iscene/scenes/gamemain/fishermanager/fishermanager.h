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

private:

	// 釣り人の人数
	static const int Max_Fisher;
	// 釣り人の状態更新時間
	static const float Fisher_Time;
	// 釣り人の座標
	static const vivid::Vector2 Fisher_Pos[];
	// 釣り人の幅
	static const float Fisher_WIDTH;
	// 釣り人の高さ
	static const float Fisher_HEIGHT;
	// 釣り人の間隔
	static const float Fisher_Distance;
	// 釣り人の描画範囲
	static const vivid::Rect Fisher_Rect;


	// 釣り人の状態の管理
	int Fisher_state[5];
	// 釣り人の状態更新タイマー
	float Fisher_timer;


	// 釣り人の状態をランダムに更新
	void FisherRandState(void);

	// コンストラクタ
	FisherManager(void) = default;
	// デストラクタ
	~FisherManager(void) = default;
	// コピーコンストラクタ
	FisherManager(const FisherManager& rhs) = delete;
	// 代入演算子
	FisherManager& operator=(const FisherManager& rhs) = delete;
};