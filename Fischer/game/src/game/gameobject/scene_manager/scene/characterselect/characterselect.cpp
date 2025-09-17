#include "characterselect.h"
#include "..\..\scene_manager.h"
#include "..\..\..\character_manager\character_manager.h"
#include "..\..\..\player_manager\player_manager.h"
#include "..\..\..\maxplayer_manager\maxplayer_manager.h"

const int	CharacterSelect::m_flame_width		= 220;	// 選択枠の幅
const int	CharacterSelect::m_flame_height		= 100;	// 選択枠の高さ
const int	CharacterSelect::m_max_character	= (int)CHARACTER_ID::MAX - 1;
//const int	CharacterSelect::m_two_player		= 2;	// 2人プレイ時の最大人数
//const int	CharacterSelect::m_three_player		= 3;	// 3人プレイ時の最大人数
//const int	CharacterSelect::m_four_player		= 4;	// 4人プレイ時の最大人数
const int	CharacterSelect::m_distance			= 20;	// 表示間隔

const vivid::controller::DEVICE_ID CharacterSelect::m_controller[] =
{
	vivid::controller::DEVICE_ID::PLAYER1,
	vivid::controller::DEVICE_ID::PLAYER2,
	vivid::controller::DEVICE_ID::PLAYER3,
	vivid::controller::DEVICE_ID::PLAYER4,
};

const unsigned int CharacterSelect::m_default_color[] =
{
	0xffff0000,
	0xff0000ff,
	0xffffff00,
	0xff00ff00
};

CharacterSelect::CharacterSelect(void)
	: m_MaxPlayer(0)
{
}

void CharacterSelect::Initialize(void)
{
	//プレイヤー人数取得
	m_MaxPlayer = CMaxPlayerManager::GetInstance().GetMaxPlayer();

	//必要な分の配列確保
	m_CharacterPosition = new vivid::Vector2[m_max_character];

	m_FlameNumber = new int[m_MaxPlayer];
	m_FlamePosition = new vivid::Vector2[m_MaxPlayer];
	m_UseCharacter = new CHARACTER_DATE[m_MaxPlayer];

	//初期化
	for (int i = 0; i < m_MaxPlayer; i++)
	{
		m_FlameNumber[i] = 0;
		m_FlamePosition[i] = { vivid::WINDOW_WIDTH / 10 * (m_FlameNumber[i] * 2 + 1) - 150.0f / 2, 110.0f };

		m_UseCharacter[i].first = CHARACTER_ID::DUMMY;
		m_UseCharacter[i].second = CHARACTER_ID::DUMMY;
		m_UseCharacter[i].third = CHARACTER_ID::DUMMY;
	}

	//魚の表示位置計算

	for (int i = 0; i < m_max_character; ++i)
	{
		if (i < 5)
		{
			m_CharacterPosition[i] = vivid::Vector2(vivid::WINDOW_WIDTH / 10 * (i * 2 + 1) - 150.0f / 2, 110.0f);
		}
		else if (i < m_max_character)
		{
			m_CharacterPosition[i] = vivid::Vector2(vivid::WINDOW_WIDTH / 5 * (i - 4) - 150.0f / 2, 310.0f);
		}
	}

	m_ControllerTime = 0;
	m_Ready = false;
	//m_FlamePosition = new vivid::Vector2[(int)vivid::controller::DEVICE_ID::MAX];
	//m_CurrentSelect = new int[(int)vivid::controller::DEVICE_ID::MAX];

	//for (int i = 0; i < (int)vivid::controller::DEVICE_ID::MAX; ++i)
	//{
	//	CHARACTER_ID* character = nullptr;

	//	if (!character)	return;

	//	*character = CHARACTER_ID::DUMMY;

	//	//koko

	//	//m_UseCharacter.push_back(character);

	//	m_CurrentSelect[i] = (int)CHARACTER_ID::DUMMY;

	//	m_FlamePosition[i].x = GetFlamePosition(0).x;
	//	m_FlamePosition[i].y = GetFlamePosition(0).y;
	//}
}

void CharacterSelect::Update(void)
{
	//キーボード入力
	Keyboard();

	//コントローラー
	controller();

	//UseCharacterがすべて埋まったか確認する
	m_Ready = CheckUseCharacter();

//#ifdef VIVID_DEBUG
	// Zキーでシーン変更
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::GAMEMAIN);
//#endif
}

