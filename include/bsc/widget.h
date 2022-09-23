#pragma once
// SDL
#include<SDL2/SDL.h>

class Widget
{
    public:
        virtual void setup(SDL_Window * window)     =0;
        virtual void render()                       =0;
};