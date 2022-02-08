#pragma once
#include "GameNode.h"

struct tagBullet
{
	Image* img;
	RECT rc;
	int radius;
	int count;
	float x, y;
	float fireX, fireY;
	float angle;
	float speed;
	bool fire;
	int index;
};


// ����ó�� �̸� �����صΰ� �߻� 
class Missile : public GameNode
{
private :
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
	
	float _bulletTick;

public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);


	void fire(float x, float y);
	void move(void);
	void draw(void);

	Missile() {};
	~Missile() {};
};

// �߻� �� ������ ����� ���� (�޸� �̵�)
class MissileM1 :public GameNode
{
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
	float _bulletTick;
	int _bulletMax;
public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y);
	void move(void);
	void draw(void);

	MissileM1() {};
	~MissileM1() {};
};

class MissileM2 : public GameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
	float _bulletTick;
	int _bulletMax;
	int _bulletIndex;
public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y);
	void move(void);
	void draw(void);

	MissileM2() {};
	~MissileM2() {};
};

class MissileM3 : public GameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
	float _bulletTick;
	int _bulletMax;
	int _bulletIndex;
public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y);
	void move(void);
	void draw(void);

	MissileM3() {};
	~MissileM3() {};
};
class MissileM4 : public GameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
	float _bulletTick;
	int _bulletMax;
	int _bulletIndex;
public:
	HRESULT init(int count, float range);
	void release(void);
	void update(void);
	void render(void);

	void shield(float x, float y);
	void draw(void);

	MissileM4(){};
	~MissileM4(){};
};
