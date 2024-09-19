#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <memory>
#include <utility>
#include "Renderer/IRenderObject.h"

namespace Rend
{
class Renderer
{
public:
    Renderer(int width, int hight);
    ~Renderer();

    void renderBackground(int red, int green, int blue, int alpha);
    void renderObject();
    void addObjectToRender(std::unique_ptr<IRenderObject> renderObject); 

private:
    void renderRect(SDL_Rect rec, SDL_Color color);
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;

    const int m_width;
    const int m_hight;

    std::vector<std::unique_ptr<IRenderObject>> objectToRender;
};

} // namespace Rend

