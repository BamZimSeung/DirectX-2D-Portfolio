#pragma once
class SoundManager
{
protected:
	FMOD_SYSTEM *			System;
	FMOD_SOUND**			BGSound;
	FMOD_SOUND**			EFFSound;
	FMOD_CHANNEL**			Channels;

	int						BGCount;
	int						EFFCount;

protected:
	SoundManager();
	~SoundManager();

public:
	static SoundManager* GetInstance() {
		static SoundManager instance;
		return &instance;
	}

	void Init();
	void Update();

	void PlaySoundBG(int BGIndex);
	void StopSoundBG();
	void PlaySoundEffect(int soundIndex);
	void ReleaseSound();
};

