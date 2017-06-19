//
//  TutorialScene.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-18.
//
//

#include "TutorialScene.hpp"

Scene* TutorialScene::createScene()
{
    return TutorialScene::create();
}

bool TutorialScene::init() {
    //super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    //Create the background
    ImageManager ImageCreator(this);
    ImageCreator.createInitialGameBackground();
    ImageCreator.createFollowingBackground();
    
    //Get the nodes for the background assets
    auto closeTreesI = ImageCreator.getBackgroundAsset("closeTreesI");
    auto midTreesI = ImageCreator.getBackgroundAsset("midTreesI");
    auto farTreesI = ImageCreator.getBackgroundAsset("farTreesI");
    auto mountainsI = ImageCreator.getBackgroundAsset("mountainsI");
    auto cloudsI = ImageCreator.getBackgroundAsset("cloudsI");
    
    auto closeTreesF = ImageCreator.getBackgroundAsset("closeTreesF");
    auto midTreesF = ImageCreator.getBackgroundAsset("midTreesF");
    auto farTreesF = ImageCreator.getBackgroundAsset("farTreesF");
    auto mountainsF = ImageCreator.getBackgroundAsset("mountainsF");
    auto cloudsF = ImageCreator.getBackgroundAsset("cloudsF");
    
    ActionPerformer PerformActions;
    //Infinite background scrolling
    PerformActions.parallaxScrolling(closeTreesI, midTreesI, farTreesI, mountainsI, cloudsI, closeTreesF, midTreesF, farTreesF, mountainsF, cloudsF);
    
    return true;

}
