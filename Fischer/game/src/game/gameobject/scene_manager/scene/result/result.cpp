#include "..\..\scene_manager.h"
#include "..\..\..\score_manager\score_manager.h"
#include "..\..\..\bubble_manager\bubble_manager.h"
#include "..\..\..\maxplayer_manager\maxplayer_manager.h"
#include "result.h"
#include "vivid.h"

const int			Result::m_table_width				= 860;			// 枠の幅
const int			Result::m_table_height				= 370;			// 枠の高さ
const int			Result::m_log_width					= 30;			// 丸太の幅
const int			Result::m_rank_width				= 110;			// 順位の幅
const int			Result::m_rank_height				= 70;			// 順位の高さ
const int			Result::m_use_character_text_width	= 190;			// 「使用キャラクター」文字列の幅
const int			Result::m_use_character_text_height	= 40;			// 「使用キャラクター」文字列の高さ
const int			Result::m_number_width				= 32;			// 数字一つの幅
const int			Result::m_number_height				= 48;			// 数字一つの高さ
const int			Result::m_score_text_width			= 40;			// 「pt」文字列の幅
const int			Result::m_score_text_height			= 20;			// 「pt」文字列の高さ
const int			Result::m_round_text_width			= 40;			// 「_R」文字列の幅
const int			Result::m_round_text_height			= 20;			// 「_R」文字列の高さ
const int			Result::m_tuna_width				= 75;			// マグロの幅
const int			Result::m_tuna_height				= 40;			// マグロの高さ
const int			Result::m_max_player				= 4;			// プレイヤー人数
const int			Result::m_max_fish					= 3;			// プレイヤー人数
const int			Result::m_button_width				= 310;			// ボタンの幅
const int			Result::m_button_height				= 80;			// ボタンの高さ
const int			Result::m_max_button				= 2;			// ボタンの個数
const float			Result::m_distance					= 20.0f;		// 表示間隔
const int			Result::m_player_width				= 60;			//1p,2p,3p,4pの画像の幅
const int			Result::m_player_height				= 40;			//1p,2p,3p,4pの画像の高さ
const unsigned int	Result::m_black_speed				= 0x05000000;	// 暗転速度

const vivid::controller::DEVICE_ID Result::m_DeviceID[] =
{
	vivid::controller::DEVICE_ID::PLAYER1,
	vivid::controller::DEVICE_ID::PLAYER2,
	vivid::controller::DEVICE_ID::PLAYER3,
	vivid::controller::DEVICE_ID::PLAYER4,
};

Result::Result(void)
	: m_CurrentSelect(SCENE_ID::DUMMY)
	, m_ButtonFlag(true)
	, m_AButtonFlag(true)
	, m_DButtonFlag(true)
	, m_CharacterSelectBaseScale(vivid::Vector2(1.2f, 1.2f))
	, m_ExitBaseScale(vivid::Vector2(0.8f, 0.8f))
	, m_CharacterSelectMaxScale(vivid::Vector2(1.4f, 1.4f))
	, m_ExitMaxScale(vivid::Vector2(1.0f, 1.0f))
{
}

