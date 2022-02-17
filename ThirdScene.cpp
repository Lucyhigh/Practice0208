#include "Stdafx.h"
#include "ThirdScene.h"

HRESULT ThirdScene::init(void)
{
	IMAGEMANAGER->addImage("데미지화면", "Resources/Images/BackGround/ThirdBG.bmp", WINSIZE_X, WINSIZE_Y);

	return S_OK;
}

void ThirdScene::release(void)
{
}

void ThirdScene::update(void)
{
	if (!_isLive|| KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		SCENEMANAGER->changeScene("타이틀");
	}
}

void ThirdScene::render(void)
{
	IMAGEMANAGER->render("데미지화면", getMemDC());
}
