#pragma once 
#include <iostream>
#include "Physics/IPhysicsObject.h"

class Obstacle : public physics::IPhysicsObject
{
public:
    Obstacle(int width, int height);
    Obstacle(int width, int height, int xPosition, int yPosition);
    void SetPosition(int xPosition, int yPosition);
    void SetSize(int newWidth, int newHeight);
private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
};
