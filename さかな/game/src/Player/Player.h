#pragma once
#include"vivid.h"

// �v���C���[�N���X
class Player
{
public:
	Player(void); // �R���X�g���N�^
	void Initialize(void); // ������
	void Update(void);     // ��ԍX�V
	void Draw(void);       // �`��
	void Finalize(void);   // �I������

	// ���̍��W�擾
	float Get_player_mouth_radius(void);
	vivid::Vector2 Get_Player_center_pos(void);

private:
	vivid::Vector2 Player_center_pos;//�v���C���[�̒��S�̈ʒu
	vivid::Vector2 Player_pos;//�L�����N�^�[�̈ʒu
	
	const float Player_mouth_radius = 20.0f;//�v���C���[�̌��̔��a]
	const float Player_width=255;//�v���C���[�̕�
	const float Player_height=120;//�v���C���[�̍���
	static const float Move_speed ;//�ړ����x

protected:
	vivid::Vector2 Player_speed;//�v���C���[�̈ړ����x

};