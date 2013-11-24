//
//  MessageDispatcher.cpp
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-24.
//
//

#include "MessageDispatcher.h"
#include "BaseGameEntity.h"
#include "EntityManager.h"
#include "EntityNames.h"
#include "MessageTypes.h"
#include <iostream>
using namespace std;

MessageDispatcher* MessageDispatcher::Instance()
{
    static MessageDispatcher instance;
    return &instance;
}

void MessageDispatcher::Discharge(BaseGameEntity* pReceiver, const Telegram& msg)
{
    if(!pReceiver->HandleMessage(msg)) {
        cout << "Message not handled" << endl;
    }
}

void MessageDispatcher::DispatchMessage(double delay, int sender, int receiver, int msg, void *ExtraInfo)
{
    BaseGameEntity *pReceiver = EntityMgr->GetEntityFromID(receiver);
    
    if(pReceiver == NULL) {
        cout << "\nWarning! No Receiver with ID of" << receiver << "found!";
        return;
    }
    
    Telegram telegram(0, sender, receiver, msg, ExtraInfo);
    if(delay <= 0.0) {
        Discharge(pReceiver, telegram);
    }else {
        unsigned long int currentTime = time(NULL);
        telegram.DispatchTime = currentTime + delay;
        PriorityQ.insert(telegram);
    }
}

void MessageDispatcher::DispatchDelayedMessage()
{
    double CurrentTime = time(NULL);
    while(!PriorityQ.empty() && (PriorityQ.begin()->DispatchTime < CurrentTime) && (PriorityQ.begin()->DispatchTime > 0))
    {
        const Telegram& telegram = *PriorityQ.begin();
        
        BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(telegram.Receiver);
        
        Discharge(pReceiver, telegram);
        
        PriorityQ.erase(PriorityQ.begin());
    }

}
