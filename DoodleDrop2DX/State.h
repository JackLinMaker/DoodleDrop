//
//  State.h
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-23.
//
//

#ifndef DoodleDrop2DX_State_h
#define DoodleDrop2DX_State_h

#include <iostream>

struct Telegram;

template<class entity_type>
class State
{
public:
    virtual ~State() {};
    
    virtual void Enter(entity_type*) = 0;
    
    virtual void Execute(entity_type*) = 0;
    
    virtual void Exit(entity_type*) = 0;
    
    virtual bool OnMessage(entity_type*, const Telegram&) = 0;
    
};

#endif
