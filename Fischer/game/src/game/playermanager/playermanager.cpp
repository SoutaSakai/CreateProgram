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

		//Flagの初期化
		m_SkilFlag[i] = false;
		m_ControlFlag[i] = true;
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

	vivid::DrawText(40, std::to_string(m_SkilFlag[0]), vivid::Vector2(0.0f, 0.0f),0xffffffff);
	vivid::DrawText(40, std::to_string(m_ControlFlag[0]), vivid::Vector2(0.0f, 40.0f), 0xffffffff);

	//<==
}

void playermanager::CheckHitSkil(void)
{
	vivid::Vector2 CenterPosition;		//スキルの基準点
	float			radius;				//スキルの半径

	for (int i = 0; i < MaxPlayer; i++)
	{
		//スキルの当たり判定
		if (m_SkilFlag[i] == true)
		{
			switch (player[i]->GetUseCharacter())
			{
			case CHARACTER_ID::ELSCTRICEEL:
				CenterPosition	= SkilManager::Getinstance().ElsctriceelCenterPosition(i);
				radius			= SkilManager::Getinstance().ElsctriceelSikllSize(i);

				for (int t = 0; t < MaxPlayer; t++)
				{
					if (t != i)
					{
						//比較対象の使ってるキャラクター
						CHARACTER_ID targetChara = player[t]->GetUseCharacter();
						//比較対象の中心座標
						vivid::Vector2 targetCenterPos = player[t]->GetPlayerPosition()
							+ vivid::Vector2(CharacterManager::GetInstance().CharacterWIDTH(targetChara) / 2, CharacterManager::GetInstance().CharacterHEIGHT(targetChara) / 2);
						//比較対象の角度
						float targetAngle = player[t]->GetPlayerAngle();
						//四つ角の角度
						int width  = player[t]->GetPlayerWidth();
						int height = player[t]->GetPlayerHeight();
						float edge = atan2(height - height / 2, width - width / 2) * (3.14 / 180);
						//対角線の長さ
						float dx = width - width / 2;
						float dy = height - height / 2;
						float diagonal = atan2(dy * dy, dx * dx);

						vivid::Vector2 edgePosition;
						//四つ角がスキルの範囲内かどうか
						//左上
						edgePosition.x = cos(targetAngle + 180 * (3.14 / 180) + edge) * diagonal + targetCenterPos.x;
						edgePosition.y = sin(targetAngle + 180 * (3.14 / 180) + edge) * diagonal + targetCenterPos.y;
						if (atan2((CenterPosition.y - edgePosition.y) * (CenterPosition.y - edgePosition.y),
							(CenterPosition.x - edgePosition.x) * (CenterPosition.x - edgePosition.x)) <= radius)
						{

						}
						else

					}
				}

				break;

			default:
				break;
			}
		}
	}
}

void playermanager::Finalize(void)
{
	for (int i = 0; i < MaxPlayer; i++)
	{
		player[i]->Finalize();
	}
}


