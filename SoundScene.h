#pragma once
#include "GameNode.h"
#include "Text.h"
#define SOUND_MAX 1.0f
#define SOUND_MIN 0.0f
#define SOUND_WEIGHT 0.1f
class SoundScene:public GameNode
{
private:
    tagTextWithSound _soundInfo[7];
    float _volume;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
public:
    SoundScene() :_soundInfo
    {
        {0,"LightSwitch","����"},
        {1,"GraceKelly","��ī"},
        {2,"SRSR","�̳���"},
        {3,"Lxxk2U","���縵"},
        {4,"Just","�׳�"},
        {5,"Not","�����"},
        {6,"HeartAttack","��"}
    }
    {}
	~SoundScene() {}
};