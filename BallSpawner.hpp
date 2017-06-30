//
//  BallSpawner.hpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-29.
//
//

#ifndef BallSpawner_hpp
#define BallSpawner_hpp
USING_NS_CC;
#include <stdio.h>
#include <iostream>
#include "ImageManager.hpp"
using namespace std;

class BallSpawner {
public:
    BallSpawner(Scene* ScenePlaying);
    void spawnBalls(ImageManager* ImageCreator);
    void moveBalls(ImageManager* ImageCreator);
    void collisionChecker(Sprite* bird, ImageManager* ImageCreator);
private:
    Scene* currentScene;
};

#endif /* BallSpawner_hpp */
