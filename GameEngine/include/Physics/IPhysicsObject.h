#pragma once
#include "PhysicsCalculator.h"
#include "Vector2D.h"

namespace physics {
    class IPhysicsObject
    {
    public:
        Utility::Vector2D <double> position;
        Utility::Vector2D <double> vecolity;
        Utility::Vector2D <double> accelaration;
        double mass;
    private:
};

} // namespace physics