#include "Stdafx.h"
#include "FirstScene.h"

HRESULT FirstScene::init(void)
{
	_image = IMAGEMANAGER->addImage("시작화면", "Resources/Images/BackGround/boss1floor.bmp", 2460, 800);//, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("선택창1", "Resources/Images/Object/SelectBox1.bmp", 392, 411);
	IMAGEMANAGER->addImage("선택창2", "Resources/Images/Object/SelectBox2.bmp", 392, 411);
	_player = new Player;
	_player->init();
	_player->setPlayerPosX(0);
	_player->setPlayerPosY(WINSIZE_Y-100);
	_count = 0;

	_image = IMAGEMANAGER->addFrameImage("고양이", "Resources/Images/Object/NPC.bmp", 884, 442, 4, 2, true, RGB(255, 0, 255));
	_x = WINSIZE_X - 50;
	_y = CENTER_Y + 250;
	_npcRc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());

    _camera = new Camera;
    _camera->init();
    _camera->setLimits(CENTER_X, _image->getWidth() - CENTER_X); //좌우 벽맞기

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
	if (_npcRc.left - 100 < _player->getPlayerRect().left&& _player->getPlayerRect().left < _npcRc.left + 100)
	{
		if (KEYMANAGER->isToggleKey('S'))
		{
			if (_ptMouse.x > CENTER_X - 300 && _ptMouse.y > CENTER_Y)
			{
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					SCENEMANAGER->changeScene("상점");
				}
			}
			else if (_ptMouse.x > CENTER_X - 300 && _ptMouse.y < CENTER_Y)
			{
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					SCENEMANAGER->changeScene("인벤토리");
				}
			}
		}
	}
	if (_count % 10 == 0)
	{
		_indexA++;
		IMAGEMANAGER->findImage("고양이")->setFrameY(1);
		if (_indexA >= 4)
		{
			_indexA = 0;
		}
		IMAGEMANAGER->findImage("고양이")->setFrameX(_indexA);
	}
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
    _camera->update();
    _player->setCameraRect(_camera->getScreenRect());
}

void FirstScene::render(void)
{
	IMAGEMANAGER->render("시작화면", getMemDC(),0,0,
                    _camera->getScreenRect().left, _camera->getScreenRect().top, 
                    _camera->getScreenRect().right, _camera->getScreenRect().bottom);
                    //WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->frameRender("고양이", getMemDC(), _npcRc.left, _npcRc.top);
	if (_npcRc.left - 100 < _player->getPlayerRect().left && _player->getPlayerRect().left < _npcRc.left + 100)
	{
		if (KEYMANAGER->isToggleKey('S'))
		{
			if (_ptMouse.x > CENTER_X - 300 && _ptMouse.y > CENTER_Y)
			{
				IMAGEMANAGER->render("선택창2", getMemDC(), CENTER_X - 300, CENTER_Y - 250);
			}
			else
			{
				IMAGEMANAGER->render("선택창1", getMemDC(), CENTER_X - 300, CENTER_Y - 250);
			}
		}
	}
	_player->render();
    _camera->render();
    cout << _player->getPlayerPosX()<<", 카메라x"<< _camera->getCameraPos().x<< ", 카메라 y"<< _camera->getCameraPos().y<<
        ", 넴모왼" << _camera->getScreenRect().left << ", 넴모탑 " << _camera->getScreenRect().top <<
        ", 넴모우" << _camera->getScreenRect().right << ", 넴모바텀 " << _camera->getScreenRect().bottom << endl;
}
