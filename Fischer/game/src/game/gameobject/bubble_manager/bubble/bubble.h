#pragma once
#include"vivid.h"


class Result;

class CBubble
{
public:
	CBubble(void);

	~CBubble(void);

	void Initialize(void);

	void Update(void);

	void Draw(void);

	void Finalize(void);

	bool GetActive(void);

	vivid::Vector2 GetPosition(void);

protected:

	static const vivid::Vector2 m_small_bubble_scale;		//小さい泡の大きさ
	static const vivid::Vector2 m_middle_bubble_scale;		//中くらいの泡の大きさ
	static const vivid::Vector2 m_large_bubble_scale;		//大きい泡の大きさ
	static const int			m_max_bubble;				//泡の上限
	static const int			m_bubble_speed;				//泡のスピード
	std::string			m_file_path;						//画像
	int					m_Width;							//幅
	int					m_Height;							//高さ
	float				m_Radius;							//半径
	vivid::Vector2		m_Position;							//最初の位置
	vivid::Vector2		m_Velocity;							//速度
	vivid::Vector2		m_Scale;							//拡大率
	vivid::Vector2      m_First_Position;					//この変数にm_Positionの値を代入してこっちで泡の位置を変える
	float				m_Rotation;							//回転値
	bool				m_AcitveFlag;						//アクティブフラグ
	int					m_Per;								//確率の変数
	int					m_BubbleCnt;						//泡の出たカウント
	unsigned int		m_BubbleColor;						//泡の透明度
	vivid::Rect         m_Rect;								//泡の範囲
	vivid::Vector2      m_Anchor;							//泡の基準点
	Result* m_result_button_position;

	float m_Bubble_Timer;



};