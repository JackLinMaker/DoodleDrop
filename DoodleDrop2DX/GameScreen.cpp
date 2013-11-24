//
//  GameScreen.cpp
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-22.
//
//

#include "GameScreen.h"
#include "Spider.h"
#include "AllienCollisionState.h"

#define Z_ALLIEN        0
#define Z_SPIDERCACHE   1

#define TAG_ALLIEN      2
#define TAG_SPIDERCACHE 3

GameScreen* GameScreen::_instance = NULL;

GameScreen* GameScreen::instance()
{
    if(NULL == _instance) {
        _instance = new GameScreen();
    }
    
    return _instance;
}

CCScene* GameScreen::scene()
{
    CCScene *scene = CCScene::create();
    
    GameScreen *screen = GameScreen::create();
    
    scene->addChild(screen);
    
    return scene;
}

GameScreen* GameScreen::create()
{
    GameScreen *screen = new GameScreen();
    
    if(screen && screen->init()) {
        screen->autorelease();
        return screen;
    }
    
    CC_SAFE_DELETE(screen);
    
    return NULL;
}

GameScreen::GameScreen()
{
    _screenSize = CCDirector::sharedDirector()->getWinSize();
}

bool GameScreen::init()
{
    if(!CCLayer::init()) {
        return false;
    }
    
    CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    cache->addSpriteFramesWithFile("map_elements-hd.plist");
    
    this->setAccelerometerEnabled(true);
    
    _allien = Allien::createWithSpriteFrameName("alien");
    this->addChild(_allien, Z_ALLIEN, TAG_ALLIEN);
    
    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
    float imageHeight = _allien->getTexture()->getContentSize().height;
    _allien->setPosition(CCPointMake(screenSize.width * 0.5, imageHeight * 0.5));
    
    _spiderCache = SpiderCache::create();
    this->addChild(_spiderCache, Z_SPIDERCACHE, TAG_SPIDERCACHE);
    
    this->scheduleUpdate();
    
    return true;
}

void GameScreen::update(float delta)
{
    this->checkForCollision();
}

void GameScreen::checkForCollision()
{
    float allienCollisionRadius = _allien->getTexture()->getContentSize().width * 0.4;
    Spider *spider = (Spider *)_spiderCache->getSpiders()->lastObject();
    float spiderCollisionRadius = spider->getTexture()->getContentSize().width * 0.4;
    float maxCollisionDistance = allienCollisionRadius + spiderCollisionRadius;
    int numSpiders = _spiderCache->getSpiders()->count();
    
    for(int i = 0; i < numSpiders; i++) {
        Spider *spider = (Spider *)_spiderCache->getSpiders()->objectAtIndex(i);
        
        if(spider->numberOfRunningActions() == 0) {
            continue;
        }
        
        float actualDistance = ccpDistance(_allien->getPosition(), spider->getPosition());
        if(actualDistance < maxCollisionDistance) {
            _allien->GetFSM()->ChangeState(AllienCollisionState::Instance());
            _spiderCache->resetSpiders();
            break;
        }
    }

}

GameScreen::~GameScreen()
{
    
}

void GameScreen::onEnter()
{
    CCLayer::onEnter();
}

void GameScreen::onEnterTransitionDidFinish()
{
    CCLayer::onEnterTransitionDidFinish();
}

void GameScreen::onExit()
{
    CCTextureCache::sharedTextureCache()->removeTextureForKey("map_elements-hd.pvr.ccz");
    CCSpriteFrameCache * cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    cache->removeSpriteFramesFromFile("map_elements-hd.plist");

    CCLayer::onExit();
}

void GameScreen::didAccelerate(cocos2d::CCAcceleration *pAccelerationValue)
{
    _allien->setVelocity(pAccelerationValue);
}

CCSize GameScreen::getScreenSize()
{
    return _screenSize;
}

