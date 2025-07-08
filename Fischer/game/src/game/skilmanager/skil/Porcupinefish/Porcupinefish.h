#pragma once
#include"vivid.h"

#include"../../../playermanager/playermanager.h"
#include"../../../charactermanager/charactermanager.h"

class Porcupinefish
{
public:

	void Initialize(int playernumber,vivid::Vector2 pos);
	void Update();

private:

	static const int	m_width;
	static const int	m_height;

	static const int	m_MaxSpine;		//j‚Ì”
	static const float	m_SpineSpeed;	//j‚ÌƒXƒs[ƒh
	static const float	m_SpineAngle;	//j‚ÌŠÔŠu

	vivid::Vector2		SpinePos[6];	//j‚ÌÀ•W
	vivid::Rect			m_SpineRect;
	bool*				SpineFlag;		//j‚Ìon/off
	float				Angle[6];		//Šp“x
	vivid::Vector2		m_Anchor;

	int m_PlayerNumber;
};