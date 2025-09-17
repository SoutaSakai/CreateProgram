#pragma once

#include"vivid.h"

#include"../../../player_manager/player_manager.h"
#include"../../../character_manager/character_manager.h"

class COctopus
{
public:

	//コンストラクタ
	COctopus(void);

	//初期化
	void Initialize(int playernumber, vivid::Vector2 positon, vivid::Vector2 scale);

	//更新
	void Update(void);

	//解放
	void Finalize(void);

	//スキルの当たり判定
	void CheckHitSkill(void);
	void CollisionDetection(int number, int pattern);

private:

	static const float			m_AbilityTime;	//効果時間
	static const std::string	m_FilePath;		//ファイルパス
	static const float			m_ScaleSpeed;	//スケールスピード
	static const unsigned int	m_TransparencySpeed;		//透過スピード
	static const int			m_skil_time;		//スキルの効果時間

	static const int			m_InkWidth;		//インクの横幅
	static const int			m_InkHeight;	//インクの立幅

	vivid::Vector2				m_Position;		//座標
	unsigned int				m_Color;
	vivid::Rect					m_Rect;			//表示範囲
	vivid::Vector2				m_Anchor;		//基準点
	vivid::Vector2				m_Scale;		//拡大率

	bool						m_Flag[(int)vivid::controller::DEVICE_ID::MAX];

	float						m_Timer;		//タイマー
	int							m_PlayerNumber;	//プレイヤー識別番号
	int							m_MaxPlayer;	//最大人数
};