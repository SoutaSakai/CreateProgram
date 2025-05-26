#pragma once
#include"vivid.h"

// �G�T�Ǘ��N���X
class Feed_manager
{
public:
	Feed_manager(void); // �R���X�g���N�^
	void Initialize(void); // ������
	void Update(vivid::Vector2, float); // ��ԍX�V
	void Draw(void); // �`��
	void Finalize(void); // �I������

private:
	vivid::Vector2 Fisher_feed_pos;        // �G�T�̍��W
	vivid::Vector2 Fisher_feed_center_pos; // �G�T�̒��S���W
	vivid::Vector2 Fisher_feed_hit_pos;    // �q�b�g����p���W
	const float Feed_radius = 24.0f;       // �G�T�̔��a
	const float Feed_radius_hit_length = 4.0f; // �q�b�g����p�̒���
	unsigned int Feed_color = 0xffffffff;  // �G�T�̐F
};