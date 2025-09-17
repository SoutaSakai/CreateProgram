#pragma once
#include "..\scene.h"
#include "vivid.h"
#include "..\..\..\character_manager\characterID.h"
#include <list>

struct CHARACTER_DATE
{
	CHARACTER_ID first;
	CHARACTER_ID second;
	CHARACTER_ID third;
};

class CharacterSelect : public IScene
{
public:
	CharacterSelect(void);
	~CharacterSelect(void) = default;

	void Initialize(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Finalize(void) override;

	void SetCullentSelect(int, int);

private:
	void Keyboard(void);
	void controller(void);
	bool CheckUseCharacter(void);
	void ChangeScene(void);
	vivid::Vector2 GetFlamePosition(int);
	
	//using USECHARACTERLIST = std::list<CHARACTER_ID*>;

	static const int			m_flame_width;		// 選択枠の幅
	static const int			m_flame_height;		// 選択枠の高さ
	static const int			m_max_character;	// キャラクターの最大数
	//static const int			m_two_player;		// 2人プレイ時の最大人数
	//static const int			m_three_player;		// 3人プレイ時の最大人数
	//static const int			m_four_player;		// 4人プレイ時の最大人数
	static const int			m_distance;			// 表示間隔

	int							m_MaxPlayer;

	//デバイスID格納変数
	static const vivid::controller::DEVICE_ID m_controller[(int)vivid::controller::DEVICE_ID::MAX];

	//フレームの色
	static const unsigned int m_default_color[(int)vivid::controller::DEVICE_ID::MAX];

	vivid::Vector2*				m_CharacterPosition;	// キャラクターの座標
	vivid::Vector2*				m_FlamePosition;		// 選択枠の座標
	int*						m_CurrentSelect;		// 選択中キャラクターのID
	int* m_FlameNumber;			// 選択枠の数

	bool									m_Ready;				//UseCharacterがすべて埋まったか
	int										m_ControllerTime;		//コントローラーのタイマー

	CHARACTER_DATE*			m_UseCharacter;

	//デバック用
	int d_Keyboard = 0;
};