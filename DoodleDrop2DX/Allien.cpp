//
//  Allien.cpp
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-23.
//
//

#include "Allien.h"
#include "AllienRunState.h"
#include "GameScreen.h"
#include "EntityNames.h"

Allien::Allien():_deceleration(0.4), _sensitivity(6.0), _maxVelocity(100.0), _isColliding(false)
{
    this->SetID(ent_Allien);
    
    _stateMachine = new StateMachine<Allien>(this);
    
    _stateMachine->SetCurrentState(AllienRunState::Instance());
}

Allien::~Allien()
{
    delete _stateMachine;
}

bool Allien::initWithSpriteFrameName(const char *pszSpriteFrameName)
{
    if(!BaseGameEntity::initWithSpriteFrameName(pszSpriteFrameName)) {
        return false;
    }
    
    _imageWidthHalved = this->getTexture()->getContentSize().width * 0.5;
    _leftBorderLimit = _imageWidthHalved;
    _rightBorderLimit = GameScreen::instance()->getScreenSize().width - _imageWidthHalved;
    
    this->scheduleUpdate();
    
    return true;
}

Allien* Allien::createWithSpriteFrameName(const char *pszSpriteFrameName)
{
    Allien *allien = new Allien();
    
    if(allien && allien->initWithSpriteFrameName(pszSpriteFrameName)) {
        allien->autorelease();
        return allien;
    }
    
    CC_SAFE_DELETE(allien);
    
    return NULL;
}

void Allien::update(float delta)
{
    //_stateMachine->Update();
    
    this->restrictBoundry();
}

void Allien::restrictBoundry()
{
    CCPoint pos = this->getPosition();
    pos.x += _velocity.x;
    
    if(pos.x < _leftBorderLimit) {
        pos.x = _leftBorderLimit;
        _velocity = CCPointZero;
    }else if(pos.x > _rightBorderLimit) {
        pos.x = _rightBorderLimit;
        _velocity = CCPointZero;
    }
    
    this->setPosition(pos);
}

void Allien::setVelocity(CCAcceleration *pAccelerationValue)
{
    _velocity.x = _velocity.x * _deceleration + pAccelerationValue->x * _sensitivity;
    
    if(_velocity.x > _maxVelocity) {
        _velocity.x = _maxVelocity;
    }else if(_velocity.x < -_maxVelocity) {
        _velocity.x = -_maxVelocity;
    }
}

StateMachine<Allien>* Allien::GetFSM() const
{
    return _stateMachine;
}


void Allien::collisionEffect()
{
    if(!_isColliding && this->numberOfRunningActions() == 0) {
        _isColliding = true;
        CCScaleTo *big = CCScaleTo::create(0.5, 2.0);
        CCScaleTo *small = CCScaleTo::create(0.5, 1.0);
        this->runAction(CCSequence::create(big, CCDelayTime::create(0.5), small, CCCallFunc::create(this, callfunc_selector(Allien::collisionDidFinished)),NULL));
    }
}

void Allien::collisionDidFinished()
{
    _isColliding = false;
    this->GetFSM()->RevertToPreviousState();
}

bool Allien::HandleMessage(const Telegram &msg)
{
    return _stateMachine->HandleMessage(msg);
}



