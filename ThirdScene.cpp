#include "Stdafx.h"
#include "ThirdScene.h"

HRESULT ThirdScene::init(void)
{
	IMAGEMANAGER->addImage("������ȭ��", "Resources/Images/BackGround/ThirdBG.bmp", WINSIZE_X, WINSIZE_Y);

	return S_OK;
}

void ThirdScene::release(void)
{
}

void ThirdScene::update(void)
{
	if (!_isLive|| KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		SCENEMANAGER->changeScene("Ÿ��Ʋ");
	}
}

void ThirdScene::render(void)
{
	IMAGEMANAGER->render("������ȭ��", getMemDC());
}
