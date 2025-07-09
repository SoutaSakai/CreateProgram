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

	static const int	m_Spinewidth;	//j‚Ì‰¡•
	static const int	m_Spineheight;	//j‚Ì—§•

	static const int	m_MaxSpine;		//j‚Ì”
	static const float	m_SpineSpeed;	//j‚ÌƒXƒs[ƒh
	static const float	m_SpineAngle;	//j‚ÌŠÔŠu

	vivid::Vector2		m_SpinePos[6];	//j‚ÌÀ•W
	vivid::Rect			m_SpineRect;	//j‚ÌRect
	bool				m_SpineFlag[6];	//j‚Ìon/off
	float				m_Angle[6];		//Šp“x
	vivid::Vector2		m_Anchor;		//Šî€“_

	int m_PlayerNumber;					//ƒvƒŒƒCƒ„[¯•Ê”Ô†
};