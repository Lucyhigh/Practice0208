#include "Stdafx.h"
#include "FirstScene.h"

HRESULT FirstScene::init(void)
{
    _image = IMAGEMANAGER->addImage("시작화면", "Resources/Images/BackGround/boss1floor.bmp", 2460, 800,false,RGB(255,0,255));
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
	//	//SCENEMANAGER->changeScene("마을");
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
    _camera->update();//나중에 양끝 조건식주기
    _player->setCameraRect(_camera->getScreenRect());
}

void FirstScene::render(void)
{
	IMAGEMANAGER->render("시작화면", getMemDC(),0,0,
                    _camera->getScreenRect().left, _camera->getScreenRect().top, 
                    _camera->getScreenRect().right, _camera->getScreenRect().bottom);
                    //WINSIZE_X, WINSIZE_Y);
	_player->render();
    _camera->render();

    cout << _player->getPlayerPosX()<<", 카메라x"<< _camera->getCameraPos().x<< ", 카메라 y"<< _camera->getCameraPos().y<<
        ", 넴모왼" << _camera->getScreenRect().left << ", 넴모탑 " << _camera->getScreenRect().top <<
        ", 넴모우" << _camera->getScreenRect().right << ", 넴모바텀 " << _camera->getScreenRect().bottom << endl;
}
