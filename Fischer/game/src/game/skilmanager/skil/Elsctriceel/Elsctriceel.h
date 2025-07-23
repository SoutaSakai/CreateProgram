#pragma once
#include"vivid.h"

#include"../../../charactermanager/charactermanager.h"
#include"../../../playermanager/playermanager.h"

class Elsctriceel
{
public:

	void Initialize(int playernumber);
	void Update(vivid::Vector2 Pos);

	//Šî€“_‚ğ•Ô‚·
	vivid::Vector2 GetCenterPosition(void) const { return CenterPosition; }

	//ƒXƒLƒ‹‚Ì”¼Œa‚ğ•Ô‚·
	float GetSkilSize(void) const { return SkilSize; }

private:

	static const float SkilSize;				//Œø‰Ê”ÍˆÍ
	static const float AbilityTime;				//Œø‰ÊŠÔ

	vivid::Vector2 CenterPosition;

	float Timer;

	int m_PlayerNumber;
};