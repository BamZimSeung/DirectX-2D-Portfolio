#pragma once
class MainGame
{
private:
	Player * player;
public:
	MainGame();
	~MainGame();

	void Init();
	void Update();
	void Render();
	void Release();
};

