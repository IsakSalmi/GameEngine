#pragma once
#include <ratio>
#include <SDL2/SDL_rect.h>


namespace Utility {

class ObjectUtility
{
public:
    ObjectUtility() = default;
    ~ObjectUtility() = default;
    bool checkCollision(const SDL_Rect& rectA, const SDL_Rect& rectB);
};

}
