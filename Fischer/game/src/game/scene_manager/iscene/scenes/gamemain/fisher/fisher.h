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

	//�ނ�l�̐l��
	static const int Max_Fisher;

	//�ނ�l�̍��W
	static const vivid::Vector2 Fisher_Pos[];
	//rect
	vivid::Rect Fisher_Rect[];

	//�ނ�l�̃T�C�Y
	static const float Fisher_WIDTH;
	static const float Fisher_HEIGHT;

	//�ނ�l�̊Ԋu
	static const float Fisher_Distance;


};