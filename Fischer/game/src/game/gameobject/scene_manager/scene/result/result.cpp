#include "..\..\scene_manager.h"
#include "..\scene_id.h"
#include "..\..\..\score_manager\score_manager.h"
#include "result.h"
#include "vivid.h"

const int	Result::m_rank_width				= 110;		// 順位の幅
const int	Result::m_rank_height				= 70;		// 順位の高さ
const int	Result::m_use_character_text_width	= 190;		// 「使用キャラクター」文字列の幅
const int	Result::m_use_character_text_height	= 40;		// 「使用キャラクター」文字列の高さ
const int	Result::m_number_width				= 32;		// 数字一つの幅
const int	Result::m_number_height				= 48;		// 数字一つの高さ
const int	Result::m_score_text_width			= 40;		// 「pt」文字列の幅
const int	Result::m_score_text_height			= 20;		// 「pt」文字列の高さ
const int	Result::m_round_text_width			= 40;		// 「_R」文字列の幅
const int	Result::m_round_text_height			= 20;		// 「_R」文字列の高さ
const int	Result::m_tuna_width				= 75;		// マグロの幅
const int	Result::m_tuna_height				= 40;		// マグロの高さ
const int	Result::m_max_player				= 4;		// プレイヤー人数
const int	Result::m_max_fish					= 3;		// プレイヤー人数
const int	Result::m_button_width				= 310;		// ボタンの幅
const int	Result::m_button_height				= 80;		// ボタンの高さ
const int	Result::m_max_button				= 2;		// ボタンの個数
const float	Result::m_distance					= 20.0f;	// 表示間隔

Result::Result(void)
	: m_ButtonFlag(true)
	, m_CharacterSelectBaseScale(vivid::Vector2(1.2f, 1.2f))
	, m_ExitBaseScale(vivid::Vector2(0.8f, 0.8f))
	, m_CharacterSelectMaxScale(vivid::Vector2(1.4f, 1.4f))
	, m_ExitMaxScale(vivid::Vector2(1.0f, 1.0f))
{
}

