#include "Stdafx.h"
#include "Player.h"

HRESULT Player::init(void)
{
	_image = IMAGEMANAGER->addFrameImage("캐릭터대기", "Resources/Images/Object/playerIdle.bmp", 1664, 146, 13, 2, true, RGB(255, 0, 255));
	_image = IMAGEMANAGER->addFrameImage("캐릭터이동", "Resources/Images/Object/playerRun.bmp", 1106, 140, 14, 2, true, RGB(255, 0, 255));
	
	_x = 87;
	_y = WINSIZE_Y - 170;
	_rcPlayer = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());
	
	_count = 0;
	_indexA = _indexB = 0;
	_alphaA = 0;

	_currentHp = 10;
	_maxHp = 10;
	_hpBar = new ProgressBar;
	_hpBar->init(_x, _y, 52, 4);
	return S_OK;
}

void Player::release(void)
{
	_hpBar->release();
	SAFE_DELETE(_hpBar);
}

void Player::update(void)
{
	_count++;
	_hpBar->update();
	_hpBar->setGauge(_currentHp, _maxHp);
	if (_isLive)
	{


		if (_isWaiting && _count % 5 == 0)
		{
			if (_isLeft)
			{
				_indexA++;
				IMAGEMANAGER->findImage("캐릭터대기")->setFrameY(1);
				if (_indexA >= 13)
				{
					_indexA = 0;
				}
				IMAGEMANAGER->findImage("캐릭터대기")->setFrameX(_indexA);
			}
			else if (!_isLeft)
			{
				_indexA--;
				IMAGEMANAGER->findImage("캐릭터대기")->setFrameY(0);
				if (_indexA < 0)
				{
					_indexA = 13;
				}
				IMAGEMANAGER->findImage("캐릭터대기")->setFrameX(_indexA);
			}
		}
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_isLeft = true;
			_isWaiting = false;
			_rcPlayer.left -= 5;
			_rcPlayer.right -= 5;

			_indexB++;
			IMAGEMANAGER->findImage("캐릭터이동")->setFrameY(1);
			if (_indexB >= 14)
			{
				_indexB = 0;
			}
			IMAGEMANAGER->findImage("캐릭터이동")->setFrameX(_indexB);
		}
		else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_isLeft = false;
			_isWaiting = false;
			_rcPlayer.left += 5;
			_rcPlayer.right += 5;

			_indexB--;
			IMAGEMANAGER->findImage("캐릭터이동")->setFrameY(0);
			if (_indexB < 0)
			{
				_indexB = 14;
			}
			IMAGEMANAGER->findImage("캐릭터이동")->setFrameX(_indexB);
		}
		else
		{
			_isWaiting = true;
		}
		if (_isThird && _count % 20 == 0)
		{
			hitDamage(1.0f);
		}
	}
	else
	{

	}
}

void Player::render(void)
{
	_hpBar->render();
	cout << _rcPlayer.left << endl;
	if (_isWaiting)
	{
		IMAGEMANAGER->frameRender("캐릭터대기", getMemDC(), _rcPlayer.left, _rcPlayer.top);
	}
	else
	{
		IMAGEMANAGER->frameRender("캐릭터이동", getMemDC(), _rcPlayer.left, _rcPlayer.top);
	}
	if (!_isLive)
	{

	}

}

RECT Player::getPlayerRect()
{
	return _rcPlayer;
}

void Player::setPlayerRect(int rcPos)
{
	_rcPlayer.left = rcPos;
	_rcPlayer.right = rcPos + _image->getWidth();
}

bool Player::getLeft()
{
	return _isLeft;
}

bool Player::getWaiting()
{
	return _isWaiting;
}

bool Player::getLive()
{
	return _isLive;
}

bool Player::getThird()
{
	return _isThird;
}
