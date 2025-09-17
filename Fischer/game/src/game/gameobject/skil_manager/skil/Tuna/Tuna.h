#pragma once
#include"vivid.h"

#include"../../../player_manager/player_manager.h"

class Tuna
{
public:

	void Initialize(int playernumber);
	vivid::Vector2 Update(vivid::Vector2 Pos, float Angle, float ScaleX);

private:

	static const float BlinkRange;		//ブリンクの距離
	static const float BlinkTime;		//ブリンクにかかる時間
	static const int BlinkCount;		//ブリンクを何回に分けるか

	float Timer;
	int Count;

	int m_PlayerNumber;
};