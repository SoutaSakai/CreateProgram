#pragma once
#include "vivid.h"
#include "fisher/fisher.h"
#include "fisherstate.h"

class FisherManager
{
public:

	// �C���X�^���X���擾
	static FisherManager& GetInstance(void);

	// ������
	void Initialize(void);

	// �X�V
	void Update(void);

	// �`��
	void Draw(void);

	// ���
	void Finalize(void);

	// �ނ�l�̐l����Ԃ�
	int GetMax(void);

	// �ނ�l�̕���Ԃ�
	float GetWidth(void);

	// �ނ�l�̍�����Ԃ�
	float GetHeight(void);

private:
	static const float	m_width;				// �ނ�l�̕�
	static const float	m_height;				// �ނ�l�̍���
	static const float			m_change_time;	// �ނ�l�̏�ԍX�V����

	int				m_Max;				// �ނ�l�̐l��
	float			m_Timer;			// �ނ�l�̏�ԍX�V�^�C�}�[
	float			m_Distance;			// �ނ�l�̊Ԋu

	Fisher			*m_Fishers;			// �ނ�l�̃I�u�W�F�N�g�z��

	// �R���X�g���N�^
	FisherManager(void) = default;
	// �f�X�g���N�^
	~FisherManager(void) = default;
	// �R�s�[�R���X�g���N�^
	FisherManager(const FisherManager& rhs) = delete;
	// ������Z�q
	FisherManager& operator=(const FisherManager& rhs) = delete;
};