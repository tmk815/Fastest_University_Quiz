#pragma once
#include "ofxState.h"
#include "SharedData.h"

class result : public itg::ofxState<SharedData>{ //ofxStateを継承

    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    string getName(); //状態の名前を返す関数
	double fontsize=14;
	int buttonx,buttony,buttonw,buttonh;
};
