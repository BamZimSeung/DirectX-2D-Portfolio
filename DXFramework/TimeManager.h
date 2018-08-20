#pragma once
class TimeManager
{
private:
	DWORD prevTime;
	DWORD elapsedTime;
	DWORD passedGlobalTime;
	float timeScale;

private:
	TimeManager();
	~TimeManager();

public:
	static TimeManager* GetTimeManager() {
		static TimeManager instance;
		return &instance;
	}

	void Update();
	float GetElapsedTime();
	float GetScaledElapsedTime();
	DWORD GetFrameRate();
	DWORD GetGlobalTime() {
		return passedGlobalTime;
	}
	void ChangeTimeFlow();
};

