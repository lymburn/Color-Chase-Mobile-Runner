//
//  PlayScene.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-27.
//
//

#include "PlayScene.hpp"
#include "DeathScene.hpp"
#include "TextManager.hpp"
#include "ColorDisplayer.hpp"
#include "ImageManager.hpp"
#include "ActionPerformer.hpp"
#include "Bird.hpp"
#include "BallSpawner.hpp"
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
    
    //Play music
    audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->setEffectsVolume(1.5);
        
    //Initial score and high score labels
    scoreLabel->setPosition(Vec2(scoreLabel->getContentSize().width*0.6 + origin.x, visibleSize.height - scoreLabel->getContentSize().height*0.6 + origin.y));
    scoreLabel->setTextColor(Color4B::BLACK);
    scoreNumber->setPosition(Vec2(scoreLabel->getContentSize().width + origin.x + 2*scoreNumber->getContentSize().width, visibleSize.height - scoreNumber->getContentSize().height*0.6 + origin.y));
    scoreNumber->setTextColor(Color4B::BLACK);
    highScoreLabel->setPosition(Vec2(visibleSize.width-highScoreLabel->getContentSize().width*0.7 - easyHighScoreNumber->getContentSize().width, visibleSize.height - highScoreLabel->getContentSize().height*0.6 + origin.y));
    highScoreLabel->setTextColor(Color4B::BLACK);
    //Add high score number based on difficulty
    if (def->getStringForKey("difficulty") == "easy") {
        easyHighScoreNumber->setPosition(Vec2(visibleSize.width - easyHighScoreNumber->getContentSize().width*0.9 + origin.x, visibleSize.height - easyHighScoreNumber->getContentSize().height*0.6 + origin.y));
        easyHighScoreNumber->setTextColor(Color4B::BLACK);
        this->addChild(easyHighScoreNumber,6);
    } else if (def->getStringForKey("difficulty") == "medium") {
        medHighScoreNumber->setPosition(Vec2(visibleSize.width - medHighScoreNumber->getContentSize().width*0.9 + origin.x, visibleSize.height - medHighScoreNumber->getContentSize().height*0.6 + origin.y));
        medHighScoreNumber->setTextColor(Color4B::BLACK);
        this->addChild(medHighScoreNumber,6);
    } else {
        hardHighScoreNumber->setPosition(Vec2(visibleSize.width - hardHighScoreNumber->getContentSize().width*0.9 + origin.x, visibleSize.height - hardHighScoreNumber->getContentSize().height*0.6 + origin.y));
        hardHighScoreNumber->setTextColor(Color4B::BLACK);
        this->addChild(hardHighScoreNumber,6);
    }
    this->addChild(scoreLabel,6);
    this->addChild(scoreNumber,6);
    this->addChild(highScoreLabel,6);
    
    //Reset score
    def->setIntegerForKey("score", 0);
    
    //Add score for each second dodging
    scoreLabel->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.8), CallFunc::create([&]() {score++;}), NULL)));
    
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
    
    //Creates the balls and move them
    auto BallCreator = new BallSpawner(this);
    BallCreator->spawnBalls(ImageCreator);
    BallCreator->moveBalls(ImageCreator, def->getStringForKey("difficulty"));
    
    auto PerformActions = new ActionPerformer;
    //Infinite background scrolling
    PerformActions->runBackgroundParallaxScrolling(ImageCreator);
    
    //Bird instance
    auto BirdInst = new Bird(this);
    BirdInst->animateBird();
    
    //Populate the balls array
    balls[0] = ImageCreator->getBalls(0);
    balls[1] = ImageCreator->getBalls(1);
    balls[2] = ImageCreator->getBalls(2);
    balls[3] = ImageCreator->getBalls(3);
    balls[4] = ImageCreator->getBalls(4);
    balls[5] = ImageCreator->getBalls(5);
    balls[6] = ImageCreator->getBalls(6);
    balls[7] = ImageCreator->getBalls(7);
    
    //Populate the background assets
    backgroundAssetsI[0] = ImageCreator->getBackgroundAsset("closeTreesI");
    backgroundAssetsI[1] = ImageCreator->getBackgroundAsset("midTreesI");
    backgroundAssetsI[2] = ImageCreator->getBackgroundAsset("farTreesI");
    backgroundAssetsI[3] = ImageCreator->getBackgroundAsset("mountainsI");
    backgroundAssetsI[4] = ImageCreator->getBackgroundAsset("cloudsI");
    backgroundAssetsF[0] = ImageCreator->getBackgroundAsset("closeTreesF");
    backgroundAssetsF[1] = ImageCreator->getBackgroundAsset("midTreesF");
    backgroundAssetsF[2] = ImageCreator->getBackgroundAsset("farTreesF");
    backgroundAssetsF[3] = ImageCreator->getBackgroundAsset("mountainsF");
    backgroundAssetsF[4] = ImageCreator->getBackgroundAsset("cloudsF");
    
    //Touch listener to move the bird around
    auto touchListener = EventListenerTouchOneByOne::create();
    bird = BirdInst->getBird();
    
    bool tapped = false;
    touchListener->onTouchBegan = [=](Touch* touch, Event* event) {
        return true;
    };
    
    touchListener->onTouchEnded = [=](Touch* touch, Event* event) mutable {
        if (tapped == false && !hit) {
            
            float xPosition, yPosition;
            float distanceToLocation = sqrtf(powf(touch->getLocation().x - bird->getPosition().x,2) + powf(touch->getLocation().y - bird->getPosition().y,2));
            float timeToLocation = distanceToLocation/(bird->getContentSize().width*35);
            
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
            
            //Prevent double tapping
            auto cb = CallFunc::create([&]() {
                if (tapped == false) {
                    tapped = true;
                } else {
                    tapped = false;
                }
            });
            
            auto seq = Sequence::create(cb, move, cb->clone(), NULL);
            seq->setTag(1);
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
    //Updates score every frame
    updateScore();
    //New color and text generator
    setNewColorAndText();
    //Detects collision every frame
    detectCollision();
    //Stops all actions when hit
    stopActionsWhenHit();
    fadeToDeath();
    //Change scenes after fading
    if (changeScene) {
        auto deathScene = DeathScene::createScene();
        Director::getInstance()->replaceScene(deathScene);
    }
}

void PlayScene::changeAfterEatingBall(int ballNumber) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    //Changes made after the correct ball is eaten
    balls[ballNumber]->setVisible(false);
    srand (time(NULL));
    displayColor->setString(colorString.at(newString));
    displayColor->setTextColor(visibleColor.at(newColor));
    audio->playEffect("music/whoosh.wav", false, 1.0f, 1.0f, 1.0f);
    correctColor = visibleColor.at(newColor);
    //More points for eating ball closer to the right
    if (balls[ballNumber]->getPosition().x + origin.x > origin.x && balls[ballNumber]->getPosition().x <= visibleSize.width/4 + origin.x) {
        score+=5;
    } else if (balls[ballNumber]->getPosition().x + origin.x > visibleSize.width/4 + origin.x && balls[ballNumber]->getPosition().x <= visibleSize.width/2 + origin.x) {
        score += 7;
    } else if (balls[ballNumber]->getPosition().x + origin.x > visibleSize.width/2 + origin.x && balls[ballNumber]->getPosition().x <= visibleSize.width*0.75 + origin.x) {
        score += 10;
    } else if (balls[ballNumber]->getPosition().x + origin.x > visibleSize.width*0.75 + origin.x && balls[ballNumber]->getPosition().x <= visibleSize.width + origin.x) {
        score += 20;
    }
    currentColor = newColor;
    currentColor = newColor;
}

