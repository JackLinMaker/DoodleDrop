//
//  AllienCollisionState.cpp
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-24.
//
//

#include "AllienCollisionState.h"
#include "Allien.h"
#include "AllienRunState.h"
#include "MessageTypes.h"
#include "MessageDispatcher.h"

AllienCollisionState* AllienCollisionState::Instance()
{
    static AllienCollisionState instance;
    return &instance;
}

void AllienCollisionState::Enter(Allien *allien)
{
    allien->collisionEffect();
    
    //Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, <#int sender#>, <#int receiver#>, <#int msg#>, <#void *ExtraInfo#>)
}

void AllienCollisionState::Execute(Allien *allien)
{
    
}

bool AllienCollisionState::OnMessage(Allien *allien, const Telegram &msg)
{
    return false;
}

void AllienCollisionState::Exit(Allien *allien)
{
    
}

AllienCollisionState::AllienCollisionState()
{
    
}

