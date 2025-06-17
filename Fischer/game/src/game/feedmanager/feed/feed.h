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

	void InActive(void);

	float GetRadius(void);

	vivid::Vector2 GetCenterPos(void);

private:
	static const float	Feed_width;
	static const float	Feed_height;
	static const int	Feed_max;

	vivid::Vector2	Feed_position;
	bool			Feed_active_flag;
};