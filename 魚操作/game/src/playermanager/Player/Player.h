#pragma once
#include"vivid.h"
#include"../Charactermanager/CharacterID.h"
#include"../Charactermanager/Charactermanager.h"

class Player
{
public:
	Player(vivid::controller::DEVICE_ID playerID);

	void Initialize();

	void Update(void);

	void InUseCharacter(CHARACTER_ID first, CHARACTER_ID second, CHARACTER_ID third);
	void InUseCharacter(CHARACTER_ID first);

	//�R���g���[���̓��͏���
	void Controller(void);

	//�X�e�B�b�N�̓��͂Ŋp�x�����߂�
	void CharacterStick(void);

	void Keyboard(void);

	void Draw();

	void Finalize(void);
	

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
};

