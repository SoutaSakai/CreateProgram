#include "fisher.h"

const int FISHER::Max_Fisher = 5;
const float FISHER::Fisher_WIDTH = 64;
const float FISHER::Fisher_HEIGHT = 64;
const vivid::Vector2 FISHER::Fisher_Pos[Max_Fisher] 
	= { {0 * (Fisher_Distance + Fisher_WIDTH),0},
		{1 * (Fisher_Distance + Fisher_WIDTH),0},
		{2 * (Fisher_Distance + Fisher_WIDTH),0},
		{3 * (Fisher_Distance + Fisher_WIDTH),0},
		{4 * (Fisher_Distance + Fisher_WIDTH),0} };
const float FISHER::Fisher_Distance = 10;//‰¼


FISHER::FISHER(void)

{
}

void FISHER::Initialize(void)
{
	//Fisher_pos = { 200.0f, 10.0f };

	for (int i; i < Max_Fisher; i++)
	{
		
	}

}

void FISHER::Update(void)
{
	
}

void FISHER::Draw(void)
{
	for (int i = 0; i < Max_Fisher; i++)
	{
		vivid::DrawTexture("data\\abeora.png", Fisher_Pos[i]);
	}
}

void FISHER::Finalize(void)
{
}
