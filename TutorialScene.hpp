//
//  TutorialScene.hpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-18.
//
//

#ifndef TutorialScene_hpp
#define TutorialScene_hpp

#include <stdio.h>
#include "TextManager.hpp"
#include "ColorDisplayer.hpp"
#include "ImageManager.hpp"
#include "ActionPerformer.hpp"
#include <memory.h>
#include "Bird.hpp"
#include "BallSpawner.hpp"

class TutorialScene : public cocos2d::Scene {
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(TutorialScene);
    void update(float);
    
private:
    ImageManager* ImageCreator;
    BallSpawner* BallCreator;
    ActionPerformer* PerformActions;
    Bird* BirdInst;
    Sprite* bird;
    ColorDisplayer* ColorDisplay;
    Sprite* balls[8];
    bool hit = false;

};


#endif /* TutorialScene_hpp */
