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
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    ImageCreator->createStaticBackground();
    
    auto bird1 = Sprite::create("sprites/Flying1.png");
    auto bird2 = Sprite::create("sprites/Flying1.png");
    auto color = Label::createWithTTF("RED", "fonts/Marker Felt.ttf", 24);
    auto redBall = Sprite::create("sprites/balls/red.png");
    auto blueBall = Sprite::create("sprites/balls/blue.png");
    auto instruction = Label::createWithTTF("Catch the ball with the color of the text and avoid the other colors.\nEarn more points by flying closer to the right!", "fonts/Marker Felt.ttf", 16);
    auto checkMark = Sprite::create("sprites/checkmark.png");
    auto xMark = Sprite::create("sprites/cross.png");
    auto goBack = MenuItemFont::create("Back", CC_CALLBACK_1(TutorialScene::Back, this));

    
    color->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height-color->getContentSize().height + origin.y));
    color->setTextColor(Color4B::BLUE);
    bird1->setPosition(Vec2(visibleSize.width*0.3 + origin.x,visibleSize.height/2 + origin.y));
    bird1->setScale(1.5,1.5);
    bird2->setPosition(Vec2(visibleSize.width*0.6 + origin.x,visibleSize.height/2 + origin.y));
    bird2->setScale(1.5,1.5);
    redBall->setPosition(Vec2(visibleSize.width*0.4 + origin.x, visibleSize.height/2 + origin.y));
    blueBall->setPosition(Vec2(visibleSize.width*0.7 + origin.x, visibleSize.height/2 + origin.y));
    instruction->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height*0.38));
    instruction->setTextColor(Color4B::BLACK);
    checkMark->setPosition(Vec2(visibleSize.width*0.65, visibleSize.height*0.7));
    xMark->setPosition(Vec2(visibleSize.width*0.35, visibleSize.height*0.7));
    
    goBack->setPosition(Vec2(goBack->getContentSize().width/2 + origin.x, goBack->getContentSize().height/2 + origin.y));
    goBack->setScale(0.6,0.6);
    goBack->setColor(Color3B::BLACK);
    auto *backButton = Menu::create(goBack, NULL);
    backButton->setPosition(Vec2(0, 0));
    
    
    this->addChild(backButton,1);
    this->addChild(bird1,1);
    this->addChild(bird2,1);
    this->addChild(color,1);
    this->addChild(redBall,1);
    this->addChild(blueBall,1);
    this->addChild(instruction,1);
    this->addChild(checkMark,1);
    this->addChild(xMark,1);
    
    delete ImageCreator;
    return true;
}

void TutorialScene::Back(Ref *pSender) {
    audio->playEffect("music/whoosh.wav", false, 1.0f, 1.0f, 1.0f);
    auto backScene = LevelChooserScene::createScene();
    Director::getInstance()->replaceScene(backScene);
}

