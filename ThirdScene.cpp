#include "Stdafx.h"
#include "ThirdScene.h"

HRESULT ThirdScene::init(void)
{
	IMAGEMANAGER->addImage("데미지화면", "Resources/Images/BackGround/ThirdBG.bmp", WINSIZE_X, WINSIZE_Y);
	_player = new Player;
	_player->init();
	_player->setPlayerRect(87);

	return S_OK;
}

void ThirdScene::release(void)
{
	_player->release();
}

void ThirdScene::update(void)
{
	_player->update();
	if (_player->getLive() == false || KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		SCENEMANAGER->changeScene("타이틀");
	}
}

void ThirdScene::render(void)
{
	IMAGEMANAGER->render("데미지화면", getMemDC());
	_player->render();
	if (_player->getLive()==false)
	{

	}
}
