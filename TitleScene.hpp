//
//  TitleScene.hpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-13.
//
//

#ifndef TitleScene_hpp
#define TitleScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "TextManager.hpp"
#include "ImageManager.hpp"
#include "ActionPerformer.hpp"
#include "LevelChooserScene.hpp"
#include "TutorialScene.hpp"

class TitleScene : public cocos2d::Scene {
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(TitleScene);
};

#endif /* TitleScene_hpp */
