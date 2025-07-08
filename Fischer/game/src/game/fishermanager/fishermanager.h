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

	// �a��H�ׂ�ꂽ���̏���
	void CaughtFeed(void);

private:
	// �ނ�l�̏�Ԃ������_���ɍX�V
	void FisherRandState(void);

	// �ނ�l�̐l��
	static const int m_max;
	// �ނ�l�̏�ԍX�V����
	static const float m_change_time;
	// �ނ�l�̕�
	static const float m_width;
	// �ނ�l�̍���
	static const float m_height;
	// �ނ�l�̊Ԋu
	static const float m_distance;
	// �ނ�l�̕`��͈�
	static const vivid::Rect m_rect;

	// �ނ�l�̏�Ԃ̊Ǘ�
	int m_State[5];
	// �ނ�l�̏�ԍX�V�^�C�}�[
	float m_Timer;
	// �ނ�l�̍��W
	vivid::Vector2 m_Position[5];


	// �R���X�g���N�^
	FisherManager(void) = default;
	// �f�X�g���N�^
	~FisherManager(void) = default;
	// �R�s�[�R���X�g���N�^
	FisherManager(const FisherManager& rhs) = delete;
	// ������Z�q
	FisherManager& operator=(const FisherManager& rhs) = delete;
};