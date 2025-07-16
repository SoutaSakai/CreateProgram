#include "score_manager.h"
const int ScoreManager::m_width = 32;//number��̕�

const int ScoreManager::m_height = 48;//number��̍���

const int ScoreManager::point = 10;//�|�C���g��

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

	//{0.0f + m_height * 5,0.0f},/*Player1�X�R�A*/
	///*528*/	{(vivid::WINDOW_WIDTH / 2) / 2 + m_height,0.0f},/*Player2�X�R�A*/
	//{(vivid::WINDOW_WIDTH - (vivid::WINDOW_WIDTH / 2 / 2 + m_height)) ,0.0f},/*Player3�X�R�A*/
	//{vivid::WINDOW_WIDTH - m_height * 5,0.0f }/*Player4�X�R�A*/
	//};
}

void ScoreManager::Update(void)
{
	namespace keyboard = vivid::keyboard;

	if (Time::GetInstance().GetFlag())
	{
		if (Time::GetInstance().GetTimer() > 1)//�^�C�����O���傫��
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

			vivid::DrawTexture("data\\number.png", position, 0xffffffff, rect);//�v���C���[�̃X�R�A�\��

		} while (m_score[i] > 0);
	}


	if (Time::GetInstance().GetTimer() <= 1)
	{
		vivid::DrawTexture("data\\button.png", m_button_pos, 0xffffffff, m_rect, m_anchor, m_scale);
		vivid::DrawText(25, "���U���g(ENTER�{�^���������Ă�)", vivid::Vector2(m_button_pos.x + 225 - (25 * 8), m_button_pos.y + 50 - 12.5), 0xffffffff);

		if (keyboard::Button(keyboard::KEY_ID::RETURN))//RETURN�̓G���^�[
		{
			SCENE_MANAGER::GetInstance().Change_scene(SCENE_ID::RESULT);
		}
	}





}

void ScoreManager::Finalize(void)
{
}

int ScoreManager::GetScore(int a)//���U���g�̂ق��ɃX�R�A��n���Ă�
{
	return score[a];
}









