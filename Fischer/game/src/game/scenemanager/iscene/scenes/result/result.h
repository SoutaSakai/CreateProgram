#pragma once
#include "..\iscene.h"

class RESULT : public IScene
{
public:
	RESULT(void);
	~RESULT(void) = default;

	void Initialize(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Finalize(void) override;
};