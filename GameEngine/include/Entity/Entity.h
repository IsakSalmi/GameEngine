#pragma once
#include <iostream>
#include "Renderer/IRenderObject.h"

namespace Ent {
class Entity : public Rend::IRenderObject {
    public: 
        Entity();
        Entity(std::pair<int, int> positionXY, std::pair<int, int> widthAndHeight, SDL_Color colour);
        Entity(std::pair<int, int> widthAndHeight, SDL_Color colour);
        Entity(std::pair<int, int> widthAndHeight);

        void setPoistionXY(std::pair<int, int> positionXY);
        void moveXY(std::pair<int, int> positionXY);
        void moveXY(int x, int y);
        void setWidhtAndHeight(std::pair<int, int> widthAndHeight);
        void setColour(SDL_Color colour);
        SDL_Rect getRect();

        std::pair<int, int> getPosOfObject();
        std::pair<int, int> getWidthAndhight();
        Rend::RenderType getRenderType();
        SDL_Color getColour(); 
        


    private:
        std::pair<int, int> m_positionXY;
        std::pair<int, int> m_widthAndHeight;
        SDL_Color m_colour;
};  
} // namespace Ent