#include "SkilManager.h"

const float SkilManager::fps = 60;

//Tuna				ƒ}ƒOƒ
const float SkilManager::BlinkRange = 400;
const float SkilManager::BlinkTime = 1;
const int SkilManager::BlinkCount = 2;


SkilManager& SkilManager::GetInstance(void)
{
	static SkilManager instance;

	return instance;
}

void SkilManager::TunaSkilInitialize(void)
{
	Timer = 0;
	Count = 0;
}

vivid::Vector2 SkilManager::TunaSkil(vivid::Vector2 Pos, float Angle, bool* flag, float ScaleX)
{
	Timer += vivid::GetDeltaTime();	

	if (Timer >= BlinkTime / BlinkCount)
	{
		//‚Ç‚Á‚¿Œü‚«‚©
		if (ScaleX > 0)
		{
			Pos.x += cos(Angle) * (BlinkRange / BlinkCount);
			Pos.y += sin(Angle) * (BlinkRange / BlinkCount);
		}
		else if(ScaleX < 0)
		{
			Pos.x += cos(Angle) * (-1 * BlinkRange / BlinkCount);
			Pos.y += sin(Angle) * (-1 * BlinkRange / BlinkCount);
		}

		Timer = 0;
		Count++;
	}

	if (Count >= BlinkCount) *flag = false;

	return Pos;
}
