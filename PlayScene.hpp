//
//  PlayScene.hpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-27.
//
//

#ifndef PlayScene_hpp
#define PlayScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace std;


class PlayScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(PlayScene);
    void update(float);
    
private:
    void changeAfterEatingBall(int ballNumber);
    void updateScore();
    void setNewColorAndText();
    void detectCollision();
    void stopActionsWhenHit();
    void fadeToDeath();
    Label* displayColor;
    Sprite* bird;
    Sprite* balls[8];
    Sprite* backgroundAssetsI[5];
    Sprite* backgroundAssetsF[5];
    bool hit = false;
    Color4B correctColor;
    vector<string> colorString;
    vector<Color4B> visibleColor;
    UserDefault* def = UserDefault::getInstance();
    int easyHighScore = def->getIntegerForKey("easyHighScore", 0);
    int medHighScore = def->getIntegerForKey("medHighScore", 0);
    int hardHighScore = def->getIntegerForKey("hardHighScore", 0);
    int savedScore = 0;
    int score = 0;
    bool changeScene = false;
    bool fadeOutToDeath = false;
    CocosDenshion::SimpleAudioEngine* audio;
    int currentString = 0, currentColor = 0, newString, newColor;
    
    Label* scoreLabel = Label::createWithTTF("Score: ", "fonts/Marker Felt.ttf", 16);
    Label* scoreNumber = Label::createWithTTF(std::to_string(score), "fonts/Marker Felt.ttf",16);
    Label* highScoreLabel = Label::createWithTTF("High Score: ", "fonts/Marker Felt.ttf", 16);
    Label* easyHighScoreNumber = Label::createWithTTF(std::to_string(easyHighScore), "fonts/Marker Felt.ttf",16);
    Label* medHighScoreNumber = Label::createWithTTF(std::to_string(medHighScore), "fonts/Marker Felt.ttf",16);
    Label* hardHighScoreNumber = Label::createWithTTF(std::to_string(hardHighScore), "fonts/Marker Felt.ttf",16);
};
#endif /* PlayScene_hpp */
