#include "Stdafx.h"
#include "StartScene.h"

HRESULT StartScene::init(void)
{
	IMAGEMANAGER->addImage("타이틀배경", "Resources/Images/BackGround/Title.bmp", WINSIZE_X, WINSIZE_Y);

	wsprintf(_text, "Start Scene");

	return S_OK;
}

void StartScene::release(void)
{
}

void StartScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		SCENEMANAGER->changeScene("시작");
	}
}

void StartScene::render(void)
{
	IMAGEMANAGER->render("타이틀배경", getMemDC());

	TextOut(getMemDC(), CENTER_X, CENTER_Y, _text, strlen(_text));
}