#pragma once
#include "vivid.h"
#include "fisherstate.h"

class FisherManager
{
public:

	static FisherManager& GetInstance(void);

	void Initialize(void);

	void Update(void);

	void Draw(void);

	void Finalize(void);

private:

	// 釣り人の人数
	static const int Max_Fisher = 5;
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
	int Fisher_state[];

	// コンストラクタ
	FisherManager(void) = default;
	// デストラクタ
	~FisherManager(void) = default;
	// コピーコンストラクタ
	FisherManager(const FisherManager& rhs) = delete;
	// ムーブコンストラクタ
	FisherManager& operator=(const FisherManager& rhs) = delete;
};