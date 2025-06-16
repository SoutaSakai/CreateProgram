#pragma once
#include"vivid.h"

class Tuna
{
public:

	void Initialize(void);
	vivid::Vector2 Update(vivid::Vector2 Pos, float Angle, float ScaleX);

	void GetPointer(bool* SFlag, bool* CFlag);

private:

	static const float BlinkRange;		//�u�����N�̋���
	static const float BlinkTime;		//�u�����N�ɂ����鎞��
	static const int BlinkCount;		//�u�����N������ɕ����邩

	bool* SFlag;
	bool* CFlag;

	float Timer;
	int Count;

};