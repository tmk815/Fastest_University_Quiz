#include "quiz.h"

//--------------------------------------------------------------
void quiz::setup(){
    first = true;
    srand(time_t(NULL));
}

//--------------------------------------------------------------
void quiz::update(){
    if(first){
        quiz_xml.loadFile(getSharedData().genrefile[getSharedData().genre]+".xml");
        isans_1p = false;
        isans_2p = false;
        tryed_1p = false;
        tryed_2p = false;
        timer=0;
        player_ans = "";
        getSharedData().correct_answers_1p = 0;
        getSharedData().correct_answers_2p = 0;
        getSharedData().Unanswered_numbers = 0;
        position = 0;
        quiz_number = 0;
        first = false;

    }
    if(quiz_number < getSharedData().number_of_questions){
        string ans_xml_num,quiz_xml_num; //文字列格納用
        stringstream ss_ans,ss_quiz; //StringStream

        ss_ans << "q" << to_string(quiz_number + 1) << ":ans";
        ss_ans >> ans_xml_num;
        answer = quiz_xml.getValue(ans_xml_num, ""); //xmlの読み込み

        ss_quiz << "q" << to_string(quiz_number + 1) << ":statement";
        ss_quiz >> quiz_xml_num;
        string s = quiz_xml.getValue(quiz_xml_num, ""); //xmlの読み込み

        if((!isans_1p) && (!isans_2p)){
            if(s.length() >= timer/6 && timer%18 == 0){
                if(timer%396==0 && timer!=0) {
                    statement += '\n';
                }
                statement += s.substr(timer/6,3);
            }
            timer++;
        }
    }else{
        first = true;
        changeState("result");
    }

    if(timer >= 600){
        quiz_number++;
        getSharedData().Unanswered_numbers++;
        timer=0;
        statement = "";
        tryed_1p = tryed_2p = false;
        position = 0;
    }
}

//--------------------------------------------------------------
void quiz::draw(){
    //getSharedData().font.drawString(ofToString(position),0,30);
    //getSharedData().font.drawString(ofToString(getSharedData().number_of_questions),0,60);
    getSharedData().font.drawString("1P得点："+ofToString(getSharedData().correct_answers_1p),0,30);
    getSharedData().font.drawString("2P得点："+ofToString(getSharedData().correct_answers_2p),0,60);
    getSharedData().font.drawString(statement,0,ofGetHeight()/2);

    if(isans_1p || isans_2p){
        //回答欄
        ofDrawRectangle(150,400,90,90);
        getSharedData().font.drawString(choice[0],180,460);
        ofDrawRectangle(350,400,90,90);
        getSharedData().font.drawString(choice[1],380,460);
        ofDrawRectangle(550,400,90,90);
        getSharedData().font.drawString(choice[2],580,460);
        ofDrawRectangle(750,400,90,90);
        getSharedData().font.drawString(choice[3],780,460);

        ofSetColor(255,0,0);
        getSharedData().font.drawString(player_ans,ofGetWidth()/2,300);
        ofSetColor(255,255,255);
    }

    if(isans_1p){
        getSharedData().font.drawString("回答者：1P",ofGetWidth()/2,30);
    }else if(isans_2p){
        getSharedData().font.drawString("回答者：2P",ofGetWidth()/2,30);
    }
}

void quiz::mousePressed(int x, int y, int button){
    if(button == 2){changeState("title");} //右クリックでタイトルへ戻る
    if(x>=150 && x<=240 && y>= 400 && y<= 490){
        player_ans += choice[0];
        makeChoices();
    }else if(x>=350 && x<=440 && y>= 400 && y<= 490){
        player_ans += choice[1];
        makeChoices();
    }else if(x>=550 && x<=640 && y>= 400 && y<= 490){
        player_ans += choice[2];
        makeChoices();
    }else if(x>=750 && x<=840 && y>= 400 && y<= 490){
        player_ans += choice[3];
        makeChoices();
    }
}

void quiz::keyReleased(int key){
    if(key == 'a' && !isans_2p && !tryed_1p){ //1Pが回答ボタンを押したとき
        isans_1p= true;   //回答フラグをtrueに
        tryed_1p = true;
        getSharedData().incorrect_answers_1p++;
        makeChoices();
    }else if(key == 'l' && !isans_2p && !tryed_2p){ //2Pが回答ボタンを押したとき
        isans_2p = true;   //回答フラグをtrueに
        tryed_2p = true;
        getSharedData().incorrect_answers_2p++;
        makeChoices();
    }else if(key == 'r'){
        isans_1p = isans_2p = false;
    }
}

void quiz::makeChoices(){
    for(int j=0;j<4;j++){
        int i = rand() % 72;
        choice[j] = hrgn[i];
    }
    choice[rand()%4] = answer.substr(position,1);
    position += 1;
    checkAns();
}

void quiz::checkAns(){
    //最後の文字まで答えたら
    if(answer.length() <= player_ans.length()){
        if(answer.compare(player_ans) == 0 && isans_1p){
            getSharedData().correct_answers_1p++;
            getSharedData().incorrect_answers_1p--;
            quiz_number++;
            tryed_1p = tryed_2p = false;
            statement = "";
            timer = 0;
        } else if(answer.compare(player_ans) == 0 && isans_2p){
            getSharedData().correct_answers_2p++;
            getSharedData().incorrect_answers_2p--;
            quiz_number++;
            tryed_1p = tryed_2p = false;
            statement = "";
            timer = 0;
        }
        isans_1p = false;
        isans_2p = false;
        player_ans = "";
        position = 0;
    }
}

string quiz::getName(){
    return "quiz";
}
