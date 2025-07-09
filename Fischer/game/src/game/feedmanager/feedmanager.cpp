#include "feedmanager.h"
#include "feed/feed.h"

const vivid::Vector2	FeedManager::m_range = { 115.0f, 465.0f };		// �ނ�l����a�܂ł̋���

FeedManager& FeedManager::GetInstance(void)
{
	static FeedManager	instance;

	return instance;
}

// ������
void FeedManager::Initialize(int max)
{
	m_max = max;
}

// �X�V
void FeedManager::Update(void)
{
	if (m_max <= 0)	return;

	// �e�a�I�u�W�F�N�g�̍X�V
	for (int i = 0; i < m_max; i++)
	{
		// �s�����ȃf�[�^�̍폜
		if (!m_Feeds[i]->IsActive())
		{
			m_Feeds[i]->Finalize();

			//vivid::DrawText(40, std::to_string(m_Feeds[i]->GetPos()), vivid::Vector2(100.0f, 0.0f));

			//Feed* feed = nullptr;
			//m_Feeds[i] = feed;

			continue;
		}

		// �a�̍X�V
		m_Feeds[i]->Update();
	}
}

// �`��
void FeedManager::Draw(void)
{
	if (m_max <= 0)	return;

	// �e�a�I�u�W�F�N�g�̕`��
	for (int i = 0; i < m_max; i++)
	{
		m_Feeds[i]->Draw();
	}
}

// ���
void FeedManager::Finalize(void)
{
	if (m_max <= 0)	return;

	// �e�a�I�u�W�F�N�g�̉��
	for (int i = 0; i < m_max; i++)
	{
		m_Feeds[i]->Finalize();
	}
}

// �v���C���[�̌��Ƃ̃A�^������
bool FeedManager::CheckHit(vivid::Vector2 mouth_center_pos, float mouth_radius, int number)
{	
	// �����a�͈͓̔����̔���
	bool check = m_Feeds[number]->GetRadius() + mouth_radius > sqrt(pow(m_Feeds[number]->GetCenterPos().x - mouth_center_pos.x, 2) + pow(m_Feeds[number]->GetCenterPos().y - mouth_center_pos.y, 2));

	return check;
}

// �a�̐���
void FeedManager::Create(vivid::Vector2 fisher_position, int number)
{
	Feed*	feed = nullptr;

	feed = new Feed();

	if (!feed) return;

	vivid::Vector2 Feed_position = { fisher_position.x + m_range.x, fisher_position.y + m_range.y };

	feed->Initialize(Feed_position);

	m_Feeds[number] = feed;
}

void FeedManager::Destroy(int number)
{
	m_Feeds[number]->InActive(false);
}

FeedManager::FeedManager(void)
	: m_max(0)
{
}

