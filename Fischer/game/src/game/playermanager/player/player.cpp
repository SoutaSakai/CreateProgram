#include "Player.h"

//確認コード===>
#include<DxLib.h>
//<===

//追加コード===>
#include "..\..\feedmanager\feedmanager.h"
#include "..\..\charactermanager\charactermanager.h"
//<===

const float Player::WaterHEIGHT = 165;

Player::Player()
	: CharacterPos(vivid::Vector2(0, 165))
	, Scale(vivid::Vector2(1.0f, 1.0f))
	, SkilFlag(false)
	, ControlFlag(true)
	, tuna(nullptr)
	, Angle(0)
{
	for (int i = 0; i < 3; i++)
		UseCharacter[i] = CHARACTER_ID::DUMMY;
}

void Player::Initialize(vivid::controller::DEVICE_ID Player_ID, float Xpos)
{
	CharacterPos.x = Xpos;

	//デバイスIDを入れる
	m_PlayerID = Player_ID;

	this->ChangeRound();
}

void Player::Update(void)
{
	if (ControlFlag)
	{
		this->Controller();

		this->CharacterStick();

		this->Keyboard();
	}

	this->CheckWall();

	//スキルの更新
	if (SkilFlag)
	{
		switch (UseCharacter[playermanager::GetInstance().GetRoundCount() - 1])
		{
		case CHARACTER_ID::DUMMY:
			break;
		case CHARACTER_ID::ELSCTRICEEL:
			break;
		case CHARACTER_ID::PORCUPINEFISH:
			break;
		case CHARACTER_ID::SHARK:
			break;
		case CHARACTER_ID::LIONFISH:
			break;
		case CHARACTER_ID::MIRRORMORAYELL:
			break;
		case CHARACTER_ID::TURTLE:
			break;
		case CHARACTER_ID::OCTOPUS:
			break;
		case CHARACTER_ID::POINTUNA:
			break;
		case CHARACTER_ID::TUNA:
			if(tuna != nullptr)
				CharacterPos = tuna->Update(CharacterPos, Angle, Scale.x);
			break;
		default:
			break;
		}
	}
}

void Player::InUseCharacter(CHARACTER_ID first, CHARACTER_ID second, CHARACTER_ID third)
{
	UseCharacter[0] = first;
	UseCharacter[1] = second;
	UseCharacter[2] = third;
}

void Player::InUseCharacter(CHARACTER_ID first)
{
	UseCharacter[0] = first;
	UseCharacter[1] = CHARACTER_ID::DUMMY;
	UseCharacter[2] = CHARACTER_ID::DUMMY;
}

void Player::ChangeRound(void)
{
	//ランダム抽選
	do
	{
		CharaNo = rand() % 3;
	} while (UseCharacter[CharaNo] == CHARACTER_ID::DUMMY);

	CharaWIDTH = CharacterManager::GetInstance().CharacterWIDTH(UseCharacter[CharaNo]);
	CharaHEIGHT = CharacterManager::GetInstance().CharacterHEIGHT(UseCharacter[CharaNo]);
	CharaSpeed = CharacterManager::GetInstance().CharacterSpeed(UseCharacter[CharaNo]);
	CharaRect = CharacterManager::GetInstance().CharacterRect(UseCharacter[CharaNo]);
	CharaFilePath = CharacterManager::GetInstance().CharacterFilePath(UseCharacter[CharaNo]);
	CharaMouthPos = CharacterManager::GetInstance().CharacterMouthPos(UseCharacter[CharaNo], CharacterPos);
	CharaMouthRadius = CharacterManager::GetInstance().CharacterMouthRadius(UseCharacter[CharaNo]);

	//座標挿入
	CharacterPos.x -= CharaWIDTH / 2;
	CharacterPos.y = vivid::WINDOW_HEIGHT - CharaHEIGHT;

	Anchor = vivid::Vector2(CharaWIDTH / 2, CharaHEIGHT / 2);
}

void Player::Controller(void)
{
	//Aが押されたとき	キャンセル
	if (vivid::controller::Button(m_PlayerID, vivid::controller::BUTTON_ID::A))
	{
		vivid::DrawText(40, "A", vivid::Vector2(vivid::WINDOW_WIDTH / 2, 0.0f), 0xffffffff);
	}
	//Bが押されたとき	食べる
	if (vivid::controller::Button(m_PlayerID, vivid::controller::BUTTON_ID::B))
	{
		vivid::DrawText(40, "B", vivid::Vector2(vivid::WINDOW_WIDTH / 2, 0.0f), 0xffffffff);
	}
	//RBが押されたとき	スキル
	if (vivid::controller::Button(m_PlayerID, vivid::controller::BUTTON_ID::RIGHT_SHOULDER))
	{
		vivid::DrawText(40, "RIGHT_SHOULDER", vivid::Vector2(vivid::WINDOW_WIDTH / 2, 0.0f), 0xffffffff);

	}
}

