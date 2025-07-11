#pragma once

#include"vivid.h"

#include"../../../playermanager/playermanager.h"
#include"../../../charactermanager/charactermanager.h"

class COctopus
{
public:

	//�R���X�g���N�^
	COctopus(void);

	//������
	void Initialize(int playernumber, vivid::Vector2 positon,vivid::Vector2 scale);

	//�X�V
	void Update(void);

	//���
	void Finalize(void);

private:

	static const float			m_AbilityTime;	//���ʎ���
	static const std::string	m_FilePath;		//�t�@�C���p�X
	static const float			m_ScaleSpeed;	//�X�P�[���X�s�[�h
	static const unsigned int	m_TransparencySpeed;		//���߃X�s�[�h

	static const int			m_InkWidth;		//�C���N�̉���
	static const int			m_InkHeight;	//�C���N�̗���

	vivid::Vector2				m_Position;		//���W
	unsigned int				m_Color;
	vivid::Rect					m_Rect;			//�\���͈�
	vivid::Vector2				m_Anchor;		//��_
	vivid::Vector2				m_Scale;		//�g�嗦

	float						m_Timer;		//�^�C�}�[
	int							m_PlayerNumber;	//�v���C���[���ʔԍ�

};