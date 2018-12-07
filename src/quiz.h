#pragma once
#include "ofxState.h"
#include "SharedData.h"

class quiz : public itg::ofxState<SharedData>{ //ofxStateを継承

    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    string getName(); //状態の名前を返す関数

    ofTrueTypeFont font; //フォント用
};
