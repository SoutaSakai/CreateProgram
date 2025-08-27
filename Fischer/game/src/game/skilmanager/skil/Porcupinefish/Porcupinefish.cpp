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
		//èâä˙âª
		m_SpinePos[i].x = pos.x + CharacterManager::GetInstance().CharacterWIDTH(CHARACTER_ID::PORCUPINEFISH) / 2 - m_Spinewidth / 2;
		m_SpinePos[i].y = pos.y + CharacterManager::GetInstance().CharacterHEIGHT(CHARACTER_ID::PORCUPINEFISH) / 2 - m_Spineheight / 2;

		m_SpineFlag[i] = true;

		//äpìxÇÃèâä˙âª
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
		//flagÇ™trueÇÃêjÇæÇØìÆÇ©Ç∑
		if (m_SpineFlag[i])
		{
			m_SpinePos[i].x = cos(m_Angle[i] * 3.14 / 180.0f) * m_SpineSpeed + m_SpinePos[i].x;
			m_SpinePos[i].y = sin(m_Angle[i] * 3.14 / 180.0f) * m_SpineSpeed + m_SpinePos[i].y;

			vivid::DrawTexture("data\\Spine.png", m_SpinePos[i], 0xffffffff, m_SpineRect, m_Anchor, m_Angle[i] * 3.14 / 180.0f);
		}

		//âÊñ äOîªíË
		if (m_SpinePos[i].x + m_Spinewidth < 0 || vivid::WINDOW_WIDTH < m_SpinePos[i].x ||
			m_SpinePos[i].y + m_Spineheight < 0 || vivid::WINDOW_HEIGHT < m_SpinePos[i].y)
		{
			//ÉtÉâÉOÇfalseÇ…Ç∑ÇÈ
			m_SpineFlag[i] = false;
		}
	}

	//Ç∑Ç◊ÇƒÇÃêjÇ™âÊñ äOÇ…èoÇΩÇÁ
	if (!m_SpineFlag[0] && !m_SpineFlag[1] && !m_SpineFlag[2] && !m_SpineFlag[3] && !m_SpineFlag[4] && !m_SpineFlag[5])
	{
		playermanager::GetInstance().ChangeSkilFlagFalse(m_PlayerNumber);
	}
	
	//ìñÇΩÇËîªíË
	CheckHitSkill();
}

