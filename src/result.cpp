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
	ofDrawLine(ofGetWidth()/2,ofGetHeight()/6*2,ofGetWidth()/2,ofGetHeight()/6*4);//ボーダーライン
	getSharedData().font.drawString("ジャンル：数学", ofGetWidth()/2-fontsize*4,ofGetHeight()/12*1);
	getSharedData().font.drawString("勝者：1P", ofGetWidth()/2-fontsize*2,ofGetHeight()/12*3);
	getSharedData().font.drawString("1P正答率：100%", ofGetWidth()/4-fontsize*3,ofGetHeight()/12*5);
	getSharedData().font.drawString("1P誤答率：100%", ofGetWidth()/4-fontsize*3,ofGetHeight()/12*7);
	getSharedData().font.drawString("2P正答率：100%", ofGetWidth()/4*3-fontsize*3,ofGetHeight()/12*5);
	getSharedData().font.drawString("2P誤答率：100%", ofGetWidth()/4*3-fontsize*3,ofGetHeight()/12*7);
	getSharedData().font.drawString("未答率：50%", ofGetWidth()/2-fontsize*3.25,ofGetHeight()/12*9);

}

void result::mousePressed(int x, int y, int button){

}

string result::getName()
{
	return "result";
}
