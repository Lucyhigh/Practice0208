#pragma once
#include "GameNode.h"
//��Ʈ���������� �ʹ� ū �ڽŰ��� �ִ� Ŭ����..�θ�Ŭ������ �̸����� ���̾��̱⿡ �Ļ��ɰŶ�� ������
//�߻�ȭ�ؼ� ����Ѵ�.
//�θ�Ŭ���� : �� Ŭ������ ������� ����, �Ϲ� ���͵��� ����ٰ� ���� �� ������ ������ ������ �ؾ��Ѵ�.
//��ũ , ����, �� :�����ǰ�ü�� �� �ٸ����� ������ �߻�ȭ�ڵ尡 �������̴�. 
//�浹üũ, rect, ��������, ��������? hp�� �߻�ȭ���� ���� - �޸𸮼��� �������õ� �����ؾ��� 
//Ȯ�强�� �׻� �����ؾ��Ѵ�
class Enemy : public GameNode
{
protected:
	Image* _image;
	RECT _rc;

	int _currentFrameX;
	int _currentFrameY;
	float _x, _y;
	float _rndTimeCount;
	float _worldTimeCount;


public:
	HRESULT init(void);
	HRESULT init(const char* imageName, POINT position);
	void release(void);
	void update(void);
	void render(void);

	void move(void);
	void draw(void);
	void animation(void);
	Enemy(void);
	~Enemy(void);
};

