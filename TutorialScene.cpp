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
    ColorDisplay = new ColorDisplayer(this);
    auto displayColor = ColorDisplay->getDisplayColor();
    //ColorDisplay->changeTextAndColor(displayColor);
    
    //Create the backgrounds
    ImageCreator = new ImageManager(this);
    ImageCreator->createInitialGameBackground();
    ImageCreator->createFollowingBackground();
    
    //Creates the balls
    BallCreator = new BallSpawner(this);
    BallCreator->spawnBalls(ImageCreator);
    BallCreator->moveBalls(ImageCreator);
    
    PerformActions = new ActionPerformer;
    //Infinite background scrolling
    PerformActions->runBackgroundParallaxScrolling(ImageCreator);
    
    //Bird instance
    BirdInst = new Bird(this);
    BirdInst->animateBird();
    
    balls[0] = ImageCreator->getBalls(0);
    balls[1] = ImageCreator->getBalls(1);
    balls[2] = ImageCreator->getBalls(2);
    balls[3] = ImageCreator->getBalls(3);
    balls[4] = ImageCreator->getBalls(4);
    balls[5] = ImageCreator->getBalls(5);
    balls[6] = ImageCreator->getBalls(6);
    balls[7] = ImageCreator->getBalls(7);
    
    //Touch listener
    auto touchListener = EventListenerTouchOneByOne::create();
    bird = BirdInst->getBird();
    
    bool tapped = false;
    touchListener->onTouchBegan = [=](Touch* touch, Event* event) {
        auto visibleSize = Director::getInstance()->getVisibleSize();
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
    if (balls[0]->getBoundingBox().intersectsRect(bird->getBoundingBox())) {
        balls[0]->setVisible(false);
    } else if (balls[1]->getBoundingBox().intersectsRect(bird->getBoundingBox())) {
        balls[1]->setVisible(false);
    } else if (balls[2]->getBoundingBox().intersectsRect(bird->getBoundingBox())) {
        balls[2]->setVisible(false);
    } else if (balls[3]->getBoundingBox().intersectsRect(bird->getBoundingBox())) {
        balls[3]->setVisible(false);
    } else if (balls[4]->getBoundingBox().intersectsRect(bird->getBoundingBox())) {
        balls[4]->setVisible(false);
    } else if (balls[5]->getBoundingBox().intersectsRect(bird->getBoundingBox())) {
        balls[5]->setVisible(false);
    } else if (balls[6]->getBoundingBox().intersectsRect(bird->getBoundingBox())) {
        balls[6]->setVisible(false);
    } else if (balls[7]->getBoundingBox().intersectsRect(bird->getBoundingBox())) {
        balls[7]->setVisible(false);
    }
}
