#include "Time.h"
#include<DxLib.h>
#include"../score_manager/score_manager.h"
#include "time_manager.h"

const float Time::m_number_width = 32.0f;		//数字の幅

const float Time::m_number_height = 48.0f;	//数字の高さm_height = 48;//画像サイズの高さ

const float Time::m_word_width = 30.0f;		//「Time」文字列の幅m__width = 30;//画像サイズの幅

const float Time::m_word_height = 50.0f;		//「Time」文字列の高さm__height = 50;//画像サイズの高さ

namespace keyboard = vivid::keyboard;



Time& Time::GetInstance(void)
{
	static Time instance;

	return instance;
}

void Time::Initialize(void)
{
	Start_pos = { vivid::WINDOW_WIDTH / 2 - m_number_width / 2,vivid::WINDOW_HEIGHT / 2 - m_number_height };//スタートの描画ポジション

	StartTimer = 4.0f;

	Draw_flag = true;//スタートを出す消す処理

	start_flag = false;//スタートフラグがfalseの間はtimerが更新されないtrueの時はtimerが減る

	Timer = 10.0f;
}

void Time::Update(void)
{
	StartTimer -= vivid::GetDeltaTime();

	if (Draw_flag)
	{

		if (StartTimer <= 0)//スタートタイマーが０秒以上になったらDraw_flagをfalseにする
		{
			Draw_flag = false;

		}

	}

	if (start_flag == true)//スタートが機能したら
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
			vivid::DrawText(40, "スタート！！", vivid::Vector2(vivid::WINDOW_WIDTH / 2 - 100, vivid::WINDOW_HEIGHT / 2 - 20));
		}


	}
	else if (Draw_flag == false)
	{
		start_flag = true;
	}

	do
	{
		int m_digit = start;//スタート出るまでの処理

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


	float m_cnt = 0;//何桁かの処理

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





