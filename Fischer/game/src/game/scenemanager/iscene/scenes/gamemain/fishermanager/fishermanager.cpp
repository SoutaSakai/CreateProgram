#include "fishermanager.h"

const int FisherManager::Max_Fisher = 5;
const float FisherManager::Fisher_WIDTH = 64;
const float FisherManager::Fisher_HEIGHT = 64;
const float FisherManager::Fisher_Distance = 160;//‰¼
const vivid::Vector2 FisherManager::Fisher_Pos[Max_Fisher]
	= { {0 * Fisher_WIDTH + 1 * Fisher_Distance,0},
		{1 * Fisher_WIDTH + 2 * Fisher_Distance,0},
		{2 * Fisher_WIDTH + 3 * Fisher_Distance,0},
		{3 * Fisher_WIDTH + 4 * Fisher_Distance,0},
		{4 * Fisher_WIDTH + 5 * Fisher_Distance,0} };

	
FisherManager& FisherManager::GetInstance(void)
{
	static FisherManager instance;

	return instance;
}

void FisherManager::Initialize(void)
{
	//Fisher_pos = { 200.0f, 10.0f };

	//for (int i; i < Max_Fisher; i++)
	//{
	//	
	//}

}

void FisherManager::Update(void)
{
	
}

void FisherManager::Draw(void)
{
	for (int i = 0; i < Max_Fisher; i++)
	{
		if (Fisher_state == FISHER_STATE::RELUX)
			vivid::DrawTexture("data\\reluxfisher.png", Fisher_Pos[i]);
		else if (Fisher_state == FISHER_STATE::CAUTION)
			vivid::DrawTexture("data\\cautionfisher.png", Fisher_Pos[i]);
	}
}

void FisherManager::Finalize(void)
{
}

FisherManager::FisherManager(void)
{
}

FisherManager::FisherManager(const FisherManager& rhs)
{
	(void)rhs;
}

FisherManager::FisherManager(FisherManager&& rhs)
{
	(void)rhs;
}

FisherManager::~FisherManager(void)
{
}

FisherManager& FisherManager::operator=(const FisherManager& rhs)
{
	(void)rhs;

	return *this;
}
