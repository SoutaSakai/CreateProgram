#pragma once
#include"vivid.h"
#include"../../Character_manager/CharacterID.h"
#include"../../Character_manager/Character_manager.h"
#include"..\..\feed_manager\feed\feed_id.h"
#include"../player_manager.h"
#include "..\..\feed_manager\feed\feed.h"

//スキルインクルード
#include"../Skil/Tuna/Tuna.h"
#include"../Skil/Elsctriceel/Elsctriceel.h"
#include"../Skil/Turtle/Turtle.h"


class Player
{
public:
	Player();

	void Initialize(vivid::controller::DEVICE_ID Player_ID, float Xpos);

	void Update(void);

	void InUseCharacter(CHARACTER_ID first, CHARACTER_ID second, CHARACTER_ID third);
	void InUseCharacter(CHARACTER_ID first);

	void ChangeRound(void);

	//コントローラの入力処理
	void Controller(void);

	//スティックの入力で角度を求める
	void CharacterStick(void);

	//ゲームメイン画面のキーボード入力処理
	void KeyboardGamemain(void);

	//キャラクター選択画面のキーボード入力処理
	void KeyboardCharacterSelect(void);

	//画面外に出ないように
	void CheckWall(void);

	void Draw();

	void Finalize(void);

	void Setting(void);

	void SetFeedID(FEED_ID);

	bool CheckHitFeed(Feed*);

private:
	vivid::controller::DEVICE_ID m_PlayerID;

	CHARACTER_ID UseCharacter[3];

	vivid::Vector2 CharacterPos;	//characterの座標
	float CharaWIDTH;				//characterの横幅
	float CharaHEIGHT;				//characterの立幅
	float CharaSpeed;				//characterのスピード
	vivid::Rect CharaRect;			//characterのrect
	std::string CharaFilePath;		//characterのファイルパス
	vivid::Vector2 CharaMouthPos;	//characterの口の位置
	float CharaMouthRadius;			//characterの口の半径
	vivid::Vector2 Anchor;			//characterの中心
	float Angle;					//characterの角度
	vivid::Vector2 Scale;			//characterの拡大率

	int	CharaNo;					//今のラウンドのキャラ

	bool SkilFlag;				//スキルのフラグ
	bool ControlFlag;			//プレイヤーが操作できるかどうか

	int		m_Score;

	FEED_ID m_FeedID;

	static const float WaterHEIGHT;
	static const float MouthDis;

	//スキルクラス
	Tuna* tuna;
};

