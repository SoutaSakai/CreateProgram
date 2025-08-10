#include "Elsctriceel.h"


const float Elsctriceel::SkillSize = 300;
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

	//当たり判定
	CheckHitSkill();

	//効果時間内
	if (Timer <= AbilityTime)
	{
		DxLib::DrawCircle(	CenterPosition.x,CenterPosition.y,
							SkillSize / 2, 0xffffff00, true);
	}
	//効果時間外
	else
	{
		playermanager::GetInstance().ChangeSkilFlagFalse(m_PlayerNumber);
	}
}

void Elsctriceel::CheckHitSkill(void)
{
	//for (int i = 0; i < (int)vivid::controller::DEVICE_ID::MAX; i++)
	//{
	//	if (i != m_PlayerNumber)
	//	{
	//		//対象の座標
	//		vivid::Vector2 position = playermanager::GetInstance().GetPosition(i);
	//		//対象の角度
	//		float angle = playermanager::GetInstance().GetAngle(i);
	//		//対象のキャラクター
	//		CHARACTER_ID character = playermanager::GetInstance().GetCharacter(i);
	//		//キャラクターの横幅と立幅
	//		float width = CharacterManager::GetInstance().CharacterWIDTH(character);
	//		float height = CharacterManager::GetInstance().CharacterHEIGHT(character);
	//	}
	//}
}
