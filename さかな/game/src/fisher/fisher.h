#pragma once
#include"vivid.h"
#include"../Player/Player.h"

// �ނ�l�N���X
class Fisher
{
public:
	Fisher(void);      // �R���X�g���N�^
	void Initialize(void); // ������
	void Update(void);     // ��ԍX�V
	void Draw(void);       // �`��
	void Finalize(void);   // �I������

private:
	vivid::Vector2  Fisher_pos; // �ނ�l�̍��W
};