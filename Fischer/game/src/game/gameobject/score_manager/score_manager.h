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
	static const int m_max_player = 4;	//プレイヤーの人数
	static const int m_point;			//ポイントの加算値、減算値

	int m_Score[m_max_player];			//スコア保持
	int m_PlayerPosition[m_max_player];	//プレイヤー位置

	vivid::Rect m_Rect;								//ボタンの描画範囲
	vivid::Vector2 m_Anchor;						//ボタンの基準点
	vivid::Vector2 m_Scale;							//ボタンの拡大率
	vivid::Vector2 m_ButtonPosition;				//ボタンの位置
	vivid::Vector2 m_ScorePosition[m_max_player];	//スコアの位置

	ScoreManager(void) = default;
	~ScoreManager(void) = default;
	ScoreManager(const ScoreManager& rhs) = delete;
	ScoreManager& operator=(const ScoreManager& rhs) = delete;

};