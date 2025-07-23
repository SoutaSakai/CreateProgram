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
const float	Result::m_button_base_scale = 1.0f;	// ボタンの拡大率の初期値 
const float	Result::m_button_max_scale = 1.4f;	// ボタンの最大拡大率

Result::Result(void)
	:m_ButtonFlag(true)
{
}

void Result::Initialize(void)
{
	m_Score = new int[m_max_player];





	m_ButtonPosition[0] = { vivid::WINDOW_WIDTH / 2 - 145, vivid::WINDOW_HEIGHT / 1.4 }; //キャラクターセレクトに戻るほうのボタンのポジション
	m_ButtonPosition[1] = { vivid::WINDOW_WIDTH / 2 - 150, vivid::WINDOW_HEIGHT / 1.2 };	//やめるのボタンのポジション
	m_ButtonAnchor = { 155,40 };													//ボタンの基準点

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < m_max_player; j++)
		{
			m_Score[i] = 0.0f;
			//use_character[i][j].x = vivid::WINDOW_WIDTH / 3 + i * m_tuna_width;
			//use_character[i][j].y = vivid::WINDOW_HEIGHT / 4 + j * m_tuna_height;

			m_TextPosition[j].x = vivid::WINDOW_WIDTH / 6;										// 「使用キャラクター」文字列のx軸
			m_TextPosition[j].y = use_character[i][j].y + m_tuna_height / 2.0f - 25 / 2.0f;			// 「使用キャラクター」文字列のy軸

			m_ScorePosition[j].x = vivid::WINDOW_WIDTH / 2 + vivid::WINDOW_WIDTH / 3;					// 得点のx軸
			m_ScorePosition[j].y = use_character[i][j].y + m_tuna_height / 2.0f - m_height / 2.0f;		// 得点のy軸
		}
	}

	//ボタンの個数
	for (int i = 0; i < m_max_button; i++)
	{
		m_ButtonRect[i] = { 0,0,310,80 };		//ボタンの範囲
	}

	m_BackGroundPosition = { 0.0f,0.0f };//背景ポジションの初期化
	m_CharacterSelectScale = { 1.2f,1.1f };//キャラクターセレクトに戻るほうのボタンの大きさ
	m_ExitScale = { 0.8f,0.8f };//「やめる」ボタンの大きさ

	m_FramePosition = { vivid::WINDOW_WIDTH / 2 - 145, vivid::WINDOW_HEIGHT / 1.4 };		//外枠の位置
	m_FrameAnchor = { 155,40 };
	m_FrameScale = { 1.2f,1.1f };
	m_FrameRect = { 0,0,310,80 };
}

void Result::Update(void)
{
	namespace keyboard = vivid::keyboard;

	if (keyboard::Trigger(keyboard::KEY_ID::W))//キャラクター選択画面にもどるのボタン
	{
		m_CharacterSelectScale = { m_button_max_scale,m_button_max_scale };//キャラクターセレクトを選択しているときの大きさ
		m_ExitScale = { m_button_base_scale,m_button_base_scale };//やめるのボタンの拡大率を戻す時の大きさ
		m_FramePosition = { vivid::WINDOW_WIDTH / 2 - 145, vivid::WINDOW_HEIGHT / 1.4 };		//キャラクターセレクトのポジションの合わせる外枠の位置
		m_FrameScale = { m_button_max_scale,m_button_max_scale };
		m_ButtonFlag = true;
	}
	if (keyboard::Trigger(keyboard::KEY_ID::S))//やめるのボタン
	{
		m_CharacterSelectScale = { m_button_base_scale,m_button_base_scale };	//キャラクターセレクトの拡大率を戻すときの大きさ
		m_ExitScale = { m_button_max_scale,m_button_max_scale };				//やめるのボタンを選択している時の大きさ
		m_FramePosition = { vivid::WINDOW_WIDTH / 2 - 150, vivid::WINDOW_HEIGHT / 1.2 };	//やめるのボタンのポジションに合わせる外枠
		m_FrameScale = { m_button_base_scale,m_button_base_scale };				//Sキーを押したときの外枠の拡大率
		m_ButtonFlag = false;
	}

	if (keyboard::Trigger(keyboard::KEY_ID::RETURN))//ENTERを押した時の処理
	{

		if (m_ButtonFlag)//Wボタンのとき
		{
			SceneManager::GetInstance().Change_scene(SCENE_ID::GAMEMAIN);
			ScoreManager::GetInstance().Initialize();
		}

		else//Sボタンのとき
		{

			SceneManager::GetInstance().Change_scene(SCENE_ID::TITLE);
		}

	}

//#ifdef VIVID_DEBUG
	// Zキーでシーン変更
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::TITLE);
//#endif
}

void Result::Draw(void)
{
	vivid::CreateFont(25, 1);

#ifdef VIVID_DEBUG
	vivid::DrawTexture("data\\Seabackground2.png", m_BackGroundPosition, 0xffffffff);
	vivid::DrawText(24, "result", vivid::Vector2(0.0f, 0.0f));

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

		vivid::DrawText(25, "使用キャラクター", m_TextPosition[i]);
	}

	for (int x = 0; x < 3; x++)
		for (int y = 0; y < m_max_player; y++)
			vivid::DrawTexture("data\\Tuna.png", m_UseCharacterPosition[x][y]);

	vivid::DrawTexture("data\\back_character_select.png", m_ButtonPosition[0], 0xffffffff, m_ButtonRect[0], m_ButtonAnchor, m_CharacterSelectScale);
	vivid::DrawTexture("data\\exit.png", m_ButtonPosition[1], 0xffffffff, m_ButtonRect[1], m_ButtonAnchor, m_ExitScale);//リザルトボタンの描画
	vivid::DrawTexture("data\\select_frame.png", m_FramePosition, 0xffffffff, m_FrameRect, m_FrameAnchor, m_FrameScale);//外枠の描画

	vivid::DrawText(50, "ランキング", vivid::Vector2(vivid::WINDOW_WIDTH / 2 - 125, vivid::WINDOW_HEIGHT / 10), 0xff000000);

#endif
}

void Result::Finalize(void)
{
}
