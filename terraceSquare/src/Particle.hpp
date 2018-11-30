//
//  Particle.hpp
//  DHoF01
//
//  Created by 引田祐樹 on 2018/11/26.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include "ofMain.h"

class Particle{
    
public:
    Particle(float *xIn,float *yIn,ofColor *cIn,float *_fft);
    ~Particle();
    void update();
    void warp();
    float theta,insr;
    ofVec2f location;
    ofVec2f velocity;
    ofColor c;
    float lifeSpan;
    float fft;
    
};

#endif /* Particle_hpp */
