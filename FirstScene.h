#pragma once
#include "GameNode.h"
#include "Player.h"
#include "Camera.h"

class FirstScene : public GameNode
{
private:
	Image* _image;
	Player* _player;
    Camera* _camera;
	float _x, _y;
	int _count;
	int _indexA;
	int _indexB;
	int _alphaA;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	FirstScene() {}
	~FirstScene() {}
};