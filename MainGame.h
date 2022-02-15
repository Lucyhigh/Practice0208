#pragma once
#include "GameNode.h"
#include "Rocket.h"
#include "EnemyManager.h"
#include "AniTestScene.h"

#include "ShootingEffect.h"

class MainGame : public GameNode
{
private:
    Rocket* _rocket;
    EnemyManager* _em;

    AniTestScene* _aniTest;

    MissileEffect* _missileEffect;
    BeamEffect* _beamEffect;

    float _x, _y;
public:
    HRESULT init(void);
    void release(void);
    void update(void);
    void render(void);

    void collision(void);
public:
    MainGame() {}
    ~MainGame() {}
};
