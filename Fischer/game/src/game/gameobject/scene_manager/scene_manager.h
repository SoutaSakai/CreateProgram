#pragma once
#include "vivid.h"
#include "scene\scene_id.h"

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

	SCENE_ID GetCullentSceneId();

private:

	void Change(void);

	SceneManager(void);
	SceneManager(const SceneManager& rhs);
	SceneManager(SceneManager&& rhs);
	~SceneManager(void);
	SceneManager& operator=(const SceneManager& rhs);

	IScene* Iscene;
	SCENE_ID m_CurrentSceneId;
	SCENE_ID m_NextSceneId;
};

