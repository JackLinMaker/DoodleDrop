//
//  EntityManager.cpp
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-24.
//
//

#include "EntityManager.h"
#include "BaseGameEntity.h"

EntityManager* EntityManager::Instance()
{
    static EntityManager instance;
    return &instance;
}

BaseGameEntity* EntityManager::GetEntityFromID(int id) const
{
    EntityMap::const_iterator ent = _entityMap.find(id);
    assert((ent != _entityMap.end()) && "<EntityManager::GetEntityFromID>: invalid ID");
    return ent->second;
}

void EntityManager::RemoveEntity(BaseGameEntity *pEntity)
{
    _entityMap.erase(_entityMap.find(pEntity->ID()));
}

void EntityManager::RegisterEntity(BaseGameEntity *NewEntity)
{
    _entityMap.insert(std::make_pair(NewEntity->ID(), NewEntity));
}
