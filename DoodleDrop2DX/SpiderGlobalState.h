//
//  SpiderGlobalState.h
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-23.
//
//

#ifndef __DoodleDrop2DX__SpiderGlobalState__
#define __DoodleDrop2DX__SpiderGlobalState__

#include <iostream>
#include "State.h"

class Spider;

class SpiderGlobalState : public State<Spider>
{
public:
    static SpiderGlobalState* Instance();
    
    virtual void Enter(Spider *spider);
    
    virtual void Execute(Spider *spider);
    
    virtual void Exit(Spider *spider);
    
    virtual bool OnMessage(Spider* spider, const Telegram& msg);
    
private:
    SpiderGlobalState();
    
    SpiderGlobalState(const SpiderGlobalState&);
    
    SpiderGlobalState& operator=(const SpiderGlobalState&);
};

#endif /* defined(__DoodleDrop2DX__SpiderGlobalState__) */
