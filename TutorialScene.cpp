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
    displayColor = ColorDisplay->getDisplayColor();
    correctColor = ColorDisplay->getCorrectColor();
    colorString = ColorDisplay->getColorString();
    visibleColor = ColorDisplay->getVisibleColors();
    
    //Create the backgrounds
    auto ImageCreator = new ImageManager(this);
    ImageCreator->createInitialGameBackground();
    ImageCreator->createFollowingBackground();
    
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
    //Collision detection
    auto tutScene = LevelChooserScene::createScene();
    int i = rand()%8;
    int j = rand()%8;
    
    if (i==j) {
        if (j>=0 && j<7) {
            j++;
        } else if (j == 7) {
            j--;
        }
    }
    
    /*
    if (correctColor == Color4B::YELLOW) {
        cout << "Y";
    } else if (correctColor == Color4B::ORANGE) {
        cout<<"O";
    } else if (correctColor == Color4B::RED) {
        cout<<"R";
    } else if (correctColor == Color4B::BLUE) {
        cout<<"Blue";
    } else if (correctColor == Color4B::GREEN) {
        cout<<"Green";
    } else if (correctColor == Color4B::MAGENTA) {
        cout<<"M";
    } else if (correctColor == Color4B::BLACK) {
        cout<< "B";
    } else if (correctColor == Color4B::GRAY) {
        cout<<"Gray";
    }
     */
    
    if (balls[0]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::YELLOW && balls[0]->isVisible()) {
        balls[0]->setVisible(false);
        srand (time(NULL));
        displayColor->setString(colorString.at(i));
        displayColor->setTextColor(visibleColor.at(j));
        correctColor = visibleColor.at(j);
    } else if (balls[0]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::YELLOW && balls[0]->isVisible()) {
        Director::getInstance()->replaceScene(tutScene);
    }
    
    if (balls[1]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::ORANGE && balls[1]->isVisible()) {
        balls[1]->setVisible(false);
        srand (time(NULL));
        displayColor->setString(colorString.at(i));
        displayColor->setTextColor(visibleColor.at(j));
        correctColor = visibleColor.at(j);
    } else if (balls[1]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::ORANGE && balls[1]->isVisible()){
        Director::getInstance()->replaceScene(tutScene);
    }
        
    if (balls[2]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::RED && balls[2]->isVisible()) {
        balls[2]->setVisible(false);
        srand (time(NULL));
        displayColor->setString(colorString.at(i));
        displayColor->setTextColor(visibleColor.at(j));
        correctColor = visibleColor.at(j);
    } else if (balls[2]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::RED && balls[2]->isVisible()){
        Director::getInstance()->replaceScene(tutScene);
    }
        
    if (balls[3]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::BLUE && balls[3]->isVisible()) {
        balls[3]->setVisible(false);
        srand (time(NULL));
        displayColor->setString(colorString.at(i));
        displayColor->setTextColor(visibleColor.at(j));
        correctColor = visibleColor.at(j);
    } else if (balls[3]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::BLUE && balls[3]->isVisible()){
        Director::getInstance()->replaceScene(tutScene);
    }
        
    if (balls[4]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::GREEN && balls[4]->isVisible()) {
        balls[4]->setVisible(false);
        srand (time(NULL));
        displayColor->setString(colorString.at(i));
        displayColor->setTextColor(visibleColor.at(j));
        correctColor = visibleColor.at(j);
    } else if (balls[4]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::GREEN && balls[4]->isVisible()){
        Director::getInstance()->replaceScene(tutScene);
    }
    if (balls[5]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::MAGENTA && balls[5]->isVisible()) {
        balls[5]->setVisible(false);
        srand (time(NULL));
        displayColor->setString(colorString.at(i));
        displayColor->setTextColor(visibleColor.at(j));
        correctColor = visibleColor.at(j);
    } else if (balls[5]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::MAGENTA && balls[5]->isVisible()){
        Director::getInstance()->replaceScene(tutScene);
    }
        
    if (balls[6]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::BLACK && balls[6]->isVisible()) {
        balls[6]->setVisible(false);
        srand (time(NULL));
        displayColor->setString(colorString.at(i));
        displayColor->setTextColor(visibleColor.at(j));
        correctColor = visibleColor.at(j);
    } else if (balls[6]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::BLACK && balls[6]->isVisible()){
        Director::getInstance()->replaceScene(tutScene);
    }
        
    if (balls[7]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::GRAY && balls[7]->isVisible()) {
        balls[7]->setVisible(false);
        srand (time(NULL));
        displayColor->setString(colorString.at(i));
        displayColor->setTextColor(visibleColor.at(j));
        correctColor = visibleColor.at(j);
    } else if (balls[7]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::GRAY && balls[7]->isVisible()){
        Director::getInstance()->replaceScene(tutScene);
    }
}
