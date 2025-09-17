#pragma once

#include"vivid.h"

#include"../../../character_manager/character_manager.h"
#include"../../../player_manager/player_manager.h"

class CLionFish
{
public:

	void Intialize(int playernumber, vivid::Vector2 position);
	void Update(void);
	void Draw(void);
	void Finalize(void);

	//スキルの当たり判定
	void CheckHitSkill(void);
	void CollisionDetection(int number, int pattern);

private:

	static const std::string		m_filepath;			//ファイルパス
	static const int				m_width;			//横幅
	static const int				m_height;			//立幅

	static const vivid::Rect		m_rect;				//表示範囲
	static const vivid::Vector2		m_anchor;			//基準点

	static const float				m_abilityTime;		//効果時間
	static const vivid::Vector2		m_scalespeed;		//スケールスピード

	static const int				m_score;		//スキルが当たった時のスコアの増減値

	vivid::Vector2					m_Position;			//座標
	vivid::Vector2					m_Scale;			//拡大率

	bool							m_Flag[(int)vivid::controller::DEVICE_ID::MAX];

	unsigned int					m_Color;			//色
	float							m_timer;			//タイマー

	int								m_PlayerNumber;		//プレイヤーID
	int								m_MaxPlayer;		//最大人数

};
