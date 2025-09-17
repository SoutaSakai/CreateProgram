#pragma once
#include "..\scene.h"
#include "..\scene_id.h"

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
	void FadeIn(void);

	struct UseCharacter
	{
		vivid::Vector2* Character;
	};

	static const int			m_table_width;					// 枠の幅
	static const int			m_table_height;					// 枠の高さ
	static const int			m_log_width;					// 丸太の幅
	static const int			m_rank_width;					// 順位の幅
	static const int			m_rank_height;					// 順位の高さ
	static const int			m_use_character_text_width;		// 「使用キャラクター」文字列の幅
	static const int			m_use_character_text_height;	// 「使用キャラクター」文字列の高さ
	static const int			m_round_text_width;				// 「_R」文字列の幅
	static const int			m_round_text_height;			// 「_R」文字列の高さ
	static const int			m_tuna_width;					// マグロの幅
	static const int			m_tuna_height;					// マグロの高さ
	static const int			m_number_width;					// 数字1つの幅
	static const int			m_number_height;				// 数字1つの高さ
	static const int			m_score_text_width;				// 「pt」文字列の幅
	static const int			m_score_text_height;			// 「pt」文字列の高さ
	static const int			m_button_width;					// ボタンの幅
	static const int			m_button_height;				// ボタンの高さ
	static const int			m_max_fish;						// 魚の最大値
	static const int			m_max_button;					// ボタンの個数
	static const float			m_distance;						// 表示間隔
	static const int			m_player_width;					//画像の1p,2p,3p,4pプレイヤーの幅
	static const int			m_player_height;				//画像の1p,2p,3p,4pプレイヤーの高さ
	static const unsigned int	m_black_speed;					// 暗転速度

	static const vivid::controller::DEVICE_ID m_DeviceID[(int)vivid::controller::DEVICE_ID::MAX];

	static const int m_max_player;
	int	m_MaxPlayer;					// プレイヤーの最大値

	UseCharacter*	m_UseCharacterPosition;		// 使用キャラクターの座標
	int*			m_Score;					// 得点
	vivid::Vector2*	m_ScorePosition;			// 得点の座標
	vivid::Vector2*	m_ScoreTextPosition;		// 「pt」文字列の座標
	vivid::Vector2* m_RoundTextPosition;		// 「_R」文字列の座標
	vivid::Vector2*	m_UseCharacterTextPosition;	// 「使用キャラクター」文字列の座標
	vivid::Vector2*	m_RankTextPosition;			// 順位の座標
	vivid::Vector2	m_BackGroundPosition;		// 背景の座標
	vivid::Vector2	m_CharacterSelectBaseScale;	// キャラクター選択画面に戻るボタンの拡大率の初期値
	vivid::Vector2	m_ExitBaseScale;			// やめるボタンの拡大率の初期値
	vivid::Vector2	m_CharacterSelectMaxScale;	// キャラクター選択画面に戻るボタンの最大拡大率
	vivid::Vector2	m_ExitMaxScale;				// やめるボタンの最大拡大率
	vivid::Vector2*	m_ButtonPosition;			// ボタンの座標
	vivid::Vector2	m_ButtonAnchor;				// ボタンの基準点
	vivid::Vector2	m_CharacterSelectScale;		// キャラクターセレクトボタンの拡大率
	vivid::Vector2	m_ExitScale;				// やめるボタンの拡大率
	vivid::Rect*	m_ButtonRect;				// ボタンの範囲

	vivid::Vector2* m_PlayerPosition;

	unsigned int	m_BlackColor;				// 暗転の色
	bool			m_BlackFlag;				// 暗転フラグ

	bool			m_ButtonFlag;				// ボタンの現在
	bool			m_AButtonFlag;				//Aボタンのフラグ
	bool			m_DButtonFlag;				//dボタンのフラグ
	std::string* m_FilePath;
	std::string* m_RankPath;

	SCENE_ID		m_CurrentSelect;			// ボタンの現在
};