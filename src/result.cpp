#include "result.h"

//--------------------------------------------------------------
void result::setup(){
	ofBackground(ofColor::black); //背景色設定
	ofSetColor(ofColor::white);
}

//--------------------------------------------------------------
void result::update(){


}

//--------------------------------------------------------------
void result::draw(){
	ofSetColor(ofColor::white);
	ofDrawLine(ofGetWidth()/2,ofGetHeight()/6*2,ofGetWidth()/2,ofGetHeight()/6*4);//ボーダーライン
	getSharedData().font.drawString("ジャンル：数学", ofGetWidth()/2-fontsize*15,ofGetHeight()/12*1);
	getSharedData().font.drawString("勝者：1P", ofGetWidth()/2-fontsize*7,ofGetHeight()/12*3);
	getSharedData().font.drawString("1P正答率：100%", ofGetWidth()/4-fontsize*7,ofGetHeight()/12*5);
	getSharedData().font.drawString("1P誤答率：100%", ofGetWidth()/4-fontsize*7,ofGetHeight()/12*7);
	getSharedData().font.drawString("2P正答率：100%", ofGetWidth()/4*3-fontsize*7,ofGetHeight()/12*5);
	getSharedData().font.drawString("2P誤答率：100%", ofGetWidth()/4*3-fontsize*7,ofGetHeight()/12*7);
	getSharedData().font.drawString("未答率：50%", ofGetWidth()/2-fontsize*5.5,ofGetHeight()/12*9);
	buttonw=300;
	buttonh=ofGetHeight()/12;
	buttonx=ofGetWidth()/2-buttonw/2;
	buttony=ofGetHeight()/12*10;
	ofDrawRectRounded(buttonx,buttony,0,buttonw,buttonh,10);
	ofSetColor(ofColor::red);
	getSharedData().font.drawString("Return to Title", ofGetWidth()/2-fontsize*7.5,ofGetHeight()/12*11);
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
