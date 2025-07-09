#include "fishermanager.h"
#include "..\feedmanager\feedmanager.h"

const int FisherManager::m_max		= 5;		// �ނ�l�̐l��
const float FisherManager::m_change_time	= 4.0f;						// �ނ�l�̏�ԍX�V����

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
	m_Timer = 0;

	// FeedManager�̏�����
	FeedManager::GetInstance().Initialize(m_max);

	// �ނ�l�Ɖa�̈ʒu�̏�����
	for (int i = 0; i < m_max; ++i)
	{
		m_Position[i].x = i * (m_width + m_distance);
		m_Position[i].y = 0.0f;

		// �a�̐���
		FeedManager::GetInstance().Create(m_Position[i], i);
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
	if (m_Timer > m_change_time)
	{
		// �^�C�}�[�̃��Z�b�g
		m_Timer = 0.0f;

		// ��Ԃ̍X�V
		FisherRandState();
	}
	
	// �^�C�}�[�̍X�V
	m_Timer += vivid::GetDeltaTime();

	/* �a�̍X�V */
	FeedManager::GetInstance().Update();
}

// �`��
void FisherManager::Draw(void)
{
	/* ��Ԃ̔���ɂ��ނ�l�̕`�� */
	for (int i = 0; i < m_max; i++)
	{
		if (m_State[i] == (int)FISHER_STATE::RELUX)
			vivid::DrawTexture("data\\reluxfisher.png", m_Position[i]);	// �����b�N�X��Ԃ̕`��
		else if (m_State[i] == (int)FISHER_STATE::CAUTION)
			vivid::DrawTexture("data\\cautionfisher.png", m_Position[i]); // ������Ԃ̕`��
	}

	// �a�̕`��
	FeedManager::GetInstance().Draw();
}

// ���
void FisherManager::Finalize(void)
{
}

// �ނ�l�̍ő�l��Ԃ�
int FisherManager::GetMax(void)
{
	return m_max;
}

// �ނ�l�̏�Ԃ������_���ɍX�V
void FisherManager::FisherRandState(void)
{
	/* �����ɂ���Ԃ̍X�V */
	for (int i = 0; i < m_max; ++i)
	{
		// �����𓾂�
		int random = rand() % 100 + 1;

		if (random > 0 && random <= 50)
			m_State[i] = (int)FISHER_STATE::RELUX;		// �����b�N�X��ԂɍX�V
		else if (random > 50 && random <= 100)
			m_State[i] = (int)FISHER_STATE::CAUTION;	// ������ԂɍX�V
	}
}
