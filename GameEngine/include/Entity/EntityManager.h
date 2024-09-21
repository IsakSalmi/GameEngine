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
        void addEntity(std::shared_ptr<Ent::Entity> newEntity);
        std::shared_ptr<Ent::Entity> getEntityByIndex(int index);
        std::pair<int, int> getCollisionPairByIndex(int index);
        bool checkAllCollision();
        void printCollidingIndexes();

        // getEntity(int id);

    private:
        Utility::ObjectUtility m_utility;
        
        std::vector<std::shared_ptr<Ent::Entity>> m_allEntities;
        std::vector<std::pair<int, int>> m_collidingEntities;
    };
} // namespace Ent
