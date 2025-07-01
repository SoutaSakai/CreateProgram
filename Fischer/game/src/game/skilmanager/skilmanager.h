#pragma once

#include"vivid.h"

#include"../charactermanager/characterID.h"

#include"skil/Elsctriceel/Elsctriceel.h"
#include"skil/Tuna/Tuna.h"
#include"skil/Turtle/Turtle.h"


class SkilManager
{
public:

	static SkilManager& Getinstance(void);

	void Initialize(int PlayerNumber, CHARACTER_ID Character);
	vivid::Vector2 Update(int PlayerNumber, CHARACTER_ID Character,vivid::Vector2 Pos,float Angle,float ScaleX);
	void Draw(void);
	void Finalize(void);

	//�X�L���t���O�̃|�C���^���󂯎��
	void GiveSkilFlagPt(vivid::controller::DEVICE_ID PlayerNumber, bool* skilflag);

	//�R���g���[���t���O�̃|�C���^���󂯎��
	void GiveControlFlagPt(vivid::controller::DEVICE_ID PlayerNumber, bool* Ccontrolflag);

	//				��player���H�A�g���L����1�A���E���h�J�n���ɌĂяo��
	void CreateObj(int PlayerNumber,CHARACTER_ID Character);

	void DeleteObj(void);	//	�I�u�W�F�N�g�����ׂč폜����

private:

	static const int MAXPlayer = 4;

	//�X�L���t���O�̃|�C���^�ϐ�
	//�R���g���[���t���O�̃|�C���^�ϐ�
	//Player.cpp ==> Skilmanager.cpp
	bool* m_SkilFlagPt[MAXPlayer];
	bool* m_ControlFlagPt[MAXPlayer];

	Elsctriceel*	elsctriceel[MAXPlayer];
	Tuna*			tuna[MAXPlayer];
	Turtle*			turtle[MAXPlayer];

};