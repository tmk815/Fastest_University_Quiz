#include "title.h"

//--------------------------------------------------------------
void title::setup(){
    mecha60.load("mechanoarc.ttf", 60); //
    mecha40.load("mechanoarc.ttf", 40); //
    timer = 0; //時間初期宣言
    left = right = -10; //
}

//--------------------------------------------------------------
void title::update(){
    timer++; //1ずつ増加
    w = ofGetWidth()/16; //
    h = ofGetHeight()/9; //
}

//--------------------------------------------------------------
void title::draw(){
    ofBackground(ofColor::black); //背景色設定
    ofSetColor(ofColor::white); //色指定：白
    mecha60.drawString("Buzzer Univercity Quiz", ofGetWidth()/2-500, 75); //タイトル描画
    ofNoFill(); //枠のみ
    for(int i=1; i<=7; i++){ //判定位置に四角描画
        ofDrawRectangle(w, h*i+40, w, h);
        ofDrawRectangle(w*14, h*i+40, w, h);
    }
    ofDrawRectangle(w*6, h*7+40, w*4, h); //start用の四角描画
    mecha40.drawString("start", ofGetWidth()/2-75, h*7.75+40); //start描画
    ofFill(); //塗りつぶす
    ofDrawRectangle(w, h*left+40, w, h); //左側の選んだ四角描画
    ofDrawRectangle(w*14, h*right+40, w, h); //右側の選んだ四角描画
//----------３Dボタンの描画始
    float size = 40; //3Dの箱一つのサイズ
    int x=3, z=2; //幅の半分、高さ
    cam.begin(); //画面操作ON
    ofEnableDepthTest(); //3dの動作正常化ON
    ofRotateYDeg(timer); //y軸を回す
    ofRotateXDeg(-30); //x軸を30度傾ける
    ofNoFill(); //枠のみ
    for(int i=0; i<x*2+1; i++){ //3dボタン描画
        for(int j=0; j<x*2+1; j++){
            for(int k=0; k<z; k++){
                ofSetColor(ofColor::white);
                ofDrawBox((size*1.25)*(x-i), (size*1.25)*(x-j), size*1.25*k, size);
            }
            if(0<i && i<x*2 && 0<j && j<x*2){
                ofSetColor(ofColor::red);
                ofDrawBox((size*1.25)*(x-i), (size*1.25)*(x-j), size*1.25*z, size);
            }
        }
    }
    ofDisableDepthTest(); //3dの動作正常化OFF
    cam.end(); //画面操作OFF
//----------３Dボタンの描画終
}

void title::mousePressed(int x, int y, int button){
    if(x/w==1 && 0<(y-40)/h && (y-40)/h<8){ //ジャンル選択
        left=(y-40)/h;
        getSharedData().genre = left; //1~7
    }
    if(x/w==14 && 0<(y-40)/h && (y-40)/h<8){ //問題数選択
        right=(y-40)/h;
        getSharedData().number_of_questions = right; //1~7
    }
    if((y-40)/h==7 && 5<x/w && x/w<10 && 0<left && 0<right){ //開始ボタン判定
        changeState("quiz");
        left = right = -10;
    }
}

string title::getName(){
    return "title";
}
