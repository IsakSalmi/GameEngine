#include "Entity.h"


using namespace std;

namespace Ent {
    Entity::Entity() : m_positionXY({640/2, 480/2}), m_widthAndHeight({100, 50}), m_colour({0, 255, 0, 255})
    {
    }

    Entity::Entity(pair<int, int> positionXY, pair<int, int> widthAndHeight, SDL_Color colour) : m_positionXY(positionXY), m_widthAndHeight(widthAndHeight), m_colour(colour)
    {
    }
    
    Entity::Entity(pair<int, int> widthAndHeight, SDL_Color colour) : m_positionXY({0, 0}), m_widthAndHeight(widthAndHeight), m_colour(colour)
    {
    }

    Entity::Entity(pair<int, int> widthAndHeight) : m_positionXY({0, 0}), m_widthAndHeight(widthAndHeight)
    {
    }


    void Entity::setPoistionXY(pair<int, int> positionXY) 
    {
        std::cout << "Correct function" << std::endl;
        m_positionXY = positionXY;
    }
    
    void Entity::moveXY(pair<int, int> positionXY) 
    {
        this->m_positionXY.first += positionXY.first;
        this->m_positionXY.second += positionXY.second;
    }
    
    void Entity::moveXY(int x, int y) 
    {
        m_positionXY.first = 10;
        m_positionXY.second = 10;
    }

    void Entity::setWidhtAndHeight(pair<int, int> widthAndHeight)
    {
        this->m_widthAndHeight = widthAndHeight;
    }
    
    void Entity::setColour(SDL_Color colour)
    {
        this->m_colour;
    }

    pair<int, int> Entity::getPosOfObject()
    {
        return this->m_positionXY;
    }

    pair<int, int> Entity::getWidthAndhight()
    {
        return this->m_widthAndHeight;
    }

    Rend::RenderType Entity::getRenderType()
    {
        return Rend::RenderType::Rectangle;
    }

    SDL_Color Entity::getColour()
    {
       return this->m_colour;
    }
    
    SDL_Rect Entity::getRect()
    {
        return SDL_Rect({m_positionXY.first, m_positionXY.second, m_widthAndHeight.first, m_widthAndHeight.second});
    }
}