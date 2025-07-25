#include "..\..\scene_manager.h"
#include "..\scene_id.h"
#include "..\..\..\score_manager\score_manager.h"
#include "result.h"
#include "vivid.h"

const int	Result::m_width = 32;				// 数字一つの幅
const int	Result::m_height = 48;				// 数字一つの高さ
const int	Result::m_tuna_width = 220;			// マグロの幅
const int	Result::m_tuna_height = 80;			// マグロの高さ
const int	Result::m_max_player = 4;			// プレイヤー人数
const int	Result::m_max_button = 2;			// ボタンの個数

Result::Result(void)
	: m_ButtonFlag(true)
	, m_CharacterSelectBaseScale(vivid::Vector2(1.2f, 1.2f))
	, m_ExitBaseScale(vivid::Vector2(0.8f, 0.8f))
	, m_CharacterSelectMaxScale(vivid::Vector2(1.4f, 1.4f))
	, m_ExitMaxScale(vivid::Vector2(1.0f, 1.0f))
{
}

void Result::Initialize(void)
{
	m_Score = new int[m_max_player];
	m_ScorePosition = new vivid::Vector2[m_max_player];
	m_TextPosition = new vivid::Vector2[m_max_player];
	m_ButtonPosition = new vivid::Vector2[m_max_player];
	m_ButtonRect = new vivid::Rect[m_max_player];
	m_UseCharacterPosition = new UseCharacter[m_max_player];
	for (int i = 0; i < m_max_player; i++)
	{
		m_UseCharacterPosition[i].Character = new vivid::Vector2[m_max_player];
	}

	m_ButtonPosition[0] = { vivid::WINDOW_WIDTH / 2 - 145, vivid::WINDOW_HEIGHT / 1.4 }; //キャラクターセレクトに戻るほうのボタンのポジション
	m_ButtonPosition[1] = { vivid::WINDOW_WIDTH / 2 - 150, vivid::WINDOW_HEIGHT / 1.15 };	//やめるのボタンのポジション
	m_ButtonAnchor = { 155,40 };													//ボタンの基準点

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < m_max_player; j++)
		{
			m_Score[i] = 0.0f;

			// みささコード===>
			//use_character[i][j].x = vivid::WINDOW_WIDTH / 3 + i * m_tuna_width;
			//use_character[i][j].y = vivid::WINDOW_HEIGHT / 4 + j * m_tuna_height;
			
			//text_pos[j].x = vivid::WINDOW_WIDTH / 6;										// 「使用キャラクター」文字列のx軸
			//text_pos[j].y = use_character[i][j].y + m_tuna_height / 2.0f - 25 / 2.0f;			// 「使用キャラクター」文字列のy軸
			//<===

			// 新コード===>
			m_UseCharacterPosition[j].Character[i].x = vivid::WINDOW_WIDTH / 3 + i * m_tuna_width;
			m_UseCharacterPosition[j].Character[i].y = vivid::WINDOW_HEIGHT / 4 + j * m_tuna_height;

			m_TextPosition[j].x = vivid::WINDOW_WIDTH / 6;
			m_TextPosition[j].y = m_UseCharacterPosition[j].Character[i].y + m_tuna_height / 2.0f - 25 / 2.0f;
			//<===

			m_ScorePosition[j].x = vivid::WINDOW_WIDTH / 2 + vivid::WINDOW_WIDTH / 3;					// 得点のx軸
			m_ScorePosition[j].y = m_UseCharacterPosition[j].Character[i].y + m_tuna_height / 2.0f - m_height / 2.0f;		// 得点のy軸
		}
	}

	//ボタンの個数
	for (int i = 0; i < m_max_button; i++)
	{
		m_ButtonRect[i] = { 0,0,310,80 };		//ボタンの範囲
	}

	m_BackGroundPosition = { 0.0f,0.0f };//背景ポジションの初期化
	m_CharacterSelectScale = m_CharacterSelectBaseScale;//キャラクターセレクトに戻るほうのボタンの大きさ
	m_ExitScale = m_ExitBaseScale;//「やめる」ボタンの大きさ
}

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

void Result::Draw(void)
{
	vivid::CreateFont(25, 1);

	vivid::DrawTexture("data\\Seabackground2.png", m_BackGroundPosition, 0xffffffff);

	vivid::Rect rect = { 0,0,0,0 };

	for (int i = 0; i < m_max_player; i++)
	{
		int TempScore = ScoreManager::GetInstance().GetScore(i);

		vivid::Vector2 m_point_pos = m_ScorePosition[i];

		//ポイントの表示の計算
		do
		{
			int Digit = TempScore % 10;

			rect.left = Digit * m_width;
			rect.right = rect.left + m_width;
			rect.top = 0;
			rect.bottom = m_height;

			TempScore /= 10;

			m_point_pos.x -= m_width;

			vivid::DrawTexture("data\\number.png", m_point_pos, 0xffffffff, rect);

		} while (TempScore > 0);

		vivid::DrawTexture("data\\first.png", m_TextPosition[i] - vivid::Vector2(110.0f,35.0f));
		vivid::DrawTexture("data\\use_character_text.png", m_TextPosition[i]);
	}


	for (int i = 0; i < 3; i++)
		for (int j = 0; j < m_max_player; j++)
			vivid::DrawTexture("data\\Tuna.png", m_UseCharacterPosition[j].Character[i]);

	vivid::DrawTexture("data\\back_character_select.png", m_ButtonPosition[0], 0xffffffff, m_ButtonRect[0], m_ButtonAnchor, m_CharacterSelectScale);
	vivid::DrawTexture("data\\exit.png", m_ButtonPosition[1], 0xffffffff, m_ButtonRect[1], m_ButtonAnchor, m_ExitScale);//リザルトボタンの描画
	vivid::DrawText(50, "ランキング", vivid::Vector2(vivid::WINDOW_WIDTH / 2 - 125, vivid::WINDOW_HEIGHT / 10), 0xff000000);

#ifdef VIVID_DEBUG
	vivid::DrawText(24, "result", vivid::Vector2(0.0f, 0.0f));
	vivid::DrawLine(vivid::Vector2(90.0f, 100.0f), vivid::Vector2(1190.0f, 100.0f), 0xffffffff);
#endif
}

void Result::Finalize(void)
{
}
