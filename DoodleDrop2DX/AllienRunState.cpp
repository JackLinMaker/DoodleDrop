//
//  AllienGlobalState.cpp
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-23.
//
//

#include "AllienRunState.h"
#include "Allien.h"

AllienRunState* AllienRunState::Instance()
{
    static AllienRunState instance;
    return &instance;
}

void AllienRunState::Enter(Allien *allien)
{
    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
    float imageHeight = allien->getTexture()->getContentSize().height;
    allien->setPosition(CCPointMake(screenSize.width * 0.5, imageHeight * 0.5));
}

void AllienRunState::Execute(Allien *allien)
{
    
}

void AllienRunState::Exit(Allien *allien)
{
    
}

bool AllienRunState::OnMessage(Allien *allien, const Telegram &msg)
{
    return false;
}

AllienRunState::AllienRunState()
{
    
}


