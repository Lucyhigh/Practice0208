#include "Stdafx.h"
#include "Enemy.h"

Enemy::Enemy() : _rc(RectMake(0,0,0,0)), _currentFrameX(0), _currentFrameY(0), _x(0.0f), _y(0.0f), _rndTimeCount(0.0f), _worldTimeCount(0.0f)
{ 
}

Enemy::~Enemy(){
} 

HRESULT Enemy::init(void)
{
	//������� ����
	return S_OK;
}

HRESULT Enemy::init(const char * imageName, POINT position, float speed)
{
	_worldTimeCount = GetTickCount();
	_rndTimeCount = RND->getFromFloatTo(50, 150);
	_image = IMAGEMANAGER->findImage(imageName);
	_speed = speed;
	_x = position.x;
	_y = position.y;
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

	return S_OK;
}

void Enemy::release(void)
{
	_image->release();
}

void Enemy::update(void)
{
	move();
}

void Enemy::render(void)
{
	draw();
	animation();
}

// ��
// ���� ������-������ ���� ū Ư¡�̴�. 
// ����ȭ�� �ؼ� ������ �ɱ �����غ����Ѵ�.
// ������ �������� �ٸ��� ����� �޾� �ڽĿ��� ����
void Enemy::move(void)
{
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
}

void Enemy::draw(void)
{
	_image->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);
}

void Enemy::animation(void)
{
	if (_rndTimeCount + _worldTimeCount <= GetTickCount())
	{
		_worldTimeCount = GetTickCount();
		_currentFrameX++;
		if (_image->getMaxFrameX() < _currentFrameX)
		{
			_currentFrameX = 0;
		}
	}
}
