//
//  Spider.cpp
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-23.
//
//

#include "Spider.h"
#include "SpiderGlobalState.h"
#include "GameScreen.h"
#include "EntityNames.h"

Spider::Spider()
{
    this->SetID(ent_Spider);
    
    _stateMachine = new StateMachine<Spider>(this);
    
    _stateMachine->SetGlobalState(SpiderGlobalState::Instance());
}

Spider::~Spider()
{
    delete _stateMachine;
}

bool Spider::initWithSpriteFrameName(const char *pszSpriteFrameName)
{
    if(!BaseGameEntity::initWithSpriteFrameName(pszSpriteFrameName)) {
        return false;
    }
    
    return true;
}

Spider* Spider::createWithSpriteFrameName(const char *pszSpriteFrameName)
{
    Spider *spider = new Spider();
    
    if(spider && spider->initWithSpriteFrameName(pszSpriteFrameName)) {
        spider->autorelease();
        return spider;
    }
    
    CC_SAFE_DELETE(spider);
    
    return NULL;
}

void Spider::update(float delta)
{
    _stateMachine->Update();

}


StateMachine<Spider>* Spider::GetFSM() const
{
    return _stateMachine;
}

void Spider::startDrop(float moveDuration)
{
    CCPoint belowScreenPosition = CCPointMake(this->getPosition().x, -this->getTexture()->getContentSize().height);
    CCMoveTo *move = CCMoveTo::create(moveDuration, belowScreenPosition);
    CCCallFuncN *callDidDrop = CCCallFuncN::create(this, callfuncN_selector(Spider::spiderDidDrop));
    CCSequence *sequence = CCSequence::create(move, callDidDrop, NULL);
    this->runAction(sequence);
}

void Spider::spiderDidDrop(cocos2d::CCNode *pSender)
{
    Spider *spider = (Spider *)pSender;
    CCPoint pos = spider->getPosition();
    CCSize screenSize = GameScreen::instance()->getScreenSize();
    pos.y = screenSize.height + spider->getTexture()->getContentSize().height;
    spider->setPosition(pos);
}

bool Spider::HandleMessage(const Telegram &msg)
{
    return _stateMachine->HandleMessage(msg);
}

