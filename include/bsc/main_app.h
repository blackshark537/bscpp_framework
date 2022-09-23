
#pragma once
#include<iostream>
#include<string>

//SDL
#include <glad/glad.h>
#include<SDL2/SDL.h>

// Dear ImGui
#include<../imgui/imgui.h>
#include "../imgui/imgui_impl_sdl.h"
#include "../imgui/imgui_impl_opengl3.h"

/* uncomment to performe math operations */
//#define MATH_OPERATORS

/* uncomment to enter debug mode */
//#define DEBUG_MODE

#ifdef MATH_OPERATORS
{
    #define IMGUI_DEFINE_MATH_OPERATORS
    #include "../imgui/imgui_internal.h"
}
#endif

// BSC
#include "widget.h"

class MainApp: public Widget
{
    private:
        
        SDL_GLContext gl_context;
        SDL_WindowFlags window_flags;
        SDL_Window * window     = nullptr;
        bool full_render_loop   = true;
        bool loop               = true;
        
        int SCREEN_WIDTH  = 640;
        int SCREEN_HEIGHT = 480;
        int MIN_WIDTH     = 500;
        int MIN_HEIGHT    = 300;

        void mainLoop();

    public:
        std::string * TITLE;
        Widget * scaffold = nullptr;

    public:
        /**
         * @brief Construct a new Main App object
         * 
         * @param title window title
         * @param home Home Widget common Scaffold
         */
        MainApp(std::string title, Widget * home);
        virtual ~MainApp();

        void setDebugMode(bool active);
        void setVSync(bool vSync);
        void setTitle(std::string title);
        void setResolution(int w, int h);
        void setMinimunSize(int w, int h);
        void setFalgs(SDL_WindowFlags * flags);
        void initImGui();
        //MainApp setStyle(void (*style)());
        void run();

        virtual void setup(SDL_Window * window)
        {
            if(scaffold) scaffold->setup(window);
        }

        void render()
        {
            if(scaffold) scaffold->render();
        };

};