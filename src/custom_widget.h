#pragma once
#include <iostream>
#include <string>
#include "../include/sdl/SDL.h"
#include "bsc/button.h"

#include "bsc/statefull_widget.h"

class myWidget : public StatefullWidget
{
    Widget * child = nullptr;
    int count = 0;

public:

    void inc()
    {
        std::cout << "Statefull " << std::endl;
        count++;
        this->setState();
    }

    Widget * build()
    {
        return nullptr;   
    }
};