#include "feed.h"

const float	Feed::Feed_radius = 25.0f;
const int	Feed::Feed_max = 4;

Feed::Feed(void)
	: Feed_position(vivid::Vector2(0.0f,0.0f))
	, Feed_active_flag(true)
{
}

void Feed::Initialize(const vivid::Vector2& fisher_position)
{
	Feed_position.x = fisher_position.x + 120.0f;
	Feed_position.y = fisher_position.y + 475.0f;
	Feed_active_flag = true;
}

void Feed::Update(void)
{
}

void Feed::Draw(void)
{
}

void Feed::Finalize(void)
{
}

bool Feed::IsActive(void)
{
	return Feed_active_flag;
}
