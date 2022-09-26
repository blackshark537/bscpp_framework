#include <iostream>
#include "../include/bsc/bscpp.h"

using namespace BSCpp;

int count = 0;

void App::setup()
{
    
}

void App::loop()
{
    ImGui::Text("Count %d", count);
    if(ImGui::Button("Click Me!"))
    {
        count++;
    }
}