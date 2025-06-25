#pragma once
#include"vivid.h"

class Elsctriceel
{
public:

	void Initialize(void);
	void Update(vivid::Vector2 Pos);

	void GetPointer(bool* sflag, bool* cflag);

private:

	static const float SkilSize;
	static const float AbilityTime;				//Œø‰ÊŽžŠÔ

	float Timer;

	bool* SFlag;
	bool* CFlag;
};