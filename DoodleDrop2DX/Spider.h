//
//  Spider.h
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-23.
//
//

#ifndef __DoodleDrop2DX__Spider__
#define __DoodleDrop2DX__Spider__

#include "cocos2d.h"
#include "BaseGameEntity.h"
#include "State.h"
#include "StateMachine.h"
USING_NS_CC;

struct Telegram;

class Spider : public BaseGameEntity
{
public:
    Spider();
    
    virtual ~Spider(void);
    
    virtual bool initWithSpriteFrameName(const char *pszSpriteFrameName);
	
    static Spider * createWithSpriteFrameName(const char *pszSpriteFrameName);
    
    StateMachine<Spider>* GetFSM() const;
    
    void startDrop(float moveDuration);
    
    virtual bool HandleMessage(const Telegram& msg);

private:
    void update(float delta);
    
    void spiderDidDrop(CCNode* pSender);
    
protected:
    
    StateMachine<Spider>* _stateMachine;
};



#endif /* defined(__DoodleDrop2DX__Spider__) */
