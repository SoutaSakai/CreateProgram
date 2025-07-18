#pragma once

#include"vivid.h"

#include"../../../charactermanager/charactermanager.h"
#include"../../../playermanager/playermanager.h"

class CLionFish
{
public:

	void Intialize(int playernumber,vivid::Vector2 position);
	void Update(void);
	void Draw(void);
	void Finalize(void);

private:
	
	static const std::string		m_filepath;			//�t�@�C���p�X
	static const int				m_width;			//����
	static const int				m_height;			//����

	static const vivid::Rect		m_rect;				//�\���͈�
	static const vivid::Vector2		m_anchor;			//��_

	static const float				m_abilityTime;		//���ʎ���
	static const vivid::Vector2		m_scalespeed;		//�X�P�[���X�s�[�h

	vivid::Vector2					m_position;			//���W
	vivid::Vector2					m_scale;			//�g�嗦

	unsigned int					m_Color;			//�F
	int								m_playernumber;		//�v���C���[ID
	float							m_timer;			//�^�C�}�[

};
