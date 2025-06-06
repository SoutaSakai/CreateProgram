#pragma once
#include"../playermanager/Charactermanager/CharacterID.h"
#include"vivid.h"

class SkilManager
{
public:

	static SkilManager& GetInstance(void);

	//Tuna				�}�O��
	void TunaSkilInitialize(void);
	vivid::Vector2 TunaSkil(vivid::Vector2 Pos,float Angle,bool* flag,float ScaleX);	

private:

	static const float fps;

	//Elsctriceel		�d�C���Ȃ�
	//Porcupinefish		�n���Z���{��
	//Shark				�T��
	//Lionfish			�~�m�J�T�S
	//Mirrormoray		�~���[�E�c�{
	//Turtle			�J��
	//Octopus			�^�R
	//Pointuna			�|�C���c�i
	//Tuna				�}�O��
	static const float BlinkRange;		//�u�����N�̋���
	static const float BlinkTime;		//�u�����N�ɂ����鎞��
	static const int BlinkCount;		//�u�����N������ɕ����邩

	float Timer;
	int Count;
};