#include "score_manager.h"
const int ScoreManager::m_width = 32;//number一つの幅

const int ScoreManager::m_height = 48;//number一つの高さ

const int ScoreManager::m_point = 10;//ポイントの加算値、減算値

ScoreManager& ScoreManager::GetInstance(void)
{
	static ScoreManager instance;

	return instance;
}

void ScoreManager::Initialize(void)
{
	for (int i = 0; i < m_max_player; i++)
	{
		m_PlayerPosition[i] = 0;
		m_Score[i] = 0;

		if (i <= 1)
		{
			m_ScorePosition[i].x = (i + 1) * (vivid::WINDOW_WIDTH / 6);
		}
		else
		{
			m_ScorePosition[i].x = (i + 2) * (vivid::WINDOW_WIDTH / 6);
		}
	}

	m_Rect = { 0,0,450,100 };
	m_Anchor = { 225,50 };
	m_Scale = { 1.3,1.3 };
	m_ButtonPosition = { vivid::WINDOW_WIDTH / 2 - 225,vivid::WINDOW_HEIGHT / 2 };

	//{0.0f + m_height * 5,0.0f},/*Player1スコア*/
	///*528*/	{(vivid::WINDOW_WIDTH / 2) / 2 + m_height,0.0f},/*Player2スコア*/
	//{(vivid::WINDOW_WIDTH - (vivid::WINDOW_WIDTH / 2 / 2 + m_height)) ,0.0f},/*Player3スコア*/
	//{vivid::WINDOW_WIDTH - m_height * 5,0.0f }/*Player4スコア*/
	//};
}

void ScoreManager::Update(void)
{
	namespace keyboard = vivid::keyboard;

	if (Time::GetInstance().GetFlag())
	{
		if (Time::GetInstance().GetTimer() > 1)//タイムが０より大きい
		{
			if (keyboard::Trigger(keyboard::KEY_ID::W))
			{
				m_Score[0] += m_point;
			}
			if (keyboard::Trigger(keyboard::KEY_ID::A))
			{
				m_Score[1] += m_point;
			}
			if (keyboard::Trigger(keyboard::KEY_ID::S))
			{
				m_Score[2] += m_point;
			}
			if (keyboard::Trigger(keyboard::KEY_ID::D))
			{
				m_Score[3] += m_point;
			}
		}
	}
}

void ScoreManager::Draw(void)
{
	namespace keyboard = vivid::keyboard;

	int m_TempScore[m_max_player] = { 0 };	//スコアの仮の変数

	int digit[m_max_player] = { 0 };

	vivid::Rect rect = { 0,0,0,0 };

	for (int i = 0; i < m_max_player; i++)
	{
		vivid::Vector2 position = m_ScorePosition[i];

		m_TempScore[i] = m_Score[i];

		do
		{
			digit[i] = m_TempScore[i] % 10;


			rect.left = digit[i] * m_width;
			rect.right = rect.left + m_width;
			rect.top = 0;
			rect.bottom = m_height;


			m_TempScore[i] /= 10;

			position.x -= m_width;

			vivid::DrawTexture("data\\number.png", position, 0xffffffff, rect);//プレイヤーのスコア表示

		} while (m_TempScore[i] > 0);
	}


	if (Time::GetInstance().GetTimer() <= 1)
	{
		vivid::DrawTexture("data\\button.png", m_ButtonPosition, 0xffffffff, m_Rect, m_Anchor, m_Scale);
		vivid::DrawText(25, "リザルト(ENTERボタンを押してね)", vivid::Vector2(m_ButtonPosition.x + 225 - (25 * 8), m_ButtonPosition.y + 50 - 12.5), 0xffffffff);

		//RETURNはエンター
		if (keyboard::Button(keyboard::KEY_ID::RETURN))
		{
			SceneManager::GetInstance().Change_scene(SCENE_ID::RESULT);
		}
	}
}

void ScoreManager::Finalize(void)
{
}

int ScoreManager::GetScore(int a)//リザルトのほうにスコアを渡してる
{
	return m_Score[a];
}









