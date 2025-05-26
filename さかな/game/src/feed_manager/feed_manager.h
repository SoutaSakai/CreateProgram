#pragma once
#include"vivid.h"

// エサ管理クラス
class Feed_manager
{
public:
	Feed_manager(void); // コンストラクタ
	void Initialize(void); // 初期化
	void Update(vivid::Vector2, float); // 状態更新
	void Draw(void); // 描画
	void Finalize(void); // 終了処理

private:
	vivid::Vector2 Fisher_feed_pos;        // エサの座標
	vivid::Vector2 Fisher_feed_center_pos; // エサの中心座標
	vivid::Vector2 Fisher_feed_hit_pos;    // ヒット判定用座標
	const float Feed_radius = 24.0f;       // エサの半径
	const float Feed_radius_hit_length = 4.0f; // ヒット判定用の長さ
	unsigned int Feed_color = 0xffffffff;  // エサの色
};