#pragma once
#include "GameNode.h"
struct Player
{
	RECT _rcPlayer;
	bool _isLeft;
	bool _isWaiting;
};
class FirstScene : public GameNode
{
private:
	Image* _image;
	Player _player;
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