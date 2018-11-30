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
    void init(float xIn,float yIn,ofColor cIn);
    void update();
    void warp();    
    float theta,insr,PosX,PosY;
    ofColor c;    
};

#endif /* Particle_hpp */
