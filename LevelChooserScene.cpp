//
//  LevelChooserScene.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-16.
//
//

#include "LevelChooserScene.hpp"

#include <iostream>
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
    
    //Creates the menu items
    auto menuItem1 = MenuItemFont::create("Tutorial", CC_CALLBACK_1(LevelChooserScene::Tutorial, this));
    auto menuItem2 = MenuItemFont::create("Play", CC_CALLBACK_1(LevelChooserScene::Play, this));
    auto menuItem3 = MenuItemFont::create("Settings", CC_CALLBACK_1(LevelChooserScene::Settings,this));
    
    menuItem1->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height*0.75 + origin.y));
    menuItem2->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height*0.5 + origin.y));
    menuItem3->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height*0.25 + origin.y));
    
    auto *menu = Menu::create(menuItem1, menuItem2, menuItem3, NULL);
    menu->setPosition(Vec2(0, 0));
    this->addChild(menu);
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

void LevelChooserScene::Settings(Ref *pSender) {
    auto settingsScene = SettingsScene::createScene();
    Director::getInstance()->replaceScene(settingsScene);
}
