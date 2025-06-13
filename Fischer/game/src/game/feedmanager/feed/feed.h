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

private:
	static const float	Feed_radius;
	static const int	Feed_max;

	vivid::Vector2	Feed_position;
	bool			Feed_active_flag;
};