#include <iostream>
#include "../include/bsc/bscpp.h"
#include "../include/bsc/IconsFontAwesome5.h"

using namespace BSCpp;

ImFont * icons;
ImFont * fonts;
int count = 0;

void App::setup()
{
    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->AddFontDefault();
    
    // merge in icons from Font Awesome
    static const ImWchar icons_ranges[] = { ICON_MIN_FA, ICON_MAX_16_FA, 0 };
    ImFontConfig icons_config; 
    icons_config.MergeMode = true; 
    icons_config.PixelSnapH = true;
    icons = io.Fonts->AddFontFromFileTTF( "./icons/fa-solid-900.ttf", 16.0f, &icons_config, icons_ranges );
    fonts  = io.Fonts->AddFontFromFileTTF("./fonts/verdana.ttf", 18.0f, NULL, NULL);
}

void App::loop()
{
    
    ImGui::PushFont(fonts);
        ImGui::BulletText("Count %d", count);
    ImGui::PopFont();

    ImGui::PushFont(icons);
        ImGui::Text( ICON_FA_LAPTOP);
    ImGui::PopFont();

    ImGui::SameLine();
    
    ImGui::PushFont(fonts);
        if(ImGui::Button("Click Me!"))
        {
            count++;
        }
    ImGui::PopFont();
}