/**
Copyright (c) 2022 Berlin Santos Cruz

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
'Software'), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <filesystem>
#include <vector>
#include <iostream>

// SDL
#include <glad/glad.h>
#include <SDL2/SDL.h>

// Dear ImGui
#include <../imgui/imgui.h>
#include "../imgui/imgui_impl_sdl.h"
#include "../imgui/imgui_impl_opengl3.h"

#include "bscpp.h"

SDL_Window * window     = nullptr;
bool full_render_loop   = true;
bool loop               = true;

std::string TITLE   = "BSCpp Framework";

int SCREEN_WIDTH    = 640;
int SCREEN_HEIGHT   = 480;
int MIN_WIDTH       = 500;
int MIN_HEIGHT      = 300;
int sdl_width       = 0;
int sdl_height      = 0;

using namespace BSCpp;

#define _DEBUG_MODE_

int main(int argc, char *argv[])
{
    try
    {

        #ifdef _DEBUG_MODE_
                SDL_Log("App Start");
        #endif

        // initiate SDL
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
        {
            throw "[ERROR]" + (std::string)SDL_GetError();
        }

        SDL_version compiled;
        SDL_VERSION(&compiled);

        SDL_version linked;
        SDL_GetVersion(&linked);

        #ifdef _DEBUG_MODE_
                std::cout << "Compiled with "
                        << std::to_string(compiled.major)
                        << "." << std::to_string(compiled.minor)
                        << "." << std::to_string(compiled.patch) << std::endl;

                std::cout << "Linked with "
                        << std::to_string(linked.major)
                        << "." << std::to_string(linked.minor)
                        << "." << std::to_string(linked.patch) << std::endl;
        #endif
        // Setup Glad
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

        SDL_GL_SetAttribute(
            SDL_GL_CONTEXT_PROFILE_MASK,
            SDL_GL_CONTEXT_PROFILE_CORE);
        std::string glsl_version = "";

        #ifdef __APPLE__
                // GL 3.2 Core + GLSL 150
                glsl_version = "#version 150";
                SDL_GL_SetAttribute( // required on Mac OS
                    SDL_GL_CONTEXT_FLAGS,
                    SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
        #endif

        // setup SDL window
        SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

        // create SDL window
        window = SDL_CreateWindow(
            TITLE.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            window_flags);

        // limit to which minimum size user can resize the window
        SDL_SetWindowMinimumSize(window, MIN_WIDTH, MIN_HEIGHT);

        // Setup OpenGl Context
        SDL_GLContext gl_context = SDL_GL_CreateContext(window);

        // Initialize OpenGl Context
        SDL_GL_MakeCurrent(window, gl_context);

        if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
        {
            throw "[ERROR] Couldn't initialize glad";
        }
        else
        {
            std::cout << "[INFO] glad initialized\n";
        }

        std::cout << "[INFO] OpenGL renderer: "
                  << glGetString(GL_RENDERER)
                  << std::endl;

        // apparently, that shows maximum supported version
        std::cout << "[INFO] OpenGL from glad: "
                  << GLVersion.major
                  << "."
                  << GLVersion.minor
                  << std::endl;

        if (window == NULL)
        {
            // In the case that the window could not be made...
            throw "[ERROR]: Could not create window" + (std::string)SDL_GetError();
        }

        // Setup ViewPort
        glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

        // setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        // Load Fonts
        /* ImGuiIO &io = ImGui::GetIO();
        (void)io;
        io.Fonts->AddFontFromFileTTF("./fonts/verdana.ttf", 18.0f, NULL, NULL); */

        // Set Style
        // ImGui::StyleColorsClassic();
        ImGui::StyleColorsDark();
        // ImGui::StyleColorsLight();

        // setup platform/renderer bindings
        ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
        ImGui_ImplOpenGL3_Init(glsl_version.c_str());

        // setup background context color
        // colors are set in RGBA, but as float
        ImVec4 background = ImVec4(35 / 255.0f, 35 / 255.0f, 35 / 255.0f, 1.00f);
        glClearColor(background.x, background.y, background.z, background.w);

        #ifdef _DEBUG_MODE_
                SDL_Log("Start Loop");
        #endif
        // Instantiating BSCpp_App
        std::unique_ptr app = std::make_unique<App>();
        if(!app) {
            throw "Couldn't create an instance of BSC_APP\n";
        }

        // Call App Setup Function;
        app->setup();

        while (loop)
        {
            //this->mainLoop();
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

            // Event Loop
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                // without it you won't have keyboard input and other things
                ImGui_ImplSDL2_ProcessEvent(&event);

                // you might also want to check io.WantCaptureMouse and io.WantCaptureKeyboard
                // before processing events

                switch (event.type)
                {
                case SDL_QUIT:
                    loop = false;
                    break;
                };

                if (event.type == SDL_WINDOWEVENT)
                {
                    switch (event.window.event)
                    {
                    case SDL_WINDOWEVENT_MAXIMIZED:
                        full_render_loop = true;
                        #ifdef _DEBUG_MODE_
                            SDL_Log("Window %d maximized", event.window.windowID);
                        #endif
                        break;
                    case SDL_WINDOWEVENT_MINIMIZED:
                        full_render_loop = false;
                        #ifdef _DEBUG_MODE_
                            SDL_Log("Window %d minimized", event.window.windowID);
                        #endif
                        break;
                    case SDL_WINDOWEVENT_RESTORED:
                        full_render_loop = true;
                        #ifdef _DEBUG_MODE_
                            SDL_Log("Window %d restored", event.window.windowID);
                        #endif
                        break;
                    case SDL_WINDOWEVENT_ENTER:
                            full_render_loop = true;
                            #ifdef _DEBUG_MODE_
                                SDL_Log("Mouse entered window %d", event.window.windowID);
                            #endif
                            break;
                        case SDL_WINDOWEVENT_LEAVE:
                            full_render_loop = false;
                            #ifdef _DEBUG_MODE_
                                SDL_Log("Mouse left window %d", event.window.windowID);
                            #endif
                            break;
                    }
                }
            }

            /* ImGui Tree Start Here */
                // start the Dear ImGui frame
                ImGui_ImplOpenGL3_NewFrame();
                ImGui_ImplSDL2_NewFrame(window);
                SDL_GetWindowSize(window, &sdl_width, &sdl_height);

                ImGui::NewFrame();
                    // Call App Loop;
                    app->loop();
                ImGui::EndFrame();

                ImGui::Render();
                ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            /* ImGui Tree End Here */

            // rendering
            SDL_GL_SwapWindow(window);

            if (!full_render_loop)
                SDL_Delay(50);
        }
        #ifdef _DEBUG_MODE_
                SDL_Log("End Loop");
        #endif

        // Close and destroy the window
        #ifdef _DEBUG_MODE_
                SDL_Log("App Exit");
        #endif

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();

        SDL_GL_DeleteContext(gl_context);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}