void Porcupinefish::CheckHitSkill(void)
{
	//êjÇÃ3Ç¬ÇÃí∏ì_äiî[ïœêî
	vivid::Vector2 SpineVertex[6][3];

	//êjÇÃëŒäpê¸ÇÃí∑Ç≥ÇãÅÇﬂÇÈ
	float Spinediagonal = sqrt(pow(0 - m_Spinewidth / 2, 2) + pow(0 - m_Spineheight / 2, 2));

	for (int i = 0; i < m_MaxSpine; i++)
	{
		//êjÇÃíÜêSì_
		vivid::Vector2 SpineCenterPos = m_SpinePos[i] + vivid::Vector2(m_Spinewidth / 2, m_Spineheight / 2);

		SpineVertex[i][0].x = SpineCenterPos.x + cos((m_Angle[i] + 225) * 3.14 / 180.0f) * Spinediagonal;
		SpineVertex[i][0].y = SpineCenterPos.y + sin((m_Angle[i] + 225) * 3.14 / 180.0f) * Spinediagonal;

		SpineVertex[i][1].x = SpineCenterPos.x + m_Spinewidth / 2;
		SpineVertex[i][1].y = SpineCenterPos.y + m_Spineheight / 2;

		SpineVertex[i][2].x = SpineCenterPos.x + cos((m_Angle[i] + 135) * 3.14 / 180.0f) * Spinediagonal;
		SpineVertex[i][2].y = SpineCenterPos.y + sin((m_Angle[i] + 135) * 3.14 / 180.0f) * Spinediagonal;
		
	}

	for (int i = 0; i < 2; i++)
	{
		if (i != m_PlayerNumber)
		{
			//âÒì]ÇµÇΩèÛë‘ÇÃéläpå`ÇÃí∏ì_ÇÃç¿ïW
			vivid::Vector2 vertex[4];

			//ëŒè€ÇÃç¿ïW
			vivid::Vector2 targetposition = playermanager::GetInstance().GetPosition(i);
			//ëŒè€ÇÃäpìx
			float targetangle = playermanager::GetInstance().GetAngle(i);
			//ëŒè€ÇÃÉLÉÉÉâÉNÉ^Å[
			CHARACTER_ID targetcharacter = playermanager::GetInstance().GetCharacter(i);
			//ÉLÉÉÉâÉNÉ^Å[ÇÃâ°ïùÇ∆óßïù
			float width = CharacterManager::GetInstance().CharacterWIDTH(targetcharacter);
			float height = CharacterManager::GetInstance().CharacterHEIGHT(targetcharacter);
			//ëŒè€ÇÃíÜêSì_
			vivid::Vector2 targetcenterpos = vivid::Vector2(targetposition.x + width / 2, targetposition.y + height / 2);
			//ëŒè€ÇÃëŒäpê¸ÇÃí∑Ç≥ÇãÅÇﬂÇÈ
			float targetdiagonal = sqrt(pow(targetposition.x - targetcenterpos.x, 2) + pow(targetposition.y - targetcenterpos.y, 2));

			for (int j = 0; j < 4; j++)
			{
				//âÒì]ÇµÇΩèÛë‘ÇÃí∏ì_ÇÃç¿ïWÇãÅÇﬂÇÈ
				vertex[j].x = cos((targetangle + 135 + 90 * j) * 3.14 / 180) * targetdiagonal + targetcenterpos.x;
				vertex[j].y = sin((targetangle + 135 + 90 * j) * 3.14 / 180) * targetdiagonal + targetcenterpos.y;
			}

			//êjÇÃï”(AB)Ç∆characterÇÃï”(CD)Ç™åç∑ÇµÇƒÇÈÇ©í≤Ç◊ÇÈ
			vivid::Vector2 A, B, C, D;
			//êjÇÃêî
			for (int p = 0; p < m_MaxSpine; p++)
			{
				//êjÇ™óLå¯ÇæÇ¡ÇΩÇÁ
				if (m_SpineFlag[p])
				{
					//éOäpå`ÇÃï”ÇÃêî
					for (int t = 0; t < 3; t++)
					{
						//éOäpå`ÇÃàÍï”(AB)
						A = SpineVertex[p][t];
						if (t >= 2)	B = SpineVertex[p][0];
						else		B = SpineVertex[p][t + 1];

						//characterÇÃï”ÇÃêî
						for (int b = 0; b < 4; b++)
						{
							//characterÇÃàÍï”(CD)
							C = vertex[b];
							if (b >= 3)	D = vertex[0];
							else		D = vertex[b + 1];

							if (CheckCross(A, B, C, D))
							{
								//ÉtÉâÉOÇfalseÇ…Ç∑ÇÈ
								m_SpineFlag[p] = false;
								vivid::DrawText(40, "HIT", vivid::Vector2(640.0f, 0.0f), 0xffffffff);
							}
						}
					}
				}
			}
		}
	}
}

bool Porcupinefish::CheckCross(vivid::Vector2 A, vivid::Vector2 B, vivid::Vector2 C, vivid::Vector2 D)
{
	vivid::Vector2 AB = B - A;
	vivid::Vector2 AC = C - A;
	vivid::Vector2 AD = D - A;

	vivid::Vector2 CD = D - C;
	vivid::Vector2 CA = A - C;
	vivid::Vector2 CB = B - C;

	double cross1 = vivid::Vector2::Cross(AB, AC);
	double cross2 = vivid::Vector2::Cross(AB, AD);
	double cross3 = vivid::Vector2::Cross(CD, CA);
	double cross4 = vivid::Vector2::Cross(CD, CB);

	if ((cross1 * cross2 <= 0) && (cross3 * cross4 <= 0))
		return true;

	return false;
}
