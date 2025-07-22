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

	static const int m_width;			//ナンバー画像サイズの幅
	static const int m_height;			//ナンバー画像サイズの高さ
	static const int m_tuna_width;		//ツナ画像サイズの幅
	static const int m_tuna_height;		//ツナ画像サイズの高さ
	static const int m_max_player = 4;	//プレイヤー人数
	static const int m_button = 2;		//ボタンの個数


	int				m_Score[m_max_player];						// スコアポイント
	vivid::Vector2	m_ScorePosition[m_max_player];				// ポイントのポジション
	vivid::Vector2	m_UseCharacter[m_max_player][m_max_player];	// マグロの描画
	vivid::Vector2	m_UseDrawText[m_max_player];				// 使用キャラクターのDrawText
	vivid::Vector2	m_BackGround;								// 背景
	vivid::Vector2	m_ResultButtonPosition[m_button];			// ボタンのポジション
	vivid::Vector2	m_ResultAnchor[m_button];					// 基準点
	vivid::Vector2	m_ResultCharacterSelectScale;				// キャラクターセレクトボタンの拡大率
	vivid::Vector2	m_ResultExitScale;							// やめるボタンの拡大率
	vivid::Rect		m_ResultRect[m_button];						// 範囲
	vivid::Vector2	m_SelectFramePosition;						// 外枠のポジション
	vivid::Vector2	m_SelectFrameAnchor;						// 外枠の基準点
	vivid::Vector2	m_SelectFrameScale;							// 外枠の拡大率
	vivid::Rect		m_SelectFrameRect;							// 外枠の範囲
	unsigned int	m_WordColor[m_button];						// DrawTextの色
	bool			m_ButtonFlag;								// ボタンの現在
};