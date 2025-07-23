#pragma once
#include"vivid.h"
#include"../../Charactermanager/CharacterID.h"
#include"../../Charactermanager/Charactermanager.h"

#include"../playermanager.h"

#include"../../skilmanager/skilmanager.h"

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

	void Setting(vivid::Vector2 pos,float scale ,float angle,bool skilflag);

	//���̃��E���h�̎g���Ă�L�����N�^�[ID��n��
	CHARACTER_ID GetUseCharacter(void) const { return UseCharacter[CharaNo]; }
	//�v���C���[�̍��W��n��
	vivid::Vector2 GetPlayerPosition(void) const { return CharacterPos; }
	//�v���C���[�̊p�x��n��
	float GetPlayerAngle(void) const { return Angle; }
	//�v���C���[�̉����Ɨ�����n��
	float GetPlayerWidth(void) const { return CharaWIDTH; }
	float GetPlayerHeight(void) const { return CharaHEIGHT; }
	

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

	static const float WaterHEIGHT;

};

