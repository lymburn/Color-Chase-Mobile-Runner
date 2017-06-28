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
    void displayCurrentColor(Label* displayColor);
    void changeTextAndColor();
    Label* getDisplayColor();
    ColorDisplayer(Scene* scenePlaying);
private:
    Label* displayColor;
    vector<string> colorString;
    vector<Color4B> visibleColor;
    Scene* currentScene;
};

#endif /* ColorDisplayer_hpp */
