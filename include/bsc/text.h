
#pragma once
#include<iostream>
#include<string>

// SDL
#include<SDL2/SDL.h>

// Dear ImGui
#include<../imgui/imgui.h>
#include "../imgui/imgui_impl_sdl.h"
#include "../imgui/imgui_impl_opengl3.h"

// BSC
#include "widget.h"

class Text: public Widget
{
    std::string * label;

    public:
    Text(std::string _label)
    {
        label = &_label;
    }

    ~Text()
    {}

    void setup(SDL_Window * _window)
    {}

    void render()
    {
        ImGui::Text(label->c_str());
    }
};