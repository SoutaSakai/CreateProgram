#include "fishermanager.h"

const int FisherManager::Max_Fisher = 5;			// �ނ�l�̐l��
const vivid::Vector2 FisherManager::Fisher_Pos[Max_Fisher]		// �ނ�l�̍��W
= { {0 * Fisher_WIDTH + 1 * Fisher_Distance,0},
	{1 * Fisher_WIDTH + 2 * Fisher_Distance,0},
	{2 * Fisher_WIDTH + 3 * Fisher_Distance,0},
	{3 * Fisher_WIDTH + 4 * Fisher_Distance,0},
	{4 * Fisher_WIDTH + 5 * Fisher_Distance,0} };
const float FisherManager::Fisher_WIDTH = 64;		// �ނ�l�̕�
const float FisherManager::Fisher_HEIGHT = 64;		// �ނ�l�̍���
const float FisherManager::Fisher_Distance = 160;	// �ނ�l�̊Ԋu
const vivid::Rect FisherManager::Fisher_Rect = { 0,0,Fisher_WIDTH,Fisher_HEIGHT };	// �ނ�l�̕`��͈�


	
FisherManager& FisherManager::GetInstance(void)
{
	static FisherManager instance;

	return instance;
}

void FisherManager::Initialize(void)
{
	for (int i = 0; i < Max_Fisher; ++i)
	{
		Fisher_state[i] = (int)FISHER_STATE::DUMMY;
	}
}

void FisherManager::Update(void)
{
	srand((unsigned int)time(nullptr));

	for (int i = 0; i < Max_Fisher; ++i)
	{
		if (rand() % 2 == 0)
			Fisher_state[i] = (int)FISHER_STATE::RELUX;
		else if (rand() % 2 == 1)
			Fisher_state[i] = (int)FISHER_STATE::CAUTION;
	}
}

void FisherManager::Draw(void)
{
	for (int i = 0; i < Max_Fisher; i++)
	{
		if (Fisher_state[i] == (int)FISHER_STATE::RELUX)
			vivid::DrawTexture("data\\reluxfisher.png", Fisher_Pos[i]);
		else if (Fisher_state[i] == (int)FISHER_STATE::CAUTION)
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

FisherManager::~FisherManager(void)
{
}

FisherManager& FisherManager::operator=(const FisherManager& rhs)
{
	(void)rhs;

	return *this;
}
