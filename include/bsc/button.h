
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

class Button: public Widget
{
    std::string * label;
    void (*callback)(void) = nullptr;
    public:
    Button(
        std::string _label,
        void (*_callback)(void)
    )
    {
        label = &_label;
        callback = _callback;
    }

    ~Button()
    {}

    void setup(SDL_Window * _window)
    {}

    void render()
    {
        if(ImGui::Button(label->c_str()))
        {
            this->callback();
        }
    }
};