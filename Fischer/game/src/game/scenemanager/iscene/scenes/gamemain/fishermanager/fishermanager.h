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

private:

	// �ނ�l�̐l��
	static const int Max_Fisher;
	// �ނ�l�̏�ԍX�V����
	static const float Fisher_Time;
	// �ނ�l�̍��W
	static const vivid::Vector2 Fisher_Pos[];
	// �ނ�l�̕�
	static const float Fisher_WIDTH;
	// �ނ�l�̍���
	static const float Fisher_HEIGHT;
	// �ނ�l�̊Ԋu
	static const float Fisher_Distance;
	// �ނ�l�̕`��͈�
	static const vivid::Rect Fisher_Rect;


	// �ނ�l�̏�Ԃ̊Ǘ�
	int Fisher_state[5];
	// �ނ�l�̏�ԍX�V�^�C�}�[
	float Fisher_timer;


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