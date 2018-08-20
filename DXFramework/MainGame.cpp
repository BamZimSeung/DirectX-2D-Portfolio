#include "stdafx.h"
#include "MainGame.h"


MainGame::MainGame()
{
}


MainGame::~MainGame()
{
	Release();
}

void MainGame::Init()
{
	SOUND->Init();
}

void MainGame::Update()
{
	// Framework Update
	TIME->Update();
	SOUND->Update();
	KEYBOARD->Update();
	CAMERA->Update();
}

void MainGame::Render()
{
}

void MainGame::Release()
{
	SOUND->ReleaseSound();
	Texture::ReleaseTexture();
}
