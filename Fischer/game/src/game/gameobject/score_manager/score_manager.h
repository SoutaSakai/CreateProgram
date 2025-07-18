#pragma once
#include"vivid.h"
#include "../time_manager/time_manager.h"
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
	static const int m_width;			//�摜�T�C�Y�̕�
	static const int m_height;			//�摜�T�C�Y�̍���
	static const int max_player = 4;	//�v���C���[�̐l��
	static const int point;				//�|�C���g

	int m_Score[max_player];			//�X�R�A�ێ�
	int m_TempScore[max_player];		//�X�R�A�̉��̕ϐ�
	int m_PlayerPosition[max_player];	//�v���C���[�ʒu

	vivid::Rect m_rect;						//�{�^���͈̔�
	vivid::Vector2 m_anchor;				//�{�^���̊�_
	vivid::Vector2 m_scale;					//�{�^���̊g�嗦
	vivid::Vector2 m_button_pos;			//�{�^���̈ʒu
	vivid::Vector2 Score_pos[max_player];	//�X�R�A�̈ʒu

	ScoreManager(void) = default;
	~ScoreManager(void) = default;
	ScoreManager(const ScoreManager& rhs) = delete;
	ScoreManager& operator=(const ScoreManager& rhs) = delete;

};