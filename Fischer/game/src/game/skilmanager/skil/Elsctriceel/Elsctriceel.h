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
	float GetSkillSize(void) const { return SkillSize; }

private:

	static const float SkillSize;				//���ʔ͈�
	static const float AbilityTime;				//���ʎ���

	vivid::Vector2 CenterPosition;

	float Timer;

	int m_PlayerNumber;
};