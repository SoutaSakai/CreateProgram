#pragma once
#include"../playermanager/Charactermanager/CharacterID.h"
#include"vivid.h"

class SkilManager
{
public:

	static SkilManager& GetInstance(void);

	//Tuna				マグロ
	void TunaSkilInitialize(void);
	vivid::Vector2 TunaSkil(vivid::Vector2 Pos,float Angle,bool* flag,float ScaleX);	

private:

	static const float fps;

	//Elsctriceel		電気うなぎ
	//Porcupinefish		ハリセンボン
	//Shark				サメ
	//Lionfish			ミノカサゴ
	//Mirrormoray		ミラーウツボ
	//Turtle			カメ
	//Octopus			タコ
	//Pointuna			ポインツナ
	//Tuna				マグロ
	static const float BlinkRange;		//ブリンクの距離
	static const float BlinkTime;		//ブリンクにかかる時間
	static const int BlinkCount;		//ブリンクを何回に分けるか

	float Timer;
	int Count;
};