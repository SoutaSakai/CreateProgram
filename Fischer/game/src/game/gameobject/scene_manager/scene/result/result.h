#pragma once
#include "..\scene.h"

class Result : public IScene
{
public:
	Result(void);
	~Result(void) = default;

	void Initialize(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Finalize(void) override;

private:

	static const int m_width;			//�i���o�[�摜�T�C�Y�̕�
	static const int m_height;			//�i���o�[�摜�T�C�Y�̍���
	static const int m_tuna_width;		//�c�i�摜�T�C�Y�̕�
	static const int m_tuna_height;		//�c�i�摜�T�C�Y�̍���
	static const int m_max_player = 4;	//�v���C���[�l��
	static const int m_button = 2;		//�{�^���̌�


	int				m_Score[m_max_player];						// �X�R�A�|�C���g
	vivid::Vector2	m_ScorePosition[m_max_player];				// �|�C���g�̃|�W�V����
	vivid::Vector2	m_UseCharacter[m_max_player][m_max_player];	// �}�O���̕`��
	vivid::Vector2	m_UseDrawText[m_max_player];				// �g�p�L�����N�^�[��DrawText
	vivid::Vector2	m_BackGround;								// �w�i
	vivid::Vector2	m_ResultButtonPosition[m_button];			// �{�^���̃|�W�V����
	vivid::Vector2	m_ResultAnchor[m_button];					// ��_
	vivid::Vector2	m_ResultCharacterSelectScale;				// �L�����N�^�[�Z���N�g�{�^���̊g�嗦
	vivid::Vector2	m_ResultExitScale;							// ��߂�{�^���̊g�嗦
	vivid::Rect		m_ResultRect[m_button];						// �͈�
	vivid::Vector2	m_SelectFramePosition;						// �O�g�̃|�W�V����
	vivid::Vector2	m_SelectFrameAnchor;						// �O�g�̊�_
	vivid::Vector2	m_SelectFrameScale;							// �O�g�̊g�嗦
	vivid::Rect		m_SelectFrameRect;							// �O�g�͈̔�
	unsigned int	m_WordColor[m_button];						// DrawText�̐F
	bool			m_ButtonFlag;								// �{�^���̌���
};