#include "Tuna.h"


const float Tuna::BlinkRange = 400;
const float Tuna::BlinkTime = 1;
const int Tuna::BlinkCount = 10;


void Tuna::Initialize(void)
{
	Timer = 0.0f;
	Count = 0;
}

vivid::Vector2 Tuna::Update(vivid::Vector2 Pos, float Angle, float ScaleX)
{
	Timer += vivid::GetDeltaTime();

	if (Timer>= BlinkTime / BlinkCount)
	{
		//‚Ç‚Á‚¿Œü‚«‚©
		if (ScaleX > 0)
		{
			Pos.x += cos(Angle) * (BlinkRange / BlinkCount);
			Pos.y += sin(Angle) * (BlinkRange / BlinkCount);
		}
		else if (ScaleX < 0)
		{
			Pos.x += cos(Angle) * (-1 * BlinkRange / BlinkCount);
			Pos.y += sin(Angle) * (-1 * BlinkRange / BlinkCount);
		}

		Timer = 0;
		Count++;
	}

	if (Count >= BlinkCount)
	{
		*SFlag = false;
		*CFlag = true;
	}

	return Pos;
}

void Tuna::GetPointer(bool* sflag, bool* cflag)
{
	this->SFlag = sflag;
	this->CFlag = cflag;
}
