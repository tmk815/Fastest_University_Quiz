#pragma once
#include "ofxState.h"

class result : public itg::ofxState<>{ //ofxStateを継承

    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    string getName(); //状態の名前を返す関数

};
