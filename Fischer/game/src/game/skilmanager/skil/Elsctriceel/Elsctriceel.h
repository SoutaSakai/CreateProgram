#pragma once
#include"vivid.h"

#include"../../../charactermanager/charactermanager.h"
#include"../../../playermanager/playermanager.h"

class Elsctriceel
{
public:

	void Initialize(int playernumber);
	void Update(vivid::Vector2 Pos);

	void CheckHitSkill(void);

	//Šî€“_‚ğ•Ô‚·
	vivid::Vector2 GetCenterPosition(void) const { return m_CenterPosition; }

	void CollisionDetection(int number);

private:

	static const float SkillSize;				//Œø‰Ê”ÍˆÍ(‰~‚Ì’¼Œa)
	static const float AbilityTime;				//Œø‰ÊŠÔ

	vivid::Vector2		m_CenterPosition;

	float Timer;

	int m_PlayerNumber;
};