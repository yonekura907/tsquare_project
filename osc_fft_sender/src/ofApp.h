#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxEasyFft.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        //FFT
		ofxEasyFft fft;
    
        // ポート番号
        static const int PORT = 7400;
        // Osc送信用のインスタンス変数
        ofxOscSender sender;
    
};
