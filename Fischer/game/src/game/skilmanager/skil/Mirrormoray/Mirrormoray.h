#pragma once
#include"vivid.h"

#include"../../../charactermanager/charactermanager.h"
#include"../../../playermanager/playermanager.h"

class CMirrormoray
{
public:

	//�R���X�g���N�^
	CMirrormoray(void);
	//�f�X�g���N�^
	~CMirrormoray(void) = default;

	void Initialize(int playernumber);
	void Update(vivid::Vector2 pos,float angle,float scalex);
	void Finalize(void);

private:

	static const int		m_MaxDecoy;		//���g�̐�
	static const float		m_Range;		//���g���o�鋗��

	static const float		m_width;		//����
	static const float		m_height;		//����

	vivid::Vector2			m_Position;		//���W
	vivid::Rect				m_Rect;			//�\���͈�
	std::string				m_FilePath;		//�t�@�C���p�X
	vivid::Vector2			m_Anchor;
	float					m_Angle;		//�p�x

	int m_PlayerNumber;

};