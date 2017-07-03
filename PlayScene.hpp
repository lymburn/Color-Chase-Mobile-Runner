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
#include "TextManager.hpp"
#include "ColorDisplayer.hpp"
#include "ImageManager.hpp"
#include "ActionPerformer.hpp"
#include <memory.h>
#include "Bird.hpp"
#include "BallSpawner.hpp"
#include "TitleScene.hpp"
#include "DeathScene.hpp"

class PlayScene : public cocos2d::Scene {
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(PlayScene);
    void update(float);
    int getHighScore();
    
private:
    Label* displayColor;
    Sprite* bird;
    Sprite* balls[8];
    bool hit = false;
    Color4B correctColor;
    vector<string> colorString;
    vector<Color4B> visibleColor;
    UserDefault* def = UserDefault::getInstance();
    int highScore = def->getIntegerForKey("xxx", 0);
    int score = 0;
    
    Label* scoreLabel = Label::createWithTTF("Score: ", "fonts/Marker Felt.ttf", 16);
    Label* scoreNumber = Label::createWithTTF(std::to_string(score), "fonts/Marker Felt.ttf",16);
    Label* highScoreLabel = Label::createWithTTF("High Score: ", "fonts/Marker Felt.ttf", 16);
    Label* highScoreNumber = Label::createWithTTF(std::to_string(highScore), "fonts/Marker Felt.ttf",16);
    
};
#endif /* PlayScene_hpp */