void PlayScene::updateScore() {
    //Updates score every frame
    savedScore = score;
    def->setIntegerForKey("score", savedScore);
    if (score>easyHighScore && def->getStringForKey("difficulty") == "easy") {
        easyHighScore = score;
        easyHighScoreNumber->setString(std::to_string(score));
        def->setIntegerForKey("easyHighScore", easyHighScore);
    } else if (score>medHighScore && def->getStringForKey("difficulty") == "medium") {
        medHighScore = score;
        medHighScoreNumber->setString(std::to_string(score));
        def->setIntegerForKey("medHighScore", medHighScore);
    } else if (score>hardHighScore && def->getStringForKey("difficulty") == "hard") {
        hardHighScore = score;
        hardHighScoreNumber->setString(std::to_string(score));
        def->setIntegerForKey("hardHighScore", hardHighScore);
    }
    def->flush();
    scoreNumber->setString(std::to_string(score));
}

void PlayScene::setNewColorAndText() {
    newString = rand()%8; //Text string
    newColor = rand()%8; //Text color
    //Prevents the new color/text to be the same as the one before eating the ball
    if (newString == currentString) {
        if (newString>=0 && newString<7) {
            newString++;
        } else if (newString==7) {
            newString--;
        }
    }
    
    if (newColor == currentColor) {
        if (newColor>=0 && newColor<7) {
            newColor++;
        } else if (newColor==7) {
            newColor--;
        }
    }
}