// 初期化
void Result::Initialize(void)
{
	m_MaxPlayer = CMaxPlayerManager::GetInstance().GetMaxPlayer();

	/* 配列作成 */
	m_Score						= new int[m_max_player];								// 得点
	m_ScorePosition				= new vivid::Vector2[m_max_player];				// 得点の座標
	m_ScoreTextPosition			= new vivid::Vector2[m_max_player];			// 「pt」文字列の座標
	m_RoundTextPosition			= new vivid::Vector2[m_max_fish];			// 「_R」文字列の座標
	m_RankTextPosition			= new vivid::Vector2[m_max_player];			// 順位の座標
	m_ButtonPosition			= new vivid::Vector2[m_max_player];			// ボタンの座標
	m_ButtonRect				= new vivid::Rect[m_max_player];					// ボタンの描画範囲
	m_UseCharacterTextPosition	= new vivid::Vector2[m_max_player];	// 「使用キャラクター」文字列の座標
	m_UseCharacterPosition		= new UseCharacter[m_max_player];		// 使用キャラクターの座標（1次元目）
	m_PlayerPosition			= new vivid::Vector2[m_max_player];		//1p,2p,3p,4pの画像のポジション
	m_FilePath					= new std::string[m_max_player];		//1p,2p,3p,4pの画像
	m_RankPath					= new std::string[m_max_player];		//1位,2位,3位,4位の画像

	for (int i = 0; i < m_max_player; i++)
	{
		m_UseCharacterPosition[i].Character = new vivid::Vector2[m_max_player];		// 使用キャラクターの座標（2次元目）

		m_PlayerPosition[i].x = { vivid::WINDOW_WIDTH / 4 + (m_player_width / 2) * 2 };								//1p,2p,3p,4pの画像のポジション
		m_PlayerPosition[i].y = { vivid::WINDOW_HEIGHT / 6 + ((float)m_player_height * i) + m_player_height * i };	//1p,2p,3p,4pの画像のポジション

		m_Score[i] = ScoreManager::GetInstance().GetScore(i);		// 得点

		m_RankTextPosition[i].x = vivid::WINDOW_WIDTH / 5;											// 順位のx座標
		m_RankTextPosition[i].y = vivid::WINDOW_HEIGHT / 6 + (m_rank_height + m_distance / 2) * i;	// 順位のy座標

		m_UseCharacterTextPosition[i].x = m_RankTextPosition[i].x + m_rank_width;									// 「使用キャラクター」文字列のx座標
		m_UseCharacterTextPosition[i].y = m_RankTextPosition[i].y + (m_rank_height - m_use_character_text_height);	// 「使用キャラクター」文字列のy座標

		for (int j = 0; j < m_max_fish; j++)
		{
			m_UseCharacterPosition[i].Character[j].x = (m_UseCharacterTextPosition[i].x + m_use_character_text_width + m_distance)	// 使用キャラクターのx座標
															+ (m_tuna_width + m_distance) * j;
			m_UseCharacterPosition[i].Character[j].y = m_UseCharacterTextPosition[i].y;												// 使用キャラクターのy座標
		}

		m_ScorePosition[i].x = m_UseCharacterPosition[i].Character[m_max_fish - 1].x + m_tuna_width + m_distance * 2 + m_number_width * 2;		// 得点のx座標
		m_ScorePosition[i].y = m_UseCharacterPosition[i].Character[m_max_fish - 1].y - (m_number_height - m_tuna_height);						// 得点のy座標

		m_ScoreTextPosition[i].x = m_ScorePosition[i].x + m_number_width + m_distance;					// 「pt」文字列のx座標
		m_ScoreTextPosition[i].y = m_ScorePosition[i].y + (m_number_height - m_score_text_height);		// 「pt」文字列のy座標
	}


	for (int j = 0; j < m_max_fish; j++)
	{
		m_RoundTextPosition[j].x = m_UseCharacterPosition[0].Character[j].x + (m_tuna_width - m_round_text_width) / 2;	// 「_R」文字列のx座標
		m_RoundTextPosition[j].y = m_UseCharacterPosition[0].Character[0].y - m_round_text_height;						// 「_R」文字列のy座標
	}

	for (int i = 0; i < m_max_button; i++)
	{
		m_ButtonRect[i] = { 0,0,m_button_width,m_button_height };	//ボタンの描画範囲
	}

	m_BackGroundPosition = { 0.0f,0.0f };					// 背景座標
	m_CharacterSelectScale = m_CharacterSelectBaseScale;	// 「キャラクターセレクトに戻る」ボタンの大きさ
	m_ExitScale = m_ExitBaseScale;							// 「やめる」ボタンの大きさ

	/* 座標計算 */
	m_ButtonPosition[0] = { vivid::WINDOW_WIDTH / 2 - m_button_width / 2, vivid::WINDOW_HEIGHT / 7 * 5 };	// 「キャラクターセレクトに戻る」ボタンのポジション
	m_ButtonPosition[1] = { vivid::WINDOW_WIDTH / 2 - m_button_width / 2, vivid::WINDOW_HEIGHT / 6 * 5 };	// 「やめる」ボタンのポジション
	m_ButtonAnchor = { m_button_width / 2,m_button_height / 2 };											// ボタンの基準点

	m_AButtonFlag = true;																															//Aボタンのフラグ
	m_DButtonFlag = true;

	//1p,2p,3p,4pの画像
	m_FilePath[0] = "data\\1p_player.png";
	m_FilePath[1] = "data\\2p_player.png";
	m_FilePath[2] = "data\\3p_player.png";
	m_FilePath[3] = "data\\4p_player.png";

	//1位,2位,3位,4位の画像
	m_RankPath[0] = "data\\first.png";
	m_RankPath[1] = "data\\second.png";
	m_RankPath[2] = "data\\third.png";
	m_RankPath[3] = "data\\four.png";

	m_BlackColor = 0xff000000;
	m_BlackFlag = true;
}

