#include "Elsctriceel.h"


const float Elsctriceel::SkilSize = 300;
const float Elsctriceel::AbilityTime = 1000;


void Elsctriceel::Initialize(void)
{
	Timer = 0;
}

void Elsctriceel::Update(vivid::Vector2 Pos)
{
	Timer += vivid::GetDeltaTime();

	if (Timer <= AbilityTime)
	{
		DxLib::DrawCircle(Pos.x, Pos.y, SkilSize / 2, 0xffffff00, true);
	}
	else
	{
		
		*SFlag = false;
	}
}

void Elsctriceel::GetPointer(bool* sflag, bool* cflag)
{
	this->SFlag = sflag;
	this->CFlag = cflag;
}
