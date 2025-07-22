#include "scene_manager.h"
#include "scene\title\title.h"
#include "scene\characterselect\characterselect.h"
#include "scene\gamemain\gamemain.h"
#include "scene\result\result.h"

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
	case SCENE_ID::CHARACTERSELECT:
		Iscene = new CharacterSelect();
		break;
	case SCENE_ID::GAMEMAIN:
		Iscene = new Gamemain();
		break;
	case SCENE_ID::RESULT:
		Iscene = new Result();
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