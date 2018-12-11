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
    ofEasyCam cam; //3d操作のため
    ofTrueTypeFont mecha60; //フォント使用のため
    ofTrueTypeFont mecha40; //フォント使用のため
    int timer; //時間経過
    int w, h, left, right; //画面の横幅、立幅、ジャンル、問題数
};
