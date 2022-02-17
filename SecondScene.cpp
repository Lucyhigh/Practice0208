#include "Stdafx.h"
#include "SecondScene.h"

HRESULT SecondScene::init(void)
{
	IMAGEMANAGER->addImage("마을화면", "Resources/Images/BackGround/SecondBG.bmp", WINSIZE_X, WINSIZE_Y);
	_image = IMAGEMANAGER->addFrameImage("캐릭터대기", "Resources/Images/Object/playerIdle.bmp", 1664, 146, 13, 2, true, RGB(255, 0, 255));
	_image = IMAGEMANAGER->addFrameImage("캐릭터이동", "Resources/Images/Object/playerRun.bmp", 1106, 140, 14, 2, true, RGB(255, 0, 255));
	_x = CENTER_X;
	_y = WINSIZE_Y - 170;

	_player._rcPlayer = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());

	_count = 0;
	_indexA = _indexB = 0;
	_alphaA = 0;
	_player._isWaiting = true;
	_player._isLeft = false;
	return S_OK;
}

void SecondScene::release(void)
{
}

void SecondScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		SCENEMANAGER->changeScene("죽음땅");
	}
	_count++;
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON) || _player._rcPlayer.left > 800)
	{
		SCENEMANAGER->changeScene("마을");
	}
	if (_player._isWaiting && _count % 5 == 0)
	{
		if (_player._isLeft)
		{
			_indexA++;
			IMAGEMANAGER->findImage("캐릭터대기")->setFrameY(1);
			if (_indexA > 10)
			{
				_indexA = 0;
			}
			IMAGEMANAGER->findImage("캐릭터대기")->setFrameX(_indexA);
		}
		else if (!_player._isLeft)
		{
			_indexA--;
			IMAGEMANAGER->findImage("캐릭터대기")->setFrameY(0);
			if (_indexA < 0)
			{
				_indexA = 10;
			}
			IMAGEMANAGER->findImage("캐릭터대기")->setFrameX(_indexA);
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_player._isLeft = true;
		_player._isWaiting = false;
		_player._rcPlayer.left -= 5;
		_player._rcPlayer.right -= 5;

		_indexB++;
		IMAGEMANAGER->findImage("캐릭터이동")->setFrameY(1);
		if (_indexB >= 10)
		{
			_indexB = 0;
		}
		IMAGEMANAGER->findImage("캐릭터이동")->setFrameX(_indexB);
	}
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_player._isLeft = false;
		_player._isWaiting = false;
		_player._rcPlayer.left += 5;
		_player._rcPlayer.right += 5;

		_indexB--;
		IMAGEMANAGER->findImage("캐릭터이동")->setFrameY(0);
		if (_indexB < 0)
		{
			_indexB = 10;
		}
		IMAGEMANAGER->findImage("캐릭터이동")->setFrameX(_indexB);
	}
	else
	{
		_player._isWaiting = true;
	}
}

void SecondScene::render(void)
{
	IMAGEMANAGER->render("마을화면", getMemDC());
	if (_player._isWaiting)
	{
		IMAGEMANAGER->frameRender("캐릭터대기", getMemDC(), _player._rcPlayer.left, _player._rcPlayer.top);
	}
	else
	{
		IMAGEMANAGER->frameRender("캐릭터이동", getMemDC(), _player._rcPlayer.left, _player._rcPlayer.top);

	}
}
