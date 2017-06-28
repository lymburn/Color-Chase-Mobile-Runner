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

class PlayScene : public cocos2d::Scene {
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(PlayScene);
};
#endif /* PlayScene_hpp */
