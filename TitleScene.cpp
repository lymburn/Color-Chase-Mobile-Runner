//
//  TitleScene.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-13.
//
//

#include "TitleScene.hpp"
#include "SimpleAudioEngine.h"


USING_NS_CC;

Scene* TitleScene::createScene()
{
    return TitleScene::create();
}

// on "init" you need to initialize your instance
bool TitleScene::init()
{
    //super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    //Creates title text and tap to play
    TextManager TextCreator(this);
    TextCreator.createTitle();
    TextCreator.createTapToPlay();

    //Create the title background
    ImageManager ImageCreator(this);
    ImageCreator.createBackground();

    ActionPerformer PerformActions;
    PerformActions.fadeInAndOut(TextCreator.getTapToPlay());
    
    Director::getInstance()->replaceScene(LevelChooserScene);

    return true;
    
}

