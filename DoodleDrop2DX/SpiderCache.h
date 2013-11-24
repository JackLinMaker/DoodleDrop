//
//  SpiderCache.h
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-23.
//
//

#ifndef __DoodleDrop2DX__SpiderCache__
#define __DoodleDrop2DX__SpiderCache__

#include "cocos2d.h"
USING_NS_CC;

class Spider;

class SpiderCache : public CCNode
{
public:
    SpiderCache();
    
    virtual ~SpiderCache();
    
    virtual bool init();
    
    static SpiderCache* create();
    
    CCArray *getSpiders();
    
    void resetSpiders();
    
private:
    void spidersUpdate(float delta);
    
    void runSpiderMoveSequence(Spider *spider);
    
protected:
    CCSpriteBatchNode *_batch;
    
    CCArray *_spiders;
    
    int _numSpidersMoved;
    
    float _spiderMoveDuration;
    
};

#endif /* defined(__DoodleDrop2DX__SpiderCache__) */
