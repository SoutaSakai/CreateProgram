#pragma once
#include "vivid.h"
#include "iscene\scenes\scene_id.h"

class IScene;

class SceneManager
{
public:

	static SceneManager& GetInstance(void);

	void Initialize(void);
	
	void Update(void);
	
	void Draw(void);
	
	void Finalize(void);

	void Change_scene(SCENE_ID next_scene);

private:

	void Change(void);

	SceneManager(void);
	SceneManager(const SceneManager& rhs);
	SceneManager(SceneManager&& rhs);
	~SceneManager(void);
	SceneManager& operator=(const SceneManager& rhs);

	IScene* Iscene;
	SCENE_ID Current_scene_id;
	SCENE_ID Next_scene_id;
};

