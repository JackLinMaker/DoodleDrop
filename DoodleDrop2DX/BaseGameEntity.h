//
//  BaseGameEntity.h
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-22.
//
//

#ifndef __DoodleDrop2DX__BaseGameEntity__
#define __DoodleDrop2DX__BaseGameEntity__

#include <iostream>
#include <assert.h>
using namespace std;
#include "cocos2d.h"
USING_NS_CC;

struct Telegram;

class BaseGameEntity : public CCSprite {
public:
    virtual ~BaseGameEntity();
    
    int ID() const;
    
    virtual bool HandleMessage(const Telegram& msg) = 0;
    
    void SetID(int val);
private:
    int _id;
    
};


#endif /* defined(__DoodleDrop2DX__BaseGameEntity__) */
