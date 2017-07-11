//
//  TutorialScene.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-18.
//
//

#include "TutorialScene.hpp"
#include "ImageManager.hpp"
#include "LevelChooserScene.hpp"
#include "TextManager.hpp"

Scene* TutorialScene::createScene()
{
    return TutorialScene::create();
}

bool TutorialScene::init() {
    //super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto ImageCreator = new ImageManager(this);
    auto TextCreator = new TextManager(this);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //Background and instruction
    ImageCreator->createStaticBackground();
    ImageCreator->createTutorialPictureInstructions();
    TextCreator->createTutorialInstructions();
   
    //Back button
    auto goBack = MenuItemFont::create("Back", CC_CALLBACK_1(TutorialScene::Back, this));
    goBack->setPosition(Vec2(goBack->getContentSize().width/2 + origin.x, goBack->getContentSize().height/2 + origin.y));
    goBack->setScale(0.6,0.6);
    goBack->setColor(Color3B::BLACK);
    auto *backButton = Menu::create(goBack, NULL);
    backButton->setPosition(Vec2(0, 0));
    
    this->addChild(backButton,1);
    
    delete ImageCreator;
    delete TextCreator;
    return true;
}

void TutorialScene::Back(Ref *pSender) {
    audio->playEffect("music/whoosh.wav", false, 1.0f, 1.0f, 1.0f);
    auto backScene = LevelChooserScene::createScene();
    Director::getInstance()->replaceScene(backScene);
}

