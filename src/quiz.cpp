#include "quiz.h"

//--------------------------------------------------------------
void quiz::setup(){
    ofTrueTypeFontSettings jsettings("Mamelon.otf", 32);//設定一式を納めるインスタンス
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
    font.load(jsettings); // 設定をロード
    font.setLetterSpacing(1.2);//文字間 デフォルトは1.0 文字間をより開ける場合は1.0を超える値を指定する
}

//--------------------------------------------------------------
void quiz::update(){

}

//--------------------------------------------------------------
void quiz::draw(){

}

void quiz::mousePressed(int x, int y, int button){

}

string quiz::getName(){
    return "quiz";
}
