#include "stdafx.h"
#include "MainGame.h"


MainGame::MainGame()
	: player(NULL)
{
}


MainGame::~MainGame()
{
	SAFE_DELETE(player);
}

void MainGame::Init()
{
	TIMEMANAGER;
	D3DVIEWPORT9 viewport;
	DEVICE->GetViewport(&viewport);

	player = new Player();
	D3DXVECTOR2 pos = { (float)viewport.Width / 2.f, (float)viewport.Height/ 2.f };
	D3DXVECTOR3 rot = { 0, 0, 0 };
	D3DXVECTOR2 moveDir = { 0, 0 };
	player->Init(L"image/sun.png", pos, rot, moveDir, 25);
}

void MainGame::Update()
{
	TIMEMANAGER->Update();
	KEYBOARD->Update();
	CAMERA->Update();

	player->Update();
	ENEMYMANAGER->Update();
	BULLETMANAGER->Update();
}

void MainGame::Render()
{
	player->Render();
	BULLETMANAGER->Render();
	ENEMYMANAGER->Render();
}

void MainGame::Release()
{
}
