//
//  SpiderGlobalState.cpp
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-23.
//
//

#include "SpiderGlobalState.h"
#include "Spider.h"

SpiderGlobalState* SpiderGlobalState::Instance()
{
    static SpiderGlobalState instance;
    return &instance;
}

void SpiderGlobalState::Enter(Spider *spider)
{

}

void SpiderGlobalState::Execute(Spider *spider)
{

}

void SpiderGlobalState::Exit(Spider *spider)
{

}

bool SpiderGlobalState::OnMessage(Spider *spider, const Telegram &msg)
{
    return false;
}

SpiderGlobalState::SpiderGlobalState()
{
    
}
