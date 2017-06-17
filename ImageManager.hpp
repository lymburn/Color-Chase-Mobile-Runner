//
//  ImageManager.hpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-16.
//
//

#ifndef ImageManager_hpp
#define ImageManager_hpp
USING_NS_CC;
#include <stdio.h>

class ImageManager {
public:
    ImageManager (Scene* scenePlaying);
    void createBackground();
private:
    Sprite* titleBackground;
    Scene* currentScene;
};
#endif /* ImageManager_hpp */
