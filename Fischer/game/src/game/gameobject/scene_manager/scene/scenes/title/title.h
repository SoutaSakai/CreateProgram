#pragma once
#include "..\..\scene.h"

class Title : public IScene
{
public:
	Title(void);
	~Title(void) = default;

	void Initialize(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Finalize(void) override;

private:

	// ���Ƀ{�^���̍��W�ƃT�C�Y��ݒ�i��: x=100, y=300, width=200, height=50�j
	static const vivid::Vector2		button_position;
	static const float				button_width;
	static const float				button_height;
};
