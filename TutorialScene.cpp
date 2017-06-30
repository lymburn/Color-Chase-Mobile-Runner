//
//  TutorialScene.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-18.
//
//

#include "TutorialScene.hpp"

Scene* TutorialScene::createScene()
{
    return TutorialScene::create();
}

bool TutorialScene::init() {
    //super init first
    if ( !Scene::init() )
    {
        return false;
    }
    //Creates text
    
    
    //Displays the color/goal for player
    auto ColorDisplay = new ColorDisplayer(this);
    auto displayColor = ColorDisplay->getDisplayColor();
    ColorDisplay->changeTextAndColor(displayColor);
    
    //Create the backgrounds
    auto ImageCreator = new ImageManager(this);
    ImageCreator->createInitialGameBackground();
    ImageCreator->createFollowingBackground();
    ImageCreator->createBalls();
    
    //Creates the balls
    auto BallCreator = new BallSpawner(this);
    BallCreator->spawnBalls(ImageCreator);
    BallCreator->moveBalls(ImageCreator);
    
    auto PerformActions = new ActionPerformer;
    //Infinite background scrolling
    PerformActions->runBackgroundParallaxScrolling(ImageCreator);
    
    //Bird instance
    auto BirdInst = new Bird(this);
    BirdInst->animateBird();

    //Touch listener
    auto touchListener = EventListenerTouchOneByOne::create();
    Sprite* bird = BirdInst->getBird();
    bird->setTag(1);
    
    
    bool tapped = false;
    touchListener->onTouchBegan = [=](Touch* touch, Event* event) {
        return true;
    };
    
    touchListener->onTouchEnded = [=](Touch* touch, Event* event) mutable {
        if (tapped == false) {
            float distanceToLocation = sqrtf(powf(touch->getLocation().x - bird->getPosition().x,2) + powf(touch->getLocation().y - bird->getPosition().y,2));
            float timeToLocation = distanceToLocation/(bird->getContentSize().width*25);
            auto move = MoveTo::create(timeToLocation,Vec2(touch->getLocation().x, touch->getLocation().y));
            
            auto cb = CallFunc::create([&]() {
                if (tapped == false) {
                    tapped = true;
                } else {
                    tapped = false;
                }
            });
            auto seq = Sequence::create(cb, move, cb->clone(), NULL);
            bird->runAction(seq);
        }
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener,this);
    this->scheduleUpdate();

    
    delete ColorDisplay;
    delete ImageCreator;
    delete PerformActions;
    delete BirdInst;
    delete BallCreator;
    
    return true;

}

void TutorialScene::update(float delta) {
}
