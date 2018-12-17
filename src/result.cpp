#include "result.h"

//--------------------------------------------------------------
void result::setup(){
	ofBackground(ofColor::black); //背景色設定
	ofSetColor(ofColor::white);
}

//--------------------------------------------------------------
void result::update(){
	/*getSharedData().correct_answers_1p=2;
	getSharedData().correct_answers_2p=1;
	getSharedData().incorrect_answers_1p=1;
	getSharedData().incorrect_answers_2p=2;
	getSharedData().number_of_questions=3;
	getSharedData().Unanswered_numbers=2;*/
	if(getSharedData().correct_answers_1p==getSharedData().correct_answers_2p)winner="ＤＲＡＷ";
	if(getSharedData().correct_answers_1p>getSharedData().correct_answers_2p)winner="勝者：1P";
	if(getSharedData().correct_answers_1p<getSharedData().correct_answers_2p)winner="勝者：2P";
	correct_ratio_1p=getSharedData().correct_answers_1p/(double)getSharedData().number_of_questions;
	correct_ratio_2p=getSharedData().correct_answers_2p/(double)getSharedData().number_of_questions;
	incorrect_ratio_1p=getSharedData().incorrect_answers_1p/(double)(getSharedData().correct_answers_1p+getSharedData().incorrect_answers_1p);
	incorrect_ratio_2p=getSharedData().incorrect_answers_2p/(double)(getSharedData().correct_answers_2p+getSharedData().incorrect_answers_2p);
	unanswered_ratio=getSharedData().Unanswered_numbers/(double)getSharedData().number_of_questions;
}

//--------------------------------------------------------------
void result::draw(){
	ofSetColor(ofColor::white);
	ofDrawLine(ofGetWidth()/2,ofGetHeight()/6*2,ofGetWidth()/2,ofGetHeight()/6*4);//ボーダーライン
	getSharedData().font.drawString("ジャンル："+getSharedData().genrename[getSharedData().genre], ofGetWidth()/2-fontsize*9,ofGetHeight()/12*1);
	getSharedData().font.drawString(winner, ofGetWidth()/2-fontsize*4,ofGetHeight()/12*3);
	getSharedData().font.drawString("1P正答率："+ofToString(round(correct_ratio_1p*1000.0)/10.0)+"%", ofGetWidth()/4*1-fontsize*6.5,ofGetHeight()/12*5);
	getSharedData().font.drawString("1P誤答率："+ofToString(round(incorrect_ratio_1p*1000.0)/10.0)+"%", ofGetWidth()/4*1-fontsize*6.5,ofGetHeight()/12*7);
	getSharedData().font.drawString("2P正答率："+ofToString(round(correct_ratio_2p*1000.0)/10.0)+"%", ofGetWidth()/4*3-fontsize*6.5,ofGetHeight()/12*5);
	getSharedData().font.drawString("2P誤答率："+ofToString(round(incorrect_ratio_2p*1000.0)/10.0)+"%", ofGetWidth()/4*3-fontsize*6.5,ofGetHeight()/12*7);
	getSharedData().font.drawString("未答率："+ofToString(round(unanswered_ratio*1000.0)/10.0)+"%", ofGetWidth()/2-fontsize*7,ofGetHeight()/12*9);
	buttonw=300;
	buttonh=ofGetHeight()/12;
	buttonx=ofGetWidth()/2-buttonw/2;
	buttony=ofGetHeight()/12*10;
	ofFill();
	ofDrawRectRounded(buttonx,buttony,0,buttonw,buttonh,10);
	ofSetColor(ofColor::red);
	getSharedData().font.drawString("Return to Title", ofGetWidth()/2-fontsize*5,ofGetHeight()/12*11);
}

void result::mousePressed(int x, int y, int button){
	if(buttonx<=x&&x<=buttonx+buttonw&&buttony<=y&&y<=buttony+buttonh){
		changeState("title");
	}
}

string result::getName()
{
	return "result";
}
