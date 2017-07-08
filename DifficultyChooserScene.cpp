//
//  DifficultyChooserScene.cpp
//  Color Chase
//
//  Created by Eugene Lu on 2017-07-08.
//
//

#include "DifficultyChooserScene.hpp"
#include "ImageManager.hpp"
#include "TextManager.hpp"
#include "ActionPerformer.hpp"
#include "PlayScene.hpp"

Scene* DifficultyChooserScene::createScene()
{
    return DifficultyChooserScene::create();
}

bool DifficultyChooserScene::init() {
    //super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    auto ImageCreator = new ImageManager(this);
    auto TextCreator = new TextManager(this);
    auto PerformActions = new ActionPerformer;
    
    //Creates background
    ImageCreator->createStaticBackground();
    //Create title
    TextCreator->createTitle();
    
    auto menuItem1 = MenuItemFont::create("EASY", CC_CALLBACK_1(DifficultyChooserScene::Easy, this));
    auto menuItem2 = MenuItemFont::create("MEDIUM", CC_CALLBACK_1(DifficultyChooserScene::Medium, this));
    auto menuItem3 = MenuItemFont::create("HARD", CC_CALLBACK_1(DifficultyChooserScene::Hard, this));

    menuItem1->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height*0.4 + origin.y));
    menuItem2->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height*0.3 + origin.y));
    menuItem3->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height*0.2 + origin.y));
    
    menuItem1->setScale(0.6,0.6);
    menuItem2->setScale(0.6,0.6);
    menuItem3->setScale(0.6,0.6);
    
    menuItem1->setColor(Color3B::BLACK);
    menuItem2->setColor(Color3B::BLACK);
    menuItem3->setColor(Color3B::BLACK);
    
    auto *menu = Menu::create(menuItem1, menuItem2, menuItem3, NULL);
    menu->setPosition(Vec2(0, 0));
    this->addChild(menu);
    PerformActions->fadeIn(menuItem1);
    PerformActions->fadeIn(menuItem2);
    PerformActions->fadeIn(menuItem3);

    return true;
}

void DifficultyChooserScene::Easy(Ref *pSender) {
    def->setStringForKey("difficulty", "easy");
    audio->playEffect("music/whoosh.wav", false, 1.0f, 1.0f, 1.0f);
    auto playScene = PlayScene::createScene();
    Director::getInstance()->replaceScene(playScene);
}

void DifficultyChooserScene::Medium(Ref *pSender) {
    def->setStringForKey("difficulty", "medium");
    audio->playEffect("music/whoosh.wav", false, 1.0f, 1.0f, 1.0f);
    auto playScene = PlayScene::createScene();
    Director::getInstance()->replaceScene(playScene);
}

void DifficultyChooserScene::Hard(Ref *pSender) {
    def->setStringForKey("difficulty", "hard");
    audio->playEffect("music/whoosh.wav", false, 1.0f, 1.0f, 1.0f);
    auto playScene = PlayScene::createScene();
    Director::getInstance()->replaceScene(playScene);
}

