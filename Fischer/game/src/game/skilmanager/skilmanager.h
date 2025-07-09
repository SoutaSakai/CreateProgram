#pragma once

#include"vivid.h"

#include"../charactermanager/characterID.h"

#include"skil/Elsctriceel/Elsctriceel.h"
#include"skil/Tuna/Tuna.h"
#include"skil/Turtle/Turtle.h"
#include"skil/Porcupinefish/Porcupinefish.h"
#include"skil/Octopus/Octopus.h"

class Elsctriceel;
class Tuna;
class Turtle;
class Porcupinefish;
class COctopus;

class SkilManager
{
public:

	static SkilManager& Getinstance(void);

	void Initialize(int PlayerNumber, CHARACTER_ID Character, vivid::Vector2 pos, vivid::Vector2 scale);
	vivid::Vector2 Update(int PlayerNumber, CHARACTER_ID Character,vivid::Vector2 Pos,float Angle,float ScaleX);
	void Draw(void);
	void Finalize(void);

	//				��player���H�A�g���L����1�A���E���h�J�n���ɌĂяo��
	void CreateObj(int PlayerNumber,CHARACTER_ID Character);

	void DeleteObj(void);	//	�I�u�W�F�N�g�����ׂč폜����

private:

	Elsctriceel*		elsctriceel[(int)vivid::controller::DEVICE_ID::MAX];
	Tuna*				tuna[(int)vivid::controller::DEVICE_ID::MAX];
	Turtle*				turtle[(int)vivid::controller::DEVICE_ID::MAX];
	Porcupinefish*		porcupinefish[(int)vivid::controller::DEVICE_ID::MAX];
	COctopus*			octopus[(int)vivid::controller::DEVICE_ID::MAX];

};