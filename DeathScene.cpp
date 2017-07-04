//
//  DeathScene.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-07-01.
//
//
USING_NS_CC;
#include "DeathScene.hpp"
#include "PlayScene.hpp"
#include "ImageManager.hpp"
#include "TextManager.hpp"

Scene* DeathScene::createScene()
{
    return DeathScene::create();
}

bool DeathScene::init() {
    //super init first
    if ( !Scene::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    auto ImageCreator = new ImageManager(this);

     
    auto TextCreator = new TextManager(this);
    TextCreator->printScoreAndHighScore();
    ImageCreator->createDeathBackground();
    //Replay button
    auto replayButton = Sprite::create("sprites/return.png");
    replayButton->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    replayButton->setScale(2, 2);
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [](Touch* touch, Event* event) -> bool {
        
        auto bounds = event->getCurrentTarget()->getBoundingBox();
        
        if (bounds.containsPoint(touch->getLocation())){
            auto playScene = PlayScene::create();
            Director::getInstance()->replaceScene(playScene);
        }
        return true;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener,replayButton);
    this->addChild(replayButton, 0);

    delete TextCreator;
    delete ImageCreator;
    return true;
}
