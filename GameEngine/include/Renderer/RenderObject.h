#pragma once
#include <iostream>
#include <utility>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Renderer/IRenderObject.h"


namespace Rend
{

class RenderObject
: public IRenderObject 
{
public:
    RenderObject() = default;
    ~RenderObject() override = default;
    std::pair<int, int> getPosOfObject();
    std::pair<int, int> getWidthAndhight();
    RenderType getRenderType(); 
    SDL_Color getColour();

    void setPos(int x, int y);
private:
    std::pair<int, int> m_pos;
};

} // namespace Rend