void PlayScene::detectCollision() {
    //Collision detection
    if (balls[0]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::YELLOW && balls[0]->isVisible()) {
        changeAfterEatingBall(0);
    } else if (balls[0]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::YELLOW && balls[0]->isVisible()) {
        hit = true;
    }
    
    if (balls[1]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::ORANGE && balls[1]->isVisible()) {
        changeAfterEatingBall(1);
    } else if (balls[1]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::ORANGE && balls[1]->isVisible()){
        hit = true;
    }
    
    if (balls[2]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::RED && balls[2]->isVisible()) {
        changeAfterEatingBall(2);
    } else if (balls[2]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::RED && balls[2]->isVisible()){
        hit = true;
    }
    
    if (balls[3]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::BLUE && balls[3]->isVisible()) {
        changeAfterEatingBall(3);
    } else if (balls[3]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::BLUE && balls[3]->isVisible()){
        hit = true;
    }
    
    if (balls[4]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::GREEN && balls[4]->isVisible()) {
        changeAfterEatingBall(4);
    } else if (balls[4]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::GREEN && balls[4]->isVisible()){
        hit = true;
    }
    if (balls[5]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::MAGENTA && balls[5]->isVisible()) {
        changeAfterEatingBall(5);
    } else if (balls[5]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::MAGENTA && balls[5]->isVisible()){
        hit = true;
    }
    
    if (balls[6]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::BLACK && balls[6]->isVisible()) {
        changeAfterEatingBall(6);
    } else if (balls[6]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::BLACK && balls[6]->isVisible()){
        hit = true;
    }
    
    if (balls[7]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor == Color4B::GRAY && balls[7]->isVisible()) {
        changeAfterEatingBall(7);
    } else if (balls[7]->getBoundingBox().intersectsRect(bird->getBoundingBox()) && correctColor != Color4B::GRAY && balls[7]->isVisible()){
        hit = true;
    }
}

void PlayScene::stopActionsWhenHit() {
    //If hit by wrong ball
    if (hit) {
        //If hit stop all actions of moving sprites
        backgroundAssetsI[0]->stopAllActions();
        backgroundAssetsI[1]->stopAllActions();
        backgroundAssetsI[2]->stopAllActions();
        backgroundAssetsI[3]->stopAllActions();
        backgroundAssetsI[4]->stopAllActions();
        backgroundAssetsF[0]->stopAllActions();
        backgroundAssetsF[1]->stopAllActions();
        backgroundAssetsF[2]->stopAllActions();
        backgroundAssetsF[3]->stopAllActions();
        backgroundAssetsF[4]->stopAllActions();
        
        balls[0]->stopAllActions();
        balls[1]->stopAllActions();
        balls[2]->stopAllActions();
        balls[3]->stopAllActions();
        balls[4]->stopAllActions();
        balls[5]->stopAllActions();
        balls[6]->stopAllActions();
        balls[7]->stopAllActions();
        
        scoreLabel->stopAllActions();
        bird->stopActionByTag(1);
        fadeOutToDeath = true;
    }
}

void PlayScene::fadeToDeath() {
    if (fadeOutToDeath) {
        auto visibleSize = Director::getInstance()->getVisibleSize();
        auto origin = Director::getInstance()->getVisibleOrigin();
        auto death = Sprite::create("backgrounds/sky.png");
        death->setScale(visibleSize.width/death->getContentSize().width, visibleSize.height/death->getContentSize().height);
        death->setAnchorPoint(Vec2(0,0));
        death->setPosition(Vec2(origin.x,origin.y));
        death->setOpacity(0);
        this->addChild(death,7);
        death->runAction(Sequence::create(FadeIn::create(0.5), CallFunc::create([&]() {changeScene = true;}), nullptr));
    }
}
