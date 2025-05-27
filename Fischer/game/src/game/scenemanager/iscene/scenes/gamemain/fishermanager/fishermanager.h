#pragma once
#include "vivid.h"
#include "fisherstate.h"

class FisherManager
{
public:

	static FisherManager& GetInstance(void);

	void Initialize(void);

	void Update(void);

	void Draw(void);

	void Finalize(void);

private:

	//�ނ�l�̐l��
	static const int Max_Fisher;

	//�ނ�l�̍��W
	static const vivid::Vector2 Fisher_Pos[];

	//�ނ�l�̃T�C�Y
	static const float Fisher_WIDTH;
	static const float Fisher_HEIGHT;

	//�ނ�l�̊Ԋu
	static const float Fisher_Distance;

	//rect
	vivid::Rect Fisher_Rect[];


	FISHER_STATE Fisher1_state;
	FISHER_STATE Fisher2_state;
	FISHER_STATE Fisher3_state;
	FISHER_STATE Fisher4_state;
	FISHER_STATE Fisher5_state;

	FisherManager(void);
	FisherManager(const FisherManager& rhs);
	FisherManager(FisherManager&& rhs);
	~FisherManager(void);
	FisherManager& operator=(const FisherManager& rhs);
};