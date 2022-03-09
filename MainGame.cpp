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

HRESULT MainGame::init(void) //초기화
{
	GameNode::init(TRUE);

	SCENEMANAGER->addScene("타이틀", new StartScene);
	SCENEMANAGER->addScene("시작", new FirstScene);
	SCENEMANAGER->addScene("마을", new SecondScene);
	SCENEMANAGER->addScene("죽음땅", new ThirdScene);

	SCENEMANAGER->addScene("인벤토리", new Inventory);
	SCENEMANAGER->addScene("상점", new Store);
	SCENEMANAGER->addScene("픽셀", new PixelScene);
	SCENEMANAGER->addScene("사운드", new SoundScene);

	SCENEMANAGER->changeScene("사운드");

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
	//검은색 빈 비트맵
	//PatBlt() : 사각형 영역을 브러쉬로 채우는 함수
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	//==================================================

	SCENEMANAGER->render();
	TIMEMANAGER->render(getMemDC());

	//==================================================
	this->getBackBuffer()->render(getHDC()); //백버퍼의 내용을 HDC에 그린다.
}
/*
과제 MP3플레이어
- 7곡 -
1. 재생 버튼을 누르면 재생이 되고 재생버튼이 일시정지 버튼으로 바뀐다.
2. 일시정지를 누르면 일시정지가 되고 재생버튼으로 바뀐다.//bool 문 사용
3. 이전 버튼을 누르면 이전곡 //인덱스 -1
4. 다음 버튼을 누르면 다음곡 //인덱스 +1
5. 재상바가 있어야 하고 중간을 클릭하면 중간부터 재생 //찾아봐야함
6. 곡 재생 시간이 표시되어야 하고 전체 시간 표기 //걍 추가
7. 한 곡의 재생이 끝나면 다음곡으로 넘어간다. >자동 //찾기
8. 이미지는 윈앰프 이미지로 ㅇ
9. 곡에 대한 이름까지 ㅇ
노래 7곡 해당되는 앨범 이미지 ㅇ
볼륨조절 필수 //찾아봐야함
+@ 노래와 이미지는 전부 로딩을 거쳐 가져온다.세이브로드
ㄴ 업데이트 처리(노래 X)
*/