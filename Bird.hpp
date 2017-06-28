//
//  Bird.hpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-20.
//
//

#ifndef Bird_hpp
#define Bird_hpp
USING_NS_CC;
#include <stdio.h>
#include <iostream>


class Bird {
public:
    Bird(Scene* scenePlaying);
    Sprite* getBird();
    void animateBird();
private:
    Sprite* bird = Sprite::create("sprites/Flying1.png");
    Scene* currentScene;
};

#endif /* Bird_hpp */
