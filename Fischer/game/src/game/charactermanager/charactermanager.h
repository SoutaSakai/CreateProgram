#pragma once
#include"vivid.h"
#include"../Charactermanager/CharacterID.h"

class CharacterManager
{
public:

	static CharacterManager& GetInstance(void);

	float			CharacterWIDTH(CHARACTER_ID Character);			//�L�����N�^�[�̉�����Ԃ�
	float			CharacterHEIGHT(CHARACTER_ID Character);		//�L�����N�^�[�̏c����Ԃ�
	float			CharacterSpeed(CHARACTER_ID Character);			//�L�����N�^�[�̃X�s�[�h��Ԃ�
	vivid::Rect		CharacterRect(CHARACTER_ID Character);			//�L�����N�^�[��Rect��Ԃ�
	std::string		CharacterFilePath(CHARACTER_ID Character);		//�L�����N�^�[�̃t�@�C���p�X��Ԃ�
	vivid::Vector2	CharacterMouthPos(CHARACTER_ID Character, vivid::Vector2);		//�L�����N�^�[�̌��̈ʒu��Ԃ�
	float			CharacterMouthRadius(CHARACTER_ID Character);	//�L�����N�^�[�̌��̔��a��Ԃ�


	void Finalize(void);

private:

	//Elsctriceel		�d�C���Ȃ�
	static const float ElsctriceelWIDTH;				//�d�C�E�i�M�̉���
	static const float ElsctriceelHEIGHT;				//�d�C���Ȃ��̗���
	static const float ElsctriceelSpeed;				//�d�C�E�i�M�̃X�s�[�h
	static const vivid::Rect ElsctriceelRect;			//�d�C�E�i�M��Rect
	static const std::string ElsctriceelFilePath;		//�d�C���Ȃ��̃t�@�C���p�X
	static const vivid::Vector2 ElsctriceelMouthPos;	//�d�C�E�i�M�̌��̈ʒu
	static const float ElsctriceelMouthRadius;			//�d�C���Ȃ��̌��̔��a

	//Porcupinefish		�n���Z���{��
	static const float PorcupinefishWIDTH;				//�n���Z���{���̉���
	static const float PorcupinefishHEIGHT;				//�n���Z���{���̗���
	static const float PorcupinefishSpeed;				//�n���Z���{���̃X�s�[�h
	static const vivid::Rect PorcupinefishRect;			//�n���Z���{����Rect
	static const std::string PorcupinefishFilePath;		//�n���Z���{���̃t�@�C���p�X
	static const vivid::Vector2 PorcupinefishMouthPos;	//�n���Z���{���̌��̈ʒu
	static const float PorcupinefishMouthRadius;		//�n���Z���{���̌��̔��a

	//Shark				�T��
	static const float SharkWIDTH;					//�T���̉���
	static const float SharkHEIGHT;					//�T���̗���
	static const float SharkSpeed;					//�T���̃X�s�[�h
	static const vivid::Rect SharkRect;				//�T����Rect
	static const std::string SharkFilePath;			//�T���̃t�@�C���p�X
	static const vivid::Vector2 SharkMouthPos;		//�T���̌��̈ʒu
	static const float SharkMouthRadius;			//�T���̌��̔��a

	//Lionfish			�~�m�J�T�S
	static const float LionfishWIDTH;				//�~�m�J�T�S�̉���
	static const float LionfishHEIGHT;				//�~�m�J�T�S�̗���
	static const float LionfishSpeed;				//�~�m�J�T�S�̃X�s�[�h
	static const vivid::Rect LionfishRect;			//�~�m�J�T�S��Rect
	static const std::string LionfishFilePath;		//�~�m�J�T�S�̃t�@�C���p�X
	static const vivid::Vector2 LionfishMouthPos;	//�~�m�J�T�S�̌��̈ʒu
	static const float LionfishMouthRadius;			//�~�m�J�T�S�̌��̔��a

	//Mirrormorayell		�~���[�E�c�{
	static const float MirrormorayellWIDTH;				//�~���[�E�c�{�̉���
	static const float MirrormorayellHEIGHT;			//�~���[�E�c�{�̗���
	static const float MirrormorayellSpeed;				//�~���[�E�c�{�̃X�s�[�h
	static const vivid::Rect MirrormorayellRect;		//�~���[�E�c�{��Rect
	static const std::string MirrormorayellFilePath;	//�~���[�E�c�{�̃t�@�C���p�X
	static const vivid::Vector2 MirrormorayellMouthPos;	//�~���[�E�c�{�̌��̈ʒu
	static const float MirrormorayellMouthRadius;		//�~���[�E�c�{�̌��̔��a

	//Turtle			�J��
	static const float TurtleWIDTH;					//�J���̉���
	static const float TurtleHEIGHT;				//�J���̗���
	static const float TurtleSpeed;					//�J���̃X�s�[�h
	static const vivid::Rect TurtleRect;			//�J����Rect
	static const std::string TurtleFilePath;		//�J���̃t�@�C���p�X
	static const vivid::Vector2 TurtleMouthPos;		//�J���̌��̈ʒu
	static const float TurtleMouthRadius;			//�J���̌��̔��a

	//Octopus			�^�R
	static const float OctopusWIDTH;				//�^�R�̉���
	static const float OctopusHEIGHT;				//�^�R�̗���
	static const float OctopusSpeed;				//�^�R�̃X�s�[�h
	static const vivid::Rect OctopusRect;			//�^�R��Rect
	static const std::string OctopusFilePath;		//�^�R�̃t�@�C���p�X
	static const vivid::Vector2 OctopusMouthPos;	//�^�R�̌��̈ʒu
	static const float OctopusMouthRadius;			//�^�R�̌��̔��a

	//Pointuna			�|�C���c�i
	static const float PointunaWIDTH;				//�|�C���c�i�̉���
	static const float PointunaHEIGHT;				//�|�C���c�i�̗���
	static const float PointunaSpeed;				//�|�C���c�i�̃X�s�[�h
	static const vivid::Rect PointunaRect;			//�|�C���c�i��Rect
	static const std::string PointunaFilePath;		//�|�C���c�i�̃t�@�C���p�X
	static const vivid::Vector2 PointunaMouthPos;	//�|�C���c�i�̌��̈ʒu
	static const float PointunaMouthRadius;			//�|�C���c�i�̌��̔��a

	//Tuna				�}�O��
	static const float TunaWIDTH;					//�}�O���̉���
	static const float TunaHEIGHT;					//�}�O���̗���
	static const float TunaSpeed;					//�}�O���̃X�s�[�h
	static const vivid::Rect TunaRect;				//�}�O����Rect
	static const std::string TunaFilePath;			//�}�O���̃t�@�C���p�X
	static const vivid::Vector2 TunaMouthPos;		//�}�O���̌��̈ʒu
	static const float TunaMouthRadius;				//�}�O���̌��̔��a

};

