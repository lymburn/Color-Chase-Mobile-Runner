//
//  LevelChooserScene.hpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-16.
//
//

#ifndef LevelChooserScene_hpp
#define LevelChooserScene_hpp

#include <stdio.h>
#include "SimpleAudioEngine.h"

class LevelChooserScene : public cocos2d::Scene {
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    void Tutorial(Ref *pSender);
    void Play(Ref *pSender);
private:
    CocosDenshion::SimpleAudioEngine* audio = CocosDenshion::SimpleAudioEngine::getInstance();
    
    // implement the "static create()" method manually
    CREATE_FUNC(LevelChooserScene);
};


#endif /* LevelChooserScene_hpp */
