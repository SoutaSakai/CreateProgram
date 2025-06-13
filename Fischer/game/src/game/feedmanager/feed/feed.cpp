#include "feed.h"

const float	Feed::Feed_width	= 36.0f;
const float	Feed::Feed_height	= 40.0f;
const int	Feed::Feed_max		= 4;

Feed::Feed(void)
	: Feed_position(vivid::Vector2(0.0f,0.0f))
	, Feed_active_flag(true)
{
}

void Feed::Initialize(const vivid::Vector2& current_pos)
{
	Feed_position.x = current_pos.x;
	Feed_position.y = current_pos.y;
	Feed_active_flag = true;
}

void Feed::Update(void)
{
}

void Feed::Draw(void)
{
	vivid::DrawTexture("data\\ball.png", Feed_position);
}

void Feed::Finalize(void)
{
}

bool Feed::IsActive(void)
{
	return Feed_active_flag;
}

float Feed::GetRadius(void)
{
	return Feed_width / 2.0f;
}
