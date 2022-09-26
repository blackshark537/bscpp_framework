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

typedef struct {
    int column = 0;
    float size = 100.0f;
} StyleColumn;

class Column : public Widget
{
private:
    std::vector<Widget *> childs;
    StyleColumn * style = nullptr;
public:
    Column(
        std::vector<Widget *> _childs,
        StyleColumn * _style = nullptr
    )
    {
        childs = _childs;
        style = _style;
    }

    ~Column()
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
            ImGui::Columns(childs.size(), NULL);
            if(style){
                ImGui::SetColumnWidth(style->column-1, style->size);
            }
            for (Widget *child : childs)
            {
                child->render();
                ImGui::NextColumn();
            }
        }
    }
};