#pragma once
#include"vivid.h"

#include"../../../playermanager/playermanager.h"

class Tuna
{
public:

	void Initialize(int playernumber);
	vivid::Vector2 Update(vivid::Vector2 Pos, float Angle, float ScaleX);

private:

	static const float BlinkRange;		//�u�����N�̋���
	static const float BlinkTime;		//�u�����N�ɂ����鎞��
	static const int BlinkCount;		//�u�����N������ɕ����邩

	float Timer;
	int Count;

	int m_PlayerNumber;
};