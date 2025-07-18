#include "feed_manager.h"
#include "feed/feed.h"

FeedManager& FeedManager::GetInstance(void)
{
	static FeedManager	instance;

	return instance;
}

// ������
void FeedManager::Initialize(int max)
{
	m_Max = max;

	m_Feeds = new Feed[m_Max];

	m_Range = vivid::Vector2(115.0f, 465.0f);
}

// �X�V
void FeedManager::Update(void)
{
	if (m_Max <= 0)	return;

	// �e�a�I�u�W�F�N�g�̍X�V
	for (int i = 0; i < m_Max; i++)
	{
		// �s�����ȃf�[�^�̏�����
		if (!m_Feeds[i].IsActive())
		{
			m_Feeds[i].Finalize();

			continue;
		}

		// �a�̍X�V
		m_Feeds[i].Update();
	}
}

// �`��
void FeedManager::Draw(void)
{
	if (m_Max <= 0)	return;

	// �e�a�I�u�W�F�N�g�̕`��
	for (int i = 0; i < m_Max; i++)
	{
		if (m_Feeds[i].IsActive())
			m_Feeds[i].Draw();
	}
}

// ���
void FeedManager::Finalize(void)
{
	if (m_Max <= 0)	return;

	// �e�a�I�u�W�F�N�g�̉��
	for (int i = 0; i < m_Max; i++)
	{
		m_Feeds[i].Finalize();

		delete[] m_Feeds;
	}
}

// �v���C���[�̌��Ƃ̃A�^������
bool FeedManager::CheckHit(vivid::Vector2 mouth_center_pos, float mouth_radius, int number)
{	
	// �����a�͈͓̔����̔���
	bool check = m_Feeds[number].GetRadius() + mouth_radius > sqrt(pow(m_Feeds[number].GetCenterPos().x - mouth_center_pos.x, 2) + pow(m_Feeds[number].GetCenterPos().y - mouth_center_pos.y, 2));

	return check;
}

// �a�̐���
void FeedManager::Create(vivid::Vector2 fisher_position, int number)
{
	//Feed*	feed = nullptr;

	//feed = new Feed();

	//if (!feed) return;

	//vivid::Vector2 Feed_position = { fisher_position.x + m_range.x, fisher_position.y + m_range.y };

	//feed->Initialize(Feed_position);

	//m_Feeds[number] = feed;
}

void FeedManager::Destroy(int number)
{
	m_Feeds[number].InActive(false);
}

void FeedManager::SetPosition(vivid::Vector2 fisher_position, int number)
{
	vivid::Vector2 Feed_position = { fisher_position.x + m_Range.x, fisher_position.y + m_Range.y };

	m_Feeds[number].Initialize(Feed_position);
}

FeedManager::FeedManager(void)
	: m_Max(0)
{
}

