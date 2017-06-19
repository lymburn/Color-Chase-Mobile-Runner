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

class TextManager {
public:
    void createTitle();
    void createTapToPlay();
    TextManager (Scene* scenePlaying);
    Label* getTapToPlay();
private:
    Label* title;
    Label* tapToPlay;
    Scene* currentScene;
};

#endif /* TextManager_hpp */
