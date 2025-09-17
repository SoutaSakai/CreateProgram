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

	int GetMaxPlayer(void);

private:

	enum class ButtonNumber
	{
		DUMMY,
		TWO,
		THREE,
		FOUR
	};

	void Keyboard(void);

	void controller(void);

	// 仮にボタンの座標とサイズを設定（例: x=100, y=300, width=200, height=50）
	static const int				m_button_width;
	static const int				m_button_height;
	static const int				m_button_distance;
	static const int				m_max_button;
	static const vivid::Vector2		m_default_scale;
	static const vivid::Vector2		m_max_scale;
	static const vivid::Rect		m_rect;
	static const vivid::Vector2		m_anchor;
	static const vivid::Vector2		m_logo_position;

	static const vivid::controller::DEVICE_ID m_DeviceID[(int)vivid::controller::DEVICE_ID::MAX];

	ButtonNumber		m_CurrentSelect;
	vivid::Vector2*		m_ButtonPosition;
	vivid::Vector2*		m_ButtonScale;
	int					m_MaxPlayer;

	int					m_ControllerTime;
};
