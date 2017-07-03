//
//  Bird.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-20.
//
//

#include "Bird.hpp"
Bird::Bird(Scene* scenePlaying) {
    currentScene = scenePlaying;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    bird->setPosition(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);
    currentScene->addChild(bird,6);
}

Sprite* Bird::getBird() {
    return bird;
}

void Bird::animateBird() {
    
    auto f2 = Sprite::create("sprites/Flying1.png");
    auto f3 = Sprite::create("sprites/Flying2.png");
    auto f4 = Sprite::create("sprites/Flying3.png");
    auto f5 = Sprite::create("sprites/Flying4.png");
    auto f6 = Sprite::create("sprites/Flying5.png");
    
    Vector<SpriteFrame*> animFrames;
    animFrames.reserve(6);
    animFrames.pushBack(SpriteFrame::create("sprites/Flying1.png", Rect(0,0,bird->getContentSize().width,bird->getContentSize().height)));
    animFrames.pushBack(SpriteFrame::create("sprites/Flying2.png", Rect(0,0,f2->getContentSize().width,f2->getContentSize().height)));
    animFrames.pushBack(SpriteFrame::create("sprites/Flying3.png", Rect(0,0,f3->getContentSize().width,f3->getContentSize().height)));    animFrames.pushBack(SpriteFrame::create("sprites/Flying4.png", Rect(0,0,f4->getContentSize().width,f4->getContentSize().height)));
    animFrames.pushBack(SpriteFrame::create("sprites/Flying5.png", Rect(0,0,f5->getContentSize().width,f5->getContentSize().height)));
    animFrames.pushBack(SpriteFrame::create("sprites/Flying6.png", Rect(0,0,f6->getContentSize().width,f6->getContentSize().height)));
    // create the animation out of the frames
    Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
    Animate* animate = Animate::create(animation);
    
    bird->runAction(RepeatForever::create(animate));
}


