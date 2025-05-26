#pragma once
//スピードタイプ.h
#include"vivid.h"
#include"../Player.h"

class Speed_type:public Player

{
public:
	Speed_type();

	void Initialize(void);

	void Update(void);

	void Draw(void);

	void Finalize(void);


private:
	
	static const float Speed_type_speed ;//スピードタイプキャラの基準スピード





};