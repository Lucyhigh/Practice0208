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
- 두번째 씬에서는 Npc가 있고 플레이어와 Npc가 인접하면 팝업창을 하나 띄운다.- 팝업창 메뉴는  - 세번째 씬으로 - / - 시작 화면으로 - 를 표시하며 마우스 클릭을통해 선택할수 있게 한다.


*/