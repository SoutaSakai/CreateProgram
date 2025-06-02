#include "fishermanager.h"

const int FisherManager::Max_Fisher = 5;					// �ނ�l�̐l��
const vivid::Vector2 FisherManager::Fisher_Pos[Max_Fisher]	// �ނ�l�̍��W
= { {0 * Fisher_WIDTH + 0 * Fisher_Distance,0},
	{1 * Fisher_WIDTH + 1 * Fisher_Distance,0},
	{2 * Fisher_WIDTH + 2 * Fisher_Distance,0},
	{3 * Fisher_WIDTH + 3 * Fisher_Distance,0},
	{4 * Fisher_WIDTH + 4 * Fisher_Distance,0} };
const float FisherManager::Fisher_WIDTH = 150;		// �ނ�l�̕�
const float FisherManager::Fisher_HEIGHT = 720;		// �ނ�l�̍���
const float FisherManager::Fisher_Distance = 110;	// �ނ�l�̊Ԋu
const float FisherManager::Fisher_Time = 4.0f;		// �ނ�l�̏�ԍX�V����
const vivid::Rect FisherManager::Fisher_Rect = { 0,0,Fisher_WIDTH,Fisher_HEIGHT };	// �ނ�l�̕`��͈�

// �C���X�^���X���擾
FisherManager& FisherManager::GetInstance(void)
{
	static FisherManager instance;

	return instance;
}

// ������
void FisherManager::Initialize(void)
{
	Fisher_timer = 0;

	srand((unsigned int)time(nullptr));

	FisherRandState();
}

// �X�V
void FisherManager::Update(void)
{
	if (Fisher_timer > Fisher_Time)
	{
		Fisher_timer = 0.0f;

		FisherRandState();
	}

	Fisher_timer += vivid::GetDeltaTime();
}

// �`��
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

// ���
void FisherManager::Finalize(void)
{
}

// �ނ�l�̏�Ԃ������_���ɍX�V
void FisherManager::FisherRandState(void)
{
	int random = 0;

	for (int i = 0; i < Max_Fisher; ++i)
	{
		random = rand() % 100 + 1;

		if (random > 0 && random <= 50)
			Fisher_state[i] = (int)FISHER_STATE::RELUX;
		else if (random > 50 && random <= 100)
			Fisher_state[i] = (int)FISHER_STATE::CAUTION;
	}
}
