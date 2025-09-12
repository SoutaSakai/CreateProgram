#pragma once
#pragma once
#include"vivid.h"


class CTimeManager
{
public:
	static CTimeManager& GetInstance(void);

	void Initialize(void);

	void Update(void);

	void Draw(void);

	void Finalize(void);

	float GetTimer(void);//timerを返す関数

	void SetTimer(void);

	bool GetFlag(void);//start_flagを返す関数

	bool Finish(void);

private:

	static const float m_number_width;		//数字の幅
	static const float m_number_height;		//数字の高さ
	static const float m_word_width;		//「Time」文字列の幅
	static const float m_word_height;		//「Time」文字列の高さ
	static const float m_round_time;		// 1ラウンド分の時間

	float m_StartTimer;
	float m_Timer;

	vivid::Vector2 m_StartPosition;//スタートのポジション
	vivid::Rect m_Rect;

	bool m_DrawFlag;
	bool m_StartFlag;

	CTimeManager(void) = default;

	~CTimeManager(void) = default;

	CTimeManager(const CTimeManager& rhs) = delete;

	CTimeManager& operator=(const CTimeManager& rhs) = delete;
};
