#pragma once
#include"vivid.h"
#include"../../Charactermanager/CharacterID.h"
#include"../../Charactermanager/Charactermanager.h"

#include"../playermanager.h"

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

	//キーボード入力処理
	void Keyboard(void);

	//画面外に出ないように
	void CheckWall(void);

	void Draw();

	void Finalize(void);

	void Setting(void);

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

	int	CharaNo;					//今のラウンドのキャラ

	vivid::Vector2 Anchor;			//characterの中心
	float Angle;					//characterの角度
	vivid::Vector2 Scale;			//characterの拡大率

	bool SkilFlag;				//スキルのフラグ
	bool ControlFlag;			//プレイヤーが操作できるかどうか

	static const float WaterHEIGHT;

	//追加コード===>
	bool Hit_feed[4];	// 餌とのアタリ判定の結果
	//<===

	//スキルクラス
	Tuna* tuna;


};

