#pragma once
#include "GameNode.h"
#include "Enemy.h"
#define PI 3.141592
class EnemyManager:public GameNode
{
	//typedef c����..
	//typedef vector<Enemy***> vEnemy;�� ���� ����
	//���������ʹ� ������ ����
	//Ʈ���������� friend Ű���� ��ü���� �ı��ϴ� Ű���� - �������� ����
	//������� ����� ������ ģ��Ű����� ������ �����̺��� �����ϼ����� �Ϲ��� ģ����
	//�ټ��� �Լ��� ���� ȣ��
	//�ټ��� ���Լ���(LIFO) - �ӵ��� �� ����
	//go to���̶�� �����ϴ� ����� ���� �� �������ҿ� ���°� ����! - ���İ�Ƽ �Ǳ� ������

	//����-> �ּڰ��� ���״� ����Ʈ�����ͷ� ����ϼ�
private:
	typedef vector<Enemy*> vEnemy;
	typedef vector<Enemy*>::iterator viEnemy;

private:
	vEnemy _vMiniom;
	viEnemy _viMiniom;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void setMinion(void);
	void setMinion2(void);

	EnemyManager() {}
	~EnemyManager() {}
};

