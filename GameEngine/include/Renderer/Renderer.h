#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "Renderer/IRenderObject.h"

namespace Rend
{
class Renderer
{
public:
    Renderer(int width, int hight, int maxFps);
    ~Renderer();

    void renderBackground(int red, int green, int blue, int alpha); 

private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    const int m_width;
    const int m_hight;
    const int m_maxFps;

    std::vector<IRenderObject> objectToRender;
};

} // namespace Rend

