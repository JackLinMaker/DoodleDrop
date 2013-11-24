//
//  BaseGameEntity.cpp
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-22.
//
//

#include "BaseGameEntity.h"


BaseGameEntity::~BaseGameEntity()
{

}

int BaseGameEntity::ID() const
{
    return _id;
}

void BaseGameEntity::SetID(int val)
{
    _id = val;
}

