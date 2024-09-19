#include "Obstacle.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


Obstacle::Obstacle(int width, int height) : m_x {0}, m_y {0}
{
    SetSize(width, height);
}

Obstacle::Obstacle(int width, int height, int xPosition, int yPosition)
{
    SetSize(width, height);
    SetSize(xPosition, yPosition);
}


void Obstacle::SetPosition(int x, int y)
{
    this->m_x = x;
    this->m_y = y;    
}

void Obstacle::SetSize(int width, int height)
{
    this->m_height = height;
    this->m_width = width;
}