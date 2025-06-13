#include "fishermanager.h"
#include "..\feedmanager\feedmanager.h"

const int FisherManager::Max_Fisher = 4;		// �ނ�l�̐l��
const float FisherManager::Fisher_WIDTH = 150;	// �ނ�l�̕�
const float FisherManager::Fisher_HEIGHT = 720;	// �ނ�l�̍���
const float FisherManager::Fisher_Distance		// �ނ�l�̊Ԋu
				= (vivid::WINDOW_WIDTH - Fisher_WIDTH * Max_Fisher) / (Max_Fisher - 1);
const float FisherManager::Fisher_Time = 4.0f;	// �ނ�l�̏�ԍX�V����
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
	// �ނ�l�̏�ԍX�V�^�C�}�[�̏�����
	Fisher_timer = 0;

	// �ނ�l�Ɖa�̈ʒu�̏�����
	for (int i = 0; i < Max_Fisher; ++i)
	{
		Fisher_Pos[i].x = i * (Fisher_WIDTH + Fisher_Distance);
		Fisher_Pos[i].y = 0.0f;
	}

	// �a�̏�����
	FeedManager::GetInstance().Initialize();

	// �ނ�l�̏�Ԃ������_���ɍX�V�i�������j
	FisherRandState();
}

// �X�V
void FisherManager::Update(void)
{
	/* �ނ�l�̍X�V */
	// �^�C�}�[�����莞�Ԃ𒴂����Ƃ��ɏ�Ԃ��X�V
	if (Fisher_timer > Fisher_Time)
	{
		// �^�C�}�[�̃��Z�b�g
		Fisher_timer = 0.0f;

		// ��Ԃ̍X�V
		FisherRandState();
	}

	// �^�C�}�[�̍X�V
	Fisher_timer += vivid::GetDeltaTime();


	/* �a�̍X�V */
	FeedManager::GetInstance().Update();
}

// �`��
void FisherManager::Draw(void)
{
	/* ����ɂ��ނ�l�̕`�� */
	for (int i = 0; i < Max_Fisher; i++)
	{
		if (Fisher_state[i] == (int)FISHER_STATE::RELUX)
			vivid::DrawTexture("data\\reluxfisher.png", Fisher_Pos[i]);	// �����b�N�X��Ԃ̕`��
		else if (Fisher_state[i] == (int)FISHER_STATE::CAUTION)
			vivid::DrawTexture("data\\cautionfisher.png", Fisher_Pos[i]); // ������Ԃ̕`��
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

	/* �����ɂ���Ԃ̍X�V */
	for (int i = 0; i < Max_Fisher; ++i)
	{
		// �����𓾂�
		random = rand() % 100 + 1;

		if (random > 0 && random <= 50)
			Fisher_state[i] = (int)FISHER_STATE::RELUX;		// �����b�N�X��ԂɍX�V
		else if (random > 50 && random <= 100)
			Fisher_state[i] = (int)FISHER_STATE::CAUTION;	// ������ԂɍX�V
	}
}
