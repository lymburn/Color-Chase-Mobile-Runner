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
    tapToPlay->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*0.3));
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
    
    bestEasyScore = Label::createWithTTF("EASY HIGH SCORE", "fonts/Marker Felt.ttf", 25);
    bestEasyScore->enableShadow(Color4B::GRAY,Size(1,-1),0);
    bestEasyScore->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height*0.22 + origin.y));
    bestEasyScore->setColor(Color3B::BLACK);
    
    bestMedScore = Label::createWithTTF("MEDIUM HIGH SCORE", "fonts/Marker Felt.ttf", 25);
    bestMedScore->enableShadow(Color4B::GRAY,Size(1,-1),0);
    bestMedScore->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height*0.22 + origin.y));
    bestMedScore->setColor(Color3B::BLACK);
    
    bestHardScore = Label::createWithTTF("HARD HIGH SCORE", "fonts/Marker Felt.ttf", 25);
    bestHardScore->enableShadow(Color4B::GRAY,Size(1,-1),0);
    bestHardScore->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height*0.22 + origin.y));
    bestHardScore->setColor(Color3B::BLACK);
    
    deathScenePlayerScoreNumber = Label::createWithTTF(std::to_string(def->getIntegerForKey("score")), "fonts/Marker Felt.ttf", 20);
    deathScenePlayerScoreNumber->setPosition(Vec2(visibleSize.width/2 + origin.x, yourScore->getPosition().y - 3*deathScenePlayerScoreNumber->getContentSize().height + origin.y));
    deathScenePlayerScoreNumber->setColor(Color3B::BLACK);
    
    if (def->getStringForKey("difficulty") == "easy") {
        deathSceneHighScoreNumber = Label::createWithTTF(std::to_string(def->getIntegerForKey("easyHighScore")), "fonts/Marker Felt.ttf", 20);
        bestEasyScore->setVisible(true);
        bestMedScore->setVisible(false);
        bestHardScore->setVisible(false);
    } else if (def->getStringForKey("difficulty") == "medium") {
        deathSceneHighScoreNumber = Label::createWithTTF(std::to_string(def->getIntegerForKey("medHighScore")), "fonts/Marker Felt.ttf", 20);
        bestEasyScore->setVisible(false);
        bestMedScore->setVisible(true);
        bestHardScore->setVisible(false);
    } else if (def->getStringForKey("difficulty") == "hard") {
        deathSceneHighScoreNumber = Label::createWithTTF(std::to_string(def->getIntegerForKey("hardHighScore")), "fonts/Marker Felt.ttf", 20);
        bestEasyScore->setVisible(false);
        bestMedScore->setVisible(false);
        bestHardScore->setVisible(true);
    }
    
    deathSceneHighScoreNumber->setPosition(Vec2(visibleSize.width/2 + origin.x, bestEasyScore->getPosition().y - 3*deathSceneHighScoreNumber->getContentSize().height + origin.y));
    deathSceneHighScoreNumber->setColor(Color3B::BLACK);
    
    currentScene->addChild(yourScore,1);
    currentScene->addChild(bestEasyScore,1);
    currentScene->addChild(bestMedScore,1);
    currentScene->addChild(bestHardScore,1);
    currentScene->addChild(deathSceneHighScoreNumber,1);
    currentScene->addChild(deathScenePlayerScoreNumber,1);
    PerformActions.fadeIn(yourScore);
    PerformActions.fadeIn(bestEasyScore);
    PerformActions.fadeIn(bestMedScore);
    PerformActions.fadeIn(bestHardScore);
}




