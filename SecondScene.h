#pragma once
#include "GameNode.h"


class SecondScene : public GameNode
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

	SecondScene() {}
	~SecondScene() {}
};
/*
- �ι�° �������� Npc�� �ְ� �÷��̾�� Npc�� �����ϸ� �˾�â�� �ϳ� ����.- �˾�â �޴���  - ����° ������ - / - ���� ȭ������ - �� ǥ���ϸ� ���콺 Ŭ�������� �����Ҽ� �ְ� �Ѵ�.


*/