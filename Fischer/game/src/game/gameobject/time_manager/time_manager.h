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

	float GetTimer(void);//timer��Ԃ��֐�

	bool GetFlag(void);//start_flag��Ԃ��֐�

	bool Finish(void);

private:

	static const float m_number_width;		//�����̕�
	static const float m_number_height;		//�����̍���
	static const float m_word_width;		//�uTime�v������̕�
	static const float m_word_height;		//�uTime�v������̍���


	float m_StartTimer;
	float m_Timer;

	vivid::Vector2 m_StartPosition;//�X�^�[�g�̃|�W�V����
	vivid::Rect m_Rect;

	bool m_DrawFlag;
	bool m_StartFlag;

	Time(void) = default;

	~Time(void) = default;

	Time(const Time& rhs) = delete;

	Time& operator=(const Time& rhs) = delete;





};
