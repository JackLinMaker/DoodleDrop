//
//  MessageDispatcher.h
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-24.
//
//

#ifndef __DoodleDrop2DX__MessageDispatcher__
#define __DoodleDrop2DX__MessageDispatcher__

#include <set>
#include <sys/time.h>
#include "Telegram.h"
using namespace std;

class BaseGameEntity;

const double SEND_MSG_IMMEDIATELY = 0.0;
const int NO_ADDITIONAL_INFO = 0;

#define Dispatch MessageDispatcher::Instance()

class MessageDispatcher
{
public:
    static MessageDispatcher* Instance();
    
    void DispatchMessage(double delay, int sender, int receiver, int msg, void *ExtraInfo);
    
    void DispatchDelayedMessage();
    
private:
    set<Telegram> PriorityQ;
    
    void Discharge(BaseGameEntity* pReceiver, const Telegram& msg);
    
    MessageDispatcher() {}
    
    MessageDispatcher(const MessageDispatcher&);
    
    MessageDispatcher& operator=(const MessageDispatcher&);
    
};

#endif /* defined(__DoodleDrop2DX__MessageDispatcher__) */
