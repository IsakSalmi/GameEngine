#pragma once
#include "Utility/Vector2D.h"
#include "IPhysicsObject.h"
namespace physics
{
class PhysicsCalculator
{
public:
    PhysicsCalculator() = default;
    ~PhysicsCalculator() = default;

    void calculateTrajectory(IPhysicsObject PhysicsObject, double deltaT);
private:
};    
} // namespace physics
