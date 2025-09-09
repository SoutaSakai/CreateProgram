#pragma once
#include"vivid.h"

#include"../../../playermanager/playermanager.h"
#include"../../../charactermanager/charactermanager.h"

class CShark
{
public:

	void Initialize(int playernumber,vivid::Vector2 position);
	void Update(vivid::Vector2 pos ,float angle,float scaleX);

	void CheckHitSkill(void);
	void CollisionDetection(int number, int pattern);

private:

	static const int		m_time;		//効果時間

	vivid::Vector2		m_RMouthPos;	//口の位置(ローカル)
	vivid::Vector2		m_WMouthPos;	//口の位置(ワールド)
	float				m_MouthRadius;

	vivid::Vector2		m_Position;			//座標
	vivid::Vector2		m_CenterPosition;	//中心座標
	float				m_MouthAngle;		//中心点から口の角度
	float				m_Angle;			//プレイヤーの角度
	float				m_Width;
	float				m_Height;
	float				m_Diagonal;			//中心点から口までの距離

	int	m_Timer;				
	int m_PlayerNumber;						//プレイヤー識別番号

};