#pragma once

#include"vivid.h"

#include"../../../charactermanager/charactermanager.h"
#include"../../../playermanager/playermanager.h"

class CLionFish
{
public:

	void Intialize(int playernumber,vivid::Vector2 position);
	void Update(void);
	void Draw(void);
	void Finalize(void);

private:
	
	static const std::string		m_filepath;			//ファイルパス
	static const int				m_width;			//横幅
	static const int				m_height;			//立幅

	static const vivid::Rect		m_rect;				//表示範囲
	static const vivid::Vector2		m_anchor;			//基準点

	static const float				m_abilityTime;		//効果時間
	static const vivid::Vector2		m_scalespeed;		//スケールスピード

	vivid::Vector2					m_position;			//座標
	vivid::Vector2					m_scale;			//拡大率

	unsigned int					m_Color;			//色
	int								m_playernumber;		//プレイヤーID
	float							m_timer;			//タイマー

};
