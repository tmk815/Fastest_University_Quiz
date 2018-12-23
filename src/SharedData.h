#pragma once

class SharedData
{
public:
    int genre; //選択したジャンル
    string genrename[7]={"データベース","English","情報理論","日本史","OS","世界史","地球と生命"};
    string genrefile[7]={"DB","English","johoriron","nihonshi", "OS", "sekaishi", "earth"};
    int number_of_questions; //問題数
    int correct_answers_1p; //1P正答数
    int correct_answers_2p; //2P正答数
    int incorrect_answers_1p; //1P誤答数
    int incorrect_answers_2p; //2P誤答数
    int Unanswered_numbers; //未答の問題数

    ofTrueTypeFont font; //フォント用
};
