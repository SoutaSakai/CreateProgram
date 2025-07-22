#include "game.h"
#include "gameobject\scene_manager\scene_manager.h"

/**
 *	@brief	�v���O�����J�n����1�x�����Ă΂��B
 *			�Q�[���ɕK�v�ȃf�[�^�̏��������s���B
 */
void Initialize_game(void)
{
	SceneManager::GetInstance().Initialize();
}

/**
 *	@brief	�v���O�����̎��s���Ɍp���I�ɌĂяo�����B
 *			1�t���[�����Ƃ̃Q�[���̍X�V
 */
void Update_game(void)
{
	SceneManager::GetInstance().Update();
}

/**
 *	@brief	�v���O�����̎��s���Ɍp���I�ɌĂяo�����B
 *			1�t���[�����Ƃ̕`��
 */
void Draw_game(void)
{
	SceneManager::GetInstance().Draw();
}

/**
 *	@brief	�v���O�����̏I������1�x�����Ă΂��B
 */
void Finalize_game(void)
{
	SceneManager::GetInstance().Finalize();
}