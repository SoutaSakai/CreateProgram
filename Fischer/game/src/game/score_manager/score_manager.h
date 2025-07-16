#pragma once
#include"vivid.h"
#include "../scene_manager/iscene/scenes/gamemain/timer/timer.h"
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
	static const int m_width;//画像サイズの幅

	static const int m_height;//画像サイズの高さ

	static const int max_player = 4;//プレイヤーの人数

	static const int point;//ポイント（１０ポイント）


	vivid::Vector2 Score_pos[max_player];//スコアポジション



	int score[max_player];//スコア保持

	int m_score[max_player];//スコアの仮の変数

	int digit[max_player];

	int ppos[max_player];//プレイヤーポジション

	int getscore[max_player];

	vivid::Rect m_rect;//ボタンの範囲
	vivid::Vector2 m_anchor;//ボタンの中心範囲
	vivid::Vector2 m_scale;//拡大率
	vivid::Vector2 m_button_pos;//ボタンのポジション



	ScoreManager(void) = default;
	~ScoreManager(void) = default;
	ScoreManager(const ScoreManager& rhs) = delete;
	ScoreManager& operator=(const ScoreManager& rhs) = delete;

};