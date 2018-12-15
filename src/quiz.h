#pragma once
#include "ofxState.h"
#include "SharedData.h"
#include "ofxXmlSettings.h"

class quiz : public itg::ofxState<SharedData>{ //ofxStateを継承

    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void keyReleased(int key);
    void makeChoices(); //ランダムな選択肢を作成する
    void checkAns(); //正解かどうか確認
    string getName(); //状態の名前を返す関数

    ofTrueTypeFont font; //フォント用
    ofxXmlSettings quiz_xml; //XMLの設定用
    string statement; //問題文
    string answer; //正解
    bool isans_1p,isans_2p; //回答中かどうかのフラグ
    int timer; //文字数に使うtimer
    string player_ans; //回答
    string choice[4]; //選択肢
    char hrgn[46][4] = {
            "あ","い","う","え","お","か","き","く","け","こ","さ","し","す","せ","そ",
            "た","ち","つ","て","と","な","に","ぬ","ね","の","は","ひ","ふ","へ","ほ",
            "ま","み","む","め","も","や","ゆ","よ","ら","り","る","れ","ろ","わ","を","ん" }; //あ～ん生成用
    unsigned int position; //回答が何文字目か
    int quiz_number; //何番目の問題か

};
