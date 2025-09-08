#pragma once
#include "..\scene.h"
#include "vivid.h"
#include "..\..\..\character_manager\characterID.h"

class CharacterSelect : public IScene
{
public:
	CharacterSelect(void);
	~CharacterSelect(void) = default;

	void Initialize(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Finalize(void) override;

	void SetCullentSelect(int, int);

private:
	void Keyboard(void);
	vivid::Vector2 GetFlamePosition(int);
	

	static const int	m_flame_width;		// 選択枠の幅
	static const int	m_flame_height;		// 選択枠の高さ
	static const int	m_max_character;	// キャラクターの最大数
	static const int	m_max_player;		// プレイヤーの最大数
	static const int	m_distance;			// 表示間隔

	vivid::Vector2*		m_CharacterPosition;	// キャラクターの座標
	vivid::Vector2*		m_FlamePosition;		// 選択枠の座標
	int*				m_CurrentSelect;		// 選択中キャラクターのID
};