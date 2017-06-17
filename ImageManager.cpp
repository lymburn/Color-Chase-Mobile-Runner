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
}

void ImageManager::createBackground() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    titleBackground = Sprite::create("backgrounds/titlescene.png");
    titleBackground->setScale(visibleSize.width/titleBackground->getContentSize().width, visibleSize.height/titleBackground->getContentSize().height);
    titleBackground->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    currentScene->addChild(titleBackground,0);
}
