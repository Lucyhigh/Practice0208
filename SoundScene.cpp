#include "Stdafx.h"
#include "SoundScene.h"

HRESULT SoundScene::init(void)
{
	IMAGEMANAGER->addImage("���縵","Resources/Images/BackGround/Ring.bmp",WINSIZE_X,WINSIZE_Y);

	SOUNDMANAGER->addSound("����","Resources/Sounds/OBLIVION.wav", true, true);
	//SOUNDMANAGER->setUp("Resources/Sounds/Golden.mp3", SOUND_BGM, true, true);
	return S_OK;
}

void SoundScene::release(void)
{
}

void SoundScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		SOUNDMANAGER->play("����", 1.0f);
		//SOUNDMANAGER->play(SOUND_BGM, 1.0f);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		SOUNDMANAGER->stop("����");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SOUNDMANAGER->pause("����");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		SOUNDMANAGER->resume("����");
	}
	SOUNDMANAGER->update();
}

void SoundScene::render(void)
{
	IMAGEMANAGER->render("���縵", getMemDC());
}

SoundScene::SoundScene()
{
}
