#include "ofApp.h"
#include "title.h"
#include "quiz.h"
#include "result.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofTrueTypeFontSettings jsettings("Mamelon.otf", 28);//設定一式を納めるインスタンス
    jsettings.addRanges(ofAlphabet::Emoji);//絵文字
    jsettings.addRanges(ofAlphabet::Japanese);//日本語
    jsettings.addRange(ofUnicode::Space);//スペース
    jsettings.addRange(ofUnicode::IdeographicSpace);//全角スペース
    jsettings.addRange(ofUnicode::Latin);//アルファベット等
    //jsettings.addRange(ofUnicode::Latin1Supplement);//記号、アクサン付き文字など
    jsettings.addRange(ofUnicode::NumberForms);//数字？
    //jsettings.addRange(ofUnicode::Arrows);//矢印
    //jsettings.addRange(ofUnicode::MathOperators);//数式記号
    jsettings.addRange(ofUnicode::Hiragana);//ひらがな
    jsettings.addRange(ofUnicode::Katakana);//カタカナ
    //jsettings.addRange(ofUnicode::MiscSymbolsAndPictographs);//絵文字など
    //jsettings.addRange(ofUnicode::Emoticons);//エモーティコン
    stateMachine.getSharedData().font.load(jsettings); // 設定をロード
    stateMachine.getSharedData().font.setLetterSpacing(1.2);//文字間 デフォルトは1.0 文字間をより開ける場合は1.0を超える値を指定する

    //シーンの追加
    stateMachine.addState<title>();
    stateMachine.addState<quiz>();
    stateMachine.addState<result>();

    stateMachine.changeState("title");//最初に呼び出すシーン
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
