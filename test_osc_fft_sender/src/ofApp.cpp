#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    
    //FFTのセットアップ
    fft.setup(pow(2.0,11.0));
    // Osc送信のセットアップ
    sender.setup("127.0.0.1", PORT);
}

//--------------------------------------------------------------
void ofApp::update(){
    fft.update(); //FFT更新
}

//--------------------------------------------------------------
void ofApp::draw(){
    // FFT ------------------------------------------
    //動的配列bufferを作り周波数ごとの値を保存
    vector<float> buffer;
    buffer = fft.getBins();//fftの値をbufferに保存
    
    ofNoFill();
    // fftの値を線で表現
    ofSetLineWidth(2);
    ofBeginShape();
    for (int i=0; i<buffer.size(); i++) {
        float x = ofMap(i, 0, buffer.size(), 0, ofGetWidth());
        float y = ofMap(buffer[i],0,1,ofGetHeight(),0);
        ofVertex(x, y);
    }
    ofEndShape();


    // OSCで送信するデータの作成 ---------------------------
    ofxOscMessage msg;
    // 識別子を設定
    msg.setAddress("/fft");
    // OSC送信用の文字列
    string postFft = "";
    for (int i=0; i<buffer.size(); i++) {
        //周波数ごとの値を","区切りで文字列に連結する
        postFft += ofToString(buffer[i]) + ",";
    }
    //文字列を追加
    msg.addStringArg(postFft);
    // OSC送信
    sender.sendMessage(msg);
}
