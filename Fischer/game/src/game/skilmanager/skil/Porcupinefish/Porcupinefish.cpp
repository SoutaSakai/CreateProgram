#include "Porcupinefish.h"

const int		Porcupinefish::MaxSpine		= 10;
const float		Porcupinefish::SpineSpeed	= 8;

void Porcupinefish::Initialize(int playernumber, vivid::Vector2 pos)
{
	m_PlayerNumber = playernumber;

	Radius = 0;
	Angle = 360 / MaxSpine;

	//j‚Ì”•ª‚Ì”z—ñ‚ğì‚é
	vivid::Vector2 Pos[MaxSpine];
	SpinePos = Pos;

	bool Flag[MaxSpine];
	SpineFlag = Flag;

	for (int i = 0; i < MaxSpine; i++)
	{
		//‰Šú‰»
		SpinePos[i].x = pos.x + CharacterManager::GetInstance().CharacterWIDTH(CHARACTER_ID::PORCUPINEFISH) / 2;
		SpinePos[i].y = pos.y + CharacterManager::GetInstance().CharacterHEIGHT(CHARACTER_ID::PORCUPINEFISH) / 2;

		SpineFlag[i] = true;
	}
}

void Porcupinefish::Update()
{

	for (int i = 0; i < MaxSpine; i++)
	{
		SpinePos[i].x += cos(Angle * i * 3.14 / 180.0f) * SpineSpeed;
		SpinePos[i].y += sin(Angle * i * 3.14 / 180.0f) * SpineSpeed;

		vivid::DrawTexture("data\\Spine.png", SpinePos[i], 0xffffffff);
	}
}
