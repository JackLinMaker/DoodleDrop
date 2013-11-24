//
//  SpiderCache.cpp
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-23.
//
//

#include "SpiderCache.h"
#include "Spider.h"
#include "GameScreen.h"

#define Z_SPIDER        0
#define TAG_SPIDER      5

SpiderCache::SpiderCache():_numSpidersMoved(0), _spiderMoveDuration(4.0)
{
    
}

SpiderCache::~SpiderCache()
{
    if(_spiders != NULL) {
        _spiders->release();
        _spiders = NULL;
    }
}

SpiderCache* SpiderCache::create()
{
    SpiderCache *cache = new SpiderCache();
    
    if(cache && cache->init()) {
        cache->autorelease();
        return cache;
    }
    
    CC_SAFE_DELETE(cache);
    
    return NULL;
}

bool SpiderCache::init()
{
    if(!CCNode::init()) {
        return false;
    }
    
    CCSize screenSize = GameScreen::instance()->getScreenSize();
    
    CCSprite *spiderSprite = CCSprite::createWithSpriteFrameName("spider");
    float imageWidth = spiderSprite->getTexture()->getContentSize().width;
    int numSpiders = screenSize.width / imageWidth;
    
    _spiders = CCArray::createWithCapacity(numSpiders);
    _spiders->retain();
    
    //_batch = CCSpriteBatchNode::createWithTexture(spiderSprite->getTexture());
    _batch = CCSpriteBatchNode::create("map_elements-hd.pvr.ccz");
    this->addChild(_batch);
    
    for(int i = 0; i < numSpiders; i++) {
        Spider *spider = Spider::createWithSpriteFrameName("spider");
        _batch->addChild(spider, Z_SPIDER, TAG_SPIDER);
        _spiders->addObject(spider);
    }
    
    this->resetSpiders();
    
    return true;
}

void SpiderCache::resetSpiders()
{
    CCSize screenSize = GameScreen::instance()->getScreenSize();
    
    Spider *spider = (Spider *)_spiders->lastObject();
    CCSize imageSize = spider->getTexture()->getContentSize();
    
    int numSpiders = _spiders->count();
    for(int i = 0; i < numSpiders; i++) {
        Spider *spider = (Spider *)_spiders->objectAtIndex(i);
        spider->setPosition(CCPointMake(imageSize.width * i + imageSize.width * 0.5, screenSize.height + imageSize.height));
        spider->stopAllActions();
    }
    
    this->unschedule(schedule_selector(SpiderCache::spidersUpdate));
    this->schedule(schedule_selector(SpiderCache::spidersUpdate), 0.6);
    
    _numSpidersMoved = 0;
    _spiderMoveDuration = 4.0;
}


void SpiderCache::spidersUpdate(float delta)
{
    for(int i = 0; i < 10; i++) {
        int randomSpiderIndex = CCRANDOM_0_1() * _spiders->count();
        Spider *spider = (Spider *)_spiders->objectAtIndex(randomSpiderIndex);
        
        if(spider->numberOfRunningActions() == 0) {
            if(i > 0) {
                CCLOG("Dropping a Spider after %i retries.", i);
            }
            
            this->runSpiderMoveSequence(spider);
            
            break;
        }
    }
}

void SpiderCache::runSpiderMoveSequence(Spider *spider)
{
    _numSpidersMoved++;
    if(_numSpidersMoved % 8 == 0 && _spiderMoveDuration > 2.0) {
        _spiderMoveDuration -= 0.1;
    }
    
    spider->startDrop(_spiderMoveDuration);
}

CCArray* SpiderCache::getSpiders()
{
    return _spiders;
}




