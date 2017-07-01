//
//  ColorDisplayer.hpp
//  Rebirth
//
//  Created by Eugene Lu on 2017-06-27.
//
//

#ifndef ColorDisplayer_hpp
#define ColorDisplayer_hpp

USING_NS_CC;
using namespace std;
#include <stdio.h>
#include <iostream>

class ColorDisplayer {
public:
    void changeTextAndColor(Label* displayColor);
    Label* getDisplayColor();
    Color4B getCorrectColor();
    ColorDisplayer(Scene* scenePlaying);
    void setCorrectColor(int i);
    vector<string> getColorString();
    vector<Color4B> getVisibleColors();
private:
    Label* displayColor;
    vector<string> colorString;
    vector<Color4B> visibleColor;
    Scene* currentScene;
    Color4B correctColor;
};

#endif /* ColorDisplayer_hpp */
