#pragma once
#include"vivid.h"

#include"../../../charactermanager/charactermanager.h"
#include"../../../playermanager/playermanager.h"

class CMirrormoray
{
public:

	//コンストラクタ
	CMirrormoray(void);
	//デストラクタ
	~CMirrormoray(void) = default;

	void Initialize(int playernumber);
	void Update(vivid::Vector2 pos,float angle,float scalex);
	void Finalize(void);

private:

	static const int		m_MaxDecoy;		//分身の数
	static const float		m_Range;		//分身が出る距離

	static const float		m_width;		//横幅
	static const float		m_height;		//立幅

	vivid::Vector2			m_Position;		//座標
	vivid::Rect				m_Rect;			//表示範囲
	std::string				m_FilePath;		//ファイルパス
	vivid::Vector2			m_Anchor;
	float					m_Angle;		//角度

	int m_PlayerNumber;

};