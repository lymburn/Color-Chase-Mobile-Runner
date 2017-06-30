//
//  ColorDisplayer.cpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-27.
//
//

#include "ColorDisplayer.hpp"
using namespace std;

ColorDisplayer::ColorDisplayer(Scene* ScenePlaying) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //Sets the current scene playing
    currentScene = ScenePlaying;
    //Add the text for the colors
    colorString.push_back("Yellow");
    colorString.push_back("Orange");
    colorString.push_back("Red");
    colorString.push_back("Blue");
    colorString.push_back("Green");
    colorString.push_back("Purple");
    colorString.push_back("Black");
    colorString.push_back("Gray");
    //Add the color of the text of colorString
    visibleColor.push_back(Color4B::YELLOW);
    visibleColor.push_back(Color4B::ORANGE);
    visibleColor.push_back(Color4B::RED);
    visibleColor.push_back(Color4B::BLUE);
    visibleColor.push_back(Color4B::GREEN);
    visibleColor.push_back(Color4B::MAGENTA);
    visibleColor.push_back(Color4B::BLACK);
    visibleColor.push_back(Color4B::GRAY);
    
    displayColor = Label::createWithTTF(colorString.at(0), "fonts/Ubuntu-Medium.ttf", 24);
    displayColor->setPosition(visibleSize.width/2 + origin.x, origin.y + visibleSize.height - displayColor->getContentSize().height);
    currentScene->addChild(displayColor,6);
}

Label* ColorDisplayer::getDisplayColor() {
    return displayColor;
}

void ColorDisplayer::changeTextAndColor(Label* displayColor) {
    srand (time(NULL));
    
    auto changeString = CallFunc::create([=]() {displayColor->setString(colorString.at(rand()%8));});
    auto changeColor = CallFunc::create([=]() {displayColor->setTextColor(visibleColor.at(rand()%8));});
    
    auto seq = Sequence::create(changeString, changeColor, DelayTime::create(5), NULL);
    displayColor->runAction(RepeatForever::create(seq));
}

