#include "playermanager.h"



playermanager& playermanager::GetInstance(void)
{
	static playermanager instance;

	return instance;
}

void playermanager::GetUseCharacter(CHARACTER_ID Character, int PlayerNo, int CharacterNo)
{
	UseCharacter[PlayerNo][CharacterNo] = Character;
}

void playermanager::Initialize(const int MaxPlayer)
{
	this->MaxPlayer = MaxPlayer;
	m_RoundCount = 0;

	DeviceID[0] = vivid::controller::DEVICE_ID::PLAYER1;
	DeviceID[1] = vivid::controller::DEVICE_ID::PLAYER2;
	DeviceID[2] = vivid::controller::DEVICE_ID::PLAYER3;
	DeviceID[3] = vivid::controller::DEVICE_ID::PLAYER4;

	float distance = vivid::WINDOW_WIDTH / (this->MaxPlayer + 1);

	for (int i = 0; i < this->MaxPlayer; i++)
	{
		player[i] = new Player();

		player[i]->InUseCharacter(UseCharacter[i][0], UseCharacter[i][1], UseCharacter[i][2]);

		player[i]->Initialize(DeviceID[i], distance * (i + 1));
	}

	//‰¼
	player[0]->Setting();
	player[1]->Setting();
	player[2]->Setting();
	player[3]->Setting();


}

void playermanager::Update(void)
{
	for (int i = 0; i < MaxPlayer; i++)
	{
		player[i]->Update();
	}
}

void playermanager::Draw(void)
{
	for (int i = 0; i < MaxPlayer; i++)
	{
		player[i]->Draw();
	}
}

void playermanager::Finalize(void)
{
	for (int i = 0; i < MaxPlayer; i++)
	{
		player[i]->Finalize();
	}
}


