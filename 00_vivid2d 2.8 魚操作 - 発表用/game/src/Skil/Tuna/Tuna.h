#pragma once
#include"vivid.h"

class Tuna
{
public:

	void Initialize(void);
	vivid::Vector2 Update(vivid::Vector2 Pos, float Angle, float ScaleX);

	void GetPointer(bool* SFlag, bool* CFlag);

private:

	static const float BlinkRange;		//ブリンクの距離
	static const float BlinkTime;		//ブリンクにかかる時間
	static const int BlinkCount;		//ブリンクを何回に分けるか

	bool* SFlag;
	bool* CFlag;

	float Timer;
	int Count;

};