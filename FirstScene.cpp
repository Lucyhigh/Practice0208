#include "Stdafx.h"
#include "FirstScene.h"

HRESULT FirstScene::init(void)
{
    IMAGEMANAGER->addImage("시작화면", "Resources/Images/BackGround/boss1floor.bmp", 2460, 800,true,RGB(255,0,255));
	_player = new Player;
	_player->init();
	_player->setPlayerPosX(800);
	_player->setPlayerPosY(WINSIZE_Y-100);
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

	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON) || _player->getPlayerPosX() > 2050)
	{
		//SCENEMANAGER->changeScene("마을");
        _player->setPlayerPosX(2050);
	}

	if (_player->getPlayerPosX() < 450)
	{
		_player->setPlayerPosX(450);
	}
}

void FirstScene::render(void)
{
	IMAGEMANAGER->render("시작화면", getMemDC(),0,0,
                  _player->getPlayerPosX()-800, 0, WINSIZE_X, WINSIZE_Y);
	_player->render();
}
