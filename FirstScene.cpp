#include "Stdafx.h"
#include "FirstScene.h"

HRESULT FirstScene::init(void)
{
	_image = IMAGEMANAGER->addImage("����ȭ��", "Resources/Images/BackGround/boss1floor.bmp", 2460, 800);// , true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�⵵", "Resources/Images/Object/object.bmp", 272, 304,2,1,true,RGB(255,0,255));
	IMAGEMANAGER->addImage("�⵵E", "Resources/Images/Object/objectE.bmp", 392, 411,2,1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư", "Resources/Images/Object/buttomE.bmp", 35, 38, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("����â1", "Resources/Images/Object/SelectBox1.bmp", 392, 411);
	IMAGEMANAGER->addImage("����â2", "Resources/Images/Object/SelectBox2.bmp", 392, 411);
	_player = new Player;
	_player->init();
	_player->setPlayerPosX(0);
	_player->setPlayerPosY(WINSIZE_Y-100);
	_count = 0;
	_indexA = 0;
	_npcImage = IMAGEMANAGER->addFrameImage("�����", "Resources/Images/Object/NPC.bmp", 884, 442, 4, 2, true, RGB(255, 0, 255));
	_x = 900;
	_y = 950;
	_npcRc = RectMakeCenter(_x, _y, _npcImage->getFrameWidth(), _npcImage->getFrameHeight());

    _camera = new Camera;
    _camera->init();
    _camera->setLimits(CENTER_X, _image->getWidth()); //�¿� ���±�

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
	_count++;
	_player->update();
	if (_npcRc.left - 100 < _player->getPlayerRect().left && _player->getPlayerRect().left < _npcRc.left + 100)
	{
		if (KEYMANAGER->isToggleKey('S'))
		{
			if (_ptMouse.x > CENTER_X - 300 && _ptMouse.y > CENTER_Y)
			{
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					
				}
			}
			else if (_ptMouse.x > CENTER_X - 300 && _ptMouse.y < CENTER_Y)
			{
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					
				}
			}
		}
	}
	if (_count % 10 == 0)
	{
		_indexA++;
		IMAGEMANAGER->findImage("�����")->setFrameY(1);
		if (_indexA >= 4)
		{
			_indexA = 0;
		}
		IMAGEMANAGER->findImage("�����")->setFrameX(_indexA);
	}
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
    _camera->update();
    _player->setCameraRect(_camera->getScreenRect());
}

void FirstScene::render(void)
{
	IMAGEMANAGER->render("����ȭ��", getMemDC(),0,0,
                    _camera->getScreenRect().left, _camera->getScreenRect().top, 
                    _camera->getScreenRect().right, _camera->getScreenRect().bottom);
                    //WINSIZE_X, WINSIZE_Y);
    _camera->render();
	if (getDistance(_npcRc.left,0, _player->getPlayerPosX(),0)>100)
	{
		//if (KEYMANAGER->isToggleKey('S'))
		{
			if (_ptMouse.x > CENTER_X - 300 && _ptMouse.y > CENTER_Y)
			{
				IMAGEMANAGER->render("����â2", getMemDC(), CENTER_X - 300, CENTER_Y - 250);
			}
			else
			{
				IMAGEMANAGER->render("����â1", getMemDC(), CENTER_X - 300, CENTER_Y - 250);
			}
		}
	}
	IMAGEMANAGER->frameRender("�����", getMemDC(), _npcRc.left- _camera->getCameraPos().x, _npcRc.top- _camera->getCameraPos().y);
	_player->render();
    cout << _player->getPlayerPosX()<<", ī�޶�x"<< _camera->getCameraPos().x<< ", ī�޶� y"<< _camera->getCameraPos().y<<
        ", �۸��" << _camera->getScreenRect().left << ", �۸�ž " << _camera->getScreenRect().top <<
        ", ����" << getDistance(_npcRc.left, 0, _player->getPlayerPosX(), 0) << ", �ɿ� " << _npcRc.left << endl;
}
