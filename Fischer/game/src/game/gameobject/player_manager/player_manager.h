#pragma once
#include"vivid.h"

#include"Player/Player.h"
#include"../character_manager/CharacterID.h"

class Player;

class playermanager
{
public:

	static playermanager& GetInstance(void);

	void GetUseCharacter(CHARACTER_ID Character, int PlayerNo, int CharacterNo);

	void Initialize(const int MaxPlayer);
	void Update(void);
	void Draw(void);
	void Finalize(void);

	void InRoundCount(int RoundCount) { m_RoundCount = RoundCount; }
	int  GetRoundCount(void) { return 1/*m_RoundCount*/; }

private:

	playermanager(void) = default;

	int MaxPlayer;

	int m_RoundCount;

	Player* player[(int)vivid::controller::DEVICE_ID::MAX];

	CHARACTER_ID UseCharacter[(int)vivid::controller::DEVICE_ID::MAX][3];

	vivid::controller::DEVICE_ID DeviceID[(int)vivid::controller::DEVICE_ID::MAX];

	vivid::Vector2 StartPos[4];
};