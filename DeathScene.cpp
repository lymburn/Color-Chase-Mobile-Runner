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
#include "SimpleAudioEngine.h"
#include "TitleScene.hpp"

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
    //Audio
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    
    //Scores and background
    auto TextCreator = new TextManager(this);
    TextCreator->printScoreAndHighScore();
    ImageCreator->createDeathBackground();
    
    //Replay button
    auto replayButton = Sprite::create("sprites/return.png");
    replayButton->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    replayButton->setScale(2, 2);
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [=](Touch* touch, Event* event) -> bool {
        
        auto bounds = event->getCurrentTarget()->getBoundingBox();
        
        if (bounds.containsPoint(touch->getLocation())){
            audio->playEffect("music/whoosh.wav", false, 1.0f, 1.0f, 1.0f);
            auto playScene = PlayScene::create();
            Director::getInstance()->replaceScene(playScene);
        }
        return true;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener,replayButton);
    this->addChild(replayButton, 0);
    
    //Back to title
    auto backToTitle = MenuItemFont::create("Back to Title", CC_CALLBACK_1(DeathScene::Back, this));
    backToTitle->setPosition(Vec2(backToTitle->getContentSize().width/3 + origin.x, backToTitle->getContentSize().height/2 + origin.y));
    backToTitle->setScale(0.6,0.6);
    backToTitle->setColor(Color3B::BLACK);
    auto *backButton = Menu::create(backToTitle, NULL);
    backButton->setPosition(Vec2(0, 0));
    this->addChild(backButton,2);

    delete TextCreator;
    delete ImageCreator;
    return true;
}

void DeathScene::Back(Ref *pSender) {
    audio->playEffect("music/whoosh.wav", false, 1.0f, 1.0f, 1.0f);
    auto backScene = TitleScene::createScene();
    Director::getInstance()->replaceScene(backScene);
}
