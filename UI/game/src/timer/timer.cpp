#include "timer.h"
#include<DxLib.h>


const int TIME::Max_pos = 3;



const int TIME::m_width = 32;//画像一個サイズの幅

const int TIME::m_height = 48;//画像サイズの高さ




TIME::TIME(void)
	
{

}

void TIME::Initialize(void)

{
	timer = 102.0f;

}

void TIME::Update(void)

{
	
	timer -= vivid::GetDeltaTime();


}

void TIME::Draw(const vivid::Vector2 &position)

{
	vivid::Rect rect = { };

	

	vivid::Vector2 pos = {vivid::WINDOW_WIDTH/2.0f,0.0f};

	pos.x -= m_width / 2;


	int m_time = timer;

	

	int cnt = 0;

	do
	{

		 m_time/= 10.0f;


		cnt++;
		

	} while (m_time / 10 > 0);

	pos.x += m_width*(cnt / 2);
	
	m_time = timer;
	do
	{
	

		int digit = m_time % 10;

		rect.left = digit * m_width;

		rect.right = rect.left + m_width;

		rect.top = 0;

		rect.bottom = m_height;

		m_time /= 10.0f;

		
		
		vivid::DrawTexture("data\\number.png", pos, 0xffffffff, rect);
		pos.x -= m_width;
		

	} while (m_time>0);

	DxLib::DrawLine(vivid::WINDOW_WIDTH / 2, 0, vivid::WINDOW_WIDTH / 2, vivid::WINDOW_HEIGHT, 0xffffffff);



	/*int number = 324;
	int a, b;
	
	

	

	a = number / 100;
	number %= 100;
	b = number / 10;
	number %= 10;*/

	
	//vivid::DrawTexture("data\\number.png", vivid::Vector2(vivid::WINDOW_WIDTH / 2 - m_width/*-(m_width*3)*/, 0.0f));
	//vivid::DrawTexture("data\\number.png", vivid::Vector2(vivid::WINDOW_WIDTH / 2 /*- (m_width * 2)*/, 0.0f));
	//vivid::DrawTexture("data\\number.png", vivid::Vector2(vivid::WINDOW_WIDTH / 2 + m_width /*- (m_width * 1)*/, 0.0f));
	

}

void TIME::Finalize(void)

{

}

