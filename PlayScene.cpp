//
//  PlayScene.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-27.
//
//

#include "PlayScene.hpp"
USING_NS_CC;

Scene* PlayScene::createScene()
{
    return PlayScene::create();
}

bool PlayScene::init() {
    //super init first
    if ( !Scene::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    //Initial score and high score labels
    scoreLabel->setPosition(Vec2(scoreLabel->getContentSize().width*0.6 + origin.x, visibleSize.height - scoreLabel->getContentSize().height*0.6 + origin.y));
    scoreLabel->setTextColor(Color4B::BLACK);
    scoreNumber->setPosition(Vec2(scoreLabel->getContentSize().width + origin.x + scoreNumber->getContentSize().width, visibleSize.height - scoreNumber->getContentSize().height*0.6 + origin.y));
    scoreNumber->setTextColor(Color4B::BLACK);
    highScoreLabel->setPosition(Vec2(visibleSize.width-highScoreLabel->getContentSize().width*0.6 - highScoreNumber->getContentSize().width, visibleSize.height - highScoreLabel->getContentSize().height*0.6 + origin.y));
    highScoreLabel->setTextColor(Color4B::BLACK);
    highScoreNumber->setPosition(Vec2(visibleSize.width - highScoreNumber->getContentSize().width*0.6 + origin.x, visibleSize.height - highScoreNumber->getContentSize().height*0.6 + origin.y));
    highScoreNumber->setTextColor(Color4B::BLACK);
    this->addChild(scoreLabel,6);
    this->addChild(scoreNumber,6);
    this->addChild(highScoreLabel,6);
    this->addChild(highScoreNumber,6);
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
            
            float xPosition, yPosition;
            float distanceToLocation = sqrtf(powf(touch->getLocation().x - bird->getPosition().x,2) + powf(touch->getLocation().y - bird->getPosition().y,2));
            float timeToLocation = distanceToLocation/(bird->getContentSize().width*25);
            
            //Check whether touch location is on the edge of screen
            if (touch->getLocation().x >= (bird->getContentSize().width/2) && touch->getLocation().x <= (visibleSize.width - (bird->getContentSize().width/2)) && touch->getLocation().y >= (bird->getContentSize().height/2) && touch->getLocation().y <= (visibleSize.height - (bird->getContentSize().height/2))) {
                //Not on edge
                xPosition = touch->getLocation().x;
                yPosition = touch->getLocation().y;
            } else if (touch->getLocation().x <= (bird->getContentSize().width/2) && touch->getLocation().y >= (bird->getContentSize().height/2) && touch->getLocation().y <= (visibleSize.height - (bird->getContentSize().height/2))){
                //Left
                xPosition = bird->getContentSize().width/2;
                yPosition = touch->getLocation().y;
            } else if (touch->getLocation().x >= (visibleSize.width - (bird->getContentSize().width/2)) && touch->getLocation().y >= bird->getContentSize().height && touch->getLocation().y <= (visibleSize.height - (bird->getContentSize().height/2))) {
                //Right
                xPosition = touch->getLocation().x - (bird->getContentSize().width/2);
                yPosition = touch->getLocation().y;
            } else if (touch->getLocation().y <= bird->getContentSize().height/2 && touch->getLocation().x >= bird->getContentSize().width/2 && touch->getLocation().x <= (visibleSize.width - (bird->getContentSize().width/2))) {
                //Bottom
                xPosition = touch->getLocation().x;
                yPosition = bird->getContentSize().height/2;
            } else if (touch->getLocation().y >= (visibleSize.height + origin.y - (bird->getContentSize().height/2)) && touch->getLocation().x >= bird->getContentSize().width/2 && touch->getLocation().x <= (visibleSize.width - (bird->getContentSize().width/2))) {
                //Top
                xPosition = touch->getLocation().x;
                yPosition = visibleSize.height - (bird->getContentSize().height/2);
            } else {
                xPosition = touch->getLocation().x;
                yPosition = touch->getLocation().y;
            }
            
            auto move = MoveTo::create(timeToLocation,Vec2(xPosition, yPosition));
            
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

void PlayScene::update(float delta) {
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
    
    if (balls[0]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::YELLOW && balls[0]->isVisible()) {
        balls[0]->setVisible(false);
        srand (time(NULL));
        displayColor->setString(colorString.at(i));
        displayColor->setTextColor(visibleColor.at(j));
        correctColor = visibleColor.at(j);
        score++;
        if (score>highScore) {
            highScore = score;
            highScoreNumber->setString(std::to_string(score));
            def->setIntegerForKey("xxx", highScore);
        }
        def->flush();
        scoreNumber->setString(std::to_string(score));
    } else if (balls[0]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::YELLOW && balls[0]->isVisible()) {
        hit = true;
    }
    
    if (balls[1]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::ORANGE && balls[1]->isVisible()) {
        balls[1]->setVisible(false);
        srand (time(NULL));
        displayColor->setString(colorString.at(i));
        displayColor->setTextColor(visibleColor.at(j));
        correctColor = visibleColor.at(j);
        score++;
        if (score>highScore) {
            highScore = score;
            highScoreNumber->setString(std::to_string(score));
            def->setIntegerForKey("xxx", highScore);
        }
        def->flush();
        scoreNumber->setString(std::to_string(score));
    } else if (balls[1]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::ORANGE && balls[1]->isVisible()){
        hit = true;
    }
    
    if (balls[2]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::RED && balls[2]->isVisible()) {
        balls[2]->setVisible(false);
        srand (time(NULL));
        displayColor->setString(colorString.at(i));
        displayColor->setTextColor(visibleColor.at(j));
        correctColor = visibleColor.at(j);
        score++;
        if (score>highScore) {
            highScore = score;
            highScoreNumber->setString(std::to_string(score));
            def->setIntegerForKey("xxx", highScore);
        }
        def->flush();
        scoreNumber->setString(std::to_string(score));
    } else if (balls[2]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::RED && balls[2]->isVisible()){
        hit = true;
    }
    
    if (balls[3]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::BLUE && balls[3]->isVisible()) {
        balls[3]->setVisible(false);
        srand (time(NULL));
        displayColor->setString(colorString.at(i));
        displayColor->setTextColor(visibleColor.at(j));
        correctColor = visibleColor.at(j);
        score++;
        if (score>highScore) {
            highScore = score;
            highScoreNumber->setString(std::to_string(score));
            def->setIntegerForKey("xxx", highScore);
        }
        def->flush();
        scoreNumber->setString(std::to_string(score));
    } else if (balls[3]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::BLUE && balls[3]->isVisible()){
        hit = true;
    }
    
    if (balls[4]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::GREEN && balls[4]->isVisible()) {
        balls[4]->setVisible(false);
        srand (time(NULL));
        displayColor->setString(colorString.at(i));
        displayColor->setTextColor(visibleColor.at(j));
        correctColor = visibleColor.at(j);
        score++;
        if (score>highScore) {
            highScore = score;
            highScoreNumber->setString(std::to_string(score));
            def->setIntegerForKey("xxx", highScore);
        }
        def->flush();
        scoreNumber->setString(std::to_string(score));
    } else if (balls[4]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::GREEN && balls[4]->isVisible()){
        hit = true;
    }
    if (balls[5]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::MAGENTA && balls[5]->isVisible()) {
        balls[5]->setVisible(false);
        srand (time(NULL));
        displayColor->setString(colorString.at(i));
        displayColor->setTextColor(visibleColor.at(j));
        correctColor = visibleColor.at(j);
        score++;
        if (score>highScore) {
            highScore = score;
            highScoreNumber->setString(std::to_string(score));
            def->setIntegerForKey("xxx", highScore);
        }
        def->flush();
        scoreNumber->setString(std::to_string(score));
    } else if (balls[5]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::MAGENTA && balls[5]->isVisible()){
        hit = true;
    }
    
    if (balls[6]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::BLACK && balls[6]->isVisible()) {
        balls[6]->setVisible(false);
        srand (time(NULL));
        displayColor->setString(colorString.at(i));
        displayColor->setTextColor(visibleColor.at(j));
        correctColor = visibleColor.at(j);
        score++;
        if (score>highScore) {
            highScore = score;
            highScoreNumber->setString(std::to_string(score));
            def->setIntegerForKey("xxx", highScore);
        }
        def->flush();
        scoreNumber->setString(std::to_string(score));
    } else if (balls[6]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::BLACK && balls[6]->isVisible()){
        hit = true;
    }
    
    if (balls[7]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::GRAY && balls[7]->isVisible()) {
        balls[7]->setVisible(false);
        srand (time(NULL));
        displayColor->setString(colorString.at(i));
        displayColor->setTextColor(visibleColor.at(j));
        correctColor = visibleColor.at(j);
        score++;
        if (score>highScore) {
            highScore = score;
            highScoreNumber->setString(std::to_string(score));
            def->setIntegerForKey("xxx", highScore);
        }
        def->flush();
        scoreNumber->setString(std::to_string(score));
    } else if (balls[7]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::GRAY && balls[7]->isVisible()){
        hit = true;
    }
    if (hit) {
        Director::getInstance()->replaceScene(tutScene);
    }
}

int PlayScene::getHighScore() {
    return highScore;
}

