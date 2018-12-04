#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        vector<string> stringSplit(const string &str, char sep);

        //受信するポート番号
        static const int PORT = 7400;
    
        //OSCのレシーバー
        ofxOscReceiver receiver;

};
