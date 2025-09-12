#include "Player.h"

#include<DxLib.h>
#include "..\..\feed_manager\feed_manager.h"
#include "..\..\feed_manager\feed\feed_id.h"
#include "..\..\character_manager\character_manager.h"
#include "..\..\fisher_manager\fisher_manager.h"
#include "..\..\scene_manager\scene\characterselect\characterselect.h"
#include "..\..\score_manager\score_manager.h"
#include "..\..\player_manager\player_manager.h"

const float Player::WaterHEIGHT = 165;

//追加コード===>
const float Player::MouthDis = 55.0f;
const float Player::m_eat_time = 4;
//<===

// コンストラクタ
Player::Player()
	: CharacterPos(vivid::Vector2(0, 165))
	, Scale(vivid::Vector2(1.0f, 1.0f))
	//, SkilFlag(false)
	//, ControlFlag(true)
	//, tuna(nullptr)
	, Angle(0)
	, m_Score(0)
{
	for (int i = 0; i < 3; i++)
		UseCharacter[i] = CHARACTER_ID::DUMMY;
}

// 初期化
void Player::Initialize(vivid::controller::DEVICE_ID Player_ID, float Xpos)
{
	m_EatTimer = 0;

	m_Color = 0xffffffff;

	CharacterPos.x = Xpos;

	m_FishedFlag = false;

	//追加コード===>
	//for (int i = 0; i < 4; ++i)
	//{
	//	Hit_feed[i] = false;
	//}
	//<===

	//デバイスIDを入れる
	m_PlayerID = Player_ID;

	this->ChangeRound();
}

// 更新
void Player::Update(void)
{
	if (CTimeManager::GetInstance().GetFlag())
	{
		if (CTimeManager::GetInstance().GetTimer() > 1)//タイムが０より大きい
		{
			// キャラの中心位置
			vivid::Vector2 CharaCenterPos = CharacterPos + vivid::Vector2(CharaWIDTH / 2, CharaHEIGHT / 2);

			float x = 0;
			float y = 0;

			if (Scale.x >= 0)
			{
				x = cos(Angle);
				y = sin(Angle);
			}
			else
			{
				x = cos(Angle + 180.0f * 3.14f / 180.0f);
				y = sin(Angle + 180.0f * 3.14f / 180.0f);
			}

			CharaMouthPos = CharaCenterPos + vivid::Vector2(x * MouthDis, y * MouthDis);
			//<===

			if (playermanager::GetInstance().GetControlFlag((int)m_PlayerID))
			{
				this->Controller();

				this->CharacterStick();

				//if (SceneManager::GetInstance().GetCullentSceneId() == SCENE_ID::CHARACTERSELECT)
				//	this->KeyboardCharacterSelect();
				//else if (SceneManager::GetInstance().GetCullentSceneId() == SCENE_ID::GAMEMAIN)
				//if (SceneManager::GetInstance().GetCullentSceneId() == SCENE_ID::GAMEMAIN)
				if ((int)m_PlayerID == 0)
					this->KeyboardGamemain();
			}

			if (!m_FishedFlag)
				this->CheckWall();

			//スキルの更新
			if (playermanager::GetInstance().GetSkilFlag((int)m_PlayerID))
			{
				CharacterPos = SkilManager::Getinstance().Update((int)m_PlayerID, UseCharacter[CharaNo], CharacterPos, Angle, Scale.x);

				/*switch (UseCharacter[playermanager::GetInstance().GetRoundCount() - 1])
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
				}*/
			}

		}
	}
}

void Player::InUseCharacter(CHARACTER_ID first, CHARACTER_ID second, CHARACTER_ID third)
{
	UseCharacter[0] = first;
	UseCharacter[1] = second;
	UseCharacter[2] = third;
}

// デバッグ用
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
	CharaMouthPos = CharacterManager::GetInstance().CharacterMouthPos(UseCharacter[CharaNo]);
	CharaMouthRadius = CharacterManager::GetInstance().CharacterMouthRadius(UseCharacter[CharaNo]);

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

		if (!playermanager::GetInstance().GetSkilFlag((int)m_PlayerID)) {

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
			SkilManager::Getinstance().Initialize((int)m_PlayerID, UseCharacter[CharaNo], CharacterPos, Scale);

		}
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

