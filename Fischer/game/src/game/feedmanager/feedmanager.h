#pragma once
#include <list>
#include "vivid.h"

class Feed;

class FeedManager
{
public:
	static FeedManager& GetInstance(void);

	// ������
	void Initialize(int);

	// �X�V
	void Update(void);

	// �`��
	void Draw(void);

	// ���
	void Finalize(void);

	// �v���C���[�̌��Ƃ̃A�^������
	bool CheckHit(vivid::Vector2, float, int);

	// �a�̐���
	void Create(vivid::Vector2, int);

	// �a�̍폜
	void Destroy(int);

private:
	static const vivid::Vector2	m_range;	// �ނ�l����a�܂ł̋���

	Feed*	m_Feeds[5];			// �a�̃I�u�W�F�N�g�z��
	int		m_max;				// �a�̍ő�l

	FeedManager(void);
	~FeedManager(void) = default;
	FeedManager(const FeedManager& rhs) = delete;
	FeedManager& operator=(const FeedManager& rhs) = delete;
};