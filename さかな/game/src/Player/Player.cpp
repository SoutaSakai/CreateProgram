#include "Player.h"


// vivid::keyboard���O��Ԃ̃G�C���A�X
namespace keyboard = vivid::keyboard;
const float Move_speed = 3.0f;

// Player�N���X�̃R���X�g���N�^
Player::Player(void)
	: Player_pos(0.0f, 0.0f)
	, Player_center_pos(0.0f, 0.0f)//
{
}

// �v���C���[�̏���������
void Player::Initialize(void)
{
	Player_pos = { vivid::WINDOW_WIDTH / 4,vivid::WINDOW_HEIGHT - 270 };
	Player_center_pos = { Player_pos.x + Player_width, Player_pos.y + Player_height/2 };
}

// �v���C���[�̏�ԍX�V�i�L�[�{�[�h���͂ɂ��ړ��j
void Player::Update(void)
{
	
	if (keyboard::Button(keyboard::KEY_ID::W))
	{
		Player_speed.y = -Move_speed;	
	
	}
	else if (keyboard::Button(keyboard::KEY_ID::S))
	{
		Player_speed.y = +Move_speed;
		
	}
	else
	{
		Player_speed.y = 0.0f;
	}

	if (keyboard::Button(keyboard::KEY_ID::A))
	{
		Player_speed.x = -Move_speed;	
	
		
	}
	else if (keyboard::Button(keyboard::KEY_ID::D))
	{

		Player_speed.x = +Move_speed;	
	
	}
	else
	{
		Player_speed.x = 0.0f;
	}

	



	Player_pos.y += Player_speed.y;
	Player_center_pos.y -= Move_speed;

	
	Player_pos.x += Player_speed.x;
	Player_center_pos.x -= Move_speed;
	

	Player_pos.y += Player_speed.y;
	Player_center_pos.y += Move_speed;

	


	Player_pos.x += Player_speed.x;
	Player_center_pos.x += Move_speed;
}


// �v���C���[�̕`��
void Player::Draw(void)
{
	//
	// vivid::Rect r = { 0,0,255,120 };
	//float l = atan2(Player_pos.y, Player_pos.x) * 3.14f / 180.0f;
	vivid::DrawTexture("data\\Player.png", Player_pos);
}

// �I�������i����͉������Ă��Ȃ��j
void Player::Finalize(void)
{
}

/*
// ���̈ʒu����W���擾����֐��Q�i���g�p�j
// vivid::Vector2 Player::Get_player_mouth_pos(void)
// float Player::Get_player_mouth_x_pos(void)
// float Player::Get_player_mouth_y_pos(void)
*/

// �v���C���[�̌��̔��a���擾
float Player::Get_player_mouth_radius(void)
{
	return Player_mouth_radius;
}

// �v���C���[�̒��S���W���擾
vivid::Vector2 Player::Get_Player_center_pos(void)
{
	return Player_center_pos;
}
