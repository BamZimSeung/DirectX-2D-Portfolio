#include "stdafx.h"
#include "TimeManager.h"


TimeManager::TimeManager()
{
	prevTime = GetTickCount();
	elapsedTime = 0;
	passedGlobalTime = 0;
	timeScale = 1;
}


TimeManager::~TimeManager()
{
}

void TimeManager::Update()
{
	DWORD currentTime = GetTickCount();
	elapsedTime = currentTime - prevTime;
	prevTime = currentTime;
	passedGlobalTime += elapsedTime;
}

float TimeManager::GetElapsedTime()
{
	return elapsedTime / 1000.f;
}

float TimeManager::GetScaledElapsedTime()
{
	return elapsedTime * 0.001f * timeScale;
}

DWORD TimeManager::GetFrameRate()
{
	return 0;
}

void TimeManager::ChangeTimeFlow()
{
	if (timeScale == 1.0f) {
		timeScale = 0.3f;
	}
	else {
		timeScale = 1.0f;
	}
}
