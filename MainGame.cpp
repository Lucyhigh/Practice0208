#include "Stdafx.h"
#include "MainGame.h"
#include "StartScene.h"
#include "FirstScene.h"
#include "SecondScene.h"
#include "ThirdScene.h"
#include "Inventory.h"
#include "Store.h"
#include "PixelScene.h"
#include "SoundScene.h"

HRESULT MainGame::init(void) //�ʱ�ȭ
{
	GameNode::init(TRUE);

	SCENEMANAGER->addScene("Ÿ��Ʋ", new StartScene);
	SCENEMANAGER->addScene("����", new FirstScene);
	SCENEMANAGER->addScene("����", new SecondScene);
	SCENEMANAGER->addScene("������", new ThirdScene);

	SCENEMANAGER->addScene("�κ��丮", new Inventory);
	SCENEMANAGER->addScene("����", new Store);
	SCENEMANAGER->addScene("�ȼ�", new PixelScene);
	SCENEMANAGER->addScene("����", new SoundScene);

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
/*
���� MP3�÷��̾�
- 7�� -
1. ��� ��ư�� ������ ����� �ǰ� �����ư�� �Ͻ����� ��ư���� �ٲ��.
2. �Ͻ������� ������ �Ͻ������� �ǰ� �����ư���� �ٲ��.//bool �� ���
3. ���� ��ư�� ������ ������ //�ε��� -1
4. ���� ��ư�� ������ ������ //�ε��� +1
5. ���ٰ� �־�� �ϰ� �߰��� Ŭ���ϸ� �߰����� ��� //ã�ƺ�����
6. �� ��� �ð��� ǥ�õǾ�� �ϰ� ��ü �ð� ǥ�� //�� �߰�
7. �� ���� ����� ������ ���������� �Ѿ��. >�ڵ� //ã��
8. �̹����� ������ �̹����� ��
9. � ���� �̸����� ��
�뷡 7�� �ش�Ǵ� �ٹ� �̹��� ��
�������� �ʼ� //ã�ƺ�����
+@ �뷡�� �̹����� ���� �ε��� ���� �����´�.���̺�ε�
�� ������Ʈ ó��(�뷡 X)
*/