#pragma once 

#include <iostream>

class RunWindow
{
public:
    RunWindow();
    int Run();
private:
    int WINDOW_WIDTH{640};
    int WINDOW_HEIGHT{480};
};

