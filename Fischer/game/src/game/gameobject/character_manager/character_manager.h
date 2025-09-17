#pragma once
#include"vivid.h"
#include"../Character_manager/CharacterID.h"

class CharacterManager
{
public:

	static CharacterManager& GetInstance(void);

	float			CharacterWIDTH(CHARACTER_ID Character);			//キャラクターの横幅を返す
	float			CharacterHEIGHT(CHARACTER_ID Character);		//キャラクターの縦幅を返す
	float			CharacterSpeed(CHARACTER_ID Character);			//キャラクターのスピードを返す
	vivid::Rect		CharacterRect(CHARACTER_ID Character);			//キャラクターのRectを返す
	std::string		CharacterFilePath(CHARACTER_ID Character);		//キャラクターのファイルパスを返す
	vivid::Vector2	CharacterMouthPos(CHARACTER_ID Character);		//キャラクターの口の位置を返す
	float			CharacterMouthRadius(CHARACTER_ID Character);	//キャラクターの口の半径を返す
	int				CharacterUsagelimit(CHARACTER_ID Character);	//キャラクターのスキル使用回数を返す

	//スキル効果
	float GetSlowSpeed(void) const { return SlowSpeed; }

	void Finalize(void);

private:

	//Elsctriceel		電気うなぎ
	static const float ElsctriceelWIDTH;				//電気ウナギの横幅
	static const float ElsctriceelHEIGHT;				//電気うなぎの立幅
	static const float ElsctriceelSpeed;				//電気ウナギのスピード
	static const vivid::Rect ElsctriceelRect;			//電気ウナギのRect
	static const std::string ElsctriceelFilePath;		//電気うなぎのファイルパス
	static const vivid::Vector2 ElsctriceelMouthPos;	//電気ウナギの口の位置
	static const float ElsctriceelMouthRadius;			//電気うなぎの口の半径
	static const int ElsctriceelUsagelimit;				//電気うなぎのスキルの回数制限

	//Porcupinefish		ハリセンボン
	static const float PorcupinefishWIDTH;				//ハリセンボンの横幅
	static const float PorcupinefishHEIGHT;				//ハリセンボンの立幅
	static const float PorcupinefishSpeed;				//ハリセンボンのスピード
	static const vivid::Rect PorcupinefishRect;			//ハリセンボンのRect
	static const std::string PorcupinefishFilePath;		//ハリセンボンのファイルパス
	static const vivid::Vector2 PorcupinefishMouthPos;	//ハリセンボンの口の位置
	static const float PorcupinefishMouthRadius;		//ハリセンボンの口の半径
	static const int PorcupinefishUsagelimit;			//ハリセンボンのスキルの回数制限

	//Shark				サメ
	static const float SharkWIDTH;					//サメの横幅
	static const float SharkHEIGHT;					//サメの立幅
	static const float SharkSpeed;					//サメのスピード
	static const vivid::Rect SharkRect;				//サメのRect
	static const std::string SharkFilePath;			//サメのファイルパス
	static const vivid::Vector2 SharkMouthPos;		//サメの口の位置
	static const float SharkMouthRadius;			//サメの口の半径
	static const int SharkUsagelimit;				//サメのスキルの回数制限

	//Lionfish			ミノカサゴ
	static const float LionfishWIDTH;				//ミノカサゴの横幅
	static const float LionfishHEIGHT;				//ミノカサゴの立幅
	static const float LionfishSpeed;				//ミノカサゴのスピード
	static const vivid::Rect LionfishRect;			//ミノカサゴのRect
	static const std::string LionfishFilePath;		//ミノカサゴのファイルパス
	static const vivid::Vector2 LionfishMouthPos;	//ミノカサゴの口の位置
	static const float LionfishMouthRadius;			//ミノカサゴの口の半径
	static const int LionfishUsagelimit;			//ミノカサゴのスキルの回数制限

	//Mirrormorayell		ミラーウツボ
	static const float MirrormorayellWIDTH;				//ミラーウツボの横幅
	static const float MirrormorayellHEIGHT;			//ミラーウツボの立幅
	static const float MirrormorayellSpeed;				//ミラーウツボのスピード
	static const vivid::Rect MirrormorayellRect;		//ミラーウツボのRect
	static const std::string MirrormorayellFilePath;	//ミラーウツボのファイルパス
	static const vivid::Vector2 MirrormorayellMouthPos;	//ミラーウツボの口の位置
	static const float MirrormorayellMouthRadius;		//ミラーウツボの口の半径
	static const int MirrormorayellUsagelimit;			//ミラーウツボのスキルの回数制限

	//Turtle			カメ
	static const float TurtleWIDTH;					//カメの横幅
	static const float TurtleHEIGHT;				//カメの立幅
	static const float TurtleSpeed;					//カメのスピード
	static const vivid::Rect TurtleRect;			//カメのRect
	static const std::string TurtleFilePath;		//カメのファイルパス
	static const vivid::Vector2 TurtleMouthPos;		//カメの口の位置
	static const float TurtleMouthRadius;			//カメの口の半径
	static const int TurtleUsagelimit;				//カメのスキルの回数制限

	//Octopus			タコ
	static const float OctopusWIDTH;				//タコの横幅
	static const float OctopusHEIGHT;				//タコの立幅
	static const float OctopusSpeed;				//タコのスピード
	static const vivid::Rect OctopusRect;			//タコのRect
	static const std::string OctopusFilePath;		//タコのファイルパス
	static const vivid::Vector2 OctopusMouthPos;	//タコの口の位置
	static const float OctopusMouthRadius;			//タコの口の半径
	static const float SlowSpeed;					//タコの鈍足効果
	static const int OctopusUsagelimit;				//タコのスキルの回数制限

	//Pointuna			ポインツナ
	static const float PointunaWIDTH;				//ポインツナの横幅
	static const float PointunaHEIGHT;				//ポインツナの立幅
	static const float PointunaSpeed;				//ポインツナのスピード
	static const vivid::Rect PointunaRect;			//ポインツナのRect
	static const std::string PointunaFilePath;		//ポインツナのファイルパス
	static const vivid::Vector2 PointunaMouthPos;	//ポインツナの口の位置
	static const float PointunaMouthRadius;			//ポインツナの口の半径
	static const int PointunaUsagelimit;			//ポインツナのスキルの回数制限

	//Tuna				マグロ
	static const float TunaWIDTH;					//マグロの横幅
	static const float TunaHEIGHT;					//マグロの立幅
	static const float TunaSpeed;					//マグロのスピード
	static const vivid::Rect TunaRect;				//マグロのRect
	static const std::string TunaFilePath;			//マグロのファイルパス
	static const vivid::Vector2 TunaMouthPos;		//マグロの口の位置
	static const float TunaMouthRadius;				//マグロの口の半径
	static const int TunaUsagelimit;				//マグロのスキルの回数制限

};

