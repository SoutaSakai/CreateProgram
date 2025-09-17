#include "..\..\scene_manager.h"
#include "gamemain.h"
#include "..\..\..\fisher_manager\fisher_manager.h"
#include"..\..\..\character_manager/character_manager.h"
#include "..\..\..\character_manager\characterID.h"
#include"..\..\..\player_manager/player_manager.h"
#include "..\..\..\score_manager\score_manager.h"
#include "..\..\..\time_manager\time_manager.h"
#include "..\title\title.h"

#include "..\..\..\maxplayer_manager\maxplayer_manager.h"
//#include "..\scene_id.h"
//#include "vivid.h"

const int		Gamemain::m_max_fish = 3;
const float		Gamemain::m_water_surface = 165.0f;
const int		Gamemain::m_max_round = 3;

const vivid::controller::DEVICE_ID Gamemain::m_DeviceID[] =
{
	vivid::controller::DEVICE_ID::PLAYER1,
	vivid::controller::DEVICE_ID::PLAYER2,
	vivid::controller::DEVICE_ID::PLAYER3,
	vivid::controller::DEVICE_ID::PLAYER4,
};

//CHARACTER_ID UseCharacter[MaxPlayer][3] =
//{ {CHARACTER_ID::SHARK,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY},
//	{CHARACTER_ID::TUNA,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY}/*,
//	{CHARACTER_ID::SHARK,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY},
//	{CHARACTER_ID::TURTLE,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY}*/
//};

Gamemain::Gamemain(void)
	: m_CurrentRound(1)
	, m_MaxPlayer(0)
{
}

void Gamemain::Initialize(void)
{

	FisherManager::GetInstance().Initialize();

	//最大人数を受け取る
	m_MaxPlayer = CMaxPlayerManager::GetInstance().GetMaxPlayer();

	playermanager::GetInstance().Initialize(m_MaxPlayer);

	CTimeManager::GetInstance().Initialize();

	if (m_CurrentRound == 1)
	{
		ScoreManager::GetInstance().Initialize();
		m_BlackFlag = false;
		m_BlackColor = 0x00000000;
		m_BlackSpeed = 0x05000000;
	}

	m_Rect = { 0,0,310,80 };
	m_Anchor = { 160,40 };
	m_Scale = { 1.3,1.3 };
	m_ButtonPosition = { vivid::WINDOW_WIDTH / 2 - 160,vivid::WINDOW_HEIGHT / 2 - 40 };
}

void Gamemain::Update(void)
{
	//仮
	vivid::DrawTexture("data\\background.png", vivid::Vector2(0.0f, m_water_surface));
	namespace keyboard = vivid::keyboard;

	if (!m_BlackFlag)
	{
		CTimeManager::GetInstance().Update(m_BlackFlag);

		ScoreManager::GetInstance().Update();

		FisherManager::GetInstance().Update();

		playermanager::GetInstance().Update();
	}
	else
	{
		ChangeRound();
	}

	if (CTimeManager::GetInstance().GetTimer() <= 1)
	{
		for (int i = 0; i < (int)vivid::controller::DEVICE_ID::MAX; i++)
			if ((vivid::controller::Trigger(m_DeviceID[i], vivid::controller::BUTTON_ID::A) || vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::RETURN)))
				m_BlackFlag = true;
	}

//#ifdef VIVID_DEBUG
	// Zキーでシーン変更
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::RESULT);
//#endif
}

void Gamemain::Draw(void)
{
	//vivid::DrawTexture("data\\background.png", vivid::Vector2(0.0f, m_water_surface));

	FisherManager::GetInstance().Draw();

	playermanager::GetInstance().Draw();

	ScoreManager::GetInstance().Draw();

	CTimeManager::GetInstance().Draw();

	if (CTimeManager::GetInstance().GetTimer() <= 1)
	{
		if (m_CurrentRound == m_max_round)
			vivid::DrawTexture("data\\result_button.png", m_ButtonPosition, 0xffffffff, m_Rect, m_Anchor, m_Scale);
		else
			vivid::DrawTexture("data\\next_round.png", m_ButtonPosition, 0xffffffff, m_Rect, m_Anchor, m_Scale);
	}

	vivid::DrawTexture("data\\black.png", vivid::Vector2::ZERO, m_BlackColor);

#ifdef VIVID_DEBUG
	vivid::DrawText(24, "gamemain", vivid::Vector2(0.0f, 0.0f));
#endif
}

void Gamemain::Finalize(void)
{
}

bool Gamemain::GetBlackFlag(void)
{
	return m_BlackFlag;
}

void Gamemain::ChangeRound(void)
{
	m_BlackColor += m_BlackSpeed;

	if (m_BlackColor >= 0xff000000)
	{
		m_BlackColor = 0xff000000;

		m_BlackSpeed *= -1;

		m_CurrentRound++;

		this->Initialize();
	}

	if (m_BlackColor <= 0x00000000)
	{
		m_BlackColor = 0x00000000;

		m_BlackSpeed *= -1;

		m_BlackFlag = false;
	}

	if (m_CurrentRound > m_max_round)
		SceneManager::GetInstance().Change_scene(SCENE_ID::RESULT);
}

void Gamemain::SetMaxPlayer(int max)
{
	m_MaxPlayer = max;
}