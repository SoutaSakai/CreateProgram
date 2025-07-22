#pragma once
#include "..\..\scene.h"

class Result : public IScene
{
public:
	Result(void);
	~Result(void) = default;

	void Initialize(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Finalize(void) override;

	static const int m_width;//ナンバー画像サイズの幅
	static const int m_height;//ナンバー画像サイズの高さ
	static const int tuna_width;//ツナ画像サイズの幅
	static const int tuna_height;//ツナ画像サイズの高さ
	static const int max_player = 4;//プレイヤー人数
	static const int button = 2;//ボタンの個数
	int point[max_player];//スコアポイント
	int m_point[max_player];//代入する代わりのスコア
	int m_digit[max_player];
	vivid::Vector2 point_pos[max_player];					//ポイントのポジション
	vivid::Vector2 result_button_pos[button];				//ボタンのポジション
	vivid::Vector2 use_character[max_player][max_player];	//マグロの描画
	vivid::Vector2 use_drawtext[max_player];				// 使用キャラクターのDrawText
	vivid::Vector2 result_anchor[button];					//基準点
	vivid::Rect result_rect[button];						//範囲
	vivid::Vector2 result_character_select_scale;			//キャラクターセレクトボタンの拡大率
	vivid::Vector2 result_exit_scale;						//やめるボタンの拡大率
	vivid::Vector2 back_ground;								//背景
	vivid::Vector2 select_frame_pos;						//外枠のポジション
	vivid::Rect select_frame_rect;							//外枠の範囲
	vivid::Vector2 select_frame_anchor;						//外枠の基準点
	vivid::Vector2 select_frame_scale;						//外枠の拡大率
	unsigned int word_color[button];						//DrawTextの色
	bool button_flag;									//ボタンの現在
};