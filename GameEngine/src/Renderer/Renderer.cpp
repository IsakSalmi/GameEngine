#include "Renderer/Renderer.h"


namespace Rend
{
using namespace std;
Renderer::Renderer(int width, int hight)
: m_width(width)
, m_hight(hight)
, m_window(nullptr)
, m_renderer(nullptr)
{
    m_window = SDL_CreateWindow("SDL Window",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,m_width,m_hight,SDL_WINDOW_ALLOW_HIGHDPI);
    if (m_window == nullptr)
    {
        SDL_Log("SDL_CreateWindow Error: %s\n", SDL_GetError());
    }

    m_renderer = SDL_CreateRenderer(m_window,-1,SDL_RENDERER_ACCELERATED);
    if (m_renderer == nullptr)
    {
        SDL_Log("SDL_CreateRenderer Error: %s\n", SDL_GetError());
    }
    SDL_SetRenderDrawBlendMode(m_renderer,SDL_BLENDMODE_BLEND);
}

Renderer::~Renderer()
{
    if (m_renderer != nullptr) {
        SDL_DestroyRenderer(m_renderer);  
        m_renderer = nullptr;            
    }
    if (m_window != nullptr) {
        SDL_DestroyWindow(m_window);      
        m_window = nullptr;               
    }
    SDL_Quit();
}

void Renderer::addObjectToRender(std::shared_ptr<IRenderObject> renderObject)
{
    objectToRender.push_back(std::move(renderObject));
}

void Renderer::renderRect(SDL_Rect rec, SDL_Color color)
{
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(m_renderer, &rec);
}

void Renderer::renderObject()
{
    for(int index = 0; index <  objectToRender.size(); index++)
    {
        pair<int, int> pos = objectToRender[index]->getPosOfObject();
        pair<int, int> widthAndHight = objectToRender[index]->getWidthAndhight();
        SDL_Color color = objectToRender[index]->getColour();
        SDL_Rect r = { pos.first, pos.second, widthAndHight.first, widthAndHight.second };
        renderRect(r,color);
    }
    SDL_RenderPresent(m_renderer);
    SDL_RenderClear(m_renderer);
}

void Renderer::renderBackground(int red, int green, int blue, int alpha)
{
    SDL_SetRenderDrawColor(m_renderer, red, green, blue, alpha);
    SDL_RenderClear(m_renderer);
}

} // namespace Rend