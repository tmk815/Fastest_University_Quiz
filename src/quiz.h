#pragma once
#include "ofxState.h"
#include "SharedData.h"
#include "ofxXmlSettings.h"

class quiz : public itg::ofxState<SharedData>{ //ofxStateを継承

    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    string getName(); //状態の名前を返す関数

    ofTrueTypeFont font; //フォント用
    ofxXmlSettings quiz_xml; //XMLの設定用
    string statement; //問題文
    string answer; //正解
    bool isans; //正解したかどうかのフラグ
    int timer; //文字数に使うtimer

};
