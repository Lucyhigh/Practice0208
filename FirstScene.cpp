#include "Stdafx.h"
#include "FirstScene.h"

HRESULT FirstScene::init(void)
{
    IMAGEMANAGER->addImage("����ȭ��", "Resources/Images/BackGround/boss1floor.bmp", 1329, 400);//,true,RGB(255,0,255));
	_player = new Player;
	_player->init();
	_player->setPlayerPosX(800);
	_count = 0;

    _camera = new Camera;
    _camera->init();

	return S_OK;
}

void FirstScene::release(void)
{
	_player->release();
    _camera->release();
    SAFE_DELETE(_camera);
}

void FirstScene::update(void)
{
	_player->update();

	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON) || _player->getPlayerPosX() > 1540)
	{
		//SCENEMANAGER->changeScene("����");
        _player->setPlayerPosX(1540);
	}

	if (_player->getPlayerPosX() < 700)
	{
		_player->setPlayerPosX(700);
	}

    POINT p;
    p.x = _player->getPlayerPosX();
    p.y = _camera->getCameraPos().y;
    _camera->setCameraPos(p);
    _camera->update();//���߿� �糡 ���ǽ��ֱ�
}

void FirstScene::render(void)
{
	IMAGEMANAGER->render("����ȭ��", getMemDC(),0,0,
                  _camera->getScreenRect().left, _camera->getScreenRect().top, _camera->getScreenRect().right, _camera->getScreenRect().bottom);
	_player->render();
    _camera->render();

    cout << _player->getPlayerPosX()<<", ī�޶�x"<< _camera->getCameraPos().x<< ", ī�޶� y"<< _camera->getCameraPos().y<<
        ", �۸��" << _camera->getScreenRect().left << ", �۸�ž " << _camera->getScreenRect().top <<
        ", �۸��" << _camera->getScreenRect().right << ", �۸���� " << _camera->getScreenRect().bottom << endl;
}
