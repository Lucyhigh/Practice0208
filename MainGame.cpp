#include "Stdafx.h"
#include "MainGame.h"
#include "StartScene.h"
#include "FirstScene.h"
#include "SecondScene.h"
#include "ThirdScene.h"


HRESULT MainGame::init(void) //�ʱ�ȭ
{
	GameNode::init(TRUE);

	SCENEMANAGER->addScene("Ÿ��Ʋ", new StartScene);
	SCENEMANAGER->addScene("����", new FirstScene);
	SCENEMANAGER->addScene("����", new SecondScene);
	SCENEMANAGER->addScene("������", new ThirdScene);

	SCENEMANAGER->changeScene("����");

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
}

void MainGame::update(void)
{
	GameNode::update();
	SCENEMANAGER->update();
}

void MainGame::render(void)
{
	//������ �� ��Ʈ��
	//PatBlt() : �簢�� ������ �귯���� ä��� �Լ�
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	//==================================================

	SCENEMANAGER->render();
	TIMEMANAGER->render(getMemDC());

	//==================================================
	this->getBackBuffer()->render(getHDC()); //������� ������ HDC�� �׸���.
}