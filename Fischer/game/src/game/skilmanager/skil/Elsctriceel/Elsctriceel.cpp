#include "Elsctriceel.h"


const float Elsctriceel::SkilSize = 300;
const float Elsctriceel::AbilityTime = 5;


void Elsctriceel::Initialize(int playernumber)
{
	Timer = 0;
	CenterPosition = vivid::Vector2(0,0);
	m_PlayerNumber = playernumber;
}

void Elsctriceel::Update(vivid::Vector2 Pos)
{
	Timer += vivid::GetDeltaTime();

	CenterPosition = vivid::Vector2(Pos.x + CharacterManager::GetInstance().CharacterWIDTH (CHARACTER_ID::ELSCTRICEEL) / 2,
									Pos.y + CharacterManager::GetInstance().CharacterHEIGHT(CHARACTER_ID::ELSCTRICEEL) / 2);

	//Œø‰ÊŽžŠÔ“à
	if (Timer <= AbilityTime)
	{
		DxLib::DrawCircle(	CenterPosition.x,CenterPosition.y,
							SkilSize / 2, 0xffffff00, true);
	}
	//Œø‰ÊŽžŠÔŠO
	else
	{
		playermanager::GetInstance().ChangeSkilFlagFalse(m_PlayerNumber);
	}
}
