//
//  EntityManager.h
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-24.
//
//

#ifndef __DoodleDrop2DX__EntityManager__
#define __DoodleDrop2DX__EntityManager__

#include <map>
#include <cassert>
#include <string>
using namespace std;

class BaseGameEntity;
typedef map<int, BaseGameEntity*> EntityMap;

#define EntityMgr EntityManager::Instance()

class EntityManager
{
public:
    static EntityManager* Instance();
    
    void RegisterEntity(BaseGameEntity* NewEntity);
    
    BaseGameEntity* GetEntityFromID(int id) const;
    
    void RemoveEntity(BaseGameEntity *pEntity);
    
private:
    EntityMap _entityMap;
    
    EntityManager(){}
    
    EntityManager(const EntityManager&);
    
    EntityManager& operator=(const EntityManager&);
};

#endif /* defined(__DoodleDrop2DX__EntityManager__) */
