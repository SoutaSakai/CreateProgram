#include "Time.h"
#include<DxLib.h>
#include"../score_manager/score_manager.h"
#include "time_manager.h"

const float Time::m_number_width = 32.0f;		//�����̕�

const float Time::m_number_height = 48.0f;	//�����̍���m_height = 48;//�摜�T�C�Y�̍���

const float Time::m_word_width = 30.0f;		//�uTime�v������̕�m__width = 30;//�摜�T�C�Y�̕�

const float Time::m_word_height = 50.0f;		//�uTime�v������̍���m__height = 50;//�摜�T�C�Y�̍���

namespace keyboard = vivid::keyboard;



Time& Time::GetInstance(void)
{
	static Time instance;

	return instance;
}

void Time::Initialize(void)
{
	Start_pos = { vivid::WINDOW_WIDTH / 2 - m_number_width / 2,vivid::WINDOW_HEIGHT / 2 - m_number_height };//�X�^�[�g�̕`��|�W�V����

	StartTimer = 4.0f;

	Draw_flag = true;//�X�^�[�g���o����������

	start_flag = false;//�X�^�[�g�t���O��false�̊Ԃ�timer���X�V����Ȃ�true�̎���timer������

	Timer = 10.0f;
}

void Time::Update(void)
{
	StartTimer -= vivid::GetDeltaTime();

	if (Draw_flag)
	{

		if (StartTimer <= 0)//�X�^�[�g�^�C�}�[���O�b�ȏ�ɂȂ�����Draw_flag��false�ɂ���
		{
			Draw_flag = false;

		}

	}

	if (start_flag == true)//�X�^�[�g���@�\������
	{
		Timer -= vivid::GetDeltaTime();

		if (Timer <= 0)
		{
			Timer = 0;
		}
	}
}

void Time::Draw(void)
{
	vivid::Vector2 Start_position = Start_pos;
	int start = StartTimer;

	if (Draw_flag)
	{
		if (StartTimer <= 1)
		{
			vivid::DrawText(40, "�X�^�[�g�I�I", vivid::Vector2(vivid::WINDOW_WIDTH / 2 - 100, vivid::WINDOW_HEIGHT / 2 - 20));
		}


	}
	else if (Draw_flag == false)
	{
		start_flag = true;
	}

	do
	{
		int m_digit = start;//�X�^�[�g�o��܂ł̏���

		rect.left = m_digit * m_number_width;

		rect.right = rect.left + m_number_width;

		rect.top = 0;

		rect.bottom = m_number_height;

		start /= 10.0f;

		if (StartTimer >= 1)
		{
			vivid::DrawTexture("data\\number.png", Start_position, 0xffffffff, rect);
		}



	} while (start > 0);

	vivid::Rect rect = { };

	vivid::Vector2 pos = { vivid::WINDOW_WIDTH / 2.0f,m_word_height };

	vivid::Vector2 pos2 = { (vivid::WINDOW_WIDTH / 2.0f) - m_word_width * 2,0.0f };

	int m_timer = Timer;


	float m_cnt = 0;//�������̏���

	do
	{
		m_timer /= 10.0f;

		m_cnt++;

	} while (m_timer > 0);

	pos.x += m_number_width * (m_cnt / 2) - m_number_width;

	m_timer = Timer;

	do
	{
		int digit = m_timer % 10;

		rect.left = digit * m_number_width;

		rect.right = rect.left + m_number_width;

		rect.top = 0;

		rect.bottom = m_number_height;

		m_timer /= 10.0f;


		vivid::DrawTexture("data\\number.png", pos, 0xffffffff, rect);

		pos.x -= m_number_width;


	} while (m_timer > 0);

	vivid::DrawTexture("data\\time.png", pos2, 0xffffffff);
}

void Time::Finalize(void)
{

}

float Time::GetTimer(void)
{
	return Timer;
}

bool Time::GetFlag(void)
{
	return  start_flag;
}





