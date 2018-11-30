#pragma once

#include "ofMain.h"
#include "Particle.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void setParticle();
    void fadeout();
    void keyPressed(int key);
    
    static const int num=131072;//pow(2,17)
    Particle* particles[num];
    float alpha;
    float alphaNoise;
    ofVboMesh mesh;
    int deg;
    ofColor col;
    float resolution;
    int cols;
    int rows;
    float incr;
    
};
