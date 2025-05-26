#pragma once
#include "vivid.h"

enum class FISHER_STATE
{
	RELUX,
	CAUTION,
};

class FISHER
{
public:

	FISHER(void);

	void Initialize(void);

	void Update(void);

	void Draw(void);

	void Finalize(void);

private:

	FISHER_STATE Fisher_state;

	//vivid::Vector2	Fisher_pos;

	//釣り人の人数
	static const int Max_Fisher;

	//釣り人の座標
	static const vivid::Vector2 Fisher_Pos[];
	//rect
	vivid::Rect Fisher_Rect[];

	//釣り人のサイズ
	static const float Fisher_WIDTH;
	static const float Fisher_HEIGHT;

	//釣り人の間隔
	static const float Fisher_Distance;


};