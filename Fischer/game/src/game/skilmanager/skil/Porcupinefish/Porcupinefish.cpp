#include "Porcupinefish.h"

const int		Porcupinefish::m_MaxSpine = 6;
const float		Porcupinefish::m_SpineSpeed = 8;
const float		Porcupinefish::m_SpineAngle = 15;

const int		Porcupinefish::m_Spinewidth = 45;
const int		Porcupinefish::m_Spineheight = 30;

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
		//‰Šú‰»
		m_SpinePos[i].x = pos.x + CharacterManager::GetInstance().CharacterWIDTH(CHARACTER_ID::PORCUPINEFISH) / 2 - m_Spinewidth / 2;
		m_SpinePos[i].y = pos.y + CharacterManager::GetInstance().CharacterHEIGHT(CHARACTER_ID::PORCUPINEFISH) / 2 - m_Spineheight / 2;

		m_SpineFlag[i] = true;

		//Šp“x‚Ì‰Šú‰»
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
		//flag‚ªtrue‚Ìj‚¾‚¯“®‚©‚·
		if (m_SpineFlag[i])
		{
			m_SpinePos[i].x = cos(m_Angle[i] * 3.14 / 180.0f) * m_SpineSpeed + m_SpinePos[i].x;
			m_SpinePos[i].y = sin(m_Angle[i] * 3.14 / 180.0f) * m_SpineSpeed + m_SpinePos[i].y;

			vivid::DrawTexture("data\\Spine.png", m_SpinePos[i], 0xffffffff, m_SpineRect, m_Anchor, m_Angle[i] * 3.14 / 180.0f);
		}

		//‰æ–ÊŠO”»’è
		if (m_SpinePos[i].x + m_Spinewidth < 0 || vivid::WINDOW_WIDTH < m_SpinePos[i].x ||
			m_SpinePos[i].y + m_Spineheight < 0 || vivid::WINDOW_HEIGHT < m_SpinePos[i].y)
		{
			//ƒtƒ‰ƒO‚ðfalse‚É‚·‚é
			m_SpineFlag[i] = false;
		}
	}

	//‚·‚×‚Ä‚Ìj‚ª‰æ–ÊŠO‚Éo‚½‚ç
	if (!m_SpineFlag[0] && !m_SpineFlag[1] && !m_SpineFlag[2] && !m_SpineFlag[3] && !m_SpineFlag[4] && !m_SpineFlag[5])
	{
		playermanager::GetInstance().ChangeSkilFlagFalse(m_PlayerNumber);
	}
	
	//“–‚½‚è”»’è
	CheckHitSkill();
}

void Porcupinefish::CheckHitSkill(void)
{
	//j‚Ì3‚Â‚Ì’¸“_Ši”[•Ï”
	vivid::Vector2 SpineVertex[6][3];

	//j‚Ì‘ÎŠpü‚Ì’·‚³‚ð‹‚ß‚é
	float Spinediagonal = sqrt(pow(0 - m_Spinewidth / 2, 2) + pow(0 - m_Spineheight / 2, 2));

	for (int i = 0; i < m_MaxSpine; i++)
	{
		//j‚Ì’†S“_
		vivid::Vector2 SpineCenterPos = m_SpinePos[i] + vivid::Vector2(m_Spinewidth / 2, m_Spineheight / 2);

		SpineVertex[i][0].x += cos((m_Angle[i] + 225) * 3.14 / 180.0f) * Spinediagonal;
		SpineVertex[i][0].y += sin((m_Angle[i] + 225) * 3.14 / 180.0f) * Spinediagonal;

		SpineVertex[i][1].x += m_Spinewidth / 2;
		SpineVertex[i][1].y;

		SpineVertex[i][2].x += cos((m_Angle[i] + 135) * 3.14 / 180.0f) * Spinediagonal;
		SpineVertex[i][2].y += sin((m_Angle[i] + 135) * 3.14 / 180.0f) * Spinediagonal;
		
	}

	for (int i = 0; i < 2; i++)
	{
		if (i != m_PlayerNumber)
		{
			//‰ñ“]‚µ‚½ó‘Ô‚ÌŽlŠpŒ`‚Ì’¸“_‚ÌÀ•W
			vivid::Vector2 vertex[4];

			//‘ÎÛ‚ÌÀ•W
			vivid::Vector2 targetposition = playermanager::GetInstance().GetPosition(i);
			//‘ÎÛ‚ÌŠp“x
			float targetangle = playermanager::GetInstance().GetAngle(i);
			//‘ÎÛ‚ÌƒLƒƒƒ‰ƒNƒ^[
			CHARACTER_ID targetcharacter = playermanager::GetInstance().GetCharacter(i);
			//ƒLƒƒƒ‰ƒNƒ^[‚Ì‰¡•‚Æ—§•
			float width = CharacterManager::GetInstance().CharacterWIDTH(targetcharacter);
			float height = CharacterManager::GetInstance().CharacterHEIGHT(targetcharacter);
			//‘ÎÛ‚Ì’†S“_
			vivid::Vector2 targetcenterpos = vivid::Vector2(targetposition.x + width / 2, targetposition.y + height / 2);
			//‘ÎÛ‚Ì‘ÎŠpü‚Ì’·‚³‚ð‹‚ß‚é
			float targetdiagonal = sqrt(pow(targetposition.x - targetcenterpos.x, 2) + pow(targetposition.y - targetcenterpos.y, 2));

			for (int j = 0; j < 4; j++)
			{
				//‰ñ“]‚µ‚½ó‘Ô‚Ì’¸“_‚ÌÀ•W‚ð‹‚ß‚é
				vertex[j].x = cos((targetangle + 135 + 90 * j) * 3.14 / 180) * targetdiagonal + targetcenterpos.x;
				vertex[j].y = sin((targetangle + 135 + 90 * j) * 3.14 / 180) * targetdiagonal + targetcenterpos.y;
			}

			//j‚Ì•Ó‚Æcharacter‚Ì•Ó‚ªŒð·‚µ‚Ä‚é‚©’²‚×‚é
			//
			//j‚Ì”
			for (int p = 0; p < m_MaxSpine; p++)
			{
				//ŽOŠpŒ`‚Ì•Ó‚Ì”
				for (int t = 0; t < 3; t++)
				{
					vivid::Vector2 AB;

					//character‚Ì•Ó‚Ì”
					for (int b = 0; b < 4; b++)
					{
						vivid::Vector2 CD;
						
					}
				}
			}
		}
	}
}
