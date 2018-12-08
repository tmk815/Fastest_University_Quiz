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
    getSharedData().font.drawString(ofToString(getSharedData().genre),0,30);
    getSharedData().font.drawString(ofToString(getSharedData().number_of_questions),0,60);
}

void quiz::mousePressed(int x, int y, int button){

}

string quiz::getName(){
    return "quiz";
}
