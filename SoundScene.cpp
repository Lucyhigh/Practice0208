#include "Stdafx.h"
#include "SoundScene.h"

HRESULT SoundScene::init(void)
{
	IMAGEMANAGER->addImage("����","Resources/Images/BackGround/SS.bmp",WINSIZE_X, CENTER_Y);
	IMAGEMANAGER->addImage("��ī","Resources/Images/BackGround/MIKA.bmp",WINSIZE_X, CENTER_Y);
	IMAGEMANAGER->addImage("�̳���","Resources/Images/BackGround/MINOI.bmp",WINSIZE_X, CENTER_Y);
	IMAGEMANAGER->addImage("���縵","Resources/Images/BackGround/Ring.bmp",WINSIZE_X, CENTER_Y);//YENA ���
	IMAGEMANAGER->addImage("�׳�","Resources/Images/BackGround/JUSTRing.bmp",WINSIZE_X, CENTER_Y);
	IMAGEMANAGER->addImage("�����","Resources/Images/BackGround/JGH.bmp",WINSIZE_X, CENTER_Y);
	IMAGEMANAGER->addImage("��","Resources/Images/BackGround/CHUU.bmp",WINSIZE_X, CENTER_Y);

	//SOUNDMANAGER->addSound("����","Resources/Sounds/OBLIVION.wav", true, true);
	SOUNDMANAGER->addSound("GraceKelly","Resources/Sounds/GraceKelly.mp3", true, true);
	SOUNDMANAGER->addSound("SRSR","Resources/Sounds/SRSR.mp3", true, true);
	SOUNDMANAGER->addSound("Lxxk2U","Resources/Sounds/Lxxk2U.mp3", true, true);
	SOUNDMANAGER->addSound("Just","Resources/Sounds/Just.mp3", true, true);
	SOUNDMANAGER->addSound("Not","Resources/Sounds/Not.mp3", true, true);
	SOUNDMANAGER->addSound("LightSwitch","Resources/Sounds/LightSwitch.mp3", true, true);
	SOUNDMANAGER->addSound("HeartAttack","Resources/Sounds/HeartAttack.mp3", true, true);

	//SOUNDMANAGER->setUp("Resources/Sounds/Golden.mp3", SOUND_BGM, true, true); c��Ÿ��
    //SOUNDMANAGER->
    _volume = 0.1f;
	return S_OK;
}

void SoundScene::release(void)
{
}

void SoundScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
        
            SOUNDMANAGER->play("LightSwitch", _volume);
     
		//SOUNDMANAGER->play(SOUND_BGM, 1.0f);  c��Ÿ��
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		SOUNDMANAGER->stop("LightSwitch");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SOUNDMANAGER->pause("LightSwitch");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		SOUNDMANAGER->resume("LightSwitch");
	}

   // if (SOUNDMANAGER->isPlaySound("LightSwitch"))
    {
        if (KEYMANAGER->isOnceKeyDown(VK_UP))
        {
            if (_volume <= SOUND_MAX)
            {
                _volume += 0.1f;
            }
        } 
        else if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
        {
            if (_volume > SOUND_MIN)
            {
                _volume -= 0.1f;
            }
        }
    }
	SOUNDMANAGER->update();
    //cout << _volume << endl;
}

void SoundScene::render(void)
{
	IMAGEMANAGER->render("���縵", getMemDC(),0,CENTER_Y);
}