void Player::KeyboardGamemain(void)
{
	float speed;

	if (playermanager::GetInstance().GetOctopusSlowFlag((int)m_PlayerID))
	{
		speed = CharaSpeed - CharacterManager::GetInstance().GetSlowSpeed();
	}
	else
	{
		speed = CharaSpeed;
	}

	//追加コード===>
	int FisherMax = FisherManager::GetInstance().GetMax();

	// 餌を食べる
	if (m_EatTimer <= 0.0f && vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::R))
	{
		vivid::DrawText(40, "R", vivid::Vector2(200.0f, 0.0f));
		for (int i = 0; i < FisherMax; ++i)
		{
			if (FeedManager::GetInstance().GetHit(i))
			{
				// 当たっていた時

#ifdef VIVID_DEBUG
				vivid::DrawText(40, std::to_string(i), vivid::Vector2(300.0f, 0.0f));
#endif

				FisherManager::GetInstance().SetMoveFlag(i, true);

				if (FisherManager::GetInstance().GetState(i) == FISHER_STATE::RELUX)
				{
					switch (FeedManager::GetInstance().GetFeedID(i))
					{
					case FEED_ID::LURE:
						ScoreManager::GetInstance().AddScore(10, m_PlayerID);
						break;
					case FEED_ID::WORM:
						ScoreManager::GetInstance().AddScore(20, m_PlayerID);
						break;
					case FEED_ID::MEET:
						ScoreManager::GetInstance().AddScore(50, m_PlayerID);
						break;
					case FEED_ID::GOLD:
						ScoreManager::GetInstance().AddScore(100, m_PlayerID);
						break;
					default:
						break;
					}
				}
				else if (FisherManager::GetInstance().GetState(i) == FISHER_STATE::CAUTION)
				{
					ScoreManager::GetInstance().AddScore(-20, m_PlayerID);

					m_FishedFlag = true;
				}

				FeedManager::GetInstance().Destroy(i);
			}
		}
	}
	//<===
	 
	//確認コード===>
	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::D))
	{
		CharacterPos.x += speed;
		Scale.x = 1.0f;
		Angle = 0;
	}
	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::A))
	{
		CharacterPos.x -= speed;
		Scale.x = -1.0f;
		Angle = 0;
	}
	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::W))
	{
		CharacterPos.y -= speed;
		if (Scale.x >= 0)Angle = 270 * (3.14 / 180);
		else Angle = 90 * (3.14 / 180);
	}
	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::S))
	{
		CharacterPos.y += speed;
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

		if (!playermanager::GetInstance().GetSkilFlag((int)m_PlayerID)) {

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
			SkilManager::Getinstance().Initialize((int)m_PlayerID, UseCharacter[CharaNo], CharacterPos, Scale);

		}
	}
	//<===

	if (m_EatTimer > 0.0f)
		m_EatTimer -= vivid::GetDeltaTime();
}

int Player::KeyboardCharacterSelect(int current)
{
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::D) || vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::RIGHT))
	{
		if (current >= 9 - 1)
			return 0;
		else
			return current + 1;
	}
	else if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::A) || vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::LEFT))
	{
		if (current <= 0)
			return 9 - 1;
		else
			return current - 1;
	}
	else if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::W) || vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::UP))
	{
		if (current > 5 - 1)
			return current - 5;
	}
	else if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::S) || vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::DOWN))
	{
		if (current < 5 - 1)
			return current + 5;
	}

	return current;
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

#ifdef VIVID_DEBUG
	//確認コード===>
	//vivid::DrawText(40, std::to_string(ControlFlag), vivid::Vector2(0.0f, 0.0f));
	//vivid::DrawText(40, std::to_string(CharacterPos.y), vivid::Vector2(0.0f, 40.0f));
	//vivid::DrawText(40, std::to_string(CharaMouthPos.x), vivid::Vector2(0.0f, 80.0f));
	//vivid::DrawText(40, std::to_string(CharaMouthPos.y), vivid::Vector2(1000.0f, 80.0f));

	//DxLib::DrawLine(0, 165, vivid::WINDOW_WIDTH, 165, 0xffff000000);

	//<===
#endif
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

void Player::SetFeedID(FEED_ID id)
{
	/*m_FeedId = id;*/
}

bool Player::CheckHitFeed(Feed* feed)
{
	// 口が餌の範囲内かの判定
	bool check = feed->GetRadius() + CharaMouthRadius > sqrt(pow(feed->GetCenterPos().x - CharaMouthPos.x, 2) + pow(feed->GetCenterPos().y - CharaMouthPos.y, 2));

	//if (check)
	//	feed->InActive(false);

	return check;
}

void Player::SetMovePosition(vivid::Vector2 fisher_position, FISHER_MOVE move)
{
	if (move == FISHER_MOVE::WAIT)
		m_EatTimer = m_eat_time;

	vivid::Vector2 range = FeedManager::GetInstance().GetRange(move);

	CharacterPos = fisher_position + range - vivid::Vector2(CharaWIDTH / 2.0f, CharaHEIGHT / 2.0f);
}