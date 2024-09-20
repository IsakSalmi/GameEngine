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
    Renderer(int32_t width, int32_t hight);
    ~Renderer();


    void renderBackground(int32_t red, int32_t green, int32_t blue, int32_t alpha) const;
    void renderObject();
    void addObjectToRender(std::shared_ptr<IRenderObject> renderObject); 
    void removeObject(const std::string& ID);

private:
    void renderThisObject(std::shared_ptr<IRenderObject> object);
    void renderRect(const std::shared_ptr<IRenderObject> &object) const;
    void renderImage(const std::shared_ptr<IRenderObject>& object);
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture* texture;

    const int32_t m_width;
    const int32_t m_hight;

    std::vector<std::shared_ptr<IRenderObject>> m_objectToRender;
};

} // namespace Rend

