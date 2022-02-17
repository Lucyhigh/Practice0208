#include "Stdafx.h"
#include "SecondScene.h"
#include "FirstScene.h"
HRESULT SecondScene::init(void)
{
	IMAGEMANAGER->addImage("마을화면", "Resources/Images/BackGround/SecondBG.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("선택창1", "Resources/Images/Object/SelectBox1.bmp", 392, 411);
	IMAGEMANAGER->addImage("선택창2", "Resources/Images/Object/SelectBox2.bmp", 392, 411);
	_image = IMAGEMANAGER->addFrameImage("고양이", "Resources/Images/Object/NPC.bmp",884,442,4,2,true,RGB(255,0,255));
	_x = WINSIZE_X-50;
	_y = CENTER_Y +250;
	_npcRc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());
	_player = new Player;
	_player->init();
	_player->setPlayerRect(87);
	_count = 0;
	_indexA = 0;
	return S_OK;
}

void SecondScene::release(void)
{
	_player->release();
}

void SecondScene::update(void)
{
	_count++;
	_player->update();
	if (_npcRc.left - 100 < _player->getPlayerRect().left && _player->getPlayerRect().left < _npcRc.left + 100)
	{
		if (_ptMouse.x > CENTER_X - 300 && _ptMouse.y > CENTER_Y)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				SCENEMANAGER->changeScene("타이틀");
			}
		}
		else if (_ptMouse.x > CENTER_X - 300 && _ptMouse.y < CENTER_Y)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				SCENEMANAGER->changeScene("죽음땅");
			}
		}
	}

	if (_player->getPlayerRect().left > 1100)
	{
		_player->setPlayerRect(1100);
	}
	else if (_player->getPlayerRect().left < 10)
	{
		_player->setPlayerRect(10);
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
}

void SecondScene::render(void)
{
	IMAGEMANAGER->render("마을화면", getMemDC());

	IMAGEMANAGER->frameRender("고양이", getMemDC(), _npcRc.left, _npcRc.top);
	_player->render();
	if (_npcRc.left - 100 < _player->getPlayerRect().left && _player->getPlayerRect().left < _npcRc.left + 100)
	{
		if (_ptMouse.x > CENTER_X - 300 && _ptMouse.y > CENTER_Y)
		{
			IMAGEMANAGER->render("선택창2", getMemDC(), CENTER_X-300, CENTER_Y-250);
		}
		else
		{
			IMAGEMANAGER->render("선택창1", getMemDC(), CENTER_X-300, CENTER_Y-250);
		}
	}
}
