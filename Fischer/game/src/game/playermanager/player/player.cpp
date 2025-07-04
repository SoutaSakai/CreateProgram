#include "Player.h"

//確認コード===>
#include<DxLib.h>
//<===

const float Player::WaterHEIGHT = 165;

Player::Player()
	: CharacterPos(vivid::Vector2(0, 165))
	, Scale(vivid::Vector2(1.0f, 1.0f))

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
	if ( playermanager::GetInstance().GetControlFlag((int)m_PlayerID))
	{
		this->Controller();

		this->CharacterStick();

		this->Keyboard();
	}

	this->CheckWall();

	//スキルの更新
	if ( playermanager::GetInstance().GetSkilFlag((int)m_PlayerID))
	{
		CharacterPos = SkilManager::Getinstance().Update((int)m_PlayerID, UseCharacter[CharaNo], CharacterPos, Angle, Scale.x);
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

	CharaWIDTH =		CharacterManager::GetInstance().CharacterWIDTH(UseCharacter[CharaNo]);
	CharaHEIGHT =		CharacterManager::GetInstance().CharacterHEIGHT(UseCharacter[CharaNo]);
	CharaSpeed =		CharacterManager::GetInstance().CharacterSpeed(UseCharacter[CharaNo]);
	CharaRect =			CharacterManager::GetInstance().CharacterRect(UseCharacter[CharaNo]);
	CharaFilePath =		CharacterManager::GetInstance().CharacterFilePath(UseCharacter[CharaNo]);
	CharaMouthPos =		CharacterManager::GetInstance().CharacterMouthPos(UseCharacter[CharaNo]);
	CharaMouthRadius =	CharacterManager::GetInstance().CharacterMouthRadius(UseCharacter[CharaNo]);

	//スキルのオブジェクト
	SkilManager::Getinstance().CreateObj(CharaNo, UseCharacter[CharaNo]);


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

		if ( !playermanager::GetInstance().GetSkilFlag((int)m_PlayerID)) {

			//SkilFlagをtrueにする
			playermanager::GetInstance().ChangeSkilFlagTrue((int)m_PlayerID);

			//ControlFlagをfalseにする	==> 一部キャラだけ
			if (UseCharacter[CharaNo] == CHARACTER_ID::TUNA)
			{
				playermanager::GetInstance().ChangeControlFlagFalse((int)m_PlayerID);
			}

			//オブジェクトを作る
			SkilManager::Getinstance().CreateObj((int)m_PlayerID, UseCharacter[CharaNo]);

			//初期化する
			SkilManager::Getinstance().Initialize((int)m_PlayerID, UseCharacter[CharaNo], CharacterPos);
		}

	}
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
	/*vivid::DrawText(40, std::to_string(ControlFlag), vivid::Vector2(0.0f, 0.0f));
	vivid::DrawText(40, std::to_string(CharacterPos.y), vivid::Vector2(0.0f, 40.0f));

	DxLib::DrawLine(0, 165, vivid::WINDOW_WIDTH, 165, 0xffff000000);*/

	//<===
}

void Player::Finalize(void)
{
	//使い終わったらダミーを入れる
	UseCharacter[CharaNo] = CHARACTER_ID::DUMMY;
}

void Player::Setting(vivid::Vector2 pos, float scale, float angle, bool skilflag)
{
	CharacterPos = pos;
	Scale.x = scale;
	Angle = angle * (3.14 / 180);
}

