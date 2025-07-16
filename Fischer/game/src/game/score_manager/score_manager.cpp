#include "score_manager.h"
const int ScoreManager::m_width = 32;//number一つの幅

const int ScoreManager::m_height = 48;//number一つの高さ

const int ScoreManager::point = 10;//ポイントの

ScoreManager& ScoreManager::GetInstance(void)
{
	static ScoreManager instance;

	return instance;
}

void ScoreManager::Initialize(void)
{

	for (int i = 0; i < max_player; i++)
	{
		ppos[i] = 0;
	}

	for (int i = 0; i < max_player; i++)
	{
		score[i] = 0;
	}

	for (int i = 0; i < max_player; i++)
	{
		m_score[i] = 0;
	}

	for (int i = 0; i < max_player; i++)
	{

		if (i <= 1)
		{
			Score_pos[i].x = (i + 1) * (vivid::WINDOW_WIDTH / 6);
		}
		else
		{
			Score_pos[i].x = (i + 2) * (vivid::WINDOW_WIDTH / 6);
		}

	}

	m_rect = { 0,0,450,100 };
	m_anchor = { 225,50 };
	m_scale = { 1.3,1.3 };
	m_button_pos = { vivid::WINDOW_WIDTH / 2 - 225,vivid::WINDOW_HEIGHT / 2 };

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
				score[0] += point;
			}

			if (keyboard::Trigger(keyboard::KEY_ID::A))
			{
				score[1] += point;
			}
			if (keyboard::Trigger(keyboard::KEY_ID::S))
			{
				score[2] += point;
			}
			if (keyboard::Trigger(keyboard::KEY_ID::D))
			{
				score[3] += point;
			}
		}
	}
}

void ScoreManager::Draw(void)
{
	namespace keyboard = vivid::keyboard;


	int m_score[max_player] = { 0 };

	int digit[max_player] = { 0 };

	vivid::Rect rect = { 0,0,0,0 };

	for (int i = 0; i < max_player; i++)
	{
		vivid::Vector2 position = Score_pos[i];

		m_score[i] = score[i];

		do
		{
			digit[i] = m_score[i] % 10;

			rect.left = digit[i] * m_width;

			rect.right = rect.left + m_width;

			rect.top = 0;

			rect.bottom = m_height;

			m_score[i] /= 10;

			position.x -= m_width;

			vivid::DrawTexture("data\\number.png", position, 0xffffffff, rect);//プレイヤーのスコア表示

		} while (m_score[i] > 0);
	}


	if (Time::GetInstance().GetTimer() <= 1)
	{
		vivid::DrawTexture("data\\button.png", m_button_pos, 0xffffffff, m_rect, m_anchor, m_scale);
		vivid::DrawText(25, "リザルト(ENTERボタンを押してね)", vivid::Vector2(m_button_pos.x + 225 - (25 * 8), m_button_pos.y + 50 - 12.5), 0xffffffff);

		if (keyboard::Button(keyboard::KEY_ID::RETURN))//RETURNはエンター
		{
			SCENE_MANAGER::GetInstance().Change_scene(SCENE_ID::RESULT);
		}
	}





}

void ScoreManager::Finalize(void)
{
}

int ScoreManager::GetScore(int a)//リザルトのほうにスコアを渡してる
{
	return score[a];
}









