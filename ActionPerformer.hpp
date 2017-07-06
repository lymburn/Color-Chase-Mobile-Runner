//
//  ActionPerformer.hpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-16.
//
//

#ifndef ActionPerformer_hpp
#define ActionPerformer_hpp
USING_NS_CC;
#include <stdio.h>
#include "ImageManager.hpp"

class ActionPerformer {
public:
    void fadeInAndOut(Node* target);
    void runBackgroundParallaxScrolling(ImageManager* ImageCreator);
    void fadeIn(Node* target);
    void fadeOut (Node* target);
    void increaseScore(Label* scoreLabel, int& score);
private:
    void parallaxScrolling(Node* closeTreesI, Node* midTreesI, Node* farTreesI, Node* mountainsI, Node* cloudsI, Node* closeTreesF, Node* midTreesF, Node* farTreesF, Node* mountainsF,Node* cloudsF);
    
};
#endif /* ActionPerformer_hpp */
