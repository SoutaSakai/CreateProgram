#pragma once
#include"vivid.h"
#include "../scene_manager/iscene/scenes/gamemain/timer/timer.h"
#include"../scene_manager/scene_manager.h"



class ScoreManager
{
public:
	static ScoreManager& GetInstance(void);

	void Initialize(void);


	void Update(void);

	void Draw(void);


	void Finalize(void);


	int GetScore(int);




private:
	static const int m_width;//�摜�T�C�Y�̕�

	static const int m_height;//�摜�T�C�Y�̍���

	static const int max_player = 4;//�v���C���[�̐l��

	static const int point;//�|�C���g�i�P�O�|�C���g�j


	vivid::Vector2 Score_pos[max_player];//�X�R�A�|�W�V����



	int score[max_player];//�X�R�A�ێ�

	int m_score[max_player];//�X�R�A�̉��̕ϐ�

	int digit[max_player];

	int ppos[max_player];//�v���C���[�|�W�V����

	int getscore[max_player];

	vivid::Rect m_rect;//�{�^���͈̔�
	vivid::Vector2 m_anchor;//�{�^���̒��S�͈�
	vivid::Vector2 m_scale;//�g�嗦
	vivid::Vector2 m_button_pos;//�{�^���̃|�W�V����



	ScoreManager(void) = default;
	~ScoreManager(void) = default;
	ScoreManager(const ScoreManager& rhs) = delete;
	ScoreManager& operator=(const ScoreManager& rhs) = delete;

};