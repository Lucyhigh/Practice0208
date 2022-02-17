#include "Stdafx.h"
#include "MainGame.h"
#include "StartScene.h"
#include "ShootingScene.h"
#include "PixelScene.h"

HRESULT MainGame::init(void) //초기화
{
	GameNode::init(TRUE);

	SCENEMANAGER->addScene("슈팅", new ShootingScene);
	SCENEMANAGER->addScene("시작", new ShootingScene);
	SCENEMANAGER->addScene("픽셀충돌", new PixelScene);

	SCENEMANAGER->changeScene("픽셀충돌");

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
}

void MainGame::update(void) // 갱신
{
	GameNode::update();
	SCENEMANAGER->update();
}

void MainGame::render(void) // 그려줘
{
	//검은색 빈 비트맵
	//PatBlt() : 사각형 영역을 브러쉬로 채우는 함수
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	//==================================================

	SCENEMANAGER->render();
	TIMEMANAGER->render(getMemDC());

	//==================================================
	this->getBackBuffer()->render(getHDC()); //백버퍼의 내용을 HDC에 그린다.
}