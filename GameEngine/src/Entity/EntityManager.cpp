#include "EntityManager.h"
#include "Entity.h"


using namespace std;

namespace Entman 
{
    void EntityManager::createEntity(pair<int, int> positionXY, pair<int, int> widthAndHeight, SDL_Color colour)
    {
        m_allEntities.push_back(std::make_shared<Ent::Entity>(positionXY, widthAndHeight, colour));
    }
    
    void EntityManager::createEntity(pair<int, int> widthAndHeight, SDL_Color colour)
    {
        pair<int, int> positionXY = {0, 0};
        m_allEntities.push_back(std::make_shared<Ent::Entity>(positionXY, widthAndHeight, colour));
    }

    void EntityManager::createEntity(pair<int, int> widthAndHeight)
    {
        pair<int, int> positionXY = {0, 0};
        SDL_Color colour = {0, 255, 0, 255};
        m_allEntities.push_back(std::make_shared<Ent::Entity>(positionXY, widthAndHeight, colour));
    }

    void EntityManager::checkAllCollision() 
    {
        cout << "helo" << endl;
        /*
        m_collidingEntities.clear();
        for (int32_t index1 = 0; index1 < m_allEntities.size(); index1++)
        {
            for (int32_t index2 = index1 + 1; index2 < m_allEntities.size(); index2++)
            {
                if (m_utility.checkCollision(m_allEntities[index1]->getRect(), m_allEntities[index2]->getRect())) 
                {
                    std::pair<int, int> collidingPair = {index1, index2};
                    m_collidingEntities.push_back(collidingPair);
                }
            }
        }
        cout << "Colliding entitites: " << m_collidingEntities.size() << endl;
        */
    }

} // namespace Entman