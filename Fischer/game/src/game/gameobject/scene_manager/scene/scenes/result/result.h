#pragma once
#include "..\..\scene.h"

class Result : public IScene
{
public:
	Result(void);
	~Result(void) = default;

	void Initialize(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Finalize(void) override;

	static const int m_width;//�i���o�[�摜�T�C�Y�̕�
	static const int m_height;//�i���o�[�摜�T�C�Y�̍���
	static const int tuna_width;//�c�i�摜�T�C�Y�̕�
	static const int tuna_height;//�c�i�摜�T�C�Y�̍���
	static const int max_player = 4;//�v���C���[�l��
	static const int button = 2;//�{�^���̌�
	int point[max_player];//�X�R�A�|�C���g
	int m_point[max_player];//����������̃X�R�A
	int m_digit[max_player];
	vivid::Vector2 point_pos[max_player];					//�|�C���g�̃|�W�V����
	vivid::Vector2 result_button_pos[button];				//�{�^���̃|�W�V����
	vivid::Vector2 use_character[max_player][max_player];	//�}�O���̕`��
	vivid::Vector2 use_drawtext[max_player];				// �g�p�L�����N�^�[��DrawText
	vivid::Vector2 result_anchor[button];					//��_
	vivid::Rect result_rect[button];						//�͈�
	vivid::Vector2 result_character_select_scale;			//�L�����N�^�[�Z���N�g�{�^���̊g�嗦
	vivid::Vector2 result_exit_scale;						//��߂�{�^���̊g�嗦
	vivid::Vector2 back_ground;								//�w�i
	vivid::Vector2 select_frame_pos;						//�O�g�̃|�W�V����
	vivid::Rect select_frame_rect;							//�O�g�͈̔�
	vivid::Vector2 select_frame_anchor;						//�O�g�̊�_
	vivid::Vector2 select_frame_scale;						//�O�g�̊g�嗦
	unsigned int word_color[button];						//DrawText�̐F
	bool button_flag;									//�{�^���̌���
};