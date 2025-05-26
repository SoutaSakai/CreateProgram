#pragma once
#include"vivid.h"

// プレイヤークラス
class Player
{
public:
	Player(void); // コンストラクタ
	void Initialize(void); // 初期化
	void Update(void);     // 状態更新
	void Draw(void);       // 描画
	void Finalize(void);   // 終了処理

	// 口の座標取得
	float Get_player_mouth_radius(void);
	vivid::Vector2 Get_Player_center_pos(void);

private:
	vivid::Vector2 Player_center_pos;//プレイヤーの中心の位置
	vivid::Vector2 Player_pos;//キャラクターの位置
	
	const float Player_mouth_radius = 20.0f;//プレイヤーの口の半径]
	const float Player_width=255;//プレイヤーの幅
	const float Player_height=120;//プレイヤーの高さ
	static const float Move_speed ;//移動速度

protected:
	vivid::Vector2 Player_speed;//プレイヤーの移動速度

};