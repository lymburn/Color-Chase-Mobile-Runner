//
//  TutorialScene.hpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-18.
//
//

#ifndef TutorialScene_hpp
#define TutorialScene_hpp
USING_NS_CC;

#include <stdio.h>
#include "SimpleAudioEngine.h"

class TutorialScene : public cocos2d::Scene {
    
public:
    void Back(Ref *pSender);
    static cocos2d::Scene* createScene();
    virtual bool init();
    
private:
    CocosDenshion::SimpleAudioEngine* audio = CocosDenshion::SimpleAudioEngine::getInstance();
    Sprite* bird;
    // implement the "static create()" method manually
    CREATE_FUNC(TutorialScene);

};


#endif /* TutorialScene_hpp */
