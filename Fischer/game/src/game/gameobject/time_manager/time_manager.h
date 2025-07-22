#pragma once
#pragma once
#include"vivid.h"


class Time
{
public:
	static Time& GetInstance(void);

	void Initialize(void);

	void Update(void);

	void Draw(void);

	void Finalize(void);

	float GetTimer(void);//timerを返す関数

	bool GetFlag(void);//start_flagを返す関数

	bool Finish(void);

private:

	static const float m_number_width;		//数字の幅
	static const float m_number_height;		//数字の高さ
	static const float m_word_width;		//「Time」文字列の幅
	static const float m_word_height;		//「Time」文字列の高さ


	float m_StartTimer;
	float m_Timer;

	vivid::Vector2 m_StartPosition;//スタートのポジション
	vivid::Rect m_Rect;

	bool m_DrawFlag;
	bool m_StartFlag;

	Time(void) = default;

	~Time(void) = default;

	Time(const Time& rhs) = delete;

	Time& operator=(const Time& rhs) = delete;





};
