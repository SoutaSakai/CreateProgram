#include "fisher.h"

const float Fisher::m_width = 150.0f;	// 釣り人の幅
const float Fisher::m_height = 720.0f;	// 釣り人の高さ
const float Fisher::m_distance			// 釣り人の間隔
= (vivid::WINDOW_WIDTH - m_width * m_max) / (m_max - 1);
const vivid::Rect Fisher::m_rect = { 0,0,m_width,m_height };	// 釣り人の描画範囲

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
