#pragma once
#include"vivid.h"

#include"../../../character_manager/character_manager.h"
#include"../../../player_manager/player_manager.h"

class CMirrormoray
{
public:

	//コンストラクタ
	CMirrormoray(void);
	//デストラクタ
	~CMirrormoray(void) = default;

	void Initialize(int playernumber);
	void Update(vivid::Vector2 pos, float angle, float scalex);
	void Finalize(void);

	//デコイの情報を返す
	vivid::Vector2	GetDecoyPos(void);
	float			GetDecoyAngle(void);



private:

	static const int		m_MaxDecoy;		//分身の数
	static const float		m_Range;		//分身が出る距離

	static const float		m_width;		//横幅
	static const float		m_height;		//立幅

	vivid::Vector2			m_Position;				//座標
	float					m_Speed;
	float					m_Distance;
	vivid::Rect				m_Rect;					//表示範囲
	std::string				m_FilePath;				//ファイルパス
	vivid::Vector2			m_Anchor;				//基準点
	float					m_directionAngle;				//向き
	vivid::Vector2			m_PositionAngle;		//位置の角度
	float					m_Angle;

	int m_PlayerNumber;

};