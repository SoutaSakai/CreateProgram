#include "scenemanager.h"
#include "iscene\scenes\title\title.h"
#include "iscene\scenes\gamemain\gamemain.h"
#include "iscene\scenes\result\result.h"

// �N���X�I�u�W�F�N�g�̎擾
SceneManager& SceneManager::GetInstance(void)
{
	static SceneManager instance;

	return instance;
}

// ������
void SceneManager::Initialize(void)
{
	// �^�C�g���ɐ؂�ւ���
	Change_scene(SCENE_ID::TITLE);
}

// �X�V
void SceneManager::Update(void)
{
	// �V�[���̐؂�ւ��m�F
	if (Current_scene_id != Next_scene_id)
		Change(); // �؂�ւ��֐�

	// �V�[���̍X�V
	Iscene->Update();
}

// �`��
void SceneManager::Draw(void)
{
	// �V�[���̕`��
	Iscene->Draw();
}

// ���
void SceneManager::Finalize(void)
{
	// �V�[���̉��
	Iscene->Finalize();

	// �V�[���I�u�W�F�N�g�̍폜
	delete Iscene;

	Iscene = nullptr;
}

// �V�[���̐؂�ւ��i�v���j
void SceneManager::Change_scene(SCENE_ID next_scene)
{
	Next_scene_id = next_scene;
}

// �V�[���̐؂�ւ��i���ۂ̓���j
void SceneManager::Change(void)
{
	if (Iscene != nullptr)
	{
		// ���ݓ����Ă���V�[�����I��点��
		Iscene->Finalize();

		delete Iscene;

		Iscene = nullptr;
	}

	// �V�����V�[�����쐬����
	switch (Next_scene_id)
	{
	case SCENE_ID::TITLE:
		Iscene = new Title();
		break;
	case SCENE_ID::GAMEMAIN:
		Iscene = new GAMEMAIN();
		break;
	case SCENE_ID::RESULT:
		Iscene = new RESULT();
		break;
	}

	// �k���`�F�b�N���s���A���Ȃ���Ώ��������Ă�
	if (Iscene)
		Iscene->Initialize();

	// �V�[��ID�����킹��
	Current_scene_id = Next_scene_id;
}

// �R���X�g���N�^
SceneManager::SceneManager(void)
	: Current_scene_id(SCENE_ID::DUMMY)
	, Next_scene_id(SCENE_ID::DUMMY)
	, Iscene(nullptr)
{
}

// �R�s�[�R���X�g���N�^
SceneManager::SceneManager(const SceneManager& rhs)
{
	(void)rhs;
}

// ���[�u�R���X�g���N�^
SceneManager::SceneManager(SceneManager&& rhs)
{
	(void)rhs;
}

// �f�X�g���N�^
SceneManager::~SceneManager(void)
{
}

// ������Z�q
SceneManager& SceneManager::operator=(const SceneManager& rhs)
{
	(void)rhs;

	return *this;
}


/*#include "vivid.h"
#include "scenemanager.h"
#include "scenes\title\title.h"
#include "scenes\gamemain\gamemain.h"
#include "scenes\result\result.h"

TITLE		title;
GAMEMAIN	gamemain;
RESULT		result;


SCENE_MANAGER::SCENE_MANAGER(void)
	: Current_scene(Scene_id::DUMMY)
{
}

void SCENE_MANAGER::Initialize(void)
{
	Change_scene(Scene_id::TITLE);
}

void SCENE_MANAGER::Update(void)
{
	switch (Current_scene)
	{
	case Scene_id::DUMMY:
		break;
	case Scene_id::TITLE:
		title.Update();
		break;
	case Scene_id::GAMEMAIN:
		gamemain.Update();
		break;
	case Scene_id::RESULT:
		result.Update();
		break;
	}
}

void SCENE_MANAGER::Draw(void)
{
	switch (Current_scene)
	{
	case Scene_id::DUMMY:
		break;
	case Scene_id::TITLE:
		title.Draw();
		break;
	case Scene_id::GAMEMAIN:
		gamemain.Draw();
		break;
	case Scene_id::RESULT:
		result.Draw();
		break;
	}
}

void SCENE_MANAGER::Finalize(void)
{
}

void SCENE_MANAGER::Change_scene(Scene_id next_scene)
{
	Current_scene = next_scene;
}*/
