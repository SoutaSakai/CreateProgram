#include "fisher.h"

const float Fisher::m_width = 150.0f;	// �ނ�l�̕�
const float Fisher::m_height = 720.0f;	// �ނ�l�̍���
const float Fisher::m_distance			// �ނ�l�̊Ԋu
= (vivid::WINDOW_WIDTH - m_width * m_max) / (m_max - 1);
const vivid::Rect Fisher::m_rect = { 0,0,m_width,m_height };	// �ނ�l�̕`��͈�

Fisher::Fisher(void)
{
}

void Fisher::Initialize(void)
{
}

void Fisher::Update(void)
{
}

void Fisher::Draw(void)
{
}

void Fisher::Finalize(void)
{
}
