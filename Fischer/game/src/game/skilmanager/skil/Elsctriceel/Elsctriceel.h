#pragma once
#include"vivid.h"

#include"../../../charactermanager/charactermanager.h"
#include"../../../playermanager/playermanager.h"

class Elsctriceel
{
public:

	void Initialize(int playernumber);
	void Update(vivid::Vector2 Pos);

private:

	static const float SkilSize;				//���ʔ͈�
	static const float AbilityTime;				//���ʎ���

	float Timer;

	int m_PlayerNumber;
};