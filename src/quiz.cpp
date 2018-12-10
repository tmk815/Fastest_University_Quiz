#include "quiz.h"

//--------------------------------------------------------------
void quiz::setup(){
    quiz_xml.loadFile("DB.xml");
    isans_1p = false;
    isans_2p = false;
    timer=0;
}

//--------------------------------------------------------------
void quiz::update(){
    string s = quiz_xml.getValue("q1:statement", "");
    if((!isans_1p) && (!isans_2p)){
        if(s.size() >= timer/6 && timer%6 == 0){
            statement += s.substr(timer/6,1);
        }
        timer++;
    }
}

//--------------------------------------------------------------
void quiz::draw(){
    //getSharedData().font.drawString(u8"クイズ画面", ofGetWidth()/2-100, ofGetHeight()/2);
    getSharedData().font.drawString(ofToString(getSharedData().genre),0,30);
    getSharedData().font.drawString(ofToString(getSharedData().number_of_questions),0,60);
    getSharedData().font.drawString(u8""+statement,0,ofGetHeight()/2);
}

void quiz::mousePressed(int x, int y, int button){
    if(button == 2){changeState("title");} //右クリックでタイトルへ戻る
}

void quiz::keyReleased(int key){
    if(key == 'a' && !isans_2p){ //1Pが回答ボタンを押したとき
        isans_1p= true;   //回答フラグをtrueに
    }else if(key == 'l' && !isans_2p){ //2Pが回答ボタンを押したとき
        isans_2p = true;   //回答フラグをtrueに
    }
}

string quiz::getName(){
    return "quiz";
}
