#pragma once
#include "GameNode.h"
#define SCREEN_SIZE 600
class Camera : public GameNode
{
private:
    POINT _trace;
    RECT _screen;
    int _count;
   // Image* _cameraRect;
public:
    HRESULT init(void);
    void release(void);
    void update(void);
    void render(void);

    POINT getCameraPos();
    void setCameraPos(POINT cameraPos);

    RECT getScreenRect();
    void setScreenRect(RECT screenRect);

public:
    Camera();
    ~Camera() {}
};