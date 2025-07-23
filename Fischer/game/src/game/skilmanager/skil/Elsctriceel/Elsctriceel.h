#pragma once
#include"vivid.h"

#include"../../../charactermanager/charactermanager.h"
#include"../../../playermanager/playermanager.h"

class Elsctriceel
{
public:

	void Initialize(int playernumber);
	void Update(vivid::Vector2 Pos);

	//��_��Ԃ�
	vivid::Vector2 GetCenterPosition(void) const { return CenterPosition; }

	//�X�L���̔��a��Ԃ�
	float GetSkilSize(void) const { return SkilSize; }

private:

	static const float SkilSize;				//���ʔ͈�
	static const float AbilityTime;				//���ʎ���

	vivid::Vector2 CenterPosition;

	float Timer;

	int m_PlayerNumber;
};