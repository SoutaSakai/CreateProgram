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

	static const int Max_pos;//	最大ポジション

	vivid::Rect rect;

	   static const int m_width;//画像サイズの幅

	   static const int m_height;//画像サイズの高さ

	   float timer;
};