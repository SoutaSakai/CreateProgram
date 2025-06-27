#pragma once

#include "vivid.h"

class Feed
{
public:
	Feed(void);
	~Feed(void) = default;

	void Initialize(const vivid::Vector2&);

	void Update(void);

	void Draw(void);

	void Finalize(void);

	bool IsActive(void);

	void InActive(bool);

	float GetRadius(void);

	vivid::Vector2 GetCenterPos(void);

private:
	static const float	Width;
	static const float	Height;
	static const int	Max_feed;

	vivid::Vector2	Position;
	bool			Active_flag;
};