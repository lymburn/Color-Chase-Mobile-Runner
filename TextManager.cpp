//
//  TextManager.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-16.
//
//

#include "TextManager.hpp"
using namespace std;

void TextManager::createTitle() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    title = Label::createWithTTF("REBIRTH", "fonts/CAROBTN_.TTF", 30);
    title->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height - title->getContentSize().height));
    title->enableShadow();
    currentScene->addChild(title, 1);
}

void TextManager::createTapToPlay() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    tapToPlay = Label::createWithTTF("Tap to Play!", "fonts/Ubuntu-Medium.ttf", 16);
    tapToPlay->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height - 5*tapToPlay->getContentSize().height));
    tapToPlay->enableShadow();
    currentScene->addChild(tapToPlay,1);
}

TextManager::TextManager(Scene* ScenePlaying) {
    //Sets the current scene playing
    currentScene = ScenePlaying;

}

Label* TextManager::getTapToPlay() {
    return tapToPlay;
}


