#pragma once
#include"vivid.h"

#include"../../../charactermanager/charactermanager.h"
#include"../../../playermanager/playermanager.h"

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