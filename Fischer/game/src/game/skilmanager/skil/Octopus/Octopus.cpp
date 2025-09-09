#include "Octopus.h"

const float			COctopus::m_AbilityTime			= 1.5f;
const std::string	COctopus::m_FilePath			= "data\\ink.png";
const float			COctopus::m_ScaleSpeed			= 0.03f;
const unsigned int	COctopus::m_TransparencySpeed	= 0x01000000;

const int			COctopus::m_InkWidth		= 300/*vivid::GetTextureWidth(m_FilePath)*/;
const int			COctopus::m_InkHeight		= 300/*vivid::GetTextureHeight(m_FilePath)*/;

COctopus::COctopus(void)
{
	
}

void COctopus::Initialize(int playernumber, vivid::Vector2 positon, vivid::Vector2 scale)
{
	m_PlayerNumber = playernumber;

	m_Position.x = positon.x + CharacterManager::GetInstance().CharacterWIDTH (CHARACTER_ID::OCTOPUS) / 2 - m_InkWidth / 2;
	m_Position.y = positon.y + CharacterManager::GetInstance().CharacterHEIGHT(CHARACTER_ID::OCTOPUS) / 2 - m_InkHeight / 2;

	m_Color = 0xffffffff;

	m_Rect = { 0,0,m_InkWidth ,m_InkHeight };
	m_Anchor = vivid::Vector2(m_InkWidth / 2, m_InkHeight / 2);
	m_Scale = vivid::Vector2::ZERO;

	m_Timer = 0;
}

void COctopus::Update(void)
{
	//vivid::DrawText(40, std::to_string(m_Scale.x), vivid::Vector2(vivid::WINDOW_WIDTH / 2, vivid::WINDOW_HEIGHT / 2), 0xffffffff);

	if (m_Scale.x < 1.0f)
	{
		m_Scale.x += m_ScaleSpeed;
		m_Scale.y += m_ScaleSpeed;
	}
	else if(m_Timer <= m_AbilityTime)
	{
		m_Timer += vivid::GetDeltaTime();
	}
	else
	{
		m_Color -= 0x01000000;

		if (m_Color <= 0x00ffffff)
		{
			playermanager::GetInstance().ChangeSkilFlagFalse(m_PlayerNumber);
		}
	}
	vivid::DrawTexture(m_FilePath, m_Position, m_Color, m_Rect, m_Anchor, m_Scale);

	CheckHitSkill();
}

void COctopus::Finalize(void)
{
}

void COctopus::CheckHitSkill(void)
{
	for (int i = 0; i < 2; i++)
	{
		if (i != m_PlayerNumber)
		{
			//カメ && スキル使用中だったら
			if (playermanager::GetInstance().GetCharacter(i) == CHARACTER_ID::TURTLE &&
				playermanager::GetInstance().GetSkilFlag(i) == true)
			{
				return;
			}
			else
			{
				CollisionDetection(i, 0);
			}

			//ミラーウツボ && スキル使用中だったら
			if (playermanager::GetInstance().GetCharacter(i) == CHARACTER_ID::MIRRORMORAYELL &&
				playermanager::GetInstance().GetSkilFlag(i) == true)
			{
				CollisionDetection(i, 1);
			}
		}	
	}
}

void COctopus::CollisionDetection(int number, int pattern)
{
	vivid::Vector2 position;
	float angle;
	CHARACTER_ID character;

	if (pattern == 0)
	{
		//対象の座標
		position = playermanager::GetInstance().GetPosition(number);
		//対象の角度
		angle = playermanager::GetInstance().GetAngle(number);
		//対象のキャラクター
		character = playermanager::GetInstance().GetCharacter(number);
	}
	else
	{
		//対象の座標
		position = SkilManager::Getinstance().GetMirrormorayDecoyPos(number);
		//対象の角度
		angle = SkilManager::Getinstance().GetMirrormorayDecoyAngle(number);
		//対象のキャラクター
		character = CHARACTER_ID::MIRRORMORAYELL;
	}

	//キャラクターの横幅と立幅
	float width = CharacterManager::GetInstance().CharacterWIDTH(character);
	float height = CharacterManager::GetInstance().CharacterHEIGHT(character);

	//右辺・左辺のどちらかがインクの中に入っていたら
	if ((m_Position.x <= position.x && position.x <= m_Position.x + m_InkWidth) ||
		(m_Position.x <= position.x + width && position.x + width <= m_Position.x + m_InkWidth))
	{
		//上辺・下辺のどちらかが入っていたら
		if ((m_Position.y <= position.y && position.y <= m_Position.y + m_InkHeight) ||
			(m_Position.y <= position.x + height && position.y + height <= m_Position.y + m_InkHeight))
		{
			//当たっている時の処理
			playermanager::GetInstance().ChangeOctopusSlowFlag(m_PlayerNumber, true);
			vivid::DrawText(40, "attateru", vivid::Vector2(640.0f, 0.0f), 0xffffffff);
		}
		else
		{
			playermanager::GetInstance().ChangeOctopusSlowFlag(m_PlayerNumber, false);
		}
	}
	else
	{
		playermanager::GetInstance().ChangeOctopusSlowFlag(m_PlayerNumber, false);
	}
}
