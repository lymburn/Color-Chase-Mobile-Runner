//
//  BallSpawner.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-29.
//
//

#include "BallSpawner.hpp"
#include <iostream>

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

void BallSpawner::moveBalls(ImageManager* ImageCreator, string difficulty) {
    //Move the balls across the screen and reset them
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
    
    float yellowTimeAcrossScreen;
    float orangeTimeAcrossScreen;
    float redTimeAcrossScreen;
    float blueTimeAcrossScreen;
    float greenTimeAcrossScreen;
    float magentaTimeAcrossScreen;
    float blackTimeAcrossScreen;
    float grayTimeAcrossScreen;
    
    if (difficulty == "easy") {
        yellowTimeAcrossScreen = 2 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(3.5-2)));
        orangeTimeAcrossScreen = 2 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(3.5-2)));
        redTimeAcrossScreen = 2 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(3.5-2)));
        blueTimeAcrossScreen = 2 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(3.5-2)));
        greenTimeAcrossScreen = 2 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(3.5-2)));
        magentaTimeAcrossScreen = 2 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(3.5-2)));
        grayTimeAcrossScreen = 2 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(3.5-2)));
        blackTimeAcrossScreen = 2 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(3.5-2)));
    } else if (difficulty == "medium") {
        yellowTimeAcrossScreen = 1.5 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2.5-1.5)));
        orangeTimeAcrossScreen = 1.5 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2.5-1.5)));
        redTimeAcrossScreen = 1.5 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2.5-1.5)));
        blueTimeAcrossScreen = 1.5 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2.5-1.5)));
        greenTimeAcrossScreen = 1.5 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2.5-1.5)));
        magentaTimeAcrossScreen = 1.5 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2.5-1.5)));
        grayTimeAcrossScreen = 1.5 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2.5-1.5)));
        blackTimeAcrossScreen = 1.5 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2.5-1.5)));
    } else if (difficulty == "hard") {
        yellowTimeAcrossScreen = 0.75 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.5-0.75)));
        orangeTimeAcrossScreen = 0.75 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.5-0.75)));
        redTimeAcrossScreen = 0.75 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.5-0.75)));
        blueTimeAcrossScreen = 0.75 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.5-0.75)));
        greenTimeAcrossScreen = 0.75 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.5-0.75)));
        magentaTimeAcrossScreen = 0.75 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.5-0.75)));
        grayTimeAcrossScreen = 0.75 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.5-0.75)));
        blackTimeAcrossScreen = 0.75 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.5-0.75)));
    }
    //Move the balls across the screen between 1 and 2 seconds
    auto yellowMove = MoveBy::create(yellowTimeAcrossScreen, Vec2(-visibleSize.width - yellowBall->getContentSize().width,0));
    auto orangeMove = MoveBy::create(orangeTimeAcrossScreen, Vec2(-visibleSize.width - orangeBall->getContentSize().width,0));
    auto redMove = MoveBy::create(redTimeAcrossScreen, Vec2(-visibleSize.width - redBall->getContentSize().width,0));
    auto blueMove = MoveBy::create(blueTimeAcrossScreen, Vec2(-visibleSize.width - blueBall->getContentSize().width,0));
    auto greenMove = MoveBy::create(greenTimeAcrossScreen, Vec2(-visibleSize.width - greenBall->getContentSize().width,0));
    auto magentaMove = MoveBy::create(magentaTimeAcrossScreen, Vec2(-visibleSize.width - magentaBall->getContentSize().width,0));
    auto blackMove = MoveBy::create(blackTimeAcrossScreen, Vec2(-visibleSize.width - blackBall->getContentSize().width,0));
    auto grayMove = MoveBy::create(grayTimeAcrossScreen, Vec2(-visibleSize.width - grayBall->getContentSize().width,0));
    
    //Callback to reset balls to edge of screen
    auto yellowCb = CallFunc::create([=, &yellowTimeAcrossScreen]() {
            yellowBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*yellowBall->getContentSize().height) + 2*yellowBall->getContentSize().height); yellowBall->setVisible(true);});
    auto orangeCb = CallFunc::create([=, &orangeTimeAcrossScreen]() {
            orangeBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*orangeBall->getContentSize().height) + 2*orangeBall->getContentSize().height); orangeBall->setVisible(true);});
    auto redCb = CallFunc::create([=, &redTimeAcrossScreen]() {
            redBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*redBall->getContentSize().height) + 2*redBall->getContentSize().height); redBall->setVisible(true);});
    auto blueCb = CallFunc::create([=, &blueTimeAcrossScreen]() {
            blueBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*blueBall->getContentSize().height) + 2*blueBall->getContentSize().height); blueBall->setVisible(true);});
    auto greenCb = CallFunc::create([=, &greenTimeAcrossScreen]() {
            greenBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*greenBall->getContentSize().height) + 2*greenBall->getContentSize().height); greenBall->setVisible(true);});
    auto magentaCb = CallFunc::create([=, &magentaTimeAcrossScreen]() {
            magentaBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*magentaBall->getContentSize().height) + 2*magentaBall->getContentSize().height); magentaBall->setVisible(true);});
    auto blackCb = CallFunc::create([=, &blackTimeAcrossScreen]() {
            blackBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*blackBall->getContentSize().height) + 2*blackBall->getContentSize().height); blackBall->setVisible(true);});
    auto grayCb = CallFunc::create([=, &grayTimeAcrossScreen]() {
            grayBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*grayBall->getContentSize().height) + 2*grayBall->getContentSize().height); grayBall->setVisible(true);});
    
    yellowBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.05), yellowMove, yellowCb, NULL)));
    orangeBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.05), orangeMove, orangeCb, NULL)));
    redBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.05), redMove, redCb, NULL)));
    blueBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.05), blueMove, blueCb, NULL)));
    greenBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.05), greenMove, greenCb, NULL)));
    magentaBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.05), magentaMove, magentaCb, NULL)));
    blackBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.05), blackMove, blackCb, NULL)));
    grayBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.05), grayMove, grayCb, NULL)));
}

