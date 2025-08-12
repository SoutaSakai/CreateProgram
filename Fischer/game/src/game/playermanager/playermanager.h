#pragma once
#include"vivid.h"

#include"Player/Player.h"
#include"../Charactermanager/CharacterID.h"

class Player;

class playermanager
{
public:

	static playermanager& GetInstance(void);

	void GetUseCharacter(CHARACTER_ID Character, int PlayerNo, int CharacterNo);

	void Initialize(const int MaxPlayer);
	void Update(void);
	void Draw(void);

	//スキルの当たり判定
	void CheckHitSkil(void);

	void Finalize(void);

	void InRoundCount(int RoundCount) { m_RoundCount = RoundCount; }
	int  GetRoundCount(void) { return 1/*m_RoundCount*/; }

	//SkilFlagとControlFlagを返す
	bool GetSkilFlag(int playernumber) const { return m_SkilFlag[playernumber]; }
	bool GetControlFlag(int playernumber) const { return m_ControlFlag[playernumber]; }

	//SkilFlagとControlFlagの内容を変える
	void ChangeSkilFlagTrue(int playernumber) { m_SkilFlag[playernumber] = true; }
	void ChangeControlFlagTrue(int playernumber) { m_ControlFlag[playernumber] = true; }

	void ChangeSkilFlagFalse(int playernumber){ m_SkilFlag[playernumber] = false; }
	void ChangeControlFlagFalse(int playernumber) { m_ControlFlag[playernumber] = false; }

	//プレイヤーの座標を渡す
	vivid::Vector2 GetPosition(int playernumber);
	//プレイヤーの角度を渡す
	float GetAngle(int playernumber);
	//プレイヤーが使っているキャラクターを渡す
	CHARACTER_ID GetCharacter(int playernumber);

	bool GetOctopusSlowFlag(int playernumber) const { return m_Octopus_Slow[playernumber]; }
	void ChangeOctopusSlowFlag(int playernumber, bool flag) { m_Octopus_Slow[playernumber] = flag; }

private:

	playermanager(void) = default;

	int MaxPlayer;		//プレイヤーの最大数

	int m_RoundCount;	//ラウンドのカウンタ

	bool SkilFlag[(int)vivid::controller::DEVICE_ID::MAX];				//スキルのフラグ
	bool ControlFlag[(int)vivid::controller::DEVICE_ID::MAX];			//プレイヤーが操作できるかどうか

	Player* player[(int)vivid::controller::DEVICE_ID::MAX];							//プレイヤーのオブジェクト生成
	CHARACTER_ID UseCharacter[(int)vivid::controller::DEVICE_ID::MAX][3];			//プレイヤーの使うキャラクター
	vivid::controller::DEVICE_ID DeviceID[(int)vivid::controller::DEVICE_ID::MAX];	//デバイスID格納変数

	vivid::Vector2 StartPos[4];

	//SkilFlag ==> スキルを使ている状態
	//ControlFlag ==> 操作できるかどうか
	bool m_SkilFlag[(int)vivid::controller::DEVICE_ID::MAX];
	bool m_ControlFlag[(int)vivid::controller::DEVICE_ID::MAX];

	//バフ・デバフのフラグ
	bool m_Octopus_Slow[(int)vivid::controller::DEVICE_ID::MAX];		//タコのスロウ効果がついているかどうか
};