// 初期化
void Result::Initialize(void)
{
	/* 配列作成 */
	m_Score = new int[m_max_player];								// 得点
	m_ScorePosition = new vivid::Vector2[m_max_player];				// 得点の座標
	m_ScoreTextPosition = new vivid::Vector2[m_max_player];			// 「pt」文字列の座標
	m_RoundTextPosition = new vivid::Vector2[m_max_fish];			// 「_R」文字列の座標
	m_RankTextPosition = new vivid::Vector2[m_max_player];			// 順位の座標
	m_ButtonPosition = new vivid::Vector2[m_max_player];			// ボタンの座標
	m_ButtonRect = new vivid::Rect[m_max_player];					// ボタンの描画範囲
	m_UseCharacterTextPosition = new vivid::Vector2[m_max_player];	// 「使用キャラクター」文字列の座標
	m_UseCharacterPosition = new UseCharacter[m_max_player];		// 使用キャラクターの座標（1次元目）
	for (int i = 0; i < m_max_player; i++)
	{
		m_UseCharacterPosition[i].Character = new vivid::Vector2[m_max_player];		// 使用キャラクターの座標（2次元目）
	}

	m_ButtonPosition[0] = { vivid::WINDOW_WIDTH / 2 - m_button_width / 2, vivid::WINDOW_HEIGHT / 7 * 5 };	// 「キャラクターセレクトに戻る」ボタンのポジション
	m_ButtonPosition[1] = { vivid::WINDOW_WIDTH / 2 - m_button_width / 2, vivid::WINDOW_HEIGHT / 6 * 5 };	// 「やめる」ボタンのポジション
	m_ButtonAnchor = { m_button_width / 2,m_button_height / 2 };											// ボタンの基準点

	for (int i = 0; i < m_max_player; i++)
	{
		m_Score[i] = 0.0f;		// 得点

		m_RankTextPosition[i].x = vivid::WINDOW_WIDTH / 5;							// 順位のx座標
		m_RankTextPosition[i].y = vivid::WINDOW_HEIGHT / 6 + m_rank_height * i;		// 順位のy座標

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
}

// 更新
void Result::Update(void)
{
	namespace keyboard = vivid::keyboard;

	
	// 大幅改変===>

	//キャラクター選択画面にもどるのボタン
	if (keyboard::Trigger(keyboard::KEY_ID::W))
	{
		m_CharacterSelectScale = m_CharacterSelectMaxScale;		//キャラクターセレクトを選択しているときの大きさ
		m_ExitScale = m_ExitBaseScale;							//やめるのボタンの拡大率を戻す時の大きさ
		m_ButtonFlag = true;
	}

	//やめるボタン
	if (keyboard::Trigger(keyboard::KEY_ID::S))
	{
		m_CharacterSelectScale = m_CharacterSelectBaseScale;	//キャラクターセレクトの拡大率を戻すときの大きさ
		m_ExitScale = m_ExitMaxScale;							//やめるのボタンを選択している時の大きさ
		m_ButtonFlag = false;
	}

	//<===

	//ENTERを押した時の処理
	if (keyboard::Trigger(keyboard::KEY_ID::RETURN))
	{
		//Wボタンのとき
		if (m_ButtonFlag)
		{
			SceneManager::GetInstance().Change_scene(SCENE_ID::GAMEMAIN);
			ScoreManager::GetInstance().Initialize();
		}
		//Sボタンのとき
		else
		{
			SceneManager::GetInstance().Change_scene(SCENE_ID::TITLE);
		}
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

	for (int i = 0; i < m_max_player; i++)
	{
		vivid::DrawTexture("data\\first.png", m_RankTextPosition[i]);
		vivid::DrawTexture("data\\use_character_text.png", m_UseCharacterTextPosition[i]);

		for (int i = 0; i < m_max_fish; i++)
			for (int j = 0; j < m_max_player; j++)
			{
				vivid::DrawTexture("data\\Tuna.png", m_UseCharacterPosition[j].Character[i]);
			}

		int TempScore = ScoreManager::GetInstance().GetScore(i);

		vivid::Vector2 m_point_pos = m_ScorePosition[i];

		//ポイントの表示の計算
		do
		{
			int Digit = TempScore % 10;

			rect.left = Digit * m_number_width;
			rect.right = rect.left + m_number_width;
			rect.top = 0;
			rect.bottom = m_number_height;

			TempScore /= 10;

			vivid::DrawTexture("data\\number.png", m_point_pos, 0xffffffff, rect);

			m_point_pos.x -= m_number_width;

		} while (TempScore > 0);

		vivid::DrawTexture("data\\score_text.png", m_ScoreTextPosition[i]);
	}

	vivid::DrawTexture("data\\first_round.png", m_RoundTextPosition[0]);
	vivid::DrawTexture("data\\second_round.png", m_RoundTextPosition[1]);
	vivid::DrawTexture("data\\third_round.png", m_RoundTextPosition[2]);
	vivid::DrawTexture("data\\back_character_select.png", m_ButtonPosition[0], 0xffffffff, m_ButtonRect[0], m_ButtonAnchor, m_CharacterSelectScale);
	vivid::DrawTexture("data\\exit.png", m_ButtonPosition[1], 0xffffffff, m_ButtonRect[1], m_ButtonAnchor, m_ExitScale);//リザルトボタンの描画
	vivid::DrawText(50, "ランキング", vivid::Vector2(vivid::WINDOW_WIDTH / 2 - 125, vivid::WINDOW_HEIGHT / 36), 0xff000000);

#ifdef VIVID_DEBUG
	vivid::DrawText(24, "result", vivid::Vector2(0.0f, 0.0f));
	vivid::DrawLine(vivid::Vector2(m_RankTextPosition[0].x - 30.0f, m_RankTextPosition[0].y - 30.0f), vivid::Vector2(m_RankTextPosition[0].x - 30.0f + 860.0f, m_RankTextPosition[0].y - 30.0f), 0xffffffff);
	vivid::DrawLine(vivid::Vector2(m_RankTextPosition[0].x - 30.0f, m_RankTextPosition[0].y), vivid::Vector2(m_RankTextPosition[0].x - 30.0f + 860.0f, m_RankTextPosition[0].y), 0xffffffff);
	vivid::DrawLine(vivid::Vector2(m_RankTextPosition[0].x - 30.0f, m_RankTextPosition[0].y - 30.0f), vivid::Vector2(m_RankTextPosition[0].x - 30.0f, m_RankTextPosition[0].y - 30.0f + 360.0f), 0xffffffff);
	vivid::DrawLine(vivid::Vector2(m_RankTextPosition[0].x - 15.0f, m_RankTextPosition[0].y - 30.0f), vivid::Vector2(m_RankTextPosition[0].x - 15.0f, m_RankTextPosition[0].y - 30.0f + 360.0f), 0xffffffff);

	vivid::DrawLine(vivid::Vector2(m_RankTextPosition[0].x - 30.0f, m_RankTextPosition[0].y - 30.0f + 360.0f), vivid::Vector2(m_RankTextPosition[0].x - 30.0f + 860.0f, m_RankTextPosition[0].y - 30.0f + 360.0f), 0xffffffff);
	vivid::DrawLine(vivid::Vector2(m_RankTextPosition[0].x - 30.0f, m_RankTextPosition[0].y - 30.0f + 310.0f), vivid::Vector2(m_RankTextPosition[0].x - 30.0f + 860.0f, m_RankTextPosition[0].y - 30.0f + 310.0f), 0xffffffff);
	vivid::DrawLine(vivid::Vector2(m_RankTextPosition[0].x - 30.0f + 860.0f, m_RankTextPosition[0].y - 30.0f), vivid::Vector2(m_RankTextPosition[0].x - 30.0f + 860.0f, m_RankTextPosition[0].y - 30.0f + 360.0f), 0xffffffff);
	vivid::DrawLine(vivid::Vector2(m_RankTextPosition[0].x - 30.0f + 845.0f, m_RankTextPosition[0].y - 30.0f), vivid::Vector2(m_RankTextPosition[0].x - 30.0f + 845.0f, m_RankTextPosition[0].y - 30.0f + 360.0f), 0xffffffff);
#endif
}

// 解放
void Result::Finalize(void)
{
}
