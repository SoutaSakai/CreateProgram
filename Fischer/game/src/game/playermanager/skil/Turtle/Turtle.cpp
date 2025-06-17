#include "Turtle.h"

const float Turtle::ShieldSize = 130;
const float Turtle::ShieldTime = 1000;


void Turtle::Initialize(void)
{
	Timer = 0;
}

void Turtle::Update(vivid::Vector2 Pos)
{
	Timer += vivid::GetDeltaTime();

	if (Timer <= ShieldTime)
	{
		for(int i = 0;i < 5;i++)
			DxLib::DrawCircle(Pos.x, Pos.y, ShieldSize / 2 - i, 0xff0000ff, false);

	}
	else
	{
		*SFlag = false;
	}
}

void Turtle::GetPointer(bool* sflag, bool* cflag)
{
	this->SFlag = sflag;
	this->CFlag = cflag;
}
