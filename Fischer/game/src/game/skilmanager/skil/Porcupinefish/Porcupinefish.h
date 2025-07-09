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

	static const int	m_Spinewidth;	//�j�̉���
	static const int	m_Spineheight;	//�j�̗���

	static const int	m_MaxSpine;		//�j�̐�
	static const float	m_SpineSpeed;	//�j�̃X�s�[�h
	static const float	m_SpineAngle;	//�j�̊Ԋu

	vivid::Vector2		m_SpinePos[6];	//�j�̍��W
	vivid::Rect			m_SpineRect;	//�j��Rect
	bool				m_SpineFlag[6];	//�j��on/off
	float				m_Angle[6];		//�p�x
	vivid::Vector2		m_Anchor;		//��_

	int m_PlayerNumber;					//�v���C���[���ʔԍ�
};