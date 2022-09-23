#pragma once
#include<iostream>
#include<list>
#include<string>
#include<vector>

// SDL
#include<SDL2/SDL.h>

// Dear ImGui
#include<../imgui/imgui.h>
#include "../imgui/imgui_impl_sdl.h"
#include "../imgui/imgui_impl_opengl3.h"

// BSC
#include "widget.h"

/**
 * @brief 
 * 
 */
typedef struct {
    std::string label;
    std::string shortCut;
    void (*callback)(void);
    bool selected = false;
    bool enabled = true;
} MenuItem;

/**
 * @brief 
 * @param label
 */
typedef struct {
    std::string label;
    void (*callback)(void) = NULL;
    std::vector<MenuItem> * items;
    bool selected = false;
    bool enabled = true;
} MenuButton;

class NavBar: public Widget
{
    std::string * brand = nullptr;
    SDL_Window * window = nullptr;
    std::vector<MenuButton> * menu = nullptr;
    
    //Variables for allocate the size of the main window
    int sdl_width = 0, sdl_height = 0;

    public:
        NavBar(
            std::string _brand,
            std::vector<MenuButton> * _menu
        )
        {
            brand = &_brand;
            menu = _menu;
        }

        ~NavBar()
        {
            if (brand) delete brand;
            if (menu) delete menu;
        }

        void setup(SDL_Window * _window)
        {
            window = _window;
        }

        void render()
        {
            if (ImGui::BeginMenuBar())
            {
                ImGui::Text("%s", brand->c_str());

                if(menu)
                {

                    for(MenuButton el : *menu)
                    {
                        if(el.callback)
                        {
                            if(ImGui::Button(el.label.c_str()))
                            {
                                el.callback();
                            }
                        }
                        else
                        {
                            if (ImGui::BeginMenu(el.label.c_str(), el.enabled))
                            {
                                for(MenuItem item : *el.items)
                                {
                                    //MenuItem * item = &(*itemlist);

                                    if (ImGui::MenuItem(
                                        item.label.c_str(),
                                        item.shortCut.c_str(), 
                                        item.selected, 
                                        item.enabled)
                                    )  
                                    { 
                                        /* Event Handle */
                                        item.callback();
                                    }
                                }
                                ImGui::EndMenu();
                            }
                        }
                    }
                }
                ImGui::EndMenuBar();
            }
        }
};