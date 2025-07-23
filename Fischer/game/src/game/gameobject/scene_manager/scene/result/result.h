#pragma once
#include "..\scene.h"

class Result : public IScene
{
public:
	Result(void);
	~Result(void) = default;

	void Initialize(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Finalize(void) override;

private:

	static const int	m_width;				// ナンバー画像サイズの幅
	static const int	m_height;				// ナンバー画像サイズの高さ
	static const int	m_tuna_width;			// ツナ画像サイズの幅
	static const int	m_tuna_height;			// ツナ画像サイズの高さ
	static const int	m_max_player;			// プレイヤー人数
	static const int	m_max_button;			// ボタンの個数
	static const float	m_button_base_scale;	// ボタンの拡大率の初期値
	static const float	m_button_max_scale;		// ボタンの最大拡大率


	int*			m_Score;					// 得点
	vivid::Vector2*	m_ScorePosition;			// 得点の座標
	vivid::Vector2	m_UseCharacterPosition/*[]*/;	// 使用キャラクターの座標
	vivid::Vector2*	m_TextPosition;				// 「使用キャラクター」文字列の座標
	vivid::Vector2	m_BackGroundPosition;		// 背景の座標
	vivid::Vector2*	m_ButtonPosition;			// ボタンの座標
	vivid::Vector2	m_ButtonAnchor;				// ボタンの基準点
	vivid::Vector2	m_CharacterSelectScale;		// キャラクターセレクトボタンの拡大率
	vivid::Vector2	m_ExitScale;				// やめるボタンの拡大率
	vivid::Rect*	m_ButtonRect;				// ボタンの範囲
	vivid::Vector2	m_FramePosition;			// 外枠の座標
	vivid::Vector2	m_FrameAnchor;				// 外枠の基準点
	vivid::Vector2	m_FrameScale;				// 外枠の拡大率
	vivid::Rect		m_FrameRect;				// 外枠の範囲
	bool			m_ButtonFlag;				// ボタンの現在
};