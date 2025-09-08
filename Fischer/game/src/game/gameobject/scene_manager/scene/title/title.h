#pragma once
#include "..\scene.h"

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

	enum class ButtonNumber
	{
		DUMMY,
		TWO,
		THREE,
		FOUR
	};

	// 仮にボタンの座標とサイズを設定（例: x=100, y=300, width=200, height=50）
	static const float	m_button_width;
	static const float	m_button_height;
	static const float	m_button_distance;
	static const int	m_max_button;

	ButtonNumber		m_CurrentSelect;
	vivid::Vector2*		m_ButtonPosition;
};
