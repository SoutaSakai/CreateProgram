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
	bool GetActive(void);

	// アクティブフラグに代入
	void SetActive(bool);

	// 半径を返す
	float GetRadius(void);

	// 中心座標を返す
	vivid::Vector2 GetCenterPos(void);

	// 位置を返す
	vivid::Vector2 GetPosition(void);

	FEED_ID GetId(void);

	bool GetHit(void);
	void SetHit(bool);

	void Reset(void);

private:
	static const float	m_width;	// 幅
	static const float	m_height;	// 高さ

	vivid::Vector2	m_Position;		// 位置
	bool			m_ActiveFlag;	// アクティブフラグ
	FEED_ID			m_Id;			// 種類
	bool			m_Hit;			// 判定結果
};