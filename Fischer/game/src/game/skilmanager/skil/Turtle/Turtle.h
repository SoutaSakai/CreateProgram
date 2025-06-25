#pragma once
#include"vivid.h"

class Turtle
{
public:

	void Initialize(void);
	void Update(vivid::Vector2 Pos);

	void GetPointer(bool* sflag, bool* cflag);

private:

	static const float ShieldSize;
	static const float ShieldTime;

	float Timer;

	bool* SFlag;
	bool* CFlag;
};