void Player::CharacterStick(void)
{
	vivid::Vector2 ControllerPos = vivid::controller::GetAnalogStickLeft(m_PlayerID);

	CharacterPos.x += ControllerPos.x * CharaSpeed;
	CharacterPos.y += ControllerPos.y * CharaSpeed;

	if (ControllerPos.x > 0)
	{
		Scale.x = 1.0f;
		Angle = atan2(ControllerPos.y, ControllerPos.x);

	}
	else if (ControllerPos.x < 0)
	{
		Scale.x = -1.0f;
		Angle = atan2(ControllerPos.y * -1, ControllerPos.x * -1);

	}


}

void Player::Keyboard(void)
{

	//確認コード===>
	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::D))
	{
		CharacterPos.x += CharaSpeed;
		Scale.x = 1.0f;
		Angle = 0;
	}
	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::A))
	{
		CharacterPos.x -= CharaSpeed;
		Scale.x = -1.0f;
		Angle = 0;
	}
	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::W))
	{
		CharacterPos.y -= CharaSpeed;
		if (Scale.x >= 0)Angle = 270 * (3.14 / 180);
		else Angle = 90 * (3.14 / 180);
	}
	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::S))
	{
		CharacterPos.y += CharaSpeed;
		if (Scale.x <= 0)Angle = 270 * (3.14 / 180);
		else Angle = 90 * (3.14 / 180);
	}

	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::D) && vivid::keyboard::Button(vivid::keyboard::KEY_ID::W))
	{
		Angle = 315 * (3.14 / 180);
	}
	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::D) && vivid::keyboard::Button(vivid::keyboard::KEY_ID::S))
	{
		Angle = 45 * (3.14 / 180);
	}
	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::A) && vivid::keyboard::Button(vivid::keyboard::KEY_ID::W))
	{
		Angle = 45 * (3.14 / 180);
	}
	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::A) && vivid::keyboard::Button(vivid::keyboard::KEY_ID::S))
	{
		Angle = 315 * (3.14 / 180);
	}

	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::SPACE))
	{
		vivid::DrawText(40, "Space", vivid::Vector2(vivid::WINDOW_WIDTH / 2, 0.0f), 0xffffffff);

		if (!SkilFlag) {

			switch (UseCharacter[CharaNo])
			{
			case CHARACTER_ID::DUMMY:
				break;
			case CHARACTER_ID::ELSCTRICEEL:
				break;
			case CHARACTER_ID::PORCUPINEFISH:
				break;
			case CHARACTER_ID::SHARK:
				break;
			case CHARACTER_ID::LIONFISH:
				break;
			case CHARACTER_ID::MIRRORMORAYELL:
				break;
			case CHARACTER_ID::TURTLE:
				break;
			case CHARACTER_ID::OCTOPUS:
				break;
			case CHARACTER_ID::POINTUNA:
				break;
			case CHARACTER_ID::TUNA:
			if (tuna == nullptr) { tuna = new Tuna(); }

			SkilFlag = true;
			ControlFlag = false;
			tuna->Initialize();
			tuna->GetPointer(&SkilFlag, &ControlFlag);
				break;
			default:
				break;
			}
		}
	}

	//追加コード===>
	//if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::LSHIFT))
	//{

	//	FeedManager::FEED_LIST::iterator it = Feeds.begin();
	//	FEED_LIST::iterator end = Feeds.end();


	//	// どの餌を食べたかの判定
	//	while (it != end)
	//	{
	//		FeedManager::GetInstance().CheckHit(CharacterManager::GetInstance().CharacterMouthPos(UseCharacter[CharaNo], CharacterPos), CharacterManager::GetInstance().CharacterMouthRadius(UseCharacter[CharaNo]));

	//		++it;
	//	}
	//}
	//<===


	//<===
}

void Player::CheckWall(void)
{
	if (CharacterPos.x < 0)
	{
		CharacterPos.x = 0;
	}
	if (vivid::WINDOW_WIDTH < CharacterPos.x + CharaWIDTH)
	{
		CharacterPos.x = vivid::WINDOW_WIDTH - CharaWIDTH;
	}
	if (CharacterPos.y < WaterHEIGHT)
	{
		CharacterPos.y = WaterHEIGHT;
	}
	if (vivid::WINDOW_HEIGHT < CharacterPos.y + CharaHEIGHT)
	{
		CharacterPos.y = vivid::WINDOW_HEIGHT - CharaHEIGHT;
	}
}

void Player::Draw()
{

	vivid::DrawTexture(CharaFilePath, CharacterPos, 0xffffffff, CharaRect, Anchor, Scale, Angle);

	//確認コード===>
	vivid::DrawText(40, std::to_string(ControlFlag), vivid::Vector2(0.0f, 0.0f));
	vivid::DrawText(40, std::to_string(CharacterPos.y), vivid::Vector2(0.0f, 40.0f));

	DxLib::DrawLine(0, 165, vivid::WINDOW_WIDTH, 165, 0xffff000000);

	//<===
}

void Player::Finalize(void)
{
	//使い終わったらダミーを入れる
	UseCharacter[CharaNo] = CHARACTER_ID::DUMMY;
}

void Player::Setting(void)
{

}

