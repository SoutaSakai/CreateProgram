#pragma once
#include"vivid.h"
#include "../time_manager/time_manager.h"
#include"../scene_manager/scene_manager.h"



class ScoreManager
{
public:
	static ScoreManager& GetInstance(void);

	void Initialize(void);


	void Update(void);

	void Draw(void);


	void Finalize(void);


	int GetScore(int);




private:
	static const int m_width;			//画像サイズの幅
	static const int m_height;			//画像サイズの高さ
	static const int max_player = 4;	//プレイヤーの人数
	static const int point;				//ポイント

	int m_Score[max_player];			//スコア保持
	int m_TempScore[max_player];		//スコアの仮の変数
	int m_PlayerPosition[max_player];	//プレイヤー位置

	vivid::Rect m_rect;						//ボタンの範囲
	vivid::Vector2 m_anchor;				//ボタンの基準点
	vivid::Vector2 m_scale;					//ボタンの拡大率
	vivid::Vector2 m_button_pos;			//ボタンの位置
	vivid::Vector2 Score_pos[max_player];	//スコアの位置

	ScoreManager(void) = default;
	~ScoreManager(void) = default;
	ScoreManager(const ScoreManager& rhs) = delete;
	ScoreManager& operator=(const ScoreManager& rhs) = delete;

};