﻿#pragma once

class SharedData
{
public:
    int genre; //選択したジャンル
	string genrename[7]={"データベース","English"};
	string genrefile[7]={"DB","English"};
    int number_of_questions; //問題数
    int correct_answers_1p; //1P正答数
    int correct_answers_2p; //2P正答数
    int incorrect_answer_1p; //1P誤答数
    int incorrect_answer_2p; //2P誤答数
    int Unanswered_numbers; //未答の問題数

    ofTrueTypeFont font; //フォント用
};
