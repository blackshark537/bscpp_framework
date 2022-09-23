#pragma once
#include<iostream>
#include<vector>

// SDL
#include<SDL2/SDL.h>

// Dear ImGui
#include<../imgui/imgui.h>
#include "../imgui/imgui_impl_sdl.h"
#include "../imgui/imgui_impl_opengl3.h"

// BSC
#include "widget.h"

class Column: public Widget
{
    private:
        std::vector<Widget*> childs;

    public:
        Column
        (
            std::vector<Widget*> _childs
        )
        {
            childs = _childs;
        }

        ~Column()
        {
            
            for(Widget * child : childs)
            {
                delete child;
            }
            
        }

        void setup(SDL_Window * _window)
        {
            for(Widget * child : childs)
            {
                child->setup(_window);
            }
        }

        void render()
        {
            if(childs.size() > 0)
            {
                ImGui::Columns(childs.size(), NULL);
                for(Widget * child : childs)
                {
                    child->render();
                    ImGui::NextColumn();
                }
            }
        }

        
};