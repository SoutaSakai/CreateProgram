#include "maxplayer_manager.h"

CMaxPlayerManager& CMaxPlayerManager::GetInstance(void)
{
    static CMaxPlayerManager instance;

    return instance;
}

void CMaxPlayerManager::SetMaxPlayer(int max)
{
    m_MaxPlayer = max;
}

int CMaxPlayerManager::GetMaxPlayer(void)
{
    return m_MaxPlayer;
}
