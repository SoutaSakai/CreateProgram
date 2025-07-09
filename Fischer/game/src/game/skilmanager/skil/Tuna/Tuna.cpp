#include "Tuna.h"


const float Tuna::BlinkRange = 400;
const float Tuna::BlinkTime = 1;
const int Tuna::BlinkCount = 10;


void Tuna::Initialize(int playernumber)
{
	Timer = 0.0f;
	Count = 0;

	m_PlayerNumber = playernumber;
}

vivid::Vector2 Tuna::Update(vivid::Vector2 Pos, float Angle, float ScaleX)
{
	Timer += vivid::GetDeltaTime();

	if (Timer>= BlinkTime / BlinkCount)
	{
		//�ǂ���������
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

		playermanager::GetInstance().ChangeSkilFlagFalse(m_PlayerNumber);
		playermanager::GetInstance().ChangeControlFlagTrue(m_PlayerNumber);
	}

	return Pos;
}


