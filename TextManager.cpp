//
//  TextManager.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-16.
//
//

#include "TextManager.hpp"
#include "ActionPerformer.hpp"
using namespace std;

void TextManager::createTitle() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    title = Label::createWithTTF("COLOR\nCHASE", "fonts/CAROBTN_.TTF", 50);
    title->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*0.75));
    title->setTextColor(Color4B::BLACK);
    title->enableShadow(Color4B::GRAY);
    currentScene->addChild(title, 1);
}

void TextManager::createTapToPlay() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    tapToPlay = Label::createWithTTF("TAP TO PLAY!", "fonts/Marker Felt.ttf", 16);
    tapToPlay->setTextColor(Color4B::BLACK);
    tapToPlay->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*0.2));
    tapToPlay->enableShadow(Color4B::GRAY,Size(1,-1),0);
    currentScene->addChild(tapToPlay,1);
}

TextManager::TextManager(Scene* ScenePlaying) {
    //Sets the current scene playing
    currentScene = ScenePlaying;
}

Label* TextManager::getTapToPlay() {
    return tapToPlay;
}

void TextManager::printScoreAndHighScore() {
    
    ActionPerformer PerformActions;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    yourScore = Label::createWithTTF("YOUR SCORE", "fonts/Marker Felt.ttf", 25);
    yourScore->enableShadow(Color4B::GRAY,Size(1,-1),0);
    yourScore->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height - 1.3*yourScore->getContentSize().height + origin.y));
    yourScore->setColor(Color3B::BLACK);
    
    bestScore = Label::createWithTTF("BEST SCORE", "fonts/Marker Felt.ttf", 25);
    bestScore->enableShadow(Color4B::GRAY,Size(1,-1),0);
    bestScore->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height*0.22 + origin.y));
    bestScore->setColor(Color3B::BLACK);
    
    deathScenePlayerScoreNumber = Label::createWithTTF(std::to_string(def->getIntegerForKey("score")), "fonts/Marker Felt.ttf", 20);
    deathScenePlayerScoreNumber->setPosition(Vec2(visibleSize.width/2 + origin.x, yourScore->getPosition().y - 3*deathScenePlayerScoreNumber->getContentSize().height + origin.y));
    deathScenePlayerScoreNumber->setColor(Color3B::BLACK);
    
    deathSceneHighScoreNumber = Label::createWithTTF(std::to_string(def->getIntegerForKey("highScore")), "fonts/Marker Felt.ttf", 20);
    deathSceneHighScoreNumber->setPosition(Vec2(visibleSize.width/2 + origin.x, bestScore->getPosition().y - 3*deathSceneHighScoreNumber->getContentSize().height + origin.y));
    deathSceneHighScoreNumber->setColor(Color3B::BLACK);
    
    currentScene->addChild(yourScore,1);
    currentScene->addChild(bestScore,1);
    currentScene->addChild(deathSceneHighScoreNumber,1);
    currentScene->addChild(deathScenePlayerScoreNumber,1);
    PerformActions.fadeIn(yourScore);
    PerformActions.fadeIn(bestScore);
}



