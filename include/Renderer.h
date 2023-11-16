#ifndef MY_RENDERER_H
#define MY_RENDERER_H

#include <Screen.h>

class Renderer
{
public:
    virtual void render(Screen screen) = 0;
};

#endif