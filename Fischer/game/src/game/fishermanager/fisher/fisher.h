// fisher.h
#pragma once

#include "vivid.h"

class Fisher
{
public:
	// コンストラクタ
	Fisher::Fisher(void);

	// 初期化
	void Initialize(float);

	// 更新
	void Update(void);

	// 描画
	void Draw(void);

	// 解放
	void Finalize(void);

	// 釣り人の座標を返す
	vivid::Vector2 GetPosition(void);

	// 釣り人の状態をランダムに更新
	void FisherRandState(void);

private:
	int				m_State;			// 釣り人の状態の管理
	bool			m_FeedActiveFlag;	// 餌のアクティブフラグ
	vivid::Vector2	m_Position;			// 釣り人の位置
	vivid::Rect		m_Rect;				// 釣り人の描画範囲
};