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
    title = Label::createWithTTF("COLOR\nCHASE", "fonts/CAROBTN_.TTF", 50);
    title->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*0.75));
    title->enableShadow();
    currentScene->addChild(title, 1);
}

void TextManager::createTapToPlay() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    tapToPlay = Label::createWithTTF("TAP TO PLAY!", "fonts/Marker Felt.ttf", 16);
    tapToPlay->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*0.2));
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

void TextManager::printHighScore(int highScore) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    highScoreLabel = Label::createWithTTF(std::to_string(highScore), "fonts/Ubuntu-Medium.ttf", 16);
    highScoreLabel->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    highScoreLabel->enableShadow();
    currentScene->addChild(highScoreLabel,6);
}


