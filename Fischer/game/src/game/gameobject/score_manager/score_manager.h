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
	static const int m_max_player = 4;	//�v���C���[�̐l��
	static const int m_point;			//�|�C���g�̉��Z�l�A���Z�l

	int m_Score[m_max_player];			//�X�R�A�ێ�
	int m_PlayerPosition[m_max_player];	//�v���C���[�ʒu

	vivid::Rect m_Rect;								//�{�^���̕`��͈�
	vivid::Vector2 m_Anchor;						//�{�^���̊�_
	vivid::Vector2 m_Scale;							//�{�^���̊g�嗦
	vivid::Vector2 m_ButtonPosition;				//�{�^���̈ʒu
	vivid::Vector2 m_ScorePosition[m_max_player];	//�X�R�A�̈ʒu

	ScoreManager(void) = default;
	~ScoreManager(void) = default;
	ScoreManager(const ScoreManager& rhs) = delete;
	ScoreManager& operator=(const ScoreManager& rhs) = delete;

};