void CharacterSelect::Draw(void)
{
	// 背景の描画
	vivid::DrawTexture("data\\background.png", vivid::Vector2::ZERO);

	///* 人数分の選択したキャラクターの枠の描画 */
	//vivid::Rect rect = { 0.0f, 0.0f, 250.0f, 300.0f };

	//for (int i = 0; i < (int)vivid::controller::DEVICE_ID::MAX; ++i)
	//{
	//	vivid::Vector2 scale = { 1.0f,  1.0f };

	//	if (i < 2)
	//	{
	//		scale.x *= -1.0f;
	//	}

	//	// 選択したキャラクターの枠（岩）の描画
	//	vivid::DrawTexture("data\\rock.png",
	//		vivid::Vector2(vivid::WINDOW_WIDTH / 5 * (i + 1) - 250.0f / 2, vivid::WINDOW_HEIGHT - 300.0f), 0xffffffff, rect, vivid::Vector2(125.0f, 150.0f), scale, 0.0f);
	//}

	//// キャラ選択枠の描画
	//vivid::DrawTexture("data\\select_flame.png", m_FlamePosition[0]);

	//// 魚仮描画
	//for (int i = 0; i < m_max_character; ++i)
	//{
	//	vivid::DrawTexture("data\\tuna.png", m_CharacterPosition[i]);
	//}
	for (int i = 0; i < m_MaxPlayer; i++)
	{
		//キャラクターの枠(岩)のscale
		vivid::Vector2 scale = { 1.0f,  1.0f };
		//キャラクターの枠(岩)のrect
		vivid::Rect rect = { 0.0f, 0.0f, 250.0f, 300.0f };

		//右側は反転させる
		if (i < 2)
			scale.x = -1.0f;

		vivid::Vector2 position = vivid::Vector2(vivid::WINDOW_WIDTH / 5 * (i + 1) - 250.0f / 2, vivid::WINDOW_HEIGHT - 300.0f);
		// 選択したキャラクターの枠（岩）の描画
		vivid::DrawTexture("data\\rock.png", position, 0xffffffff, rect, vivid::Vector2(125.0f, 150.0f), scale, 0.0f);

		std::string fishname = "";

		//選択した魚があれば表示する
		if (m_UseCharacter[i].first != CHARACTER_ID::DUMMY)
		{
			fishname = CharacterManager::GetInstance().CharacterFilePath(m_UseCharacter[i].first);
			vivid::DrawTexture(fishname, position + vivid::Vector2(25, 10), 0xffffffff);
		}
		if (m_UseCharacter[i].second != CHARACTER_ID::DUMMY)
		{
			fishname = CharacterManager::GetInstance().CharacterFilePath(m_UseCharacter[i].second);
			vivid::DrawTexture(fishname, position + vivid::Vector2(25, 110), 0xffffffff);
		}
		if (m_UseCharacter[i].third != CHARACTER_ID::DUMMY)
		{
			fishname = CharacterManager::GetInstance().CharacterFilePath(m_UseCharacter[i].third);
			vivid::DrawTexture(fishname, position + vivid::Vector2(25, 210), 0xffffffff);
		}


		//フレーム描画
		vivid::DrawTexture("data\\select_flame.png", m_FlamePosition[i], m_default_color[i]);

	}

	// 魚仮描画
	for (int i = 0; i < m_max_character; ++i)
	{
		vivid::DrawTexture(CharacterManager::GetInstance().CharacterFilePath((CHARACTER_ID)(i + 1)), m_CharacterPosition[i]);
	}

	//UseCharacterがすべて埋まったら
	if (m_Ready)
	{
		vivid::Vector2 startposition = vivid::Vector2(vivid::WINDOW_WIDTH / 2 - 310 / 2, vivid::WINDOW_HEIGHT / 2 - 80 / 2);
		vivid::DrawTexture("data\\Ready.png", startposition, 0xffffffff);
	}

#ifdef VIVID_DEBUG
	vivid::DrawText(24, "characterselect", vivid::Vector2(0.0f, 0.0f));
	//vivid::DrawLine(vivid::Vector2(vivid::WINDOW_WIDTH / 6.0f, vivid::WINDOW_HEIGHT / 5.0f), vivid::Vector2(vivid::WINDOW_WIDTH / 6.0f + 105.0f, vivid::WINDOW_HEIGHT / 5.0f), 0xffffffff);
	//vivid::DrawLine(vivid::Vector2(vivid::WINDOW_WIDTH / 6.0f * 2, vivid::WINDOW_HEIGHT / 5.0f), vivid::Vector2(vivid::WINDOW_WIDTH / 6.0f * 2 - 105.0f, vivid::WINDOW_HEIGHT / 5.0f), 0xffffffff);
#endif
}

void CharacterSelect::Finalize(void)
{
}

void CharacterSelect::SetCullentSelect(int num, int player_id)
{
	m_CurrentSelect[player_id] += num;
}

