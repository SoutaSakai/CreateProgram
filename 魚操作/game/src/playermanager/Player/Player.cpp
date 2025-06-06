#include "Player.h"
#include"../../SkilManager/SkilManager.h"

Player::Player(vivid::controller::DEVICE_ID playerID)
	: m_PlayerID(playerID)
	, CharacterPos(vivid::Vector2(0, 0))
	, Scale(vivid::Vector2(1.0f, 1.0f))
	, SkilFlag(false)
	, ControlFlag(true)
{
}

void Player::Initialize()
{
	//ランダム抽選
	do
	{
		CharaNo = rand() % 3;
	} while (UseCharacter[CharaNo] == CHARACTER_ID::DUMMY);

	CharaWIDTH		 = CharacterManager::GetInstance().CharacterWIDTH(UseCharacter[CharaNo]);
	CharaHEIGHT		 = CharacterManager::GetInstance().CharacterHEIGHT(UseCharacter[CharaNo]);
	CharaSpeed		 = CharacterManager::GetInstance().CharacterSpeed(UseCharacter[CharaNo]);
	CharaRect		 = CharacterManager::GetInstance().CharacterRect(UseCharacter[CharaNo]);
	CharaFilePath	 = CharacterManager::GetInstance().CharacterFilePath(UseCharacter[CharaNo]);
	CharaMouthPos	 = CharacterManager::GetInstance().CharacterMouthPos(UseCharacter[CharaNo]);
	CharaMouthRadius = CharacterManager::GetInstance().CharacterMouthRadius(UseCharacter[CharaNo]);

	Anchor = vivid::Vector2(CharaWIDTH / 2, CharaHEIGHT / 2);

}

void Player::Update(void)
{
	if (!SkilFlag)
	{
		this->Controller();

		this->CharacterStick();

		this->Keyboard();
	}

	//スキルの更新
	if (SkilFlag)
	{
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
			vivid::DrawText(40, "true", vivid::Vector2(vivid::WINDOW_WIDTH / 2, vivid::WINDOW_HEIGHT / 2), 0xffffffff);
			CharacterPos = SkilManager::GetInstance().TunaSkil(CharacterPos, Angle, &SkilFlag,Scale.x);
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
		if (!SkilFlag)SkilFlag = true;

		SkilManager::GetInstance().TunaSkilInitialize();
		ControlFlag = false;
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
		if (!SkilFlag)SkilFlag = true;

		SkilManager::GetInstance().TunaSkilInitialize();
		ControlFlag = false;
	}
	//<===
}

void Player::Draw()
{

	vivid::DrawTexture(CharaFilePath, CharacterPos, 0xffffffff, CharaRect, Anchor, Scale,Angle );

	//確認コード===>
	vivid::DrawText(40, std::to_string(Scale.x),	vivid::Vector2(0.0f, 0.0f));
	vivid::DrawText(40, std::to_string(Angle),		vivid::Vector2(0.0f, 40.0f));

	//<===
}

void Player::Finalize(void)
{
	//使い終わったらダミーを入れる
	UseCharacter[CharaNo] = CHARACTER_ID::DUMMY;
}
