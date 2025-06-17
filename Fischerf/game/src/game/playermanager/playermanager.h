#pragma once
#include "vivid.h"

class PlayerManager
{
public:
	static PlayerManager& GetInstance(void);

	void Initialize(void);

	void Update(void);

	void Draw(void);

	void Finalize(void);

private:

	PlayerManager(void) = default;
	~PlayerManager(void) = default;
	PlayerManager(const PlayerManager& rhs) = delete;
	PlayerManager& operator=(const PlayerManager& rhs) = delete;
};