#include "bubble.h"
#include"../bubble_manager.h"
#include"../../scene_manager/scene/result/result.h"
const  vivid::Vector2 CBubble::m_small_bubble_scale = { 0.2f,0.2f };		//¬‚³‚¢–A
const  vivid::Vector2 CBubble::m_middle_bubble_scale = { 0.6f,0.6f };		//’†‚­‚ç‚¢‚Ì–A
const  vivid::Vector2 CBubble::m_large_bubble_scale = { 0.8f,0.8f };		//‘å‚«‚¢–A
const    int CBubble::m_max_bubble = 3;										//–A‚ÌãŒÀ
const    int CBubble::m_bubble_speed = 5.0f;								//–A‚ÌƒXƒs[ƒh


CBubble::CBubble(void)
	:m_Position(vivid::Vector2(0.0f, 0.0f))
	, m_Velocity(vivid::Vector2(0.0f, 0.0f))
	, m_Anchor(vivid::Vector2(0.0f, 0.0f))
	, m_Rect{ (0,0,m_Width,m_Height) }
	, m_Scale(vivid::Vector2(1.0f, 1.0f))
	, m_First_Position((vivid::Vector2(0.0f, 0.0f)))
	, m_Rotation(0.0f)
	, m_BubbleColor(0xffffffff)

	, m_AcitveFlag(true)
	, m_Per(0)
	, m_file_path("")
	, m_BubbleCnt(0)
{
}


CBubble::~CBubble(void)
{

}

void CBubble::Initialize(void)
{
	m_Per = rand() % 10;

	if (m_Per >= 0 && m_Per <= 4)
	{
		m_Scale = m_small_bubble_scale;
		/*	m_file_path = "data\\smallbubble.png";*/

	}
	else if (m_Per > 4 && m_Per < 9)
	{
		m_Scale = m_middle_bubble_scale;
		/*m_file_path = "data\\mediumbubble.png";*/
	}
	else
	{
		m_Scale = m_large_bubble_scale;
	}

	m_Width = 120;
	m_Height = 120;
	m_Position = { 0.0f,0.0f };

	m_file_path = "data\\largebubble.png";
	m_Anchor = (vivid::Vector2((float)m_Width / 2.0f, (float)m_Height / 2.0f));
	m_Rect = { 0,0,m_Width,m_Height };
	m_AcitveFlag = true;
	m_Per = 0;
	m_Bubble_Timer = rand() % 3 + 1;
	if (rand() % 2 == 0)
		m_Bubble_Timer *= -1;
}

void CBubble::Update()
{
	m_Bubble_Timer += 0.1;
	m_Position.x += cos(m_Bubble_Timer) * 10;
	m_Position.y -= m_bubble_speed;
	for (int i = 0; i < 4; i++)
	{
		if (m_BubbleColor > 0x01000000)
		{
			m_BubbleColor -= 0x01000000;
		}
		else
		{
			m_BubbleColor = 0x00000000;
			m_AcitveFlag = false;
		}
	}

}


void CBubble::Draw(void)
{

	vivid::DrawTexture(m_file_path, m_Position, m_BubbleColor, m_Rect, m_Anchor, m_Scale);

}

void CBubble::Finalize(void)
{

}

bool CBubble::GetActive(void)
{
	return m_AcitveFlag;
}

vivid::Vector2 CBubble::GetPosition(void)
{
	namespace keyboard = vivid::keyboard;



	if (keyboard::Trigger(keyboard::KEY_ID::A))
	{
		m_Position.x = ((vivid::WINDOW_WIDTH / 2 - 310 / 2 - 240) + rand() % 310) - m_Width / 2;
		m_Position.y = ((vivid::WINDOW_HEIGHT / 7 * 5.5) + rand() % 80) - m_Height / 2;

	}
	if (keyboard::Trigger(keyboard::KEY_ID::D))
	{
		m_Position.x = ((vivid::WINDOW_WIDTH / 2 - 310 / 2 + 240) + rand() % 310) - m_Width / 2;
		m_Position.y = ((vivid::WINDOW_HEIGHT / 7 * 5.5) + rand() % 80) - m_Width / 2;

	}

	return m_Position;
}




