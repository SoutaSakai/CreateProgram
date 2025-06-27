#include "feed.h"

const float	Feed::Width		= 36.0f;
const float	Feed::Height	= 40.0f;
const int	Feed::Max_feed	= 5;

Feed::Feed(void)
	: Position(vivid::Vector2(0.0f,0.0f))
	, Active_flag(true)
{
}

void Feed::Initialize(const vivid::Vector2& current_pos)
{
	Position.x = current_pos.x;
	Position.y = current_pos.y;
	Active_flag = true;
}

void Feed::Update(void)
{
}

void Feed::Draw(void)
{
	vivid::DrawTexture("data\\ball.png", Position);
}

void Feed::Finalize(void)
{
}

bool Feed::IsActive(void)
{
	return Active_flag;
}

void Feed::InActive(bool active)
{
	Active_flag = active;
}

float Feed::GetRadius(void)
{
	return Height / 2.0f;
}

vivid::Vector2 Feed::GetCenterPos(void)
{
	return Position + vivid::Vector2(18.0f, 20.0f);
}
