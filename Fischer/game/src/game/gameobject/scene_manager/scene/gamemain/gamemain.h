#pragma once
#include "..\scene.h"
#include "vivid.h"

class Gamemain : public IScene
{
public:
	Gamemain(void);
	~Gamemain(void) = default;

	void Initialize(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Finalize(void) override;

	void SetMaxPlayer(int max);

	bool GetBlackFlag(void);

private:

	void ChangeRound(void);

	static const int		m_max_fish;
	static const int		m_max_player;
	static const int		m_max_round;
	static const float		m_water_surface;

	static const vivid::controller::DEVICE_ID m_DeviceID[(int)vivid::controller::DEVICE_ID::MAX];

	int						m_MaxPlayer;

	vivid::Rect				m_Rect;				// ボタンの描画範囲
	vivid::Vector2			m_Anchor;			// ボタンの基準点
	vivid::Vector2			m_Scale;			// ボタンの拡大率
	vivid::Vector2			m_ButtonPosition;	// ボタンの位置
	int						m_CurrentRound;		// 現在のラウンド番号
	bool					m_BlackFlag;		// 暗転フラグ
	unsigned int			m_BlackColor;		// 暗転時の色
	unsigned int			m_BlackSpeed;		// 暗転の速度
};