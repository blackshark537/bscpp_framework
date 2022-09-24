#pragma once
#include <iostream>
#include <vector>

// SDL
#include <SDL2/SDL.h>

// Dear ImGui
#include <../imgui/imgui.h>
#include "../imgui/imgui_impl_sdl.h"
#include "../imgui/imgui_impl_opengl3.h"

// BSC
#include "widget.h"

class Row : public Widget
{
private:
    std::vector<Widget *> childs;

public:
    Row(
        std::vector<Widget *> _childs)
    {
        childs = _childs;
    }

    ~Row()
    {

    }

    void setup(SDL_Window *_window)
    {
        for (Widget *child : childs)
        {
            child->setup(_window);
        }
    }

    void render()
    {
        if (childs.size() > 0)
        {
            for (Widget *child : childs)
            {
                child->render();
            }
        }
    }
};