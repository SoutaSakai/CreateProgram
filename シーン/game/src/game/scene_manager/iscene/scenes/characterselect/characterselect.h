#pragma once
#include "..\iscene.h"

class CHARACTERSELECT : public IScene
{
public:
	CHARACTERSELECT(void);
	~CHARACTERSELECT(void) = default;

	void Initialize(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Finalize(void) override;
};