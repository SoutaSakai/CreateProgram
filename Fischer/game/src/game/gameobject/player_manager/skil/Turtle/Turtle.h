#pragma once
#include"vivid.h"

class Turtle
{
public:

	void Initialize(void);
	void Skil(vivid::Vector2 Pos);

private:

	static const float ShieldSize;
	static const float ShieldTime;

	float Timer;

};