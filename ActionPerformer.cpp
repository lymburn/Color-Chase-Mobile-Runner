//
//  ActionPerformer.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-16.
//
//

#include "ActionPerformer.hpp"

void ActionPerformer::fadeInAndOut(Node* target) {
    auto move1 = FadeOut::create(0.8);
    auto move2 = FadeIn::create(0.8);
    auto delay = DelayTime::create(2);
    auto seq = Sequence::create(move1, move2, delay, NULL);
    target->runAction(RepeatForever::create(seq));
}

void ActionPerformer::parallaxScrolling(Node* closeTreesI, Node* midTreesI, Node* farTreesI, Node* mountainsI, Node* cloudsI, Node* closeTreesF, Node* midTreesF, Node* farTreesF, Node* mountainsF,Node* cloudsF) {

    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    float initialCloseTreesTime, initialMidTreesTime, initialFarTreesTime, initialMountainsTime, initialCloudsTime, closeTreesTimeF, midTreesTimeF, farTreesTimeF, mountainsTimeF, cloudsTimeF;
    //Initial times for the first panel to move out of screen
    initialCloseTreesTime = 4;
    initialMidTreesTime= 8;
    initialFarTreesTime= 16;
    initialMountainsTime = 35;
    initialCloudsTime = 25;

    //Times for the following panel
    closeTreesTimeF = 2*initialCloseTreesTime;
    midTreesTimeF = 2*initialMidTreesTime;
    farTreesTimeF = 2*initialFarTreesTime;
    mountainsTimeF = 2*initialMountainsTime;
    cloudsTimeF = 2*initialCloudsTime;
    
    //Moves, sequences, and callbacks for the initial panel
    auto closeTreesMoveI = MoveBy::create(initialCloseTreesTime,Vec2(-visibleSize.width + origin.x,0));
    auto midTreesMoveI = MoveBy::create(initialMidTreesTime, Vec2(-visibleSize.width + origin.x,0));
    auto farTreesMoveI = MoveBy::create(initialFarTreesTime, Vec2(-visibleSize.width + origin.x,0));
    auto mountainsMoveI = MoveBy::create(initialMountainsTime, Vec2(-visibleSize.width + origin.x,0));
    auto cloudsMoveI = MoveBy::create(initialCloudsTime, Vec2(-visibleSize.width + origin.x,0));
    
    
    auto closeTreesCbI = CallFunc::create([=]() {closeTreesI->setPosition(Vec2(visibleSize.width + origin.x, origin.y));});
    auto midTreesCbI = CallFunc::create([=]() {midTreesI->setPosition(Vec2(visibleSize.width + origin.x, origin.y));});
    auto farTreesCbI = CallFunc::create([=]() {farTreesI->setPosition(Vec2(visibleSize.width + origin.x, origin.y));});
    auto mountainsCbI = CallFunc::create([=]() {mountainsI->setPosition(Vec2(visibleSize.width + origin.x, origin.y));});
    auto cloudsCbI = CallFunc::create([=]() {cloudsI->setPosition(Vec2(visibleSize.width + origin.x, origin.y));});
    
    auto closeTreesSeqI = Sequence::create(closeTreesMoveI,closeTreesCbI,closeTreesMoveI->clone(),NULL);
    auto midTreesSeqI = Sequence::create(midTreesMoveI,midTreesCbI,midTreesMoveI->clone(),NULL);
    auto farTreesSeqI = Sequence::create(farTreesMoveI,farTreesCbI,farTreesMoveI->clone(),NULL);
    auto mountainsSeqI = Sequence::create(mountainsMoveI,mountainsCbI,mountainsMoveI->clone(),NULL);
    auto cloudsSeqI = Sequence::create(cloudsMoveI,cloudsCbI,cloudsMoveI->clone(),NULL);
    
    
    //Moves,sequence, and callback for the following panel
    auto closeTreesMoveF = MoveTo::create(closeTreesTimeF, Vec2(-visibleSize.width + origin.x, origin.y));
    auto midTreesMoveF = MoveTo::create(midTreesTimeF, Vec2(-visibleSize.width + origin.x, origin.y));
    auto farTreesMoveF = MoveTo::create(farTreesTimeF,Vec2(-visibleSize.width + origin.x, origin.y));
    auto mountainsMoveF = MoveTo::create(mountainsTimeF,Vec2(-visibleSize.width + origin.x, origin.y));
    auto cloudsMoveF = MoveTo::create(cloudsTimeF,Vec2(-visibleSize.width + origin.x, origin.y));
    
    auto closeTreesCbF = CallFunc::create([=]() {closeTreesF->setPosition(Vec2(visibleSize.width + origin.x, origin.y));});
    auto midTreesCbF = CallFunc::create([=]() {midTreesF->setPosition(Vec2(visibleSize.width + origin.x, origin.y));});
    auto farTreesCbF = CallFunc::create([=]() {farTreesF->setPosition(Vec2(visibleSize.width + origin.x, origin.y));});
    auto mountainsCbF = CallFunc::create([=]() {mountainsF->setPosition(Vec2(visibleSize.width + origin.x, origin.y));});
    auto cloudsCbF = CallFunc::create([=]() {cloudsF->setPosition(Vec2(visibleSize.width + origin.x, origin.y));});
    
    auto closeTreesSeqF = Sequence::create(closeTreesMoveF, closeTreesCbF, NULL);
    auto midTreesSeqF = Sequence::create(midTreesMoveF, midTreesCbF, NULL);
    auto farTreesSeqF = Sequence::create(farTreesMoveF, farTreesCbF, NULL);
    auto mountainsSeqF = Sequence::create(mountainsMoveF, mountainsCbF, NULL);
    auto cloudsSeqF = Sequence::create(cloudsMoveF, cloudsCbF, NULL);
    
    //Run the actions
    closeTreesI->runAction(RepeatForever::create(closeTreesSeqI));
    midTreesI->runAction(RepeatForever::create(midTreesSeqI));
    farTreesI->runAction(RepeatForever::create(farTreesSeqI));
    mountainsI->runAction(RepeatForever::create(mountainsSeqI));
    cloudsI->runAction(RepeatForever::create(cloudsSeqI));
    
    closeTreesF -> runAction(RepeatForever::create(closeTreesSeqF));
    midTreesF -> runAction(RepeatForever::create(midTreesSeqF));
    farTreesF -> runAction(RepeatForever::create(farTreesSeqF));
    mountainsF-> runAction(RepeatForever::create(mountainsSeqF));
    cloudsF -> runAction(RepeatForever::create(cloudsSeqF));
}

void ActionPerformer::runBackgroundParallaxScrolling(ImageManager* ImageCreator) {

    //Get the nodes for the background assets
    auto closeTreesI = ImageCreator->getBackgroundAsset("closeTreesI");
    auto midTreesI = ImageCreator->getBackgroundAsset("midTreesI");
    auto farTreesI = ImageCreator->getBackgroundAsset("farTreesI");
    auto mountainsI = ImageCreator->getBackgroundAsset("mountainsI");
    auto cloudsI = ImageCreator->getBackgroundAsset("cloudsI");
    
    auto closeTreesF = ImageCreator->getBackgroundAsset("closeTreesF");
    auto midTreesF = ImageCreator->getBackgroundAsset("midTreesF");
    auto farTreesF = ImageCreator->getBackgroundAsset("farTreesF");
    auto mountainsF = ImageCreator->getBackgroundAsset("mountainsF");
    auto cloudsF = ImageCreator->getBackgroundAsset("cloudsF");
    
    parallaxScrolling(closeTreesI, midTreesI, farTreesI, mountainsI, cloudsI, closeTreesF, midTreesF, farTreesF, mountainsF, cloudsF);
}
