#include "Stdafx.h"
#include "Flame.h"
 // �̴ϼȶ���� �ʿ��� ��� ���⼭ ��Ŭ��� �Ѵ�.

Flame::Flame()
{
	//! Do Nothing
}

Flame::~Flame()
{
}

/*
HRESULT Flame::init(void)
{
	_img = IMAGEMANAGER->addFrameImage("�ν���", "Resources/Images/Object/Flame.bmp",-100,500, 432, 297, 9, 1, true, MGT);

	_count = _index = 0;
	_start = false;
	return S_OK;
}
*/

HRESULT Flame::init(const char*fileName, float* x, float* y)
{
	_img = IMAGEMANAGER->addFrameImage("�ν���", "Resources/Images/Object/Flame.bmp",
		0.0f, 0.0f, 432, 297, 9, 1, true, MGT);

	_x = x;
	_y = y;

	_rc = RectMakeCenter((int)_x, (int)_y, _img->getFrameWidth(), _img->getFrameHeight());
	_flameTick = 7.0f;
	_count = _index = 0;
	_start = false;
	return S_OK;
}

void Flame::release(void)
{

}

void Flame::update(void)
{
	/*
	if (_start)
	{
		IMAGEMANAGER->findImage("�ν���")->setX(WINSIZE_X / 2);
		IMAGEMANAGER->findImage("�ν���")->setY(WINSIZE_Y / 2);

		_count++;
		IMAGEMANAGER->findImage("�ν���")->setFrameY(0);
		if (_count % 6 == 0)
		{
			_index++; _count = 0;
		}
		if (_index > 9)
		{
			_start = false;
		}
		IMAGEMANAGER->findImage("�ν���")->setFrameX(_index);
	}
	else { _count = _index = 0; }*/

	//0207 �߰� 
	if (FLAME_COUNT + _flameTick <= GetTickCount())
	{
		_flameTick = GetTickCount();
		_img->setFrameX(_img->getFrameX() + 1);
		if (_img->getFrameX() >= _img->getMaxFrameX())
		{
			_img->setFrameX(0);
		}
	}

	_rc = RectMakeCenter(*_x, *_y+180, _img->getFrameWidth(), _img->getFrameHeight());


}

void Flame::render(void)
{
	//if(_start)	
		IMAGEMANAGER->frameRender("�ν���", getMemDC(), _rc.left,_rc.top,_img->getFrameX(), _img->getFrameY());

}
