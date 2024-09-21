#include "EntityManager.h"
#include "Entity.h"

namespace Entman 
{
    using namespace std;
    void EntityManager::addEntity(std::shared_ptr<Ent::Entity> newEntity)
    {
        m_allEntities.push_back(newEntity);
    }
    
    std::shared_ptr<Ent::Entity> EntityManager::getEntityByIndex(int index) 
    {
        return m_allEntities[index];
    }
    
    std::pair<int, int> EntityManager::getCollisionPairByIndex(int index)
    {
        return m_collidingEntities[index];
    }

    bool EntityManager::checkAllCollision() 
    {
        bool collisionFound = false;
        m_collidingEntities.clear();
        for (int32_t index1 = 0; index1 < m_allEntities.size(); index1++)
        {
            for (int32_t index2 = index1 + 1; index2 < m_allEntities.size(); index2++)
            {
                if (m_utility.checkCollision(m_allEntities[index1]->getRect(), m_allEntities[index2]->getRect())) 
                {
                    std::pair<int, int> collidingPair = {index1, index2};
                    m_collidingEntities.push_back(collidingPair);
                    collisionFound = true;
                }
            }
        }
        return collisionFound;
    }

    void EntityManager::printCollidingIndexes() 
    {
        for (size_t i = 0; i < m_collidingEntities.size(); i++)
        {
            cout << "Colliding pair indexes: (" << m_collidingEntities[i].first << ", " << m_collidingEntities[i].second << ")" << endl;
        }
    }

} // namespace Entman