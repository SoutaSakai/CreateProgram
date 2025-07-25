#include "..\..\scene_manager.h"
#include "..\scene_id.h"
#include "..\..\..\score_manager\score_manager.h"
#include "result.h"
#include "vivid.h"

const int	Result::m_width = 32;				// ������̕�
const int	Result::m_height = 48;				// ������̍���
const int	Result::m_tuna_width = 220;			// �}�O���̕�
const int	Result::m_tuna_height = 80;			// �}�O���̍���
const int	Result::m_max_player = 4;			// �v���C���[�l��
const int	Result::m_max_button = 2;			// �{�^���̌�

Result::Result(void)
	: m_ButtonFlag(true)
	, m_CharacterSelectBaseScale(vivid::Vector2(1.2f, 1.2f))
	, m_ExitBaseScale(vivid::Vector2(0.8f, 0.8f))
	, m_CharacterSelectMaxScale(vivid::Vector2(1.4f, 1.4f))
	, m_ExitMaxScale(vivid::Vector2(1.0f, 1.0f))
{
}

void Result::Initialize(void)
{
	m_Score = new int[m_max_player];
	m_ScorePosition = new vivid::Vector2[m_max_player];
	m_TextPosition = new vivid::Vector2[m_max_player];
	m_ButtonPosition = new vivid::Vector2[m_max_player];
	m_ButtonRect = new vivid::Rect[m_max_player];
	m_UseCharacterPosition = new UseCharacter[m_max_player];
	for (int i = 0; i < m_max_player; i++)
	{
		m_UseCharacterPosition[i].Character = new vivid::Vector2[m_max_player];
	}

	m_ButtonPosition[0] = { vivid::WINDOW_WIDTH / 2 - 145, vivid::WINDOW_HEIGHT / 1.4 }; //�L�����N�^�[�Z���N�g�ɖ߂�ق��̃{�^���̃|�W�V����
	m_ButtonPosition[1] = { vivid::WINDOW_WIDTH / 2 - 150, vivid::WINDOW_HEIGHT / 1.15 };	//��߂�̃{�^���̃|�W�V����
	m_ButtonAnchor = { 155,40 };													//�{�^���̊�_

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < m_max_player; j++)
		{
			m_Score[i] = 0.0f;

			// �݂����R�[�h===>
			//use_character[i][j].x = vivid::WINDOW_WIDTH / 3 + i * m_tuna_width;
			//use_character[i][j].y = vivid::WINDOW_HEIGHT / 4 + j * m_tuna_height;
			
			//text_pos[j].x = vivid::WINDOW_WIDTH / 6;										// �u�g�p�L�����N�^�[�v�������x��
			//text_pos[j].y = use_character[i][j].y + m_tuna_height / 2.0f - 25 / 2.0f;			// �u�g�p�L�����N�^�[�v�������y��
			//<===

			// �V�R�[�h===>
			m_UseCharacterPosition[j].Character[i].x = vivid::WINDOW_WIDTH / 3 + i * m_tuna_width;
			m_UseCharacterPosition[j].Character[i].y = vivid::WINDOW_HEIGHT / 4 + j * m_tuna_height;

			m_TextPosition[j].x = vivid::WINDOW_WIDTH / 6;
			m_TextPosition[j].y = m_UseCharacterPosition[j].Character[i].y + m_tuna_height / 2.0f - 25 / 2.0f;
			//<===

			m_ScorePosition[j].x = vivid::WINDOW_WIDTH / 2 + vivid::WINDOW_WIDTH / 3;					// ���_��x��
			m_ScorePosition[j].y = m_UseCharacterPosition[j].Character[i].y + m_tuna_height / 2.0f - m_height / 2.0f;		// ���_��y��
		}
	}

	//�{�^���̌�
	for (int i = 0; i < m_max_button; i++)
	{
		m_ButtonRect[i] = { 0,0,310,80 };		//�{�^���͈̔�
	}

	m_BackGroundPosition = { 0.0f,0.0f };//�w�i�|�W�V�����̏�����
	m_CharacterSelectScale = m_CharacterSelectBaseScale;//�L�����N�^�[�Z���N�g�ɖ߂�ق��̃{�^���̑傫��
	m_ExitScale = m_ExitBaseScale;//�u��߂�v�{�^���̑傫��
}

