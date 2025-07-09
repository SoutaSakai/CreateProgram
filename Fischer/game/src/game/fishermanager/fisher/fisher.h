// fisher.h
#pragma once

#include "vivid.h"

class Fisher
{
public:
	// �R���X�g���N�^
	Fisher::Fisher(void);

	// ������
	void Initialize(void);

	// �X�V
	void Update(void);

	// �`��
	void Draw(void);

	// ���
	void Finalize(void);

private:
	static const float			m_width;		// �ނ�l�̕�
	static const float			m_height;		// �ނ�l�̍���
	static const float			m_distance;		// �ނ�l�̊Ԋu
	static const vivid::Rect	m_rect;			// �ނ�l�̕`��͈�

	int				m_State;			// �ނ�l�̏�Ԃ̊Ǘ�
	vivid::Vector2	m_Position;			// �ނ�l�̈ʒu
	bool			m_FeedActiveFlag;	// �a�̃A�N�e�B�u�t���O
};