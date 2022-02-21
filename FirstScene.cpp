#include "Stdafx.h"
#include "FirstScene.h"

HRESULT FirstScene::init(void)
{
    _image = IMAGEMANAGER->addImage("����ȭ��", "Resources/Images/BackGround/boss1floor.bmp", 2460, 800,false,RGB(255,0,255));
	_player = new Player;
	_player->init();
	_player->setPlayerPosX(800);
	_player->setPlayerPosY(WINSIZE_Y-100);
	_count = 0;

    _camera = new Camera;
    _camera->init();
    _camera->setLimits(CENTER_X, _image->getWidth() - CENTER_X);

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

	//if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON) || _player->getPlayerPosX() > 2050)
	//{
	//	//SCENEMANAGER->changeScene("����");
 //       _player->setPlayerPosX(2050);
	//}

	//if (_player->getPlayerPosX() < 450)
	//{
	//	_player->setPlayerPosX(450);
	//}

    POINT cameraPos;
    cameraPos.x = _player->getPlayerPosX();
    cameraPos.y = _camera->getCameraPos().y;
    _camera->setCameraPos(cameraPos);
    _camera->update();//���߿� �糡 ���ǽ��ֱ�
    _player->setCameraRect(_camera->getScreenRect());
}

void FirstScene::render(void)
{
	IMAGEMANAGER->render("����ȭ��", getMemDC(),0,0,
                    _camera->getScreenRect().left, _camera->getScreenRect().top, 
                    _camera->getScreenRect().right, _camera->getScreenRect().bottom);
                    //WINSIZE_X, WINSIZE_Y);
	_player->render();
    _camera->render();

    cout << _player->getPlayerPosX()<<", ī�޶�x"<< _camera->getCameraPos().x<< ", ī�޶� y"<< _camera->getCameraPos().y<<
        ", �۸��" << _camera->getScreenRect().left << ", �۸�ž " << _camera->getScreenRect().top <<
        ", �۸��" << _camera->getScreenRect().right << ", �۸���� " << _camera->getScreenRect().bottom << endl;
}
