#pragma once
#include"vivid.h"
#include"../Player/Player.h"

// 釣り人クラス
class Fisher
{
public:
	Fisher(void);      // コンストラクタ
	void Initialize(void); // 初期化
	void Update(void);     // 状態更新
	void Draw(void);       // 描画
	void Finalize(void);   // 終了処理

private:
	vivid::Vector2  Fisher_pos; // 釣り人の座標
};