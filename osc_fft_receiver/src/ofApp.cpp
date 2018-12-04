#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    // Osc受信のセットアップ
    receiver.setup(PORT);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    vector <string> bufferStr;
//    int index = 0;
    string msgValue = "";

    //OSCデータの受信待ち
    while(receiver.hasWaitingMessages()){
        //受信用のインスタンス変数
        ofxOscMessage msg;
        receiver.getNextMessage(msg);

        //受信側の識別子と同じ条件で
        if(msg.getAddress() == "/fft"){
//            if(index == 0){
                msgValue = msg.getArgAsString(0);
                bufferStr = stringSplit(msgValue,',');
//            }
//            index++;
        }
    }
    
    ofNoFill();
    // fftの値を線で表現
    ofSetLineWidth(2);
    ofBeginShape();
    for (int i=0; i<bufferStr.size(); i++) {
        float x = ofMap(i, 0, bufferStr.size(), 0, ofGetWidth());
        float y = ofMap(ofToFloat(bufferStr[i]),0,1,ofGetHeight(),0);
        ofVertex(x, y);
    }
    ofEndShape();
}

// 文字列を分割する ------------------------------------------------------------
vector<string> ofApp::stringSplit(const string &str, char sep){
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while( getline(ss, buffer, sep) ) {
        v.push_back(buffer);
    }
    return v;
}
