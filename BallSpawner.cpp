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
    
    auto yellowMove = MoveBy::create(1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2.5-1))), Vec2(-visibleSize.width - yellowBall->getContentSize().width,0));
    auto orangeMove = MoveBy::create(1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2.5-1))), Vec2(-visibleSize.width - orangeBall->getContentSize().width,0));
    auto redMove = MoveBy::create(1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2.5-1))), Vec2(-visibleSize.width - redBall->getContentSize().width,0));
    auto blueMove = MoveBy::create(1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2.5-1))), Vec2(-visibleSize.width - blueBall->getContentSize().width,0));
    auto greenMove = MoveBy::create(1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2.5-1))), Vec2(-visibleSize.width - greenBall->getContentSize().width,0));
    auto magentaMove = MoveBy::create(1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2.5-1))), Vec2(-visibleSize.width - magentaBall->getContentSize().width,0));
    auto blackMove = MoveBy::create(1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2.5-1))), Vec2(-visibleSize.width - blackBall->getContentSize().width,0));
    auto grayMove = MoveBy::create(1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2.5-1))), Vec2(-visibleSize.width - grayBall->getContentSize().width,0));
    
    auto yellowCb = CallFunc::create([=]() {
        yellowBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*yellowBall->getContentSize().height) + 2*yellowBall->getContentSize().height); yellowBall->setVisible(true);});
    auto orangeCb = CallFunc::create([=]() {
        orangeBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*orangeBall->getContentSize().height) + 2*orangeBall->getContentSize().height); orangeBall->setVisible(true);});
    auto redCb = CallFunc::create([=]() {
        redBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*redBall->getContentSize().height) + 2*redBall->getContentSize().height); redBall->setVisible(true);});
    auto blueCb = CallFunc::create([=]() {
        blueBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*blueBall->getContentSize().height) + 2*blueBall->getContentSize().height); blueBall->setVisible(true);});
    auto greenCb = CallFunc::create([=]() {
        greenBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*greenBall->getContentSize().height) + 2*greenBall->getContentSize().height); greenBall->setVisible(true);});
    auto magentaCb = CallFunc::create([=]() {
        magentaBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*magentaBall->getContentSize().height) + 2*magentaBall->getContentSize().height); magentaBall->setVisible(true);});
    auto blackCb = CallFunc::create([=]() {
        blackBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*blackBall->getContentSize().height) + 2*blackBall->getContentSize().height); blackBall->setVisible(true);});
    auto grayCb = CallFunc::create([=]() {
        grayBall->setPosition(visibleSize.width,rand()%static_cast<int>(visibleSize.height - 2*grayBall->getContentSize().height) + 2*grayBall->getContentSize().height); grayBall->setVisible(true);});
    
    yellowBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.05), yellowMove, yellowCb, NULL)));
    orangeBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.1), orangeMove, orangeCb, NULL)));
    redBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.15), redMove, redCb, NULL)));
    blueBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.2), blueMove, blueCb, NULL)));
    greenBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.25), greenMove, greenCb, NULL)));
    magentaBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.3), magentaMove, magentaCb, NULL)));
    blackBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.35), blackMove, blackCb, NULL)));
    grayBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.4), grayMove, grayCb, NULL)));
}

