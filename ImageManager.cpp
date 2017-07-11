//
//  ImageManager.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-16.
//
//

#include "ImageManager.hpp"

ImageManager::ImageManager(Scene* ScenePlaying) {
    currentScene = ScenePlaying;
    
    balls.push_back(Sprite::create("sprites/balls/yellow.png"));
    balls.push_back(Sprite::create("sprites/balls/orange.png"));
    balls.push_back(Sprite::create("sprites/balls/red.png"));
    balls.push_back(Sprite::create("sprites/balls/blue.png"));
    balls.push_back(Sprite::create("sprites/balls/green.png"));
    balls.push_back(Sprite::create("sprites/balls/magenta.png"));
    balls.push_back(Sprite::create("sprites/balls/black.png"));
    balls.push_back(Sprite::create("sprites/balls/gray.png"));
    
    //Initial assets
    titleBackground->setName("titleBackground");
    closeTreesI->setName("closeTreesI");
    midTreesI->setName("midTreesI");
    farTreesI->setName("farTreesI");
    mountainsI->setName("mountainsI");
    cloudsI->setName("cloudsI");
    
    //Following assets
    closeTreesF->setName("closeTreesF");
    midTreesF->setName("midTreesF");
    farTreesF->setName("farTreesF");
    mountainsF->setName("mountainsF");
    cloudsF->setName("cloudsF");
    
    //Initial assets anchor points
    titleBackground->setAnchorPoint(Vec2(0,0));
    deathBackground->setAnchorPoint(Vec2(0,0));
    closeTreesI->setAnchorPoint(Vec2(0,0));
    midTreesI->setAnchorPoint(Vec2(0,0));
    farTreesI->setAnchorPoint(Vec2(0,0));
    mountainsI->setAnchorPoint(Vec2(0,0));
    cloudsI->setAnchorPoint(Vec2(0,0));
    skyI->setAnchorPoint(Vec2(0,0));
    
    //Following
    closeTreesF->setAnchorPoint(Vec2(0,0));
    midTreesF->setAnchorPoint(Vec2(0,0));
    farTreesF->setAnchorPoint(Vec2(0,0));
    mountainsF->setAnchorPoint(Vec2(0,0));
    cloudsF->setAnchorPoint(Vec2(0,0));
}

Sprite* ImageManager::getBackgroundAsset(std::string name) {
    if (name == "titleBackground") {
        return titleBackground;
    } else if (name == "closeTreesI") {
        return closeTreesI;
    } else if (name == "midTreesI") {
        return midTreesI;
    } else if (name == "farTreesI") {
        return farTreesI;
    } else if (name == "mountainsI") {
        return mountainsI;
    } else if (name == "cloudsI") {
        return cloudsI;
    } else if (name == "closeTreesF") {
        return closeTreesF;
    } else if (name == "midTreesF") {
        return midTreesF;
    } else if (name == "farTreesF") {
        return farTreesF;
    } else if (name == "mountainsF") {
        return mountainsF;
    } else if (name == "cloudsF") {
        return cloudsF;
    } else return NULL;
}


void ImageManager::createStaticBackground() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    titleBackground->setScale(visibleSize.width/titleBackground->getContentSize().width, visibleSize.height/titleBackground->getContentSize().height);
    titleBackground->setPosition(Vec2(origin.x,origin.y));
    currentScene->addChild(titleBackground,0);
}

void ImageManager::createDeathBackground() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    deathBackground->setScale(visibleSize.width/deathBackground->getContentSize().width, visibleSize.height/deathBackground->getContentSize().height);
    deathBackground->setPosition(Vec2(origin.x,origin.y));
    deathBackground->setOpacity(128);
    currentScene->addChild(deathBackground,0);
    auto move = FadeIn::create(0.8);
    deathBackground->runAction(move);
    
}

