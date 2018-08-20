#include "stdafx.h"
#include "SoundManager.h"


SoundManager::SoundManager()
{
	BGCount = 3;
	EFFCount = 4;
}


SoundManager::~SoundManager()
{
}

void SoundManager::ReleaseSound()
{
	SAFE_DELETE_ARRAY(Channels);

	size_t i;

	for (i = 0; i < BGCount; i++) {
		FMOD_Sound_Release(BGSound[i]);
	}
	SAFE_DELETE_ARRAY(BGSound);

	for (i = 0; i < EFFCount; i++) {
		FMOD_Sound_Release(EFFSound[i]);
	}
	SAFE_DELETE_ARRAY(EFFSound);

	// 사운드 시스템 종료
	FMOD_System_Close(System);

	// 사운드 시스템 해제
	FMOD_System_Release(System);
}

void SoundManager::Init()
{
	FMOD_System_Create(&System);
	FMOD_System_Init(System, 32, FMOD_INIT_NORMAL, NULL);

	// 배경 사운드 생성
	BGSound = new FMOD_SOUND*[BGCount];
	FMOD_SOUND* pSound = NULL;
	// FMOD_System_CreateSound(System, "sound/StartSceneBGM.mp3", FMOD_DEFAULT | FMOD_LOOP_NORMAL, 0, &BGSound[0]);
	

	// 이펙트 사운드 생성
	EFFSound = new FMOD_SOUND*[EFFCount];
	// FMOD_System_CreateSound(System, "sound/ButtonClick.mp3", FMOD_DEFAULT, 0, &EFFSound[0]);
	

	// 채널 생성
	Channels = new FMOD_CHANNEL*[8];
}

void SoundManager::Update()
{
	FMOD_System_Update(System);
}

void SoundManager::PlaySoundBG(int BGIndex)
{
	if (BGIndex < 0 || BGIndex >= BGCount)
		return;

	FMOD_System_PlaySound(System, FMOD_CHANNEL_FREE, BGSound[BGIndex], 0, &Channels[0]);
}

void SoundManager::StopSoundBG()
{
	FMOD_Channel_Stop(Channels[0]);
}

void SoundManager::PlaySoundEffect(int soundIndex)
{
	switch (soundIndex)
	{
	case 0:
		FMOD_System_PlaySound(System, FMOD_CHANNEL_FREE, EFFSound[soundIndex], 0, &Channels[1]);
		break;
	case 1:
		FMOD_System_PlaySound(System, FMOD_CHANNEL_FREE, EFFSound[soundIndex], 0, &Channels[2]);
		break;
	case 2:
	case 3:
		FMOD_System_PlaySound(System, FMOD_CHANNEL_FREE, EFFSound[soundIndex], 0, &Channels[3]);
		break;
	case 4:
		FMOD_System_PlaySound(System, FMOD_CHANNEL_FREE, EFFSound[soundIndex], 0, &Channels[4]);
		break;
	default:
		break;
	}
}
