#include "Porcupinefish.h"

const int		Porcupinefish::m_MaxSpine = 6;
const float		Porcupinefish::m_SpineSpeed = 8;
const float		Porcupinefish::m_SpineAngle = 15;

const int		Porcupinefish::m_width = 30;
const int		Porcupinefish::m_height = 45;

void Porcupinefish::Initialize(int playernumber, vivid::Vector2 pos)
{
	m_PlayerNumber = playernumber;

	m_SpineRect.left = 0;
	m_SpineRect.right = m_SpineRect.left + m_width;
	m_SpineRect.top = 0;
	m_SpineRect.bottom = m_SpineRect.top + m_height;

	m_Anchor = vivid::Vector2(m_width /2, m_height / 2);

	////j‚Ì”•ª‚Ì”z—ñ‚ğì‚é
	//vivid::Vector2 Pos[m_MaxSpine];
	//SpinePos = Pos;

	/*float angle[m_MaxSpine];
	Angle = angle;*/

	bool Flag[m_MaxSpine];
	SpineFlag = Flag;

	for (int i = 0; i < m_MaxSpine; i++)
	{
		//‰Šú‰»
		SpinePos[i].x = pos.x + CharacterManager::GetInstance().CharacterWIDTH(CHARACTER_ID::PORCUPINEFISH) / 2;
		SpinePos[i].y = pos.y + CharacterManager::GetInstance().CharacterHEIGHT(CHARACTER_ID::PORCUPINEFISH) / 2;

		SpineFlag[i] = true;

		//Šp“x‚Ì‰Šú‰»
		if (i < m_MaxSpine / 2)
		{
			Angle[i] = 0 - m_SpineAngle + i * m_SpineAngle;
		}
		else
		{
			Angle[i] = 180 - m_SpineAngle + (i - 3) * m_SpineAngle;
		}

	}
}

void Porcupinefish::Update()
{
	vivid::DrawText(40, std::to_string(SpinePos[1].x), vivid::Vector2(vivid::WINDOW_WIDTH / 2, vivid::WINDOW_HEIGHT / 2), 0xffffffff);

	for (int i = 0; i < m_MaxSpine; i++)
	{
		SpinePos[i].x = cos(Angle[i]  * 3.14 / 180.0f) * m_SpineSpeed + SpinePos[i].x;
		SpinePos[i].y = sin(Angle[i]  * 3.14 / 180.0f) * m_SpineSpeed + SpinePos[i].y;

		vivid::DrawTexture("data\\Spine.png", SpinePos[i], 0xffffffff, m_SpineRect,m_Anchor,Angle[i]);
	}
}
