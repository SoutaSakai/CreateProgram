#include "Lionfish.h"

const std::string		CLionFish::m_filepath = "data\\smoke.png";
const int				CLionFish::m_width = 200;
const int				CLionFish::m_height = 200;

const vivid::Rect		CLionFish::m_rect = { 0,0,m_width,m_height };
const vivid::Vector2	CLionFish::m_anchor = vivid::Vector2(m_width / 2, m_height / 2);

const float				CLionFish::m_abilityTime = 180;
const vivid::Vector2	CLionFish::m_scalespeed = vivid::Vector2(0.1f, 0.1f);

void CLionFish::Intialize(int playernumber, vivid::Vector2 position)
{
	m_Position.x = position.x + CharacterManager::GetInstance().CharacterWIDTH(CHARACTER_ID::LIONFISH) / 2 - m_width / 2;
	m_Position.y = position.y + CharacterManager::GetInstance().CharacterHEIGHT(CHARACTER_ID::LIONFISH) / 2 - m_height / 2;
	m_Scale = vivid::Vector2(0.0f, 0.0f);

	m_PlayerNumber = playernumber;
	m_Color = 0xffffffff;
	m_timer = 0;
}

void CLionFish::Update(void)
{
	if (++m_timer <= m_abilityTime)
	{
		if (m_Scale.x < 1.0f)
			m_Scale += m_scalespeed;

	}
	else
	{
		m_Color -= 0x01000000;

		if (m_Color <= 0x00ffffff)
		{
			playermanager::GetInstance().ChangeSkilFlagFalse(m_PlayerNumber);
		}

	}

	//当たり判定
	CheckHitSkill();

	vivid::DrawTexture(m_filepath, m_Position, m_Color, m_rect, m_anchor, m_Scale);
}

void CLionFish::Draw(void)
{
}

void CLionFish::Finalize(void)
{
}

void CLionFish::CheckHitSkill(void)
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

			//ミラーウツボだったら
			if (playermanager::GetInstance().GetCharacter(i) == CHARACTER_ID::MIRRORMORAYELL &&
				playermanager::GetInstance().GetSkilFlag(i) == true)
			{
				CollisionDetection(i, 1);
			}
		}
	}
}

void CLionFish::CollisionDetection(int number, int pattern)
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
	if ((m_Position.x <= position.x && position.x <= m_Position.x + m_width) ||
		(m_Position.x <= position.x + width && position.x + width <= m_Position.x + m_width))
	{
		//上辺・下辺のどちらかが入っていたら
		if ((m_Position.y <= position.y && position.y <= m_Position.y + m_height) ||
			(m_Position.y <= position.x + height && position.y + height <= m_Position.y + m_height))
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
