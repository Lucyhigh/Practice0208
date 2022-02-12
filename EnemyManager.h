#pragma once
#include "GameNode.h"
#include "Enemy.h"

class EnemyManager : public GameNode
{
private:
	typedef vector<Enemy*> vEnemy;
	typedef vector<Enemy*>::iterator viEnemy;

	vEnemy _vMinion;
	viEnemy _viMinion;
	ProgressBar* _minionHpBar;
	float _x, _y;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	void setMinion(void);
	void removeMinion(int arrNum);

	//������ ���� ���͸���
	//������ ��� ���� �������� �˼������� �˼�����
	vector<Enemy*> getMinion(void) { return _vMinion; }
public:
	EnemyManager() {}
	~EnemyManager() {}
};

