#pragma once
#include <iostream>
#include <utility>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace Rend
{

enum RenderType {
  Rectangle,
  image
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
  std::string getImagePath(){ return "/home/isak/dev/GameEngine/GameEngine/images/test.png";}
  std::string getID(){return "nullID";}
private:
};

} // namespace Rend