#include "Turtle.h"

const float Turtle::ShieldSize = 130;
const float Turtle::ShieldTime = 5;


void Turtle::Initialize(int playernumber)
{
	Timer = 0;

	m_PlayerNumber = playernumber;
}

void Turtle::Update(vivid::Vector2 Pos)
{
	Timer += vivid::GetDeltaTime();

	//Œø‰ÊŽžŠÔ“à
	if (Timer <= ShieldTime)
	{
		for(int i = 0;i < 4;i++)
			DxLib::DrawCircle(	Pos.x + CharacterManager::GetInstance().CharacterWIDTH (CHARACTER_ID::TURTLE) / 2,
								Pos.y + CharacterManager::GetInstance().CharacterHEIGHT(CHARACTER_ID::TURTLE) / 2,
								ShieldSize / 2 - i, 0xff0000ff, false);

	}
	//Œø‰ÊŽžŠÔŠO
	else
	{
		playermanager::GetInstance().ChangeSkilFlagFalse(m_PlayerNumber);
	}
}