// 更新
void Result::Update(void)
{
	if (!m_BlackFlag)
	{
		namespace keyboard = vivid::keyboard;

		//キャラクター選択画面にもどるのボタン
		if (m_AButtonFlag)
		{
			//キャラクター選択画面にもどるのボタン
			if (keyboard::Trigger(keyboard::KEY_ID::A))
			{
				m_CharacterSelectScale = m_CharacterSelectMaxScale;		//キャラクターセレクトを選択しているときの大きさ
				m_ExitScale = m_ExitBaseScale;							//やめるのボタンの拡大率を戻す時の大きさ
				m_CurrentSelect = SCENE_ID::CHARACTERSELECT;
				m_AButtonFlag = false;
				m_DButtonFlag = true;
				for (int i = 0; i < 4; i++)
				{
					BubbleManager::GetInstance().Create();				//４つ泡の生成
				}

			}
		}
		//やめるボタン
		if (m_DButtonFlag)
		{
			//やめるボタン
			if (keyboard::Trigger(keyboard::KEY_ID::D))
			{
				m_CharacterSelectScale = m_CharacterSelectBaseScale;	//キャラクターセレクトの拡大率を戻すときの大きさ
				m_ExitScale = m_ExitMaxScale;							//やめるのボタンを選択している時の大きさ
				m_CurrentSelect = SCENE_ID::TITLE;
				m_AButtonFlag = true;
				m_DButtonFlag = false;
				for (int i = 0; i < 4; i++)
				{
					BubbleManager::GetInstance().Create();				//４つ泡の生成
				}
			}
		}

		//<===

		//ENTERを押した時の処理
		if (keyboard::Trigger(keyboard::KEY_ID::RETURN))
		{
			switch (m_CurrentSelect)
			{
			case SCENE_ID::DUMMY:
				break;
			case SCENE_ID::TITLE:
				SceneManager::GetInstance().Change_scene(SCENE_ID::TITLE);
				break;
			case SCENE_ID::CHARACTERSELECT:
				SceneManager::GetInstance().Change_scene(SCENE_ID::GAMEMAIN/*CHARACTERSELECT*/);
				ScoreManager::GetInstance().Initialize();
				break;
			case SCENE_ID::GAMEMAIN:
				break;
			case SCENE_ID::RESULT:
				break;
			default:
				break;
			}
		}

		BubbleManager::GetInstance().Update();	//泡の更新
	}
	else
	{
		FadeIn();
	}

#ifdef VIVID_DEBUG
	// Zキーでシーン変更
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::TITLE);
#endif
}

// 描画
void Result::Draw(void)
{
	vivid::CreateFont(25, 1);

	vivid::DrawTexture("data\\Seabackground2.png", m_BackGroundPosition, 0xffffffff);

	vivid::Rect rect = { 0,0,0,0 };

	vivid::DrawTexture("data\\table.png", vivid::Vector2(m_RankTextPosition[0].x - m_log_width, m_RankTextPosition[0].y - m_log_width));

	// プレイヤー一人毎の表示
	for (int i = 0; i < m_MaxPlayer; i++)
	{
		vivid::DrawTexture(m_RankPath[ScoreManager::GetInstance().GetRank(i)], m_RankTextPosition[i]);
		vivid::DrawTexture("data\\use_character_text.png", m_UseCharacterTextPosition[i]);

		for (int i = 0; i < m_max_fish; i++)
		{
			for (int j = 0; j < m_MaxPlayer; j++)
			{
				vivid::DrawTexture("data\\result_tuna.png", m_UseCharacterPosition[j].Character[i]);
			}
		}

		int TempScore = abs(ScoreManager::GetInstance().GetScore(i));

		vivid::Vector2 m_point_pos = m_ScorePosition[i];

		vivid::Vector2 m_MinusPosition = { 0.0f,0.0f };

		//ポイント表示の計算
		do
		{
			int Digit = TempScore % 10;

			rect.left = Digit * m_number_width;
			rect.right = rect.left + m_number_width;
			rect.top = 0;
			rect.bottom = m_number_height;

			TempScore /= 10;

			if (TempScore <= 0)
				m_MinusPosition = m_point_pos;

			vivid::DrawTexture("data\\number.png", m_point_pos, 0xffffffff, rect);

			m_point_pos.x -= m_number_width;

		} while (TempScore > 0);

		if (ScoreManager::GetInstance().GetScore(i) < 0)
		{
			m_MinusPosition = { m_MinusPosition.x - 40.0f, m_MinusPosition.y };
			vivid::DrawTexture("data\\minus.png", m_MinusPosition);
		}

		vivid::DrawTexture("data\\score_text.png", m_ScoreTextPosition[i]);
	}

	vivid::DrawTexture("data\\first_round.png", m_RoundTextPosition[0]);
	vivid::DrawTexture("data\\second_round.png", m_RoundTextPosition[1]);
	vivid::DrawTexture("data\\third_round.png", m_RoundTextPosition[2]);
	vivid::DrawTexture("data\\back_character_select.png", m_ButtonPosition[0], 0xffffffff, m_ButtonRect[0], m_ButtonAnchor, m_CharacterSelectScale);
	vivid::DrawTexture("data\\exit.png", m_ButtonPosition[1], 0xffffffff, m_ButtonRect[1], m_ButtonAnchor, m_ExitScale);//リザルトボタンの描画
	vivid::DrawText(50, "ランキング", vivid::Vector2(vivid::WINDOW_WIDTH / 2 - 125, vivid::WINDOW_HEIGHT / 36), 0xff000000);

	for (int i = 0; i < m_MaxPlayer; i++)
	{
		vivid::DrawTexture(m_FilePath[ScoreManager::GetInstance().GetPlayer(i)], m_PlayerPosition[i], 0xffffffff);	//
	}

	BubbleManager::GetInstance().Draw();

	vivid::DrawTexture("data\\black.png", vivid::Vector2::ZERO, m_BlackColor);

#ifdef VIVID_DEBUG
	vivid::DrawText(24, "result", vivid::Vector2(0.0f, 0.0f));
#endif
}

// 解放
void Result::Finalize(void)
{
}

void Result::FadeIn(void)
{
	m_BlackColor -= m_black_speed;

	if (m_BlackColor <= 0x00000000)
	{
		m_BlackFlag = false;
	}
}
