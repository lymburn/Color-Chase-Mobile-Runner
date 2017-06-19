//
//  LevelChooserScene.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-16.
//
//

#include "LevelChooserScene.hpp"
#include "TextManager.hpp"
#include <iostream>
USING_NS_CC;

Scene* LevelChooserScene::createScene()
{
    return LevelChooserScene::create();
}

bool LevelChooserScene::init() {
    //super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    //Creates title text and tap to play
    TextManager TextCreator(this);
    TextCreator.createTitle();
    return true;
}
