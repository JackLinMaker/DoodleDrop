//
//  AllienGlobalState.h
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-23.
//
//

#ifndef __DoodleDrop2DX__AllienGlobalState__
#define __DoodleDrop2DX__AllienGlobalState__

#include <iostream>
#include "State.h"

class Allien;

class AllienRunState : public State<Allien> {
public:
    static AllienRunState* Instance();
    
    virtual void Enter(Allien *allien);
    
    virtual void Execute(Allien *allien);
    
    virtual void Exit(Allien *allien);
    
    virtual bool OnMessage(Allien* allien, const Telegram& msg);
    
private:
    AllienRunState();
    
    AllienRunState(const AllienRunState&);
    
    AllienRunState& operator=(const AllienRunState&);
    
};

#endif /* defined(__DoodleDrop2DX__AllienGlobalState__) */
