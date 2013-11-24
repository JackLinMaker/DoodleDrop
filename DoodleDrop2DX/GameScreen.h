//
//  GameScreen.h
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-22.
//
//

#ifndef __DoodleDrop2DX__GameScreen__
#define __DoodleDrop2DX__GameScreen__
#include "cocos2d.h"
#include "Allien.h"
#include "SpiderCache.h"
USING_NS_CC;

class GameScreen : public CCLayer {
public:
    static CCScene* scene();
    
    static GameScreen* create();
    
    virtual bool init();
    
    virtual ~GameScreen();
    
    static GameScreen* instance();
    
    virtual void onEnter();
    
    virtual void onExit();
    
    virtual void onEnterTransitionDidFinish();
    
    virtual void didAccelerate(CCAcceleration* pAccelerationValue);
    
    CCSize getScreenSize();

private:
    GameScreen();
    
    void update(float delta);
    
    void checkForCollision();
    
protected:
    static GameScreen* _instance;
    
    Allien *_allien;
    
    SpiderCache *_spiderCache;
    
    CCSize _screenSize;
    
};

#endif /* defined(__DoodleDrop2DX__GameScreen__) */
