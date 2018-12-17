#pragma once
#include "ofxState.h"
#include "SharedData.h"
#include "math.h"

class result : public itg::ofxState<SharedData>{ //ofxStateを継承

    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    string getName(); //状態の名前を返す関数
	double fontsize=22;
	int buttonx,buttony,buttonw,buttonh;
	string winner="ＤＲＡＷ";
	double correct_ratio_1p;
	double correct_ratio_2p;
	double incorrect_ratio_1p;
	double incorrect_ratio_2p;
	double unanswered_ratio;

};
