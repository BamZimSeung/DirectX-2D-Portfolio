#include "stdafx.h"
#include "Scene.h"


Scene::Scene()
{
	sceneState = SceneState::STARTING;
	alphaValue = 255;
}


Scene::~Scene()
{
}

void Scene::Init()
{
	sceneState = SceneState::STARTING;
	alphaValue = 255;
}

void Scene::Update()
{
	switch (sceneState)
	{
	case STARTING:
		alphaValue -= 3;
		alphaValue = max(alphaValue, 0);

		if (alphaValue == 0) {
			sceneState = SceneState::PROGRESSING;
		}
		break;
	case PROGRESSING:
		Progressing();
		break;
	case ENDING:
		alphaValue += 3;
		alphaValue = min(alphaValue, 255);

		// 다음 씬으로 넘어가기
		if (alphaValue == 255) {
			LoadScene();
		}
		break;
	default:
		break;
	}
}

void Scene::Render()
{
	if (sceneState != SceneState::PROGRESSING) {
	}
}

void Scene::SetSceneStateEnd()
{
	sceneState = SceneState::ENDING;
}

void Scene::Progressing()
{
	if (sceneState != SceneState::PROGRESSING)
		return;
}

void Scene::LoadScene()
{
	// 설정되 씬으로 변경
}
