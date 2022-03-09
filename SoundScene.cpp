#include "Stdafx.h"
#include "SoundScene.h"

HRESULT SoundScene::init(void)
{
	IMAGEMANAGER->addImage("¿¤µç¸µ","Resources/Images/BackGround/Ring.bmp",WINSIZE_X, CENTER_Y);
	IMAGEMANAGER->addImage("¿¤µç¸µ","Resources/Images/BackGround/CHUU.bmp",WINSIZE_X, CENTER_Y);
	IMAGEMANAGER->addImage("¿¤µç¸µ","Resources/Images/BackGround/SS.bmp",WINSIZE_X, CENTER_Y);
	IMAGEMANAGER->addImage("¿¤µç¸µ","Resources/Images/BackGround/JUSTRing.bmp",WINSIZE_X, CENTER_Y);
	IMAGEMANAGER->addImage("¿¤µç¸µ","Resources/Images/BackGround/Ring.bmp",WINSIZE_X, CENTER_Y);
	IMAGEMANAGER->addImage("¿¤µç¸µ","Resources/Images/BackGround/Ring.bmp",WINSIZE_X, CENTER_Y);
	IMAGEMANAGER->addImage("¿¤µç¸µ","Resources/Images/BackGround/Ring.bmp",WINSIZE_X, CENTER_Y);

	SOUNDMANAGER->addSound("Âù¶õ","Resources/Sounds/OBLIVION.wav", true, true);
	//SOUNDMANAGER->setUp("Resources/Sounds/Golden.mp3", SOUND_BGM, true, true); c½ºÅ¸ÀÏ
	return S_OK;
}

void SoundScene::release(void)
{
}

void SoundScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		SOUNDMANAGER->play("Âù¶õ", 1.0f);
		//SOUNDMANAGER->play(SOUND_BGM, 1.0f);  c½ºÅ¸ÀÏ
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		SOUNDMANAGER->stop("Âù¶õ");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SOUNDMANAGER->pause("Âù¶õ");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		SOUNDMANAGER->resume("Âù¶õ");
	}
	SOUNDMANAGER->update();
}

void SoundScene::render(void)
{
	IMAGEMANAGER->render("¿¤µç¸µ", getMemDC(),0,CENTER_Y);
}

SoundScene::SoundScene()
{
}
