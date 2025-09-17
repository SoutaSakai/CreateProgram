#pragma once

#include"vivid.h"

class CMaxPlayerManager
{
public:

	static CMaxPlayerManager& GetInstance(void);

	void SetMaxPlayer(int max);
	int GetMaxPlayer(void);

private:

	int m_MaxPlayer;

};