#pragma once
#include "..\..\iscene.h"

class Gamemain : public IScene
{
public:
	Gamemain(void);
	~Gamemain(void) = default;

	void Initialize(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Finalize(void) override;

private:
	static const float		water_surface;
};