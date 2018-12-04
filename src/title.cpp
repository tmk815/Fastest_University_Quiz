#include "title.h"

//--------------------------------------------------------------
void title::setup(){
    button0.load("button_0.png"); //画像読み込み
    button1.load("button_1.png"); //画像読み込み
    title.load("title.png"); //画像読み込み
    timer = 0; //時間初期宣言
}

//--------------------------------------------------------------
void title::update(){
    timer++;
}

//--------------------------------------------------------------
void title::draw(){
    title.draw(ofGetWidth()/2-300, 0, 600, 100); //画面上部に配置（仮）
    if(timer%100 < 80){
        button0.draw(ofGetWidth()/2-250, ofGetHeight()/2-250, 500, 500); //画面中央に配置（仮）
    }else{
        button1.draw(ofGetWidth()/2-250, ofGetHeight()/2-250, 500, 500); //画面中央に配置（仮）
    }

}

void title::mousePressed(int x, int y, int button){

}

string title::getName(){
    return "title";
}
