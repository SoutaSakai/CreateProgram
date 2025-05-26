#include "feed_manager.h"

// Feed_managerクラスのコンストラクタ
Feed_manager::Feed_manager(void)
	: Fisher_feed_pos(0.0f, 0.0f)
	, Fisher_feed_center_pos(0.0f, 0.0f)
	, Fisher_feed_hit_pos(0.0f, 0.0f)
	, Feed_color(0xffffffff)
{
}

// エサの初期化
void Feed_manager::Initialize(void)
{
	Fisher_feed_pos = vivid::Vector2(500.0f, 600.0f);
	Fisher_feed_center_pos = vivid::Vector2(Fisher_feed_pos.x + Feed_radius, Fisher_feed_pos.y + Feed_radius);
}

// エサの状態更新（プレイヤーの口との当たり判定など）
void Feed_manager::Update(vivid::Vector2 mouth_center_pos, float mouth_radius)
{
	namespace keyboard = vivid::keyboard;
	namespace mouse = vivid::mouse;
	float v = mouth_center_pos.x - Fisher_feed_center_pos.x + Feed_radius_hit_length;
	float h = mouth_center_pos.y - Fisher_feed_center_pos.y + Feed_radius_hit_length;

	float length = sqrt(v * v + h * h);

	// プレイヤーの口とエサが重なった場合の処理
	if (length <= mouth_radius + Feed_radius)
	{
		if (mouse::Trigger(mouse::BUTTON_ID::LEFT))
		{
			Feed_color = 0xffff0000; // クリック時は赤色
		}
		else
		{
			Feed_color = 0xffffffff; // 通常時は白色
		}

	}
	else
		Feed_color = 0xffffffff;
}

// エサの描画
void Feed_manager::Draw(void)
{
	vivid::DrawTexture("data\\ball.png", Fisher_feed_pos, Feed_color);
}

// 終了処理（現状は何もしていない）
void Feed_manager::Finalize(void)
{
}