#include "Utility/ObjectUtility.h"

namespace Utility
{
bool ObjectUtility::checkCollision(const SDL_Rect& rectA, const SDL_Rect& rectB) {
    // Check if the rectangles are not overlapping
    if (rectA.x + rectA.w <= rectB.x ||  // Right side of A is to the left of B
        rectA.x >= rectB.x + rectB.w ||  // Left side of A is to the right of B
        rectA.y + rectA.h <= rectB.y ||  // Bottom side of A is above B
        rectA.y >= rectB.y + rectB.h)    // Top side of A is below B
    {
        // No collision
        return false;
    }

    // Collision detected
    return true;
}
}
