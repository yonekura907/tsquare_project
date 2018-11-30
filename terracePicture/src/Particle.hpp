#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include "ofMain.h"

class Particle{
    
public:
    Particle(float* xIn,float* yIn);
    void update();
    void update(float *_fft);
    void warp();
    float theta,insr;
    ofVec2f location;
    ofVec2f velocity;
    float fft;
};

#endif /* Particle_hpp */
