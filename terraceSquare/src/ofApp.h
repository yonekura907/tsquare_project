#pragma once

#include "ofMain.h"
#include "Particle.hpp"
#include "ofxEasyFft.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void setParticle();
    void keyPressed(int key);
    
    static const int num=131072;//pow(2,17)
    Particle* particles[num];
    float alpha;
    float alphaNoise;
    ofVboMesh mesh;
    int deg;
    ofColor col;
    
    //FFTのクラスを呼び出す変数
    ofxEasyFft fft;
};
