#pragma once

enum SceneState {
	STARTING,
	PROGRESSING,
	ENDING
};

class Scene
{
protected:
	SceneState	sceneState;
	int			alphaValue;

public:
	Scene();
	virtual ~Scene();

	virtual void Init();
	virtual void Update();
	virtual void Render();

protected:
	void SetSceneStateEnd();

	virtual void Progressing();
	virtual void LoadScene();
};

