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

	static const int	m_width;				// �i���o�[�摜�T�C�Y�̕�
	static const int	m_height;				// �i���o�[�摜�T�C�Y�̍���
	static const int	m_tuna_width;			// �c�i�摜�T�C�Y�̕�
	static const int	m_tuna_height;			// �c�i�摜�T�C�Y�̍���
	static const int	m_max_player;			// �v���C���[�l��
	static const int	m_max_button;			// �{�^���̌�
	static const float	m_button_base_scale;	// �{�^���̊g�嗦�̏����l
	static const float	m_button_max_scale;		// �{�^���̍ő�g�嗦


	int*			m_Score;					// ���_
	vivid::Vector2*	m_ScorePosition;			// ���_�̍��W
	vivid::Vector2	m_UseCharacterPosition/*[]*/;	// �g�p�L�����N�^�[�̍��W
	vivid::Vector2*	m_TextPosition;				// �u�g�p�L�����N�^�[�v������̍��W
	vivid::Vector2	m_BackGroundPosition;		// �w�i�̍��W
	vivid::Vector2*	m_ButtonPosition;			// �{�^���̍��W
	vivid::Vector2	m_ButtonAnchor;				// �{�^���̊�_
	vivid::Vector2	m_CharacterSelectScale;		// �L�����N�^�[�Z���N�g�{�^���̊g�嗦
	vivid::Vector2	m_ExitScale;				// ��߂�{�^���̊g�嗦
	vivid::Rect*	m_ButtonRect;				// �{�^���͈̔�
	vivid::Vector2	m_FramePosition;			// �O�g�̍��W
	vivid::Vector2	m_FrameAnchor;				// �O�g�̊�_
	vivid::Vector2	m_FrameScale;				// �O�g�̊g�嗦
	vivid::Rect		m_FrameRect;				// �O�g�͈̔�
	bool			m_ButtonFlag;				// �{�^���̌���
};