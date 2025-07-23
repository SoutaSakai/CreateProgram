#pragma once
#include"vivid.h"

#include"Player/Player.h"
#include"../Charactermanager/CharacterID.h"

class Player;

class playermanager
{
public:

	static playermanager& GetInstance(void);

	void GetUseCharacter(CHARACTER_ID Character, int PlayerNo, int CharacterNo);

	void Initialize(const int MaxPlayer);
	void Update(void);
	void Draw(void);

	//�X�L���̓����蔻��
	void CheckHitSkil(void);

	void Finalize(void);

	void InRoundCount(int RoundCount) { m_RoundCount = RoundCount; }
	int  GetRoundCount(void) { return 1/*m_RoundCount*/; }

	//SkilFlag��ControlFlag��Ԃ�
	bool GetSkilFlag(int playernumber) const { return m_SkilFlag[playernumber]; }
	bool GetControlFlag(int playernumber) const { return m_ControlFlag[playernumber]; }

	//SkilFlag��ControlFlag�̓��e��ς���
	void ChangeSkilFlagTrue(int playernumber) { m_SkilFlag[playernumber] = true; }
	void ChangeControlFlagTrue(int playernumber) { m_ControlFlag[playernumber] = true; }

	void ChangeSkilFlagFalse(int playernumber){ m_SkilFlag[playernumber] = false; }
	void ChangeControlFlagFalse(int playernumber) { m_ControlFlag[playernumber] = false; }

private:

	playermanager(void) = default;

	int MaxPlayer;		//�v���C���[�̍ő吔

	int m_RoundCount;	//���E���h�̃J�E���^

	bool SkilFlag[(int)vivid::controller::DEVICE_ID::MAX];				//�X�L���̃t���O
	bool ControlFlag[(int)vivid::controller::DEVICE_ID::MAX];			//�v���C���[������ł��邩�ǂ���

	Player* player[(int)vivid::controller::DEVICE_ID::MAX];							//�v���C���[�̃I�u�W�F�N�g����
	CHARACTER_ID UseCharacter[(int)vivid::controller::DEVICE_ID::MAX][3];			//�v���C���[�̎g���L�����N�^�[
	vivid::controller::DEVICE_ID DeviceID[(int)vivid::controller::DEVICE_ID::MAX];	//�f�o�C�XID�i�[�ϐ�

	vivid::Vector2 StartPos[4];

	//SkilFlag ==> �X�L�����g�Ă�����
	//ControlFlag ==> ����ł��邩�ǂ���
	bool m_SkilFlag[(int)vivid::controller::DEVICE_ID::MAX];
	bool m_ControlFlag[(int)vivid::controller::DEVICE_ID::MAX];
};