#include "Stdafx.h"
#include "Camera.h"

Camera::Camera()
{
   _trace.x = 100;
   _trace.y = 0;
   _count = 0;
   //_screen = RectMakeCenter(_trace.x, _trace.y, _trace.x+SCREEN_SIZE, _trace.y + SCREEN_SIZE);
   _screen = RectMake(_trace.x, _trace.y, WINSIZE_X, WINSIZE_Y);
}

HRESULT Camera::init(void)
{
   
    return S_OK;
}

void Camera::release(void){
}

void Camera::update(void)
{
    _screen = RectMakeCenter(_trace.x, _trace.y, WINSIZE_X, WINSIZE_Y);
}

void Camera::render(void)
{
    
    //Rectangle(getMemDC(),_screen.left,_screen.top,_screen.right,_screen.bottom);
}

RECT Camera::getScreenRect()
{
    return _screen;
}

void Camera::setScreenRect(RECT screenRect)
{
   _screen = screenRect;
}

POINT Camera::getCameraPos()
{
    return _trace;
}

void Camera::setCameraPos(POINT cameraPos)
{
   _trace = cameraPos;
}
