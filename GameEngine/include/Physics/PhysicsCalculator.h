#pragma once
#include "Utility/Vector2D.h"
#include "Physics/IPhysicsObject.h"
#include <memory>
namespace physics
{
class IPhysicsObject; 
class PhysicsCalculator
{
public:
    PhysicsCalculator() = default;
    ~PhysicsCalculator() = default;

    void calculateTrajectory(std::shared_ptr<IPhysicsObject> PhysicsObject, double deltaT);
private:
};    
} // namespace physics
