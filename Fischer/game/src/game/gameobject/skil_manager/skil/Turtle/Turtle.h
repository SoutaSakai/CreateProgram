#pragma once
#include"vivid.h"

#include"../../../character_manager/character_manager.h"
#include"../../../player_manager/player_manager.h"

class Turtle
{
public:

	void Initialize(int playernumber);
	void Update(vivid::Vector2 Pos);

private:

	static const float ShieldSize;
	static const float ShieldTime;

	float Timer;

	int m_PlayerNumber;
};