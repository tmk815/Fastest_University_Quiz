#include "title.h"

//--------------------------------------------------------------
void title::setup(){
    mecha60.load("mechanoarc.otf", 60); //
    mecha40.load("mechanoarc.otf", 40); //
    timer = 0; //時間初期宣言
    left = right = -10; //
}

//--------------------------------------------------------------
void title::update(){
    timer++; //1ずつ増加
    w = ofGetWidth()/16; //画面横幅の１６分の1
    h = ofGetHeight()/9; //画面縦幅の９分の1
}

//--------------------------------------------------------------
void title::draw(){
    ofEnableDepthTest(); //3dの動作正常化ON
    ofBackground(ofColor::black); //背景色設定
    ofSetColor(ofColor::white); //色指定：白
    mecha60.drawString("Buzzer Univercity Quiz", ofGetWidth()/2-500, 75); //タイトル描画
    ofNoFill(); //枠のみ
    for(int i=1; i<=7; i++){ //判定位置に四角描画
        if(left==i){
            ofFill(); //塗りつぶす
            ofSetColor(ofColor::white);
            ofDrawBox(w+w, h*left+40+h/2, 0, h); //左側の選んだ四角描画
            ofNoFill();
            ofSetColor(ofColor::black);
            ofDrawBox(w+w, h*left+40+h/2, 0, h);
            ofDisableDepthTest(); //3dの動作正常化OFF
            ofSetColor(ofColor::red);
            getSharedData().font.drawString(""+getSharedData().genrename[i-1], w+w/2, h*left+40+h);
            ofEnableDepthTest(); //3dの動作正常化ON
        }else{
            ofSetColor(ofColor::white);
            ofDrawBox(w+w/2, h*i+40+h/2, 0, h);
        }
        if(right==i){
            ofFill();
            ofSetColor(ofColor::white);
            ofDrawBox(w*14, h*right+40+h/2, 0, h); //右側の選んだ四角描画
            ofNoFill();
            ofSetColor(ofColor::black);
            ofDrawBox(w*14, h*right+40+h/2, 0, h);
            ofDisableDepthTest(); //3dの動作正常化OFF
            ofSetColor(ofColor::red);
            mecha60.drawString(""+ofToString(i), w*14, h*right+40+h);
            ofEnableDepthTest(); //3dの動作正常化ON
        }else{
            ofSetColor(ofColor::white);
            ofDrawBox(w*14+w/2, h*i+40+h/2, 0, h);
        }
    }
    for(int i=0; i<4; i++){
        ofFill();
        ofSetColor(ofColor::white);
        ofDrawBox(w*(6.5+i), h*7.5+40, 0, w);
    }
    ofDisableDepthTest(); //3dの動作正常化OFF
    ofSetColor(ofColor::black);
    mecha40.drawString("start", ofGetWidth()/2-75, h*7.75+40); //start描画
    ofEnableDepthTest(); //3dの動作正常化ON
//----------３Dボタンの描画始
    float size = 40; //3Dの箱一つのサイズ
    int x=3, z=2; //幅の半分、高さ
    cam.begin(); //画面操作ON
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
    cam.end(); //画面操作OFF
//----------３Dボタンの描画終
    ofDisableDepthTest(); //3dの動作正常化OFF
}

void title::mousePressed(int x, int y, int button){
    if(x/w==1 && 0<(y-40)/h && (y-40)/h<8){ //ジャンル選択
        left=(y-40)/h;
        getSharedData().genre = left-1; //1~7
    }
    if(x/w==14 && 0<(y-40)/h && (y-40)/h<8){ //問題数選択
        right=(y-40)/h;
        getSharedData().number_of_questions = right-1; //1~7
    }
    if((y-40)/h==7 && 5<x/w && x/w<10 && 0<left && 0<right){ //開始ボタン判定
        changeState("quiz");
        left = right = -10;
    }
}

string title::getName(){
    return "title";
}
