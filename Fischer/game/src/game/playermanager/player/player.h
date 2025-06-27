#pragma once
#include"vivid.h"
#include"../../Charactermanager/CharacterID.h"
#include"../../Charactermanager/Charactermanager.h"

#include"../playermanager.h"

//�X�L���C���N���[�h
#include"../Skil/Tuna/Tuna.h"
#include"../Skil/Elsctriceel/Elsctriceel.h"
#include"../Skil/Turtle/Turtle.h"


class Player
{
public:
	Player();

	void Initialize(vivid::controller::DEVICE_ID Player_ID, float Xpos);

	void Update(void);

	void InUseCharacter(CHARACTER_ID first, CHARACTER_ID second, CHARACTER_ID third);
	void InUseCharacter(CHARACTER_ID first);

	void ChangeRound(void);

	//�R���g���[���̓��͏���
	void Controller(void);

	//�X�e�B�b�N�̓��͂Ŋp�x�����߂�
	void CharacterStick(void);

	//�L�[�{�[�h���͏���
	void Keyboard(void);

	//��ʊO�ɏo�Ȃ��悤��
	void CheckWall(void);

	void Draw();

	void Finalize(void);

	void Setting(void);

private:
	vivid::controller::DEVICE_ID m_PlayerID;

	CHARACTER_ID UseCharacter[3];

	vivid::Vector2 CharacterPos;	//character�̍��W

	float CharaWIDTH;				//character�̉���
	float CharaHEIGHT;				//character�̗���
	float CharaSpeed;				//character�̃X�s�[�h
	vivid::Rect CharaRect;			//character��rect
	std::string CharaFilePath;		//character�̃t�@�C���p�X
	vivid::Vector2 CharaMouthPos;	//character�̌��̈ʒu
	float CharaMouthRadius;			//character�̌��̔��a

	int	CharaNo;					//���̃��E���h�̃L����

	vivid::Vector2 Anchor;			//character�̒��S
	float Angle;					//character�̊p�x
	vivid::Vector2 Scale;			//character�̊g�嗦

	bool SkilFlag;				//�X�L���̃t���O
	bool ControlFlag;			//�v���C���[������ł��邩�ǂ���

	static const float WaterHEIGHT;

	//�ǉ��R�[�h===>
	bool Hit_feed[4];	// �a�Ƃ̃A�^������̌���
	//<===

	//�X�L���N���X
	Tuna* tuna;


};

