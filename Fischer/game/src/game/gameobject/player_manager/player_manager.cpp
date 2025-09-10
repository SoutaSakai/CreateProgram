#include "player_manager.h"



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

		//Flagの初期化
		m_SkilFlag[i] = false;
		m_ControlFlag[i] = true;

		m_Octopus_Slow[i] = false;
	}


	//仮
	/*player[0]->Setting(vivid::Vector2(160,400),-1,-30,false);
	player[1]->Setting(vivid::Vector2(270, 580), -1, 40, true);
	player[2]->Setting(vivid::Vector2(900, 390), -1, 30, false);
	player[3]->Setting(vivid::Vector2(790, 270), -1, 0, true);*/
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

	//確認コード ==>

	vivid::DrawText(40, std::to_string(m_SkilFlag[0]), vivid::Vector2(0.0f, 0.0f), 0xffffffff);
	vivid::DrawText(40, std::to_string(m_ControlFlag[0]), vivid::Vector2(0.0f, 40.0f), 0xffffffff);

	//<==
}

void playermanager::CheckHitSkil(void)
{
}

void playermanager::Finalize(void)
{
	for (int i = 0; i < MaxPlayer; i++)
	{
		player[i]->Finalize();
	}
}

bool playermanager::CheckHitFeed(Feed* feed)
{
	for (int i = 0; i < MaxPlayer; i++)
	{
		if (player[i]->CheckHitFeed(feed))
			return true;
	}

	return false;
}

int playermanager::KeyboradCharacterSelect(int num, int current)
{
	return player[num]->KeyboardCharacterSelect(current);
}

vivid::Vector2 playermanager::GetPosition(int playernumber) { return player[playernumber]->GetPlayerPosition(); }

float playermanager::GetAngle(int playernumber) { return player[playernumber]->GetPlayerAngle(); }

CHARACTER_ID playermanager::GetCharacter(int playernumber) { return player[playernumber]->GetUseCharacter(); }


