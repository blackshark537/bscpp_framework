#pragma once
// SDL
#include<SDL2/SDL.h>
#include "widget.h"

class StatefullWidget: public Widget
{
    Widget * child = nullptr;
    public:
        void setup(SDL_Window * window)
        {
        }

        void setState()
        {
            
        }

        void render(){
            child->render();
        }

        void build(Widget * _child){
            child = _child;
        }
};