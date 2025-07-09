// fisher.h
#pragma once

#include "vivid.h"

class Fisher
{
public:
	// コンストラクタ
	Fisher::Fisher(void);

	// 初期化
	void Initialize(void);

	// 更新
	void Update(void);

	// 描画
	void Draw(void);

	// 解放
	void Finalize(void);

private:
	static const float			m_width;		// 釣り人の幅
	static const float			m_height;		// 釣り人の高さ
	static const float			m_distance;		// 釣り人の間隔
	static const vivid::Rect	m_rect;			// 釣り人の描画範囲

	int				m_State;			// 釣り人の状態の管理
	vivid::Vector2	m_Position;			// 釣り人の位置
	bool			m_FeedActiveFlag;	// 餌のアクティブフラグ
};