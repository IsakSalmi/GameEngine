#include "Physics/PhysicsCalculator.h"
#include <memory>
#include <iostream>
namespace physics
{
void PhysicsCalculator::calculateTrajectory(std::shared_ptr<IPhysicsObject> PhysicsObject, double deltaT)    
{
    double newX = PhysicsObject->position.getX() + 
        (PhysicsObject->velocity.getX() + 1/2 * PhysicsObject->acceleration.getX()) * deltaT;
    double newY = PhysicsObject->position.getY() + 
        (PhysicsObject->velocity.getY() + 1/2 * PhysicsObject->acceleration.getY()) * deltaT;

    double newVelX = PhysicsObject->velocity.getX() + deltaT * PhysicsObject->acceleration.getX();
    double newVelY = PhysicsObject->velocity.getY() + deltaT * PhysicsObject->acceleration.getY();
    std::cout << newX << std::endl;
    PhysicsObject->position.setX(newX);
    PhysicsObject->position.setY(newY);

    PhysicsObject->velocity.setX(newVelX);
    PhysicsObject->velocity.setY(newVelY);
}
} // namespace physics
