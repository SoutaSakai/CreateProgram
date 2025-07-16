#pragma once

#include "vivid.h"
#include "feed_id.h"

class Feed
{
public:
	Feed(void);
	~Feed(void) = default;

	// 初期化
	void Initialize(const vivid::Vector2&);

	// 更新
	void Update(void);

	// 描画
	void Draw(void);

	// 解放
	void Finalize(void);

	// アクティブフラグを返す
	bool IsActive(void);

	// アクティブフラグに代入
	void InActive(bool);

	// 半径を返す
	float GetRadius(void);

	// 中心座標を返す
	vivid::Vector2 GetCenterPos(void);

	// 位置を返す
	float GetPos(void);

private:
	static const float	m_width;	// 幅
	static const float	m_height;	// 高さ

	vivid::Vector2	m_Position;		// 位置
	bool			m_ActiveFlag;	// アクティブフラグ
	FEED_ID			m_Id;			// 種類
};