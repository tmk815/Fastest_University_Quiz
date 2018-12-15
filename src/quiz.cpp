#include "quiz.h"

//--------------------------------------------------------------
void quiz::setup(){
    quiz_xml.loadFile("DB.xml");
    isans_1p = false;
    isans_2p = false;
    timer=0;
    player_ans = "";
    getSharedData().correct_answers_1p = 0;
    getSharedData().correct_answers_2p = 0;
    position = 0;
    srand(time_t(NULL));
}

//--------------------------------------------------------------
void quiz::update(){
    answer = quiz_xml.getValue("q1:ans", "");
    string s = quiz_xml.getValue("q1:statement", "");
    if((!isans_1p) && (!isans_2p)){
        if(s.length() >= timer/6 && timer%18 == 0){
            if(timer%396==0 && timer!=0) {
                statement += '\n';
            }
            statement += s.substr(timer/6,3);
        }
        timer++;
    }
}

//--------------------------------------------------------------
void quiz::draw(){
    getSharedData().font.drawString(ofToString(getSharedData().correct_answers_1p),0,90);
    getSharedData().font.drawString(ofToString(position),0,30);
    getSharedData().font.drawString(ofToString(getSharedData().number_of_questions),0,60);
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

        getSharedData().font.drawString(player_ans,ofGetWidth()/2,300);
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
    if(key == 'a' && !isans_2p){ //1Pが回答ボタンを押したとき
        isans_1p= true;   //回答フラグをtrueに
        makeChoices();
    }else if(key == 'l' && !isans_2p){ //2Pが回答ボタンを押したとき
        isans_2p = true;   //回答フラグをtrueに
        makeChoices();
    }else if(key == 'r'){
        isans_1p = isans_2p = false;
    }
}

void quiz::makeChoices(){
    checkAns();
    for(int j=0;j<3;j++){
        int i = rand() % 46;
        choice[j] = hrgn[i];
    }
    choice[3] = answer.substr(position,1);
    position += 1;
}

void quiz::checkAns(){
    if(answer.length() <= player_ans.length()){
        if(answer.compare(player_ans) == 0 && isans_1p){
            getSharedData().correct_answers_1p++;
        } else if(answer.compare(player_ans) == 0 && isans_2p){
            getSharedData().correct_answers_2p++;
        }
        isans_1p = false;
        isans_2p = false;
        player_ans = "";
    }
}

string quiz::getName(){
    return "quiz";
}
