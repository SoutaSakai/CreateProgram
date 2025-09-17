#pragma once
#include"vivid.h"

#include"../../../character_manager/character_manager.h"
#include"../../../player_manager/player_manager.h"

class Elsctriceel
{
public:

	void Initialize(int playernumber);
	void Update(vivid::Vector2 Pos);

	void CheckHitSkill(void);

	//基準点を返す
	vivid::Vector2 GetCenterPosition(void) const { return m_CenterPosition; }

	void CollisionDetection(int number, int pattern);

private:

	static const float SkillSize;				//効果範囲(円の直径)
	static const float AbilityTime;				//効果時間
	static const int	m_stan_time;			//スタン時間
	static const int	m_score;			//スタンした時にもらえるポイント

	vivid::Vector2		m_CenterPosition;

	bool				m_Flag[(int)vivid::controller::DEVICE_ID::MAX];

	float Timer;

	int		m_MaxPlayer;
	int		m_PlayerNumber;
};