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
    
    srand(time(NULL));
    int i = rand()%8;
    displayColor = Label::createWithTTF(colorString.at(rand()%8), "fonts/Ubuntu-Medium.ttf", 24);
    displayColor->setPosition(visibleSize.width/2 + origin.x, origin.y + visibleSize.height - displayColor->getContentSize().height);
    displayColor->setTextColor(visibleColor.at(i));
    setCorrectColor(i);
    currentScene->addChild(displayColor,6);
}

Label* ColorDisplayer::getDisplayColor() {
    return displayColor;
}

Color4B ColorDisplayer::getCorrectColor() {
    return correctColor;
}

vector<string> ColorDisplayer::getColorString() {
    return colorString;
}

vector<Color4B> ColorDisplayer::getVisibleColors() {
    return visibleColor;
}

void ColorDisplayer::setCorrectColor(int i) {
    
    switch (i) {
        case 0:
            correctColor = Color4B::YELLOW;
            break;
        case 1:
            correctColor = Color4B::ORANGE;
            break;
        case 2:
            correctColor = Color4B::RED;
            break;
        case 3:
            correctColor = Color4B::BLUE;
            break;
        case 4:
            correctColor = Color4B::GREEN;
            break;
        case 5:
            correctColor = Color4B::MAGENTA;
            break;
        case 6:
            correctColor = Color4B::BLACK;
            break;
        case 7:
            correctColor = Color4B::GRAY;
            break;
        default:
            correctColor = Color4B::GRAY;
            break;
    }
}

void ColorDisplayer::changeTextAndColor(Label* displayColor) {
    srand (time(NULL));
    displayColor->setString(colorString.at(rand()%8));
    displayColor->setTextColor(visibleColor.at(rand()%8));
}