void CharacterSelect::Keyboard(void)
{
	//FlameNumber切り替え　 //  デバック用
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::UP))
	{
		if (d_Keyboard < m_MaxPlayer - 1)
			d_Keyboard++;
	}
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::DOWN))
	{
		if (d_Keyboard >= 1)
			d_Keyboard--;
	}


	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::A))
	{
		if (m_FlameNumber[d_Keyboard] >= 6)										m_FlameNumber[d_Keyboard]--;
		if (1 <= m_FlameNumber[d_Keyboard] && m_FlameNumber[d_Keyboard] <= 4)	m_FlameNumber[d_Keyboard]--;
	}
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::D))
	{
		if (m_FlameNumber[d_Keyboard] <= 3)										m_FlameNumber[d_Keyboard]++;
		if (5 <= m_FlameNumber[d_Keyboard] && m_FlameNumber[d_Keyboard] <= 7)	m_FlameNumber[d_Keyboard]++;
	}
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::W))
	{
		if (m_FlameNumber[d_Keyboard] >= 5)	m_FlameNumber[d_Keyboard] -= 5;
	}
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::S))
	{
		if (m_FlameNumber[d_Keyboard] == 4)m_FlameNumber[d_Keyboard] = 8;
		if (m_FlameNumber[d_Keyboard] <= 3)m_FlameNumber[d_Keyboard] += 5;
	}

	//m_FlameNumberから座標を求める
	if (m_FlameNumber[d_Keyboard] < 5)
	{
		m_FlamePosition[d_Keyboard] = vivid::Vector2(vivid::WINDOW_WIDTH / 10 * (m_FlameNumber[d_Keyboard] * 2 + 1) - 150.0f / 2, 110.0f);
	}
	else if (m_FlameNumber[d_Keyboard] < m_max_character)
	{
		m_FlamePosition[d_Keyboard] = vivid::Vector2(vivid::WINDOW_WIDTH / 5 * (m_FlameNumber[d_Keyboard] - 4) - 150.0f / 2, 310.0f);
	}

	//キャンセル
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::BACK))
	{
		if ((int)m_UseCharacter[d_Keyboard].first - 1 == m_FlameNumber[d_Keyboard]) m_UseCharacter[d_Keyboard].first = CHARACTER_ID::DUMMY;
		else if ((int)m_UseCharacter[d_Keyboard].second - 1 == m_FlameNumber[d_Keyboard]) m_UseCharacter[d_Keyboard].second = CHARACTER_ID::DUMMY;
		else if ((int)m_UseCharacter[d_Keyboard].third - 1 == m_FlameNumber[d_Keyboard]) m_UseCharacter[d_Keyboard].third = CHARACTER_ID::DUMMY;
	}

	//スペースが押されたとき
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::SPACE))
	{
		if (m_UseCharacter[d_Keyboard].first == CHARACTER_ID::DUMMY || (int)m_UseCharacter[d_Keyboard].first - 1 == m_FlameNumber[d_Keyboard])	m_UseCharacter[d_Keyboard].first = (CHARACTER_ID)(m_FlameNumber[d_Keyboard] + 1);
		else if (m_UseCharacter[d_Keyboard].second == CHARACTER_ID::DUMMY || (int)m_UseCharacter[d_Keyboard].second - 1 == m_FlameNumber[d_Keyboard])	m_UseCharacter[d_Keyboard].second = (CHARACTER_ID)(m_FlameNumber[d_Keyboard] + 1);
		else if (m_UseCharacter[d_Keyboard].third == CHARACTER_ID::DUMMY || (int)m_UseCharacter[d_Keyboard].third - 1 == m_FlameNumber[d_Keyboard])	m_UseCharacter[d_Keyboard].third = (CHARACTER_ID)(m_FlameNumber[d_Keyboard] + 1);
	}

	//UseCharacterがすべて埋まってる && エンターが押されたら
	if (m_Ready && vivid::keyboard::Button(vivid::keyboard::KEY_ID::RETURN))
	{
		ChangeScene();
	}
}

