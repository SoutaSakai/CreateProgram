#include "Mirrormoray.h"

const int		CMirrormoray::m_MaxDecoy			= 1;
const float		CMirrormoray::m_Range				= 150;

const float		CMirrormoray::m_width				= CharacterManager::GetInstance().CharacterWIDTH (CHARACTER_ID::MIRRORMORAYELL);
const float		CMirrormoray::m_height				= CharacterManager::GetInstance().CharacterHEIGHT(CHARACTER_ID::MIRRORMORAYELL);

CMirrormoray::CMirrormoray(void)
	:m_Anchor(vivid::Vector2::ZERO)
{
}

void CMirrormoray::Initialize(int playernumber)
{
	m_PlayerNumber = playernumber;

	//�����_���Ŋp�x�����߂�
	//m_Angle = (rand() % 360) * 3.14f / 180.f;
	m_Angle = 90 * 3.14f / 180.f;

	//�t�@�C���p�X�擾
	m_FilePath = CharacterManager::GetInstance().CharacterFilePath(CHARACTER_ID::MIRRORMORAYELL);

	//Rect�擾
	m_Rect = CharacterManager::GetInstance().CharacterRect(CHARACTER_ID::MIRRORMORAYELL);

	//Anchor
	m_Anchor.x = m_width / 2;
	m_Anchor.y = m_height / 2;
}

void CMirrormoray::Update(vivid::Vector2 pos, float angle, float scalex)
{
	//�p�x������W�����߂�
	m_Position.x = cos(m_Angle) * m_Range + pos.x;
	m_Position.y = sin(m_Angle) * m_Range + pos.y;

	if (pos.y == 165 && vivid::keyboard::Button(vivid::keyboard::KEY_ID::W))
	{
		m_Position.y -= CharacterManager::GetInstance().CharacterSpeed(CHARACTER_ID::MIRRORMORAYELL);
	}

	//��ʊO����
	if (m_Position.y  <= 165)								m_Position.y = 165;								//�����
	if (m_Position.y + m_height >= vivid::WINDOW_HEIGHT)	m_Position.y = vivid::WINDOW_HEIGHT - m_height;	//������

	vivid::DrawTexture(m_FilePath, m_Position, 0xffffffff, m_Rect, m_Anchor , vivid::Vector2(scalex, 1.0f),angle);
}

void CMirrormoray::Finalize(void)
{
}
