#pragma once
#include "SingletonBase.h"

// ������ ���� ��� ���̺귯�� 
// PlaySound()�� ����ϱ� ���� 
#include <mmsystem.h>

// Media Control Interface(��ġ������) API 
// mciSendString()�� ����ϱ� ���� 
#include <mciapi.h>

#pragma comment(lib,"Winmm.lib")

class TempSoundManager : public SingletonBase <TempSoundManager>

{
public:
	HRESULT init();
	void addMp3FileWithKey(string key, string fileName);
	void addWaveFileWithKey(string key, string fileName);
	void playEffectSoundWave(char* fileName);
	void playSoundWithKey(string key);
	void stopMp3WithKey(string key);

	TempSoundManager() {}
	~TempSoundManager() {}
};

