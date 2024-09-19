#pragma once
#include <iostream>
#include <utility>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace Rend
{

enum RenderType {
  Rectangle
};

class IRenderObject
{
public:
  virtual ~IRenderObject() = default; 
  //! return a pair of the x and y coordinate whrer the image will be renderd
  virtual std::pair<int, int> getPosOfObject() = 0;
  virtual std::pair<int, int> getWidthAndhight() = 0;
  virtual RenderType getRenderType() = 0; 
  virtual SDL_Color getColour() = 0;
private:
};

} // namespace Rend