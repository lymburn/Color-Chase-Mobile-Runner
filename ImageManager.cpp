//
//  ImageManager.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-16.
//
//

#include "ImageManager.hpp"
#include <iostream>

ImageManager::ImageManager(Scene* ScenePlaying) {
    currentScene = ScenePlaying;
    
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


void ImageManager::createTitleBackground() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    titleBackground->setScale(visibleSize.width/titleBackground->getContentSize().width, visibleSize.height/titleBackground->getContentSize().height);
    titleBackground->setPosition(Vec2(origin.x,origin.y));
    currentScene->addChild(titleBackground,0);
}

void ImageManager::createLevelChooserBackground() {
    
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





