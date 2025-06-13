#pragma once
#include "vivid.h"
#include "iscene\scenes\scene_id.h"

class IScene;

class SCENE_MANAGER
{
public:

	static SCENE_MANAGER& GetInstance(void);

	void Initialize(void);
	
	void Update(void);
	
	void Draw(void);
	
	void Finalize(void);

	void Change_scene(SCENE_ID next_scene);

private:

	void Change(void);

	SCENE_MANAGER(void);
	SCENE_MANAGER(const SCENE_MANAGER& rhs);
	SCENE_MANAGER(SCENE_MANAGER&& rhs);
	~SCENE_MANAGER(void);
	SCENE_MANAGER& operator=(const SCENE_MANAGER& rhs);

	IScene* Iscene;
	SCENE_ID Current_scene_id;
	SCENE_ID Next_scene_id;
};

