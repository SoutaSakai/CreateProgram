#include "fisher.h"
#include "..\..\fishermanager\fishermanager.h"
#include "..\..\feedmanager\feedmanager.h"
#include "..\fisherstate.h"


Fisher::Fisher(void)
	: m_State(0)
	, m_FeedActiveFlag(true)
{
}

void Fisher::Initialize(float xpos)
{
	// �ʒu�̏�����
	m_Position.x = xpos;
	m_Position.y = 0.0f;
	
	// �`��͈͂̏�����
	m_Rect = vivid::Rect{ 0, 0, (int)FisherManager::GetInstance().GetWidth(), (int)FisherManager::GetInstance().GetHeight() };
}

void Fisher::Update(void)
{
}

void Fisher::Draw(void)
{
	if (m_State == (int)FISHER_STATE::RELUX)
		// �����b�N�X��Ԃ̕`��
		vivid::DrawTexture("data\\reluxfisher.png", m_Position);
	else if (m_State == (int)FISHER_STATE::CAUTION)
		// ������Ԃ̕`��
		vivid::DrawTexture("data\\cautionfisher.png", m_Position);
}

void Fisher::Finalize(void)
{
}

vivid::Vector2 Fisher::GetPosition(void)
{
	return m_Position;
}

// �ނ�l�̏�Ԃ������_���ɍX�V
void Fisher::FisherRandState(void)
{
	// �����𓾂�
	int random = rand() % 100 + 1;

	if (random > 0 && random <= 50)
		// �����b�N�X��ԂɍX�V
		m_State = (int)FISHER_STATE::RELUX;
	else if (random > 50 && random <= 100)
		// ������ԂɍX�V
		m_State = (int)FISHER_STATE::CAUTION;
}
