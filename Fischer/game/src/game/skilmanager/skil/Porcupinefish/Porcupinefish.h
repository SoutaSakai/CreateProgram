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

	static const int MaxSpine;		//j‚Ì”
	static const float SpineSpeed;	//j‚ÌƒXƒs[ƒh

	vivid::Vector2 *SpinePos;		//j‚ÌÀ•W
	bool* SpineFlag;				//j‚Ìon/off
	
	float Radius;		//”¼Œa
	float Angle;		//Šp“x
	int m_PlayerNumber;
};