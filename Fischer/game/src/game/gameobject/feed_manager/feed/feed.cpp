#include "feed.h"

const float	Feed::m_width	= 36.0f;
const float	Feed::m_height	= 40.0f;

// �R���X�g���N�^
Feed::Feed(void)
	: m_Position(vivid::Vector2(0.0f,0.0f))
	, m_ActiveFlag(true)
	, m_Id(FEED_ID::LURE)
{
}

// ������
void Feed::Initialize(const vivid::Vector2& current_pos)
{
	m_Position.x = current_pos.x;
	m_Position.y = current_pos.y;

	m_ActiveFlag = true;

	m_Id = (FEED_ID)(rand() % (int)FEED_ID::MAX);
}

// �X�V
void Feed::Update(void)
{
}

// �`��
void Feed::Draw(void)
{
	switch (m_Id)
	{
	case FEED_ID::LURE:		vivid::DrawTexture("data\\feed.png", m_Position);
	case FEED_ID::WORM:		vivid::DrawTexture("data\\feed_worm.png", m_Position);
	case FEED_ID::MEET:		vivid::DrawTexture("data\\feed_meet.png", m_Position);
	case FEED_ID::GOLD:		vivid::DrawTexture("data\\feed_gold.png", m_Position);
	}
}

// ���
void Feed::Finalize(void)
{
	m_Position = vivid::Vector2(0.0f, -m_height);
}

// �A�N�e�B�u�t���O��Ԃ�
bool Feed::IsActive(void)
{
	return m_ActiveFlag;
}

// �A�N�e�B�u�t���O�ɑ��
void Feed::InActive(bool active)
{
	m_ActiveFlag = active;
}

// ���a��Ԃ�
float Feed::GetRadius(void)
{
	return m_height / 2.0f;
}

// ���S���W��Ԃ�
vivid::Vector2 Feed::GetCenterPos(void)
{
	return m_Position + vivid::Vector2(18.0f, 20.0f);
}

// �ʒu��Ԃ�
float Feed::GetPos(void)
{
	return m_Position.y;
}