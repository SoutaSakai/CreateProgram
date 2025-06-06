#pragma once
#include"vivid.h"
#include"../Charactermanager/CharacterID.h"
#include"../Charactermanager/Charactermanager.h"

class Player
{
public:
	Player(vivid::controller::DEVICE_ID playerID);

	void Initialize();

	void Update(void);

	void InUseCharacter(CHARACTER_ID first, CHARACTER_ID second, CHARACTER_ID third);
	void InUseCharacter(CHARACTER_ID first);

	//コントローラの入力処理
	void Controller(void);

	//スティックの入力で角度を求める
	void CharacterStick(void);

	void Keyboard(void);

	void Draw();

	void Finalize(void);
	

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
};

