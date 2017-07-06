//
//  DeathScene.hpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-07-01.
//
//

#ifndef DeathScene_hpp
#define DeathScene_hpp

#include <stdio.h>
#include "SimpleAudioEngine.h"

class DeathScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void Back(Ref *pSender);
    
private:
    CocosDenshion::SimpleAudioEngine* audio = CocosDenshion::SimpleAudioEngine::getInstance();
    
    // implement the "static create()" method manually
    CREATE_FUNC(DeathScene);
};

#endif /* DeathScene_hpp */
