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
    
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->playBackgroundMusic("music/bg-music.mp3", true);
    //Creates title text and tap to play
    TextManager TextCreator(this);
    TextCreator.createTitle();
    TextCreator.createTapToPlay();

    //Create the background
    ImageManager ImageCreator(this);
    ImageCreator.createStaticBackground();

    ActionPerformer PerformActions;
    PerformActions.fadeInAndOut(TextCreator.getTapToPlay());
    
    auto titleTapListener = EventListenerTouchOneByOne::create();
    titleTapListener->setSwallowTouches(true);
    // trigger when you push down
    
    titleTapListener->onTouchBegan = [=](Touch* touch, Event* event){
        auto levelScene = LevelChooserScene::createScene();
        audio->playEffect("music/whoosh.wav", false, 1.0f, 1.0f, 1.0f);
        Director::getInstance()->replaceScene(levelScene);
        return true; // if you are consuming it
    };
     
    
    // Add listener
    _eventDispatcher->addEventListenerWithSceneGraphPriority(titleTapListener, this);
    
    return true;
    
}


