#pragma once

// SDL
#include<SDL2/SDL.h>

// Dear ImGui
#include<../imgui/imgui.h>
#include "../imgui/imgui_impl_sdl.h"
#include "../imgui/imgui_impl_opengl3.h"

// BSC
#include "widget.h"

class Container: public Widget
{
    private:
        Widget * child = nullptr;
        std::string * id;
    public:
        Container(std::string _id, Widget * _child)
        {
            id = &_id;
            child = _child;
        }

        virtual ~Container()
        {
            
        }

        void setup(SDL_Window * _window)
        {
            if(child) child->setup(_window);
        }

        void render()
        {
            ImGui::BeginChild(id->c_str());
                if(child) child->render();
            ImGui::EndChild();
        }
};