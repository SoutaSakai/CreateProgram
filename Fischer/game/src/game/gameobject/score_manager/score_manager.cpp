#include "score_manager.h"
#include "..\scene_manager\scene_manager.h"
#include "..\player_manager\player_manager.h"

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

	//{0.0f + m_height * 5,0.0f},/*Player1スコア*/
	///*528*/	{(vivid::WINDOW_WIDTH / 2) / 2 + m_height,0.0f},/*Player2スコア*/
	//{(vivid::WINDOW_WIDTH - (vivid::WINDOW_WIDTH / 2 / 2 + m_height)) ,0.0f},/*Player3スコア*/
	//{vivid::WINDOW_WIDTH - m_height * 5,0.0f }/*Player4スコア*/
	//};
}

void ScoreManager::Update(void)
{
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

		m_TempScore[i] = abs(m_Score[i]);

		vivid::Vector2 m_MinusPosition = { 0.0f,0.0f };

		do
		{
			digit[i] = m_TempScore[i] % 10;


			rect.left = digit[i] * m_width;
			rect.right = rect.left + m_width;
			rect.top = 0;
			rect.bottom = m_height;

			m_TempScore[i] /= 10;

			position.x -= m_width;

			if (m_TempScore[i] <= 0)
				m_MinusPosition = position;
			
			vivid::DrawTexture("data\\number.png", position, 0xffffffff, rect);//プレイヤーのスコア表示

		} while (m_TempScore[i] > 0);

		if (m_Score[i] < 0)
		{
			m_MinusPosition = { m_MinusPosition.x - 40.0f, m_MinusPosition.y };
			vivid::DrawTexture("data\\minus.png", m_MinusPosition);
		}
	}
}

void ScoreManager::Finalize(void)
{
}

int ScoreManager::GetRoundScore(int number)
{
	return m_Score[number];
}

int ScoreManager::GetScore(int a)//スコア取得
{
	int work = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < m_max_player; j++)
		{
			if (m_Score[i] < m_Score[i + 1])
			{
				work = m_Score[i + 1];
				m_Score[i + 1] = m_Score[i];
				m_Score[i] = work;

			}
		}
	}
	return m_Score[a];
}

int ScoreManager::GetPlayer(int a)
{

	int rank[4] = { 0,1,2,3 };
	int work = 0;
	int box[4];

	for (int i = 0; i < m_max_player; i++)
		box[i] = m_Score[i];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3 - i; j++)
		{
			if (box[j] < box[j + 1])
			{
				work = box[j];
				box[j] = box[j + 1];
				box[j + 1] = work;

				work = rank[j];
				rank[j] = rank[j + 1];
				rank[j + 1] = work;

			}
		}
	}

	return rank[a];

}

int ScoreManager::GetRank(int a)
{
	int rank[4] = { 0,1,2,3 };
	int work = 0;
	int box[4];

	for (int i = 0; i < m_max_player; i++)
	{
		box[i] = m_Score[i];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3 - i; j++)
		{
			if (box[j] < box[j + 1])
			{
				work = box[j];
				box[j] = box[j + 1];
				box[j + 1] = work;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (box[i] == box[i + 1])
		{
			rank[i + 1] = rank[i];
		}
	}
	return rank[a];

}

void ScoreManager::AddScore(int score, int num)
{
	m_Score[num] += score;
}
