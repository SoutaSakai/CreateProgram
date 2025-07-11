// fisher.h
#pragma once

#include "vivid.h"

class Fisher
{
public:
	// �R���X�g���N�^
	Fisher::Fisher(void);

	// ������
	void Initialize(float);

	// �X�V
	void Update(void);

	// �`��
	void Draw(void);

	// ���
	void Finalize(void);

	// �ނ�l�̍��W��Ԃ�
	vivid::Vector2 GetPosition(void);

	// �ނ�l�̏�Ԃ������_���ɍX�V
	void FisherRandState(void);

private:
	int				m_State;			// �ނ�l�̏�Ԃ̊Ǘ�
	bool			m_FeedActiveFlag;	// �a�̃A�N�e�B�u�t���O
	vivid::Vector2	m_Position;			// �ނ�l�̈ʒu
	vivid::Rect		m_Rect;				// �ނ�l�̕`��͈�
};