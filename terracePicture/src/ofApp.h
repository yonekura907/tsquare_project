#pragma once

#include "ofMain.h"
#include "Particle.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void setParticle();
    
    static const int num=65536;//pow(2,16)
    Particle* particles[num];
    float alpha;
    float alphaNoise;
    ofVboMesh mesh;
    
};
