#pragma once
#include <iostream>
#include "Entity/Entity.h"
#include "Utility/ObjectUtility.h"
#include <memory>
#include <vector>

namespace Entman {
class EntityManager {
    public: 
        EntityManager() = default;

        void createEntity(std::pair<int, int> positionXY, std::pair<int, int> widthAndHeight, SDL_Color colour);
        void createEntity(std::pair<int, int> widthAndHeight, SDL_Color colour);
        void createEntity(std::pair<int, int> widthAndHeight);

        void checkAllCollision();

        // getEntity(int id);

    private:
        Utility::ObjectUtility m_utility;
        
        std::vector<std::shared_ptr<Ent::Entity>> m_allEntities;
        std::vector<std::pair<int, int>> m_collidingEntities;
    };  
} // namespace Ent
