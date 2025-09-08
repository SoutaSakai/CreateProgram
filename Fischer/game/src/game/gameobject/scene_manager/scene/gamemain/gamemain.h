#pragma once
#include "..\scene.h"
#include "..\..\..\character_manager\characterID.h"

class Gamemain : public IScene
{
public:
	Gamemain(void);
	~Gamemain(void) = default;

	void Initialize(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Finalize(void) override;

private:
	struct UseCharacter
	{
		CHARACTER_ID* Character;
	};

	static const int		m_max_fish;
	static const float		m_water_surface;

	vivid::Rect				m_Rect;				// ボタンの描画範囲
	vivid::Vector2			m_Anchor;			// ボタンの基準点
	vivid::Vector2			m_Scale;			// ボタンの拡大率
	vivid::Vector2			m_ButtonPosition;	// ボタンの位置

	UseCharacter*			m_UseCharacter;
};