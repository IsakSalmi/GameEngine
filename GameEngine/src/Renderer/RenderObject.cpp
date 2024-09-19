#include "Renderer/RenderObject.h"


namespace Rend
{

void RenderObject::setPos(int x, int y)
{
    m_pos.first = x;
    m_pos.second = y;
}

std::pair<int, int> RenderObject::getPosOfObject()
{
    return m_pos;
}
std::pair<int, int> RenderObject::getWidthAndhight()
{
    return std::pair<int, int>(200 , 200);
}
RenderType RenderObject::getRenderType()
{
    return RenderType::Rectangle;
}
SDL_Color RenderObject::getColour()
{
    SDL_Color color;
    color.a = 255;
    color.b = 255;
    color.g = 0;
    color.r = 0;
    return color;
}
} // namespace Rend