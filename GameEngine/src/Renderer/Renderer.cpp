#include "Renderer/Renderer.h"

namespace Rend
{
using namespace std;
Renderer::Renderer(int32_t width, int32_t hight)
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
    m_objectToRender.push_back(std::move(renderObject));
}

void Renderer::renderRect(std::shared_ptr<IRenderObject> object)
{
    std::pair<int, int> pos = object->getPosOfObject();
    std::pair<int, int> widthAndHight = object->getWidthAndhight();
    SDL_Color color = object->getColour();
    SDL_Rect rec = {pos.first, 
                    pos.second, 
                    widthAndHight.first, widthAndHight.second};
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(m_renderer, &rec);
}

void Renderer::renderImage(std::shared_ptr<IRenderObject> object)
{
    std::string imagePath = object->getImagePath();
    texture = IMG_LoadTexture(m_renderer,imagePath.c_str());

    if (texture == nullptr)
    {
        std::cout << "Failed to load texture from " << imagePath << "! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }
    std::pair<int, int> pos = object->getPosOfObject();
    std::pair<int, int> size = object->getWidthAndhight();
    SDL_Rect renderQuad = { pos.first, 
                            pos.second, 
                            size.first, 
                            size.second };
    SDL_RenderCopy(m_renderer, texture, nullptr, &renderQuad);
    SDL_DestroyTexture(texture);
}

void Renderer::renderObject()
{   
    SDL_RenderClear(m_renderer);
    for(int32_t index = 0; index <  m_objectToRender.size(); index++)
    {
        renderThisObject(m_objectToRender[index]);
    }
    SDL_RenderPresent(m_renderer);
}

void Renderer::renderThisObject(std::shared_ptr<IRenderObject> object)
{
    RenderType type = object->getRenderType();
    switch (type)
    {
    case RenderType::Rectangle:
        renderRect(object);
        break;
    case RenderType::image:
        renderImage(object);
        break;
    default:
        break;
    }
}

void Renderer::removeObject(const std::string& ID)
{
    auto it = m_objectToRender.begin();
    
    while (it < m_objectToRender.end())
    {
        if ((*it)->getID() == ID)
        {
            it = m_objectToRender.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
void Renderer::renderBackground(int32_t red, int32_t green, int32_t blue, int32_t alpha)
{
    SDL_RenderClear(m_renderer);
    SDL_SetRenderDrawColor(m_renderer, red, green, blue, alpha);
}

} // namespace Rend