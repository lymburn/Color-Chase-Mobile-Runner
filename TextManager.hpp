//
//  TextManager.hpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-16.
//
//

#ifndef TextManager_hpp
#define TextManager_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class TextManager {
public:
    void createTitle();
    void createTapToPlay();
    void printScoreAndHighScore();
    void createScoreLabels();
    UserDefault* def = UserDefault::getInstance();
    TextManager (Scene* scenePlaying);
    Label* getTapToPlay();
private:
    Label* title;
    Label* tapToPlay;
    Label* yourScore;
    Label* bestScore;
    Label* deathScenePlayerScoreNumber;
    Label* deathSceneHighScoreNumber;
    int score;
    Scene* currentScene;

};

#endif /* TextManager_hpp */
