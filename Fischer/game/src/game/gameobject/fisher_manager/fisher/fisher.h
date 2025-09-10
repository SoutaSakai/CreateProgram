// fisher.h
#pragma once

#include "vivid.h"
#include "..\fisherstate.h"

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

	// 釣り人の幅を返す
	int GetWidth(void);

	// 釣り人の高さを返す
	int GetHeight(void);

	FISHER_MOVE GetMoveState(void);

	void SetMoveState(FISHER_MOVE);

	bool GetMoveFlag(void);
	void SetMoveFlag(bool);

	void ChangeMove(void);

private:
	static const int	m_width;		// 釣り人の幅
	static const int	m_height;		// 釣り人の高さ

	FISHER_STATE	m_State;			// 釣り人の状態
	FISHER_MOVE		m_Move;				// 釣り人の動き
	bool			m_MoveFlag;			// 動きのアクティブフラグ
	vivid::Vector2	m_Position;			// 釣り人の位置
	vivid::Rect		m_Rect;				// 釣り人の描画範囲
};