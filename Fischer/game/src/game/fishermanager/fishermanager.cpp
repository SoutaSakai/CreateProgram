#include "fishermanager.h"
#include "..\feedmanager\feedmanager.h"

const float			FisherManager::m_width = 150.0f;		// �ނ�l�̕�
const float			FisherManager::m_height = 720.0f;		// �ނ�l�̍���
const float			FisherManager::m_change_time = 4.0f;	// �ނ�l�̏�ԍX�V����

// �C���X�^���X���擾
FisherManager& FisherManager::GetInstance(void)
{
	static FisherManager instance;

	return instance;
}

// ������
void FisherManager::Initialize(void)
{
	// �ނ�l�̐l��
	m_Max = 5;

	// �a�Ǘ��N���X�̏�����
	FeedManager::GetInstance().Initialize(m_Max);

	// �ނ�l�̃I�u�W�F�N�g�z��̍ő�l�ݒ�
	m_Fishers = new Fisher[m_Max];

	// �ނ�l�̊Ԋu
	m_Distance = (vivid::WINDOW_WIDTH - m_width * m_Max) / (m_Max - 1);

	// �ނ�l�Ɖa�̈ʒu�̏�����
	for (int i = 0; i < m_Max; ++i)
	{
		// �ނ�l��X���W�̌v�Z
		float XPos = i * (m_width + m_Distance);

		// �ނ�l�̏�����
		m_Fishers[i].Initialize(XPos);

		FeedManager::GetInstance().SetPosition(vivid::Vector2(XPos, 0.0f), i);

		//// �a�̐���
		//FeedManager::GetInstance().Create(m_Fishers[i].GetPosition(), i);
	}

	// �ނ�l�̏�ԍX�V�^�C�}�[�̏�����
	m_Timer = 0;

	// �ނ�l�̏�Ԃ������_���ɍX�V�i�������j
	for (int i = 0; i < m_Max; ++i)
	{
		m_Fishers[i].FisherRandState();
	}
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

		// �����ɂ���Ԃ̍X�V
		for (int i = 0; i < m_Max; ++i)
		{
			// ��Ԃ̍X�V
			m_Fishers[i].FisherRandState();
		}
	}
	
	// �^�C�}�[�̍X�V
	m_Timer += vivid::GetDeltaTime();

	// �a�̍X�V
	FeedManager::GetInstance().Update();
}

// �`��
void FisherManager::Draw(void)
{
	/* ��Ԃ̔���ɂ��ނ�l�̕`�� */
	for (int i = 0; i < m_Max; i++)
	{
		m_Fishers[i].Draw();
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
	return m_Max;
}

// �ނ�l�̕���Ԃ�
float FisherManager::GetWidth(void)
{
	return m_width;
}

// �ނ�l�̍�����Ԃ�
float FisherManager::GetHeight(void)
{
	return m_height;
}
