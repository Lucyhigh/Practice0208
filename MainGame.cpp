#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
    GameNode::init(TRUE);

    //IMAGEMANAGER->addImage("½´ÆÃ ¸Ê", "Resources/Images/BackGround/ShootingBG.bmp", WINSIZE_X, WINSIZE_Y);
    IMAGEMANAGER->addImage("ÀüÀå", "Resources/Images/BackGround/BattleField.bmp", WINSIZE_X, WINSIZE_Y);

    _rocket = new Rocket;
    _rocket->init();
    _em = new EnemyManager;
    _em->init();

    _aniTest = new AniTestScene;
    _aniTest->init();

    _missileEffect = new MissileEffect;
    _missileEffect->init();

    _beamEffect = new BeamEffect;
    _beamEffect->init();

    _em->setRocketMemoryAddress(_rocket);
    _rocket->setEnemyManagerMemoryAddress(_em);

    _x, _y = 0.0f;
    return S_OK;
}

void MainGame::release(void)
{
    GameNode::release();

    _rocket->release();
    SAFE_DELETE(_rocket);
    _em->release();
    SAFE_DELETE(_em);

    _aniTest->release();
    SAFE_DELETE(_aniTest);

    _missileEffect->release();
    SAFE_DELETE(_missileEffect);

    _beamEffect->release();
    SAFE_DELETE(_beamEffect);
}

void MainGame::update(void)
{
    GameNode::update();

    _rocket->update();
    _em->update();
    _aniTest->update();

    collision();

    /*  _missileEffect->update();
      _beamEffect->update();*/
    _y -= 0.2f;
}

void MainGame::render(void)
{
    PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

    //IMAGEMANAGER->render("½´ÆÃ ¸Ê", getMemDC());
    RECT rc = { 0,0, WINSIZE_X, WINSIZE_Y };
    IMAGEMANAGER->findImage("ÀüÀå")->loopRender(getMemDC(), &rc, _x, _y);
    TIMEMANAGER->render(getMemDC());

    _rocket->render();
    _em->render();

    _aniTest->render();
    _missileEffect->render();
    _beamEffect->render();

    this->getBackBuffer()->render(getHDC());
}

