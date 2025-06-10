#pragma once
#include "..\iscene.h"

class GAMEMAIN : public IScene
{
public:
	GAMEMAIN(void);
	~GAMEMAIN(void) = default;

	void Initialize(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Finalize(void) override;
};