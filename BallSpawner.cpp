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
        int intervalMultiplier = rand()%5 + 1;
        ImageCreator->getBalls(i)->setPosition(Vec2(visibleSize.width, intervalMultiplier*heightInterval));
        currentScene->addChild(ImageCreator->getBalls(i),6);
    }
}

void BallSpawner::moveBalls(ImageManager* ImageCreator) {
    //Move the balls across the screen
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    float heightInterval = visibleSize.height/6;

    srand (time(NULL));
    auto yellowBall = ImageCreator->getBalls(0);
    auto orangeBall = ImageCreator->getBalls(1);
    auto redBall = ImageCreator->getBalls(2);
    auto blueBall = ImageCreator->getBalls(3);
    auto greenBall = ImageCreator->getBalls(4);
    auto magentaBall = ImageCreator->getBalls(5);
    auto blackBall = ImageCreator->getBalls(6);
    auto grayBall = ImageCreator->getBalls(7);
    
    yellowBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0), MoveBy::create(rand()%6 + 2, Vec2(-visibleSize.width - yellowBall->getContentSize().width,0)), CallFunc::create([=]() {
        yellowBall->setPosition(visibleSize.width,(rand()%5 + 1)*heightInterval);}), NULL)));
    orangeBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.5), MoveBy::create(rand()%6 + 2, Vec2(-visibleSize.width - orangeBall->getContentSize().width,0)), CallFunc::create([=]() {
        orangeBall->setPosition(visibleSize.width,(rand()%5 + 1)*heightInterval);}), NULL)));
    redBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(1), MoveBy::create(rand()%6 + 2, Vec2(-visibleSize.width - redBall->getContentSize().width,0)), CallFunc::create([=]() {
        redBall->setPosition(visibleSize.width,(rand()%5 + 1)*heightInterval);}), NULL)));
    blueBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(1.5), MoveBy::create(rand()%6 + 2, Vec2(-visibleSize.width - blueBall->getContentSize().width,0)), CallFunc::create([=]() {
        blueBall->setPosition(visibleSize.width,(rand()%5 + 1)*heightInterval);}), NULL)));
    greenBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(2), MoveBy::create(rand()%6 + 2, Vec2(-visibleSize.width - greenBall->getContentSize().width,0)), CallFunc::create([=]() {
        greenBall->setPosition(visibleSize.width,(rand()%5 + 1)*heightInterval);}), NULL)));
    magentaBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(2.5), MoveBy::create(rand()%6 + 2, Vec2(-visibleSize.width - magentaBall->getContentSize().width,0)), CallFunc::create([=]() {
        magentaBall->setPosition(visibleSize.width,(rand()%5 + 1)*heightInterval);}), NULL)));
    blackBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(3), MoveBy::create(rand()%6 + 2, Vec2(-visibleSize.width - blackBall->getContentSize().width,0)), CallFunc::create([=]() {
        blackBall->setPosition(visibleSize.width,(rand()%5 + 1)*heightInterval);}), NULL)));
    grayBall->runAction(RepeatForever::create(Sequence::create(DelayTime::create(3.5), MoveBy::create(rand()%6 + 2, Vec2(-visibleSize.width - grayBall->getContentSize().width,0)), CallFunc::create([=]() {
        grayBall->setPosition(visibleSize.width,(rand()%5 + 1)*heightInterval);}), NULL)));
}

void BallSpawner::collisionChecker(Sprite* bird, ImageManager* ImageCreator) {
    //cout<<balls.at(0)->getPosition().x<<endl;
    
    if (ImageCreator->getBalls(0)->getPosition().x == bird->getPosition().x + bird->getContentSize().width
        || ImageCreator->getBalls(1)->getPosition().x == bird->getPosition().x + bird->getContentSize().width
        || ImageCreator->getBalls(2)->getPosition().x == bird->getPosition().x + bird->getContentSize().width
        || ImageCreator->getBalls(3)->getPosition().x == bird->getPosition().x + bird->getContentSize().width
        || ImageCreator->getBalls(4)->getPosition().x == bird->getPosition().x + bird->getContentSize().width
        || ImageCreator->getBalls(5)->getPosition().x == bird->getPosition().x + bird->getContentSize().width
        || ImageCreator->getBalls(6)->getPosition().x == bird->getPosition().x + bird->getContentSize().width
        || ImageCreator->getBalls(7)->getPosition().x == bird->getPosition().x + bird->getContentSize().width) {
        
        cout<<"hit"<<endl;
    }
}

