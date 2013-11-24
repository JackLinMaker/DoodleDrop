//
//  Allien.h
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-23.
//
//

#ifndef __DoodleDrop2DX__Allien__
#define __DoodleDrop2DX__Allien__

#include "cocos2d.h"
#include "BaseGameEntity.h"
#include "State.h"
#include "StateMachine.h"
USING_NS_CC;

struct Telegram;

class Allien : public BaseGameEntity
{
public:
    Allien();
    
    virtual ~Allien(void);
    
    virtual bool initWithSpriteFrameName(const char *pszSpriteFrameName);
	
    static Allien * createWithSpriteFrameName(const char *pszSpriteFrameName);
    
    void setVelocity(CCAcceleration *pAccelerationValue);
    
    StateMachine<Allien>* GetFSM() const;
    
    void collisionEffect();
    
    virtual bool HandleMessage(const Telegram& msg);

private:
    void update(float delta);
    
    void restrictBoundry();
    
    void collisionDidFinished();
    
protected:
    CCPoint _velocity;
    
    float _deceleration;
    
    float _sensitivity;
    
    float _maxVelocity;
    
    StateMachine<Allien>* _stateMachine;
    
    bool _isColliding;
    
    float _imageWidthHalved;
    
    float _leftBorderLimit;
    
    float _rightBorderLimit;
};


#endif /* defined(__DoodleDrop2DX__Allien__) */
