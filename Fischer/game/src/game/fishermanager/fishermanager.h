#pragma once
#include "vivid.h"
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

private:
	void FisherRandState(void);			// �ނ�l�̏�Ԃ������_���ɍX�V

	static const int			m_max;			// �ނ�l�̐l��
	static const float			m_change_time;	// �ނ�l�̏�ԍX�V����

	float			m_Timer;			// �ނ�l�̏�ԍX�V�^�C�}�[

	// �R���X�g���N�^
	FisherManager(void) = default;
	// �f�X�g���N�^
	~FisherManager(void) = default;
	// �R�s�[�R���X�g���N�^
	FisherManager(const FisherManager& rhs) = delete;
	// ������Z�q
	FisherManager& operator=(const FisherManager& rhs) = delete;
};