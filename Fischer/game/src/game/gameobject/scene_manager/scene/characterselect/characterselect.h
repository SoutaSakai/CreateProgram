#pragma once
#include "..\scene.h"
#include "vivid.h"

class CharacterSelect : public IScene
{
public:
	CharacterSelect(void);
	~CharacterSelect(void) = default;

	void Initialize(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Finalize(void) override;

private:
	static const int	m_max_character;	// キャラクターの最大数
	static const int	m_max_player;		// プレイヤーの最大数
	static const int	m_distance;			// 表示間隔

	vivid::Vector2*		m_CharacterPosition;	// キャラクターの座標
	vivid::Vector2*		m_SelectPosition;		// 選択枠の座標
};