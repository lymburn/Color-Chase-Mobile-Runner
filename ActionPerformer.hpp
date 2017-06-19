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
#include <iostream>

class ActionPerformer {
public:
    void fadeInAndOut(Node* target);
    void parallaxScrolling(Node* closeTreesI, Node* midTreesI, Node* farTreesI, Node* mountainsI, Node* cloudsI, Node* closeTreesF, Node* midTreesF, Node* farTreesF, Node* mountainsF,Node* cloudsF);
private:
    
};
#endif /* ActionPerformer_hpp */