//Background for the first panel
void ImageManager::createInitialGameBackground() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    closeTreesI->setScale(visibleSize.width/closeTreesI->getContentSize().width, visibleSize.height/closeTreesI->getContentSize().height);
    closeTreesI->setPosition(Vec2(origin.x,origin.y));
    currentScene->addChild(closeTreesI,5);
    
    midTreesI->setScale(visibleSize.width/midTreesI->getContentSize().width, visibleSize.height/midTreesI->getContentSize().height);
    midTreesI->setPosition(Vec2(origin.x,origin.y));
    currentScene->addChild(midTreesI,4);
    
    farTreesI->setScale(visibleSize.width/farTreesI->getContentSize().width, visibleSize.height/farTreesI->getContentSize().height);
    farTreesI->setPosition(Vec2(origin.x,origin.y));
    currentScene->addChild(farTreesI,3);
    
    mountainsI->setScale(visibleSize.width/mountainsI->getContentSize().width, visibleSize.height/mountainsI->getContentSize().height);
    mountainsI->setPosition(Vec2(origin.x,origin.y));
    currentScene->addChild(mountainsI,1);
    
    cloudsI->setScale(visibleSize.width/cloudsI->getContentSize().width, visibleSize.height/cloudsI->getContentSize().height);
    cloudsI->setPosition(Vec2(origin.x,origin.y));
    currentScene->addChild(cloudsI,0);
    
    skyI->setScale(visibleSize.width/skyI->getContentSize().width, visibleSize.height/skyI->getContentSize().height);
    skyI->setPosition(Vec2(origin.x,origin.y));
    currentScene->addChild(skyI,0);
}

//Background for the 2nd panel of images
void ImageManager::createFollowingBackground() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    closeTreesF->setScale(visibleSize.width/closeTreesF->getContentSize().width, visibleSize.height/closeTreesF->getContentSize().height);
    closeTreesF->setPosition(Vec2(visibleSize.width + origin.x, origin.y));
    currentScene->addChild(closeTreesF,5);
    
    midTreesF->setScale(visibleSize.width/midTreesF->getContentSize().width, visibleSize.height/midTreesF->getContentSize().height);
    midTreesF->setPosition(Vec2(visibleSize.width + origin.x, origin.y));
    currentScene->addChild(midTreesF,4);
    
    farTreesF->setScale(visibleSize.width/farTreesF->getContentSize().width, visibleSize.height/farTreesF->getContentSize().height);
    farTreesF->setPosition(Vec2(visibleSize.width + origin.x, origin.y));
    currentScene->addChild(farTreesF,3);
    
    mountainsF->setScale(visibleSize.width/mountainsF->getContentSize().width, visibleSize.height/mountainsF->getContentSize().height);
    mountainsF->setPosition(Vec2(visibleSize.width + origin.x, origin.y));
    currentScene->addChild(mountainsF,1);
    
    cloudsF->setScale(visibleSize.width/cloudsF->getContentSize().width, visibleSize.height/cloudsF->getContentSize().height);
    cloudsF->setPosition(Vec2(visibleSize.width + origin.x, origin.y));
    currentScene->addChild(cloudsF,0);
}

Sprite* ImageManager::getBalls(int location) {
    return balls.at(location);
}

void ImageManager::createTutorialPictureInstructions() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    auto bird1 = Sprite::create("sprites/Flying1.png");
    auto bird2 = Sprite::create("sprites/Flying1.png");
    auto color = Label::createWithTTF("RED", "fonts/Marker Felt.ttf", 24);
    auto redBall = Sprite::create("sprites/balls/red.png");
    auto blueBall = Sprite::create("sprites/balls/blue.png");
    auto checkMark = Sprite::create("sprites/checkmark.png");
    auto xMark = Sprite::create("sprites/cross.png");
    
    color->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height-color->getContentSize().height + origin.y));
    color->setTextColor(Color4B::BLUE);
    bird1->setPosition(Vec2(visibleSize.width*0.3 + origin.x,visibleSize.height/2 + origin.y));
    bird1->setScale(1.5,1.5);
    bird2->setPosition(Vec2(visibleSize.width*0.6 + origin.x,visibleSize.height/2 + origin.y));
    bird2->setScale(1.5,1.5);
    redBall->setPosition(Vec2(visibleSize.width*0.4 + origin.x, visibleSize.height/2 + origin.y));
    blueBall->setPosition(Vec2(visibleSize.width*0.7 + origin.x, visibleSize.height/2 + origin.y));
    checkMark->setPosition(Vec2(visibleSize.width*0.65, visibleSize.height*0.7));
    xMark->setPosition(Vec2(visibleSize.width*0.35, visibleSize.height*0.7));

    currentScene->addChild(bird1,1);
    currentScene->addChild(bird2,1);
    currentScene->addChild(color,1);
    currentScene->addChild(redBall,1);
    currentScene->addChild(blueBall,1);
    currentScene->addChild(checkMark,1);
    currentScene->addChild(xMark,1);
}




