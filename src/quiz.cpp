#include "quiz.h"

//--------------------------------------------------------------
void quiz::setup(){

}

//--------------------------------------------------------------
void quiz::update(){

}

//--------------------------------------------------------------
void quiz::draw(){
    getSharedData().font.drawString(u8"クイズ画面", ofGetWidth()/2-100, ofGetHeight()/2);
}

void quiz::mousePressed(int x, int y, int button){

}

string quiz::getName(){
    return "quiz";
}
