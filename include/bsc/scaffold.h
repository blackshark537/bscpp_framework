#pragma once
#include<iostream>

// SDL
#include<SDL2/SDL.h>

// Dear ImGui
#include<../imgui/imgui.h>
#include "../imgui/imgui_impl_sdl.h"
#include "../imgui/imgui_impl_opengl3.h"

// BSC
#include "widget.h"
#include "app_bar.h"

class Scaffold: public Widget
{
    SDL_Window * window = nullptr;
    NavBar * appBar = nullptr;
    Widget * body = nullptr;
    
    //Variables for allocate the size of the main window
    int sdl_width = 0, sdl_height = 0;

    public:
        Scaffold(
            NavBar * _appBar,
            Widget * _body
        )
        {
            appBar = _appBar;
            body = _body;
        }

        virtual ~Scaffold()
        {
            if(appBar) delete appBar;
            if(body) delete body;
        }

        void setup(SDL_Window * _window)
        {
            window = _window;
            if(appBar) appBar->setup(_window);
            if(body) body->setup(_window);
        }

        void render()
        {
            // get the window size as a base for calculating widgets geometry
            SDL_GetWindowSize(window, &sdl_width, &sdl_height);

            ImGui::NewFrame();
                // position the controls widget in the top-right corner with some margin
                ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
                // here we set the calculated width and also make the height to be
                // be the height of the main window also with some margin
                ImGui::SetNextWindowSize(
                ImVec2(static_cast<float>(sdl_width), static_cast<float>(sdl_height)),
                    ImGuiCond_Always
                );
                ImGui::Begin(
                    "Scaffold", NULL, 
                    ImGuiWindowFlags_NoResize 
                    | ImGuiWindowFlags_NoCollapse 
                    | ImGuiWindowFlags_NoTitleBar
                    | ImGuiWindowFlags_MenuBar
                    | ImGuiWindowFlags_NoBringToFrontOnFocus
                );
                    if(appBar) appBar->render();
                    if(body) body->render();
                ImGui::End();

            ImGui::EndFrame();
            
        }
};