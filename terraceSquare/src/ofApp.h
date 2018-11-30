#pragma once

#include "ofMain.h"
#include "Particle.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void setParticle();
    
    
    
    static const int num=100;
    vector<Particle*> particles;
    float alpha;
    float alphaNoise;
    ofVboMesh mesh;
    
};
