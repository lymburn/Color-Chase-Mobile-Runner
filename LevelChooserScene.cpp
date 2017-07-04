//
//  LevelChooserScene.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-16.
//
//

#include "LevelChooserScene.hpp"
#include "TextManager.hpp"
#include "PlayScene.hpp"
#include "ActionPerformer.hpp"
#include "TutorialScene.hpp"

USING_NS_CC;

Scene* LevelChooserScene::createScene()
{
    return LevelChooserScene::create();
}

bool LevelChooserScene::init() {
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
    
    //Creates the menu items
    auto menuItem1 = MenuItemFont::create("PLAY", CC_CALLBACK_1(LevelChooserScene::Play, this));
    auto menuItem2 = MenuItemFont::create("TUTORIAL", CC_CALLBACK_1(LevelChooserScene::Tutorial, this));
    
    menuItem1->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height*0.25 + origin.y));
    menuItem2->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height*0.1 + origin.y));
    
    menuItem1->setScale(0.6,0.6);
    menuItem2->setScale(0.6,0.6);
    
    auto *menu = Menu::create(menuItem1, menuItem2, NULL);
    menu->setPosition(Vec2(0, 0));
    this->addChild(menu);
    PerformActions->fadeIn(menuItem1);
    PerformActions->fadeIn(menuItem2);
    
    delete ImageCreator;
    delete TextCreator;
    delete PerformActions;
    return true;
}

void LevelChooserScene::Tutorial(Ref *pSender) {
    auto tutScene = TutorialScene::createScene();
    Director::getInstance()->replaceScene(tutScene);
}

void LevelChooserScene::Play(Ref *pSender) {
    auto playScene = PlayScene::createScene();
    Director::getInstance()->replaceScene(playScene);
}

