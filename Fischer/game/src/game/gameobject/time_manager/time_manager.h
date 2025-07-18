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



private:

	vivid::Rect rect;

	static const float m_number_width;		//�����̕�

	static const  float m_number_height;	//�����̍���

	static const float m_word_width;		//�uTime�v������̕�

	static const float m_word_height;		//�uTime�v������̍���

	float StartTimer;

	float Timer;

	vivid::Vector2 Start_pos;//�X�^�[�g�̃|�W�V����

	bool Draw_flag;

	bool start_flag;

	Time(void) = default;

	~Time(void) = default;

	Time(const Time& rhs) = delete;

	Time& operator=(const Time& rhs) = delete;





};
