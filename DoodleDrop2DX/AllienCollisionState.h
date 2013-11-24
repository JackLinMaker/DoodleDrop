//
//  AllienCollisionState.h
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-24.
//
//

#ifndef __DoodleDrop2DX__AllienCollisionState__
#define __DoodleDrop2DX__AllienCollisionState__

#include <iostream>
#include "State.h"

class Allien;

class AllienCollisionState : public State<Allien> {
public:
    static AllienCollisionState* Instance();
    
    virtual void Enter(Allien *allien);
    
    virtual void Execute(Allien *allien);
    
    virtual void Exit(Allien *allien);
    
    virtual bool OnMessage(Allien* allien, const Telegram& msg);
    
private:
    AllienCollisionState();
    
    AllienCollisionState(const AllienCollisionState&);
    
    AllienCollisionState& operator=(const AllienCollisionState&);
    
};

#endif /* defined(__DoodleDrop2DX__AllienCollisionState__) */
