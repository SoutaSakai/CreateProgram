#include "fishermanager.h"
#include "..\feedmanager\feedmanager.h"

const int FisherManager::Max = 5;			// �ނ�l�̐l��
const float FisherManager::Width = 150.0f;	// �ނ�l�̕�
const float FisherManager::Height = 720.0f;	// �ނ�l�̍���
const float FisherManager::Distance			// �ނ�l�̊Ԋu
				= (vivid::WINDOW_WIDTH - Width * Max) / (Max - 1);
const float FisherManager::Change_time = 4.0f;	// �ނ�l�̏�ԍX�V����
const vivid::Rect FisherManager::Rect = { 0,0,Width,Height };	// �ނ�l�̕`��͈�

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
	Timer = 0;

	// �ނ�l�Ɖa�̈ʒu�̏�����
	for (int i = 0; i < Max; ++i)
	{
		Position[i].x = i * (Width + Distance);
		Position[i].y = 0.0f;

		// �a�̐���
		FeedManager::GetInstance().CreateFeed(Position[i], Max, i);	
	}

	// �a�̏�����
	/*FeedManager::GetInstance().Initialize();*/

	// �ނ�l�̏�Ԃ������_���ɍX�V�i�������j
	FisherRandState();
}

// �X�V
void FisherManager::Update(void)
{
	/* �ނ�l�̍X�V */
	// �^�C�}�[�����莞�Ԃ𒴂����Ƃ��ɏ�Ԃ��X�V
	if (Timer > Change_time)
	{
		// �^�C�}�[�̃��Z�b�g
		Timer = 0.0f;

		// ��Ԃ̍X�V
		FisherRandState();
	}
	
	// �^�C�}�[�̍X�V
	Timer += vivid::GetDeltaTime();


	/* �a�̍X�V */
	FeedManager::GetInstance().Update();
}

// �`��
void FisherManager::Draw(void)
{
	/* ��Ԃ̔���ɂ��ނ�l�̕`�� */
	for (int i = 0; i < Max; i++)
	{
		if (State[i] == (int)FISHER_STATE::RELUX)
			vivid::DrawTexture("data\\reluxfisher.png", Position[i]);	// �����b�N�X��Ԃ̕`��
		else if (State[i] == (int)FISHER_STATE::CAUTION)
			vivid::DrawTexture("data\\cautionfisher.png", Position[i]); // ������Ԃ̕`��
	}

	// �a�̕`��
	FeedManager::GetInstance().Draw();
}

// ���
void FisherManager::Finalize(void)
{
}

// �a��H�ׂ�ꂽ���̏���
void FisherManager::CaughtFeed(void)
{

}

// �ނ�l�̏�Ԃ������_���ɍX�V
void FisherManager::FisherRandState(void)
{
	/* �����ɂ���Ԃ̍X�V */
	for (int i = 0; i < Max; ++i)
	{
		// �����𓾂�
		int random = rand() % 100 + 1;

		if (random > 0 && random <= 50)
			State[i] = (int)FISHER_STATE::RELUX;		// �����b�N�X��ԂɍX�V
		else if (random > 50 && random <= 100)
			State[i] = (int)FISHER_STATE::CAUTION;	// ������ԂɍX�V
	}
}
