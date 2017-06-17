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
