#pragma once
#include "vivid.h"
#include "fisherstate.h"

class FisherManager
{
public:

	static FisherManager& GetInstance(void);

	void Initialize(void);

	void Update(void);

	void Draw(void);

	void Finalize(void);

private:

	// �ނ�l�̐l��
	static const int Max_Fisher = 5;
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
	int Fisher_state[];

	// �R���X�g���N�^
	FisherManager(void) = default;
	// �f�X�g���N�^
	~FisherManager(void) = default;
	// �R�s�[�R���X�g���N�^
	FisherManager(const FisherManager& rhs) = delete;
	// ���[�u�R���X�g���N�^
	FisherManager& operator=(const FisherManager& rhs) = delete;
};