#include "Stdafx.h"
#include "Bullets.h"

HRESULT Missile::init(int bulletMax, float range)
{
	_range = range;

	for (int i = 0; i < bulletMax; i++)
	{
		tagBullet bullet;
		// �޸𸮸� 0���� �ʱ�ȭ(�޸� �ּ�, �޸� �� ������) : �޸� �� �� ��ŭ, �޸� �ּ��� �޸𸮸� 0���� �ʱ�ȭ
		ZeroMemory(&bullet, sizeof(tagBullet));

		bullet.img = new Image;
		bullet.img->init("Resources/Images/Object/Missile.bmp", 0.0f, 0.0f,
			416, 64, 13, 1, true, MGT);
		bullet.fire = false;
		bullet.speed = 5.0f;
		_vBullet.push_back(bullet);
	}
	_bulletTick = 7.0f;

	return S_OK;
}

void Missile::release(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		SAFE_DELETE(_viBullet->img);
	}

	_vBullet.clear();
}

void Missile::update(void)
{
	move();
}

void Missile::render(void)
{
	draw();
}

void Missile::fire(float x, float y)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (_viBullet->fire) continue;
		_viBullet->fire = true;
		_viBullet->x = _viBullet->fireX = x - 15;
		_viBullet->y = _viBullet->fireY = y - 90;

		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());

		break;
	}
}

void Missile::draw(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->fire)continue;
		_viBullet->img->frameRender(getMemDC(), _viBullet->x, _viBullet->y);
	}
}

void Missile::move(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->fire) continue;

		// ������ ������ 
		if (_bulletTick <= GetTickCount())
		{
			_bulletTick = GetTickCount();
			_viBullet->img->setFrameX(_viBullet->img->getFrameX() + 1);
			if (_viBullet->img->getFrameX() >= _viBullet->img->getMaxFrameX())
			{
				_viBullet->img->setFrameX(0);
			}
		}

		// ��ġ �ű��
		_viBullet->y -= _viBullet->speed;

		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());
		//��Ÿ� ������ ������
		if (_range < getDistance(_viBullet->fireX, _viBullet->fireY,
			_viBullet->x, _viBullet->y))
		{
			_viBullet->fire = false;
		}
	}
}
// �̻��� M1 ------------------------------------------------------------------------------
HRESULT MissileM1::init(int bulletMax, float range)
{
	_range = range;
	_bulletMax = bulletMax;

	return S_OK;
}

void MissileM1::release(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		SAFE_DELETE(_viBullet->img);
	}

	_vBullet.clear();
}

void MissileM1::update(void)
{
	move();
}

void MissileM1::render(void)
{
	draw();
}

void MissileM1::fire(float x, float y)
{
	//�ִ� �߻� ������ ���´�.
	if (_bulletMax <= _vBullet.size()) return;
	tagBullet bullet;
	//���� �ּҰ��� �޸𸮸� 0���� �ʱ�ȭ
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.img = new Image;
	bullet.img->init("Resources/Images/Object/Missile.bmp", 0.0f, 0.0f, 416, 64, 13, 1, true, RGB(255, 0, 255));

	bullet.fire = false;
	bullet.speed = 4.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y - 70;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.img->getFrameWidth(), bullet.img->getFrameHeight());

	_vBullet.push_back(bullet);
}

void MissileM1::move(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		// ��ġ �ű��
		_viBullet->y -= _viBullet->speed;

		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());

		//��Ÿ� ������ ������
		if (_range < getDistance(_viBullet->fireX, _viBullet->fireY,
			_viBullet->x, _viBullet->y))
		{
			SAFE_DELETE(_viBullet->img);
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void MissileM1::draw(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->img->frameRender(getMemDC(), _viBullet->rc.left, _viBullet->rc.top);

		_viBullet->count++;
		if (_viBullet->count % 3 == 0)
		{
			_viBullet->img->setFrameX(_viBullet->img->getFrameX() + 1);
			if (_viBullet->img->getFrameX() >= _viBullet->img->getMaxFrameX())
			{
				_viBullet->img->setFrameX(0);
			}
			_viBullet->count = 0;
		}
	}
}

// �̻��� M2 ------------------------------------------------------------------------------
HRESULT MissileM2::init(int bulletMax, float range)
{
	return S_OK;
}

void MissileM2::release(void)
{
}

void MissileM2::update(void)
{
}

void MissileM2::render(void)
{
}

void MissileM2::fire(float x, float y)
{
}

void MissileM2::move(void)
{
}

void MissileM2::draw(void)
{
}
