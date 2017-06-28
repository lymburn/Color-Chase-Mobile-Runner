//
//  SettingsScene.hpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-27.
//
//

#ifndef SettingsScene_hpp
#define SettingsScene_hpp

#include <stdio.h>

class SettingsScene : public cocos2d::Scene {
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(SettingsScene);
};

#endif /* SettingsScene_hpp */
