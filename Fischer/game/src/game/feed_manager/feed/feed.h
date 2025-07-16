#pragma once

#include "vivid.h"
#include "feed_id.h"

class Feed
{
public:
	Feed(void);
	~Feed(void) = default;

	// ������
	void Initialize(const vivid::Vector2&);

	// �X�V
	void Update(void);

	// �`��
	void Draw(void);

	// ���
	void Finalize(void);

	// �A�N�e�B�u�t���O��Ԃ�
	bool IsActive(void);

	// �A�N�e�B�u�t���O�ɑ��
	void InActive(bool);

	// ���a��Ԃ�
	float GetRadius(void);

	// ���S���W��Ԃ�
	vivid::Vector2 GetCenterPos(void);

	// �ʒu��Ԃ�
	float GetPos(void);

private:
	static const float	m_width;	// ��
	static const float	m_height;	// ����

	vivid::Vector2	m_Position;		// �ʒu
	bool			m_ActiveFlag;	// �A�N�e�B�u�t���O
	FEED_ID			m_Id;			// ���
};