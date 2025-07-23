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
const float	Result::m_button_base_scale = 1.0f;	// �{�^���̊g�嗦�̏����l 
const float	Result::m_button_max_scale = 1.4f;	// �{�^���̍ő�g�嗦

Result::Result(void)
	:m_ButtonFlag(true)
{
}

void Result::Initialize(void)
{
	m_Score = new int[m_max_player];





	m_ButtonPosition[0] = { vivid::WINDOW_WIDTH / 2 - 145, vivid::WINDOW_HEIGHT / 1.4 }; //�L�����N�^�[�Z���N�g�ɖ߂�ق��̃{�^���̃|�W�V����
	m_ButtonPosition[1] = { vivid::WINDOW_WIDTH / 2 - 150, vivid::WINDOW_HEIGHT / 1.2 };	//��߂�̃{�^���̃|�W�V����
	m_ButtonAnchor = { 155,40 };													//�{�^���̊�_

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < m_max_player; j++)
		{
			m_Score[i] = 0.0f;
			//use_character[i][j].x = vivid::WINDOW_WIDTH / 3 + i * m_tuna_width;
			//use_character[i][j].y = vivid::WINDOW_HEIGHT / 4 + j * m_tuna_height;

			m_TextPosition[j].x = vivid::WINDOW_WIDTH / 6;										// �u�g�p�L�����N�^�[�v�������x��
			m_TextPosition[j].y = use_character[i][j].y + m_tuna_height / 2.0f - 25 / 2.0f;			// �u�g�p�L�����N�^�[�v�������y��

			m_ScorePosition[j].x = vivid::WINDOW_WIDTH / 2 + vivid::WINDOW_WIDTH / 3;					// ���_��x��
			m_ScorePosition[j].y = use_character[i][j].y + m_tuna_height / 2.0f - m_height / 2.0f;		// ���_��y��
		}
	}

	//�{�^���̌�
	for (int i = 0; i < m_max_button; i++)
	{
		m_ButtonRect[i] = { 0,0,310,80 };		//�{�^���͈̔�
	}

	m_BackGroundPosition = { 0.0f,0.0f };//�w�i�|�W�V�����̏�����
	m_CharacterSelectScale = { 1.2f,1.1f };//�L�����N�^�[�Z���N�g�ɖ߂�ق��̃{�^���̑傫��
	m_ExitScale = { 0.8f,0.8f };//�u��߂�v�{�^���̑傫��

	m_FramePosition = { vivid::WINDOW_WIDTH / 2 - 145, vivid::WINDOW_HEIGHT / 1.4 };		//�O�g�̈ʒu
	m_FrameAnchor = { 155,40 };
	m_FrameScale = { 1.2f,1.1f };
	m_FrameRect = { 0,0,310,80 };
}

void Result::Update(void)
{
	namespace keyboard = vivid::keyboard;

	if (keyboard::Trigger(keyboard::KEY_ID::W))//�L�����N�^�[�I����ʂɂ��ǂ�̃{�^��
	{
		m_CharacterSelectScale = { m_button_max_scale,m_button_max_scale };//�L�����N�^�[�Z���N�g��I�����Ă���Ƃ��̑傫��
		m_ExitScale = { m_button_base_scale,m_button_base_scale };//��߂�̃{�^���̊g�嗦��߂����̑傫��
		m_FramePosition = { vivid::WINDOW_WIDTH / 2 - 145, vivid::WINDOW_HEIGHT / 1.4 };		//�L�����N�^�[�Z���N�g�̃|�W�V�����̍��킹��O�g�̈ʒu
		m_FrameScale = { m_button_max_scale,m_button_max_scale };
		m_ButtonFlag = true;
	}
	if (keyboard::Trigger(keyboard::KEY_ID::S))//��߂�̃{�^��
	{
		m_CharacterSelectScale = { m_button_base_scale,m_button_base_scale };	//�L�����N�^�[�Z���N�g�̊g�嗦��߂��Ƃ��̑傫��
		m_ExitScale = { m_button_max_scale,m_button_max_scale };				//��߂�̃{�^����I�����Ă��鎞�̑傫��
		m_FramePosition = { vivid::WINDOW_WIDTH / 2 - 150, vivid::WINDOW_HEIGHT / 1.2 };	//��߂�̃{�^���̃|�W�V�����ɍ��킹��O�g
		m_FrameScale = { m_button_base_scale,m_button_base_scale };				//S�L�[���������Ƃ��̊O�g�̊g�嗦
		m_ButtonFlag = false;
	}

	if (keyboard::Trigger(keyboard::KEY_ID::RETURN))//ENTER�����������̏���
	{

		if (m_ButtonFlag)//W�{�^���̂Ƃ�
		{
			SceneManager::GetInstance().Change_scene(SCENE_ID::GAMEMAIN);
			ScoreManager::GetInstance().Initialize();
		}

		else//S�{�^���̂Ƃ�
		{

			SceneManager::GetInstance().Change_scene(SCENE_ID::TITLE);
		}

	}

//#ifdef VIVID_DEBUG
	// Z�L�[�ŃV�[���ύX
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		SceneManager::GetInstance().Change_scene(SCENE_ID::TITLE);
//#endif
}

void Result::Draw(void)
{
	vivid::CreateFont(25, 1);

#ifdef VIVID_DEBUG
	vivid::DrawTexture("data\\Seabackground2.png", m_BackGroundPosition, 0xffffffff);
	vivid::DrawText(24, "result", vivid::Vector2(0.0f, 0.0f));

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

		vivid::DrawText(25, "�g�p�L�����N�^�[", m_TextPosition[i]);
	}

	for (int x = 0; x < 3; x++)
		for (int y = 0; y < m_max_player; y++)
			vivid::DrawTexture("data\\Tuna.png", m_UseCharacterPosition[x][y]);

	vivid::DrawTexture("data\\back_character_select.png", m_ButtonPosition[0], 0xffffffff, m_ButtonRect[0], m_ButtonAnchor, m_CharacterSelectScale);
	vivid::DrawTexture("data\\exit.png", m_ButtonPosition[1], 0xffffffff, m_ButtonRect[1], m_ButtonAnchor, m_ExitScale);//���U���g�{�^���̕`��
	vivid::DrawTexture("data\\select_frame.png", m_FramePosition, 0xffffffff, m_FrameRect, m_FrameAnchor, m_FrameScale);//�O�g�̕`��

	vivid::DrawText(50, "�����L���O", vivid::Vector2(vivid::WINDOW_WIDTH / 2 - 125, vivid::WINDOW_HEIGHT / 10), 0xff000000);

#endif
}

void Result::Finalize(void)
{
}
