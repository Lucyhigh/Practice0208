#include "Stdafx.h"
#include "Player.h"

HRESULT Player::init(void)
{
	_image = IMAGEMANAGER->addFrameImage("ĳ���ʹ��", "Resources/Images/Object/playerIdle.bmp", 1664, 146, 13, 2, true, RGB(255, 0, 255));
	_image = IMAGEMANAGER->addFrameImage("ĳ�����̵�", "Resources/Images/Object/playerRun.bmp", 1106, 140, 14, 2, true, RGB(255, 0, 255));
	
	_x = CENTER_X;
	_y = WINSIZE_Y-35;
	_rcPlayer = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());
	
	_count = 0;
	_indexA = _indexB = 0;
	_alphaA = 0;
    _speed = 5;
    _playerPos.x = 0;
   // _playerPos.y = WINSIZE_Y-170;
    _playerPos.y =0 ;
    _camera = new Camera;
    _camera->init();
    _camera->setCameraPos(_playerPos);

	_currentHp = 10;
	_maxHp = 10;
	_hpBar = new ProgressBar;
	_hpBar->init(280, WINSIZE_Y - 250, 52, 4);
	return S_OK;
}

void Player::release(void)
{
    _camera->release();
    SAFE_DELETE(_camera);
	_hpBar->release();
	SAFE_DELETE(_hpBar);
}

void Player::update(void)
{
	_count++;
	if (_isThird)
	{
		_hpBar->update();
		_hpBar->setGauge(_currentHp, _maxHp);
	}
	if (_isLive)
	{
        _camera->update();//���߿� �糡 ���ǽ��ֱ�
		if (_isWaiting && _count % 5 == 0)
		{
			if (_isLeft)
			{
				_indexA++;
				IMAGEMANAGER->findImage("ĳ���ʹ��")->setFrameY(1);
				if (_indexA >= 13)
				{
					_indexA = 0;
				}
				IMAGEMANAGER->findImage("ĳ���ʹ��")->setFrameX(_indexA);
			}
			else if (!_isLeft)
			{
				_indexA--;
				IMAGEMANAGER->findImage("ĳ���ʹ��")->setFrameY(0);
				if (_indexA < 0)
				{
					_indexA = 13;
				}
				IMAGEMANAGER->findImage("ĳ���ʹ��")->setFrameX(_indexA);
			}
		}
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_isLeft = true;
			_isWaiting = false;
			_x -= _speed;
          
            if (_playerPos.x < 0)
            {
                _playerPos.x = 0;
            }
            else
            {
                _playerPos.x -= _speed;
            }
			_hpBar->setX(_hpBar->getX() - _speed);
			_indexB++;
			IMAGEMANAGER->findImage("ĳ�����̵�")->setFrameY(1);
			if (_indexB >= 14)
			{
				_indexB = 0;
			}
			IMAGEMANAGER->findImage("ĳ�����̵�")->setFrameX(_indexB);
		}
		else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_isLeft = false;
			_isWaiting = false;
			_x += _speed;
            if (_playerPos.x >= WINSIZE_X-100)
            {
                _playerPos.x = WINSIZE_X;
            }
            else
            {
                _playerPos.x += _speed;
            }
			_hpBar->setX(_hpBar->getX() + _speed);
			_indexB--;
			IMAGEMANAGER->findImage("ĳ�����̵�")->setFrameY(0);
			if (_indexB < 0)
			{
				_indexB = 14;
			}
			IMAGEMANAGER->findImage("ĳ�����̵�")->setFrameX(_indexB);
		}
		else
		{
			_isWaiting = true;
		}
		if (_isThird && _count % 20 == 0)
		{
			hitDamage(0.5f);
		}
		_rcPlayer = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());
	}

    _camera->setCameraPos(_playerPos);
}

void Player::render(void)
{
	cout << getPlayerPosX()<<", ī�޶�x"<< _playerPos.x<< ", ī�޶� y"<< _playerPos.y<<
        ", �۸��" << _camera->getScreenRect().left << ", �۸�ž " << _camera->getScreenRect().top <<
        ", �۸��" << _camera->getScreenRect().right << ", �۸���� " << _camera->getScreenRect().bottom << endl;

	if (_isThird)
	{
		_hpBar->render();
	}
	if (_isLive)
	{
		if (_isWaiting)
		{
			IMAGEMANAGER->frameRender("ĳ���ʹ��", getMemDC(), _rcPlayer.left- _camera->getCameraPos().x,
                                                               _rcPlayer.top - _camera->getCameraPos().y);
		}
		else
		{
			IMAGEMANAGER->frameRender("ĳ�����̵�", getMemDC(), _rcPlayer.left - _camera->getCameraPos().x,
                                                               _rcPlayer.top - _camera->getCameraPos().y);
		}
	}
    _camera->render();
}

POINT Player::setPlayerPosXY()
{
    return _playerPos;
}

float Player::getPlayerPosX()
{
	return _x;
}

void Player::setPlayerPosX(float x)
{
	_x = x;
}

RECT Player::getPlayerRect()
{
	return _rcPlayer;
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

bool Player::setLive(bool status)
{
	return _isLive = status;
}

bool Player::getThird()
{
	return _isThird;
}

bool Player::setThird(bool isThird)
{
	return _isThird = isThird;
}

void Player::hitDamage(float damage)
{
	if (_currentHp <= 0)
	{
		_currentHp = 0;
		_isLive = false;
		return;
	}
	_currentHp -= damage;
}
