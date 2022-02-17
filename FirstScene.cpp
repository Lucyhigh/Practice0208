#include "Stdafx.h"
#include "FirstScene.h"

HRESULT FirstScene::init(void)
{
	IMAGEMANAGER->addImage("시작화면", "Resources/Images/BackGround/StartBG.bmp", WINSIZE_X, WINSIZE_Y);
	_player = new Player;
	_player->init();
	_player->setPlayerPos(630);
	_count = 0;

	return S_OK;
}

void FirstScene::release(void)
{
	_player->release();
}

void FirstScene::update(void)
{
	_player->update();

	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON) || _player->getPlayerPos() > 1850)
	{
		SCENEMANAGER->changeScene("마을");
	}

	if (_player->getPlayerPos() < 800)
	{
		_player->setPlayerPos(800);
	}
}

void FirstScene::render(void)
{
	IMAGEMANAGER->render("시작화면", getMemDC());
	_player->render();
}
