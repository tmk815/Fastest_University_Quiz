#pragma once
#include "ofxState.h"
#include "SharedData.h"

class title : public itg::ofxState<SharedData>{ //ofxStateを継承

    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    string getName(); //状態の名前を返す関数

    ofImage button0; //画像表示のためのインスタンス変数
    ofImage button1; //画像表示のためのインスタンス変数
    ofImage title; //画像表示のためのインスタンス変数
    ofEasyCam cam;
    ofTrueTypeFont mecha60;
    ofTrueTypeFont mecha40;
    int timer; //時間経過
    int w, h, left, right;
};
