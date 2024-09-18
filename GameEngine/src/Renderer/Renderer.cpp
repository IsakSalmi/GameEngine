#include "Renderer/Renderer.h"


namespace Rend
{

Renderer::Renderer(int width, int hight, int maxFps)
: m_width(width)
, m_hight(hight)
, m_maxFps(maxFps)
{
    window = SDL_CreateWindow("SDL Window",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,m_width,m_hight,SDL_WINDOW_ALLOW_HIGHDPI);
    if (window == nullptr)
    {
        SDL_Log("SDL_CreateWindow Error: %s\n", SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        SDL_Log("SDL_CreateRenderer Error: %s\n", SDL_GetError());
    }
    SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Renderer::renderBackground(int red, int green, int blue, int alpha)
{
    SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

} // namespace Rend