#include "title.h"

//--------------------------------------------------------------
void title::setup(){
    /*button0.load("button_0.png"); //画像読み込み
    button1.load("button_1.png"); //画像読み込み
    title.load("title.png"); //画像読み込み*/
    timer = 0; //時間初期宣言
}

//--------------------------------------------------------------
void title::update(){
    timer++; //1ずつ増加
}

//--------------------------------------------------------------
void title::draw(){
    ofBackground(ofColor::black); //背景色設定
    /*title.draw(ofGetWidth()/2-300, 0, 600, 100); //画面上部に配置（仮）
    if(timer%100 < 80){
        button0.draw(ofGetWidth()/2-250, ofGetHeight()/2-250, 500, 500); //画面中央に配置（仮）
    }else{
        button1.draw(ofGetWidth()/2-250, ofGetHeight()/2-250, 500, 500); //画面中央に配置（仮）
    }*/
//----------３Dボタンの描画始
    float size = 40;
    int x=3, z=2;
    cam.begin();
    ofEnableDepthTest();
    ofRotateY(timer);
    ofRotateX(-30);
    ofNoFill();
    for(int i=0; i<x*2+1; i++){
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
    ofDisableDepthTest();
    cam.end();
//----------３Dボタンの描画終
}

void title::mousePressed(int x, int y, int button){

}

string title::getName(){
    return "title";
}
