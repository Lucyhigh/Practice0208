#pragma once
#include "GameNode.h"
#include "Flame.h"
#include "Bullets.h"


#define ROCKET_SPEED 3.0f
#define ROCKET_BULLET 30
enum BULLETTYPE
{
	NORMAL,
	SHOT,//Ŭ���� ������ �ø������� �ϴ� �����غ��� Ŭ���� �����
	MINIROCKET,
	SHIELD,
	GUIDED,
	LASER
};
class Rocket : public  GameNode
{
private :
	Image* _image;
	RECT _rc;
	float _x, _y;
	int _bulletType;
	Flame* _flame;

	MissileM1* _missile;
	//Missile*  _missileM1;

public:
	Rocket() {}
	~Rocket() {}

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	float getFlameX() 
	{ return IMAGEMANAGER->findImage("�ν���")->getX(); }

	void setFlameX(float _x) 
	{
		IMAGEMANAGER->findImage("�ν���")->setX(_x);
	}

	float getFlameY()
	{
		return IMAGEMANAGER->findImage("�ν���")->getY();
	}

	void setFlameY(float _y)
	{
		IMAGEMANAGER->findImage("�ν���")->setY(_y);
	}

};