void Result::Update(void)
{
	namespace keyboard = vivid::keyboard;

	
	// �啝����===>

	//�L�����N�^�[�I����ʂɂ��ǂ�̃{�^��
	if (keyboard::Trigger(keyboard::KEY_ID::W))
	{
		m_CharacterSelectScale = m_CharacterSelectMaxScale;		//�L�����N�^�[�Z���N�g��I�����Ă���Ƃ��̑傫��
		m_ExitScale = m_ExitBaseScale;							//��߂�̃{�^���̊g�嗦��߂����̑傫��
		m_ButtonFlag = true;
	}

	//��߂�{�^��
	if (keyboard::Trigger(keyboard::KEY_ID::S))
	{
		m_CharacterSelectScale = m_CharacterSelectBaseScale;	//�L�����N�^�[�Z���N�g�̊g�嗦��߂��Ƃ��̑傫��
		m_ExitScale = m_ExitMaxScale;							//��߂�̃{�^����I�����Ă��鎞�̑傫��
		m_ButtonFlag = false;
	}


	//<===

	//ENTER�����������̏���
	if (keyboard::Trigger(keyboard::KEY_ID::RETURN))
	{
		//W�{�^���̂Ƃ�
		if (m_ButtonFlag)
		{
			SceneManager::GetInstance().Change_scene(SCENE_ID::GAMEMAIN);
			ScoreManager::GetInstance().Initialize();
		}
		//S�{�^���̂Ƃ�
		else
		{
			SceneManager::GetInstance().Change_scene(SCENE_ID::TITLE);
		}
	}

#ifdef VIVID_DEBUG
	// Z�L�[�ŃV�[���ύX
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::TITLE);
#endif
}

void Result::Draw(void)
{
	vivid::CreateFont(25, 1);

	vivid::DrawTexture("data\\Seabackground2.png", m_BackGroundPosition, 0xffffffff);

	vivid::Rect rect = { 0,0,0,0 };

	for (int i = 0; i < m_max_player; i++)
	{
		int TempScore = ScoreManager::GetInstance().GetScore(i);

		vivid::Vector2 m_point_pos = m_ScorePosition[i];

		//�|�C���g�̕\���̌v�Z
		do
		{
			int Digit = TempScore % 10;

			rect.left = Digit * m_width;
			rect.right = rect.left + m_width;
			rect.top = 0;
			rect.bottom = m_height;

			TempScore /= 10;

			m_point_pos.x -= m_width;

			vivid::DrawTexture("data\\number.png", m_point_pos, 0xffffffff, rect);

		} while (TempScore > 0);

		vivid::DrawTexture("data\\first.png", m_TextPosition[i] - vivid::Vector2(110.0f,35.0f));
		vivid::DrawTexture("data\\use_character_text.png", m_TextPosition[i]);
	}


	for (int i = 0; i < 3; i++)
		for (int j = 0; j < m_max_player; j++)
			vivid::DrawTexture("data\\Tuna.png", m_UseCharacterPosition[j].Character[i]);

	vivid::DrawTexture("data\\back_character_select.png", m_ButtonPosition[0], 0xffffffff, m_ButtonRect[0], m_ButtonAnchor, m_CharacterSelectScale);
	vivid::DrawTexture("data\\exit.png", m_ButtonPosition[1], 0xffffffff, m_ButtonRect[1], m_ButtonAnchor, m_ExitScale);//���U���g�{�^���̕`��
	vivid::DrawText(50, "�����L���O", vivid::Vector2(vivid::WINDOW_WIDTH / 2 - 125, vivid::WINDOW_HEIGHT / 10), 0xff000000);

#ifdef VIVID_DEBUG
	vivid::DrawText(24, "result", vivid::Vector2(0.0f, 0.0f));
	vivid::DrawLine(vivid::Vector2(90.0f, 100.0f), vivid::Vector2(1190.0f, 100.0f), 0xffffffff);
#endif
}

void Result::Finalize(void)
{
}
