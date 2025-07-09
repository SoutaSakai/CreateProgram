#include "Porcupinefish.h"

const int		Porcupinefish::m_MaxSpine = 6;
const float		Porcupinefish::m_SpineSpeed = 8;
const float		Porcupinefish::m_SpineAngle = 15;

const int		Porcupinefish::m_Spinewidth = 30;
const int		Porcupinefish::m_Spineheight = 45;

void Porcupinefish::Initialize(int playernumber, vivid::Vector2 pos)
{
	m_PlayerNumber = playernumber;

	m_SpineRect.left = 0;
	m_SpineRect.right = m_SpineRect.left + m_Spinewidth;
	m_SpineRect.top = 0;
	m_SpineRect.bottom = m_SpineRect.top + m_Spineheight;

	m_Anchor = vivid::Vector2(m_Spinewidth /2, m_Spineheight / 2);

	for (int i = 0; i < m_MaxSpine; i++)
	{
		//������
		m_SpinePos[i].x = pos.x + CharacterManager::GetInstance().CharacterWIDTH(CHARACTER_ID::PORCUPINEFISH) / 2 - m_Spinewidth / 2;
		m_SpinePos[i].y = pos.y + CharacterManager::GetInstance().CharacterHEIGHT(CHARACTER_ID::PORCUPINEFISH) / 2 - m_Spineheight / 2;

		m_SpineFlag[i] = true;

		//�p�x�̏�����
		if (i < m_MaxSpine / 2)
		{
			m_Angle[i] = 0 - m_SpineAngle + i * m_SpineAngle;
		}
		else
		{
			m_Angle[i] = 180 - m_SpineAngle + (i - 3) * m_SpineAngle;
		}

	}
}

void Porcupinefish::Update()
{
	for (int i = 0; i < m_MaxSpine; i++)
	{
		//flag��true�̐j����������
		if (m_SpineFlag[i])
		{
			m_SpinePos[i].x = cos(m_Angle[i] * 3.14 / 180.0f) * m_SpineSpeed + m_SpinePos[i].x;
			m_SpinePos[i].y = sin(m_Angle[i] * 3.14 / 180.0f) * m_SpineSpeed + m_SpinePos[i].y;

			vivid::DrawTexture("data\\Spine.png", m_SpinePos[i], 0xffffffff, m_SpineRect, m_Anchor, (m_Angle[i] + 90) * 3.14 / 180.0f);
		}

		//��ʊO����
		if (m_SpinePos[i].x + m_Spinewidth < 0 || vivid::WINDOW_WIDTH < m_SpinePos[i].x ||
			m_SpinePos[i].y + m_Spineheight < 0 || vivid::WINDOW_HEIGHT < m_SpinePos[i].y)
		{
			m_SpineFlag[i] = false;
		}
	}

	//���ׂĂ̐j����ʊO�ɏo����
	if (!m_SpineFlag[0] && !m_SpineFlag[1] && !m_SpineFlag[2] && !m_SpineFlag[3] && !m_SpineFlag[4] && !m_SpineFlag[5])
	{
		playermanager::GetInstance().ChangeSkilFlagFalse(m_PlayerNumber);
	}
	
}
