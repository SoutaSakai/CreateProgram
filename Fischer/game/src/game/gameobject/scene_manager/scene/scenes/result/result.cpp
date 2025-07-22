#include "..\..\..\scene_manager.h"
#include "..\scene_id.h"
#include "result.h"
#include "vivid.h"

const int RESULT::m_width = 32;//number一つの幅
const int RESULT::m_height = 48;//number一つの高さ
const int RESULT::tuna_width = 220;//マグロのサイズの幅
const int RESULT::tuna_height = 80;//マグロのサイズの高さ

Result::Result(void)
	:button_flag(true)
{
}

void Result::Initialize(void)
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < max_player; y++)
		{

			point[x] = 0.0f;
			m_point[x] = 0.0f;
			m_digit[x] = 0.0f;
			use_character[x][y].x = vivid::WINDOW_WIDTH / 3 + x * tuna_width;
			use_character[x][y].y = vivid::WINDOW_HEIGHT / 4 + y * tuna_height;

			use_drawtext[y].x = vivid::WINDOW_WIDTH / 6;										//使用キャラクターのx軸
			use_drawtext[y].y = use_character[x][y].y + tuna_height / 2.0f - 25 / 2.0f;			//使用キャラクターのy軸

			point_pos[y].x = vivid::WINDOW_WIDTH / 2 + vivid::WINDOW_WIDTH / 3;					//得点のx軸
			point_pos[y].y = use_character[x][y].y + tuna_height / 2.0f - m_height / 2.0f;		//得点のy軸

			result_button_pos[0] = { vivid::WINDOW_WIDTH / 2 - 145, vivid::WINDOW_HEIGHT / 1.4 }; //キャラクターセレクトに戻るほうのボタンのポジション
			result_button_pos[1] = { vivid::WINDOW_WIDTH / 2 - 150, vivid::WINDOW_HEIGHT / 1.2 };	//やめるのボタンのポジション




			for (int i = 0; i < button; i++)//ボタンの個数
			{
				result_rect[i] = { 0,0,310,80 };												//ボタンの範囲
				result_anchor[i] = { 155,40 };													//ボタンの基準点
				word_color[i] = 0xffffffff;//ボタン２つの文字の色
			}

		}
	}


	back_ground = { 0.0f,0.0f };//背景ポジションの初期化
	result_character_select_scale = { 1.2f,1.1f };//キャラクターセレクトに戻るほうのボタンの大きさ
	result_exit_scale = { 0.8f,0.8f };//やめるのボタンの大きさ

	select_frame_pos = { vivid::WINDOW_WIDTH / 2 - 145, vivid::WINDOW_HEIGHT / 1.4 };		//外枠の位置
	select_frame_rect = { 0,0,310,80 };
	select_frame_anchor = { 155,40 };
	select_frame_scale = { 1.2f,1.1f };
}

void Result::Update(void)
{
	namespace keyboard = vivid::keyboard;

	if (keyboard::Trigger(keyboard::KEY_ID::W))//キャラクター選択画面にもどるのボタン
	{
		result_character_select_scale = { 1.4f,1.1f };//キャラクターセレクトを選択しているときの大きさ
		result_exit_scale = { 0.8f,0.8f };//やめるのボタンの拡大率を戻す時の大きさ
		select_frame_pos = { vivid::WINDOW_WIDTH / 2 - 145, vivid::WINDOW_HEIGHT / 1.4 };		//キャラクターセレクトのポジションの合わせる外枠の位置

		select_frame_scale = { 1.4f,1.1f };

		button_flag = true;

	}




	if (keyboard::Trigger(keyboard::KEY_ID::S))//やめるのボタン
	{
		result_exit_scale = { 1.0f,1.0f };				//やめるのボタンを選択している時の大きさ
		result_character_select_scale = { 1.2f,1.1f };	//キャラクターセレクトの拡大率を戻すときの大きさ
		select_frame_pos = { vivid::WINDOW_WIDTH / 2 - 150, vivid::WINDOW_HEIGHT / 1.2 };	//やめるのボタンのポジションに合わせる外枠
		select_frame_scale = { 1.0f,1.0f };				//Sキーを押したときの外枠の拡大率
		button_flag = false;
	}




	if (keyboard::Trigger(keyboard::KEY_ID::RETURN))//ENTERを押した時の処理
	{

		if (button_flag)//Wボタンのとき
		{
			SCENE_MANAGER::GetInstance().Change_scene(SCENE_ID::GAMEMAIN);
			ScoreManager::GetInstance().Initialize();
		}

		else//Sボタンのとき
		{

			SCENE_MANAGER::GetInstance().Change_scene(SCENE_ID::TITLE);
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
	vivid::DrawTexture("data\\Seabackground2.png", back_ground, 0xffffffff);
	vivid::DrawText(24, "result", vivid::Vector2(0.0f, 0.0f));


	vivid::Rect rect = { 0,0,0,0 };



	for (int i = 0; i < max_player; i++)
	{
		point[i] = ScoreManager::GetInstance().GetScore(i);

		m_point[i] = point[i];

		vivid::Vector2 m_point_pos = point_pos[i];



		//ポイントの表示の計算

		do
		{
			m_digit[i] = m_point[i] % 10;

			rect.left = m_digit[i] * m_width;

			rect.right = rect.left + m_width;

			rect.top = 0;

			rect.bottom = m_height;

			m_point[i] /= 10;

			m_point_pos.x -= m_width;

			vivid::DrawTexture("data\\number.png", m_point_pos, 0xffffffff, rect);

		} while (m_point[i] > 0);

		vivid::DrawText(25, "使用キャラクター", use_drawtext[i]);



	}

	for (int x = 0; x < 3; x++)
		for (int y = 0; y < max_player; y++)
			vivid::DrawTexture("data\\Tuna.png", use_character[x][y]);

	vivid::DrawTexture("data\\back_character_select.png", result_button_pos[0], 0xffffffff, result_rect[0], result_anchor[0], result_character_select_scale);
	vivid::DrawTexture("data\\exit.png", result_button_pos[1], 0xffffffff, result_rect[1], result_anchor[1], result_exit_scale);//リザルトボタンの描画
	vivid::DrawTexture("data\\select_frame.png", select_frame_pos, 0xffffffff, select_frame_rect, select_frame_anchor, select_frame_scale);//外枠の描画

	vivid::DrawText(50, "ランキング", vivid::Vector2(vivid::WINDOW_WIDTH / 2 - 125, vivid::WINDOW_HEIGHT / 10), 0xff000000);

#endif
}

void Result::Finalize(void)
{
}
