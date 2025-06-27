#pragma once
#include "vivid.h"
#include "fisherstate.h"

class FisherManager
{
public:

	// �C���X�^���X���擾
	static FisherManager& GetInstance(void);

	// ������
	void Initialize(void);

	// �X�V
	void Update(void);

	// �`��
	void Draw(void);

	// ���
	void Finalize(void);

	// �a��H�ׂ�ꂽ���̏���
	void CaughtFeed(void);

private:

	// �ނ�l�̐l��
	static const int Max;
	// �ނ�l�̏�ԍX�V����
	static const float Change_time;

	// �ނ�l�̕�
	static const float Width;
	// �ނ�l�̍���
	static const float Height;
	// �ނ�l�̊Ԋu
	static const float Distance;
	// �ނ�l�̕`��͈�
	static const vivid::Rect Rect;


	// �ނ�l�̏�Ԃ̊Ǘ�
	int State[5];
	// �ނ�l�̏�ԍX�V�^�C�}�[
	float Timer;
	// �ނ�l�̍��W
	vivid::Vector2 Position[5];

	// �ނ�l�̏�Ԃ������_���ɍX�V
	void FisherRandState(void);

	// �R���X�g���N�^
	FisherManager(void) = default;
	// �f�X�g���N�^
	~FisherManager(void) = default;
	// �R�s�[�R���X�g���N�^
	FisherManager(const FisherManager& rhs) = delete;
	// ������Z�q
	FisherManager& operator=(const FisherManager& rhs) = delete;
};