void CharacterSelect::controller(void)
{
	//タイマー更新
	++m_ControllerTime;

	vivid::Vector2 controllerpos[4];

	for (int i = 0; i < m_MaxPlayer; i++)
	{
		//コントローラーのスティックの入力
		controllerpos[i] = vivid::controller::GetAnalogStickLeft(m_controller[i]);

		//タイマー比較
		if (m_ControllerTime >= 10)
		{
			if (controllerpos[i].x <= -0.3)
			{
				if (m_FlameNumber[i] >= 6)							m_FlameNumber[i]--;
				if (1 <= m_FlameNumber[i] && m_FlameNumber[i] <= 4)	m_FlameNumber[i]--;
			}
			if (controllerpos[i].x >= 0.3)
			{
				if (m_FlameNumber[i] <= 3)							m_FlameNumber[i]++;
				if (5 <= m_FlameNumber[i] && m_FlameNumber[i] <= 7)	m_FlameNumber[i]++;
			}
			if (controllerpos[i].y >= 0.3)
			{
				if (m_FlameNumber[i] == 4)m_FlameNumber[i] = 8;
				if (m_FlameNumber[i] <= 3)m_FlameNumber[i] += 5;
			}
			if (controllerpos[i].y <= -0.3)
			{
				if (m_FlameNumber[i] >= 5)	m_FlameNumber[i] -= 5;
			}

			//m_FlameNumberから座標を求める
			if (m_FlameNumber[i] < 5)
			{
				m_FlamePosition[i] = vivid::Vector2(vivid::WINDOW_WIDTH / 10 * (m_FlameNumber[i] * 2 + 1) - 150.0f / 2, 110.0f);
			}
			else if (m_FlameNumber[i] < m_max_character)
			{
				m_FlamePosition[i] = vivid::Vector2(vivid::WINDOW_WIDTH / 5 * (m_FlameNumber[i] - 4) - 150.0f / 2, 310.0f);
			}
		}

		//キャンセル
		if (vivid::controller::Trigger(m_controller[i], vivid::controller::BUTTON_ID::B))
		{
			if ((int)m_UseCharacter[i].first - 1 == m_FlameNumber[i]) m_UseCharacter[i].first = CHARACTER_ID::DUMMY;
			else if ((int)m_UseCharacter[i].second - 1 == m_FlameNumber[i]) m_UseCharacter[i].second = CHARACTER_ID::DUMMY;
			else if ((int)m_UseCharacter[i].third - 1 == m_FlameNumber[i]) m_UseCharacter[i].third = CHARACTER_ID::DUMMY;
		}

		//ボタンが押されたら
		if (vivid::controller::Trigger(m_controller[i], vivid::controller::BUTTON_ID::A))
		{
			if (m_UseCharacter[i].first == CHARACTER_ID::DUMMY || (int)m_UseCharacter[i].first - 1 == m_FlameNumber[i])	m_UseCharacter[i].first = (CHARACTER_ID)(m_FlameNumber[i] + 1);
			else if (m_UseCharacter[i].second == CHARACTER_ID::DUMMY || (int)m_UseCharacter[i].second - 1 == m_FlameNumber[i])	m_UseCharacter[i].second = (CHARACTER_ID)(m_FlameNumber[i] + 1);
			else if (m_UseCharacter[i].third == CHARACTER_ID::DUMMY || (int)m_UseCharacter[i].third - 1 == m_FlameNumber[i])	m_UseCharacter[i].third = (CHARACTER_ID)(m_FlameNumber[i] + 1);
		}

		//UseCharacterがすべて埋まってる && エンターが押されたら
		if (m_Ready && vivid::controller::Trigger(m_controller[i], vivid::controller::BUTTON_ID::A))
		{
			ChangeScene();
		}

	}

	//タイマー初期化
	if (m_ControllerTime >= 10)
		m_ControllerTime = 0;
}

bool CharacterSelect::CheckUseCharacter(void)
{
	for (int i = 0; i < m_MaxPlayer; i++)
	{
		if (m_UseCharacter[i].first == CHARACTER_ID::DUMMY ||
			m_UseCharacter[i].second == CHARACTER_ID::DUMMY ||
			m_UseCharacter[i].third == CHARACTER_ID::DUMMY)
		{
			return false;
		}
	}

	return true;
}

void CharacterSelect::ChangeScene(void)
{
	for (int i = 0; i < m_MaxPlayer; i++)
	{
		playermanager::GetInstance().SetUseCharacter(m_UseCharacter[i].first, i, 0);
		playermanager::GetInstance().SetUseCharacter(m_UseCharacter[i].second, i, 1);
		playermanager::GetInstance().SetUseCharacter(m_UseCharacter[i].third, i, 2);
	}

	SceneManager::GetInstance().Change_scene(SCENE_ID::GAMEMAIN);
}

vivid::Vector2 CharacterSelect::GetFlamePosition(int num)
{
	float CenterPositionX = m_CharacterPosition[num - 1].x + CharacterManager::GetInstance().CharacterWIDTH(CHARACTER_ID::TUNA) / 2.0f;
	float CenterPositionY = m_CharacterPosition[num - 1].y + CharacterManager::GetInstance().CharacterHEIGHT(CHARACTER_ID::TUNA) / 2.0f;

	float FlamePositionX = CenterPositionX - m_flame_width / 2.0f;
	float FlamePositionY = CenterPositionY - m_flame_height / 2.0f;

	return vivid::Vector2(FlamePositionX, FlamePositionY);
}
