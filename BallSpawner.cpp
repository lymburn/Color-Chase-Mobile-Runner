//
//  BallSpawner.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-29.
//
//

#include "BallSpawner.hpp"

BallSpawner::BallSpawner(Scene* ScenePlaying) {
    currentScene = ScenePlaying;
}

void BallSpawner::spawnBalls(ImageManager* ImageCreator) {
    //Spawn balls at random heights
    for (int i = 0; i<8; i++) {
        ImageCreator->getBalls(i)->setAnchorPoint(Vec2(0,0));
        ImageCreator->getBalls(i)->setScale(0.7,0.7);
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    srand (time(NULL));
    float heightInterval = visibleSize.height/6;
    
    for (int i = 0; i<8; i++) {
        ImageCreator->getBalls(i)->setPosition(Vec2(visibleSize.width, rand()%static_cast<int>(visibleSize.height - 2*ImageCreator->getBalls(i)->getContentSize().height) + 2*ImageCreator->getBalls(i)->getContentSize().height));
        currentScene->addChild(ImageCreator->getBalls(i),6);
    }
}

void BallSpawner::moveBalls(ImageManager* ImageCreator) {
    //Move the balls across the screen
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    srand (time(NULL));
    auto yellowBall = ImageCreator->getBalls(0);
    auto orangeBall = ImageCreator->getBalls(1);
    auto redBall = ImageCreator->getBalls(2);
    auto blueBall = ImageCreator->getBalls(3);
    auto greenBall = ImageCreator->getBalls(4);
    auto magentaBall = ImageCreator->getBalls(5);
    auto blackBall = ImageCreator->getBalls(6);
    auto grayBall = ImageCreator->getBalls(7);
    
    yellowBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0), MoveBy::create(rand()%2 + 2, Vec2(-visibleSize.width - yellowBall->getContentSize().width,0)), CallFunc::create([=]() {
        yellowBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*yellowBall->getContentSize().height) + 2*yellowBall->getContentSize().height); yellowBall->setVisible(true);}), NULL)));
    orangeBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.1), MoveBy::create(rand()%2 + 2, Vec2(-visibleSize.width - orangeBall->getContentSize().width,0)), CallFunc::create([=]() {
        orangeBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*orangeBall->getContentSize().height) + 2*orangeBall->getContentSize().height); orangeBall->setVisible(true);}), NULL)));
    redBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.2), MoveBy::create(rand()%2 + 2, Vec2(-visibleSize.width - redBall->getContentSize().width,0)), CallFunc::create([=]() {
        redBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*redBall->getContentSize().height) + 2*redBall->getContentSize().height); redBall->setVisible(true);}), NULL)));
    blueBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.3), MoveBy::create(rand()%2 + 2, Vec2(-visibleSize.width - blueBall->getContentSize().width,0)), CallFunc::create([=]() {
        blueBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*blueBall->getContentSize().height) + 2*blueBall->getContentSize().height); blueBall->setVisible(true);}), NULL)));
    greenBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.4), MoveBy::create(rand()%2 + 2, Vec2(-visibleSize.width - greenBall->getContentSize().width,0)), CallFunc::create([=]() {
        greenBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*greenBall->getContentSize().height) + 2*greenBall->getContentSize().height); greenBall->setVisible(true);}), NULL)));
    magentaBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.5), MoveBy::create(rand()%2 + 2, Vec2(-visibleSize.width - magentaBall->getContentSize().width,0)), CallFunc::create([=]() {
        magentaBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*magentaBall->getContentSize().height) + 2*magentaBall->getContentSize().height); magentaBall->setVisible(true);}), NULL)));
    blackBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.6), MoveBy::create(rand()%2 + 2, Vec2(-visibleSize.width - blackBall->getContentSize().width,0)), CallFunc::create([=]() {
        blackBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*blackBall->getContentSize().height) + 2*blackBall->getContentSize().height); blackBall->setVisible(true);}), NULL)));
    grayBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.7), MoveBy::create(rand()%2 + 2, Vec2(-visibleSize.width - grayBall->getContentSize().width,0)), CallFunc::create([=]() {
        grayBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*grayBall->getContentSize().height) + 2*grayBall->getContentSize().height); grayBall->setVisible(true);}), NULL)));
}

