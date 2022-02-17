#pragma once
#include "GameNode.h"
#include "ProgressBar.h"
struct Player
{
	RECT _rcPlayer;
	int _plHp;
	bool _isLeft;
	bool _isWaiting;

};
class ThirdScene : public GameNode
{
private:
	char _text[64];
	bool _isLive;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	ThirdScene() {}
	~ThirdScene() {}
};
/*
- ������ �������� �÷��̾� �Ӹ����� HP�ٰ� ��µȴ�.- �׸��� ����� ���ÿ� HP�� ��� ����- HP�� ���� ���ҵǸ� ��� ���� ���- ��� ������ �߰� ���� �ð��� ������ ȭ���� ��ο� ���� ��ŸƮ ������ �ڵ� ��ȯ

*/
