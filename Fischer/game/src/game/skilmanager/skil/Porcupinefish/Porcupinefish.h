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

	static const int MaxSpine;		//�j�̐�
	static const float SpineSpeed;	//�j�̃X�s�[�h

	vivid::Vector2 *SpinePos;		//�j�̍��W
	bool* SpineFlag;				//�j��on/off
	
	float Radius;		//���a
	float Angle;		//�p�x
	int m_PlayerNumber;
};