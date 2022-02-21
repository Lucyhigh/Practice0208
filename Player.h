#pragma once
#include "GameNode.h"
#include "ProgressBar.h"
#include "Inventory.h"
#include "Camera.h"

class Player : public GameNode
{
private:
	Image* _image;
	ProgressBar* _hpBar;
	RECT _rcPlayer;
    Inventory* _inventory;
    Camera* _camera;
    POINT _playerPos;

	float _x, _y;
    int _speed;
	int _count;
	int _indexA;
	int _indexB;
	int _indexC;
	int _alphaA;
	float _currentHp;
	float _maxHp;

	bool _isLeft;
	bool _isWaiting;
	bool _isLive;
	bool _isThird;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

    POINT setPlayerPosXY();
	float getPlayerPosX();
	void setPlayerPosX(float x);
	RECT getPlayerRect();


	bool getLeft();
	bool getWaiting();
	bool getLive();
	bool setLive(bool status);
	bool getThird();
	bool setThird(bool isThird);
	void hitDamage(float damage);
	
	Player():_isLeft(false),_isWaiting(true),_isLive(true), _isThird(false){}
	~Player() {}
};
