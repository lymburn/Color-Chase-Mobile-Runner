//
//  DifficultyChooserScene.hpp
//  Color Chase
//
//  Created by Eugene Lu on 2017-07-08.
//
//

#ifndef DifficultyChooserScene_hpp
#define DifficultyChooserScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace std;


class DifficultyChooserScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
private:
    void Back(Ref *pSender);
    void Easy(Ref *pSender);
    void Medium(Ref *pSender);
    void Hard(Ref *pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(DifficultyChooserScene);

private:
    CocosDenshion::SimpleAudioEngine* audio = CocosDenshion::SimpleAudioEngine::getInstance();
    UserDefault* def = UserDefault::getInstance();
};

#endif /* DifficultyChooserScene_hpp */

