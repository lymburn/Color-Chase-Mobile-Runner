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
    void createTitleBackground();
    void createLevelChooserBackground();
    void createInitialGameBackground();
    void createFollowingBackground();
    Sprite* getBackgroundAsset(std::string name);
private:
    Sprite* titleBackground = Sprite::create("backgrounds/landscape.png");
    Scene* currentScene;
    
    //Initial assets
    Sprite* closeTreesI = Sprite::create("backgrounds/closetrees.png");
    Sprite* midTreesI = Sprite::create("backgrounds/midtrees.png");
    Sprite* farTreesI = Sprite::create("backgrounds/fartrees.png");
    Sprite* mountainsI = Sprite::create("backgrounds/mountains.png");
    Sprite* cloudsI = Sprite::create("backgrounds/clouds.png");
    Sprite* skyI = Sprite::create("backgrounds/sky.png");
    
    //Following
    Sprite* closeTreesF = Sprite::create("backgrounds/closetrees.png");
    Sprite* midTreesF = Sprite::create("backgrounds/midtrees.png");
    Sprite* farTreesF = Sprite::create("backgrounds/fartrees.png");
    Sprite* mountainsF = Sprite::create("backgrounds/mountains.png");
    Sprite* cloudsF = Sprite::create("backgrounds/clouds.png");
};
#endif /* ImageManager_hpp */
