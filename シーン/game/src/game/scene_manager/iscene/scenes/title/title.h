#pragma once
#include "..\iscene.h"

class TITLE : public IScene
{
public:
	TITLE(void);
	~TITLE(void) = default;

	void Initialize(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Finalize(void) override;
};