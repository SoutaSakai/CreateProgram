#pragma once
#include"vivid.h"


class TIME
{
public:
	TIME(void);
	void Initialize(void);

	void Update(void);

	void Draw(const vivid::Vector2 &position);

	void Finalize(void);


private:

	static const int Max_pos;//	�ő�|�W�V����

	vivid::Rect rect;

	   static const int m_width;//�摜�T�C�Y�̕�

	   static const int m_height;//�摜�T�C�Y�̍���

	   float timer;
};