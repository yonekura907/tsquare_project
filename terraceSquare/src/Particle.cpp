//
//  Particle.cpp
//  DHoF01
//
//  Created by 引田祐樹 on 2018/11/26.
//

#include "Particle.hpp"

Particle::Particle(float *xIn,float *yIn, ofColor *cIn,float *_fft){
    location.x=*xIn;
    location.y=*yIn;
    c=*cIn;
    insr=1;
    lifeSpan=100;
    //cout<<"init"<<endl;
    velocity=ofVec2f(0,0);
    fft=*_fft;
}

Particle::~Particle(){
    
}

void Particle::update(){
    velocity=ofVec2f(0,0);
    insr+=0.008;
    theta=ofNoise(location.x*0.0015,location.y*0.0010,insr)*TWO_PI;
    velocity.x+=2*cos(theta);
    velocity.y+=2*sin(theta);
    location+=velocity*fft;
    //cout<<PosX<<endl;
    lifeSpan-=0.1;
}

void Particle::warp(){
    if(location.x>ofGetWidth()){
        location.x=0;
    }
    else if(location.x<0){
        location.x=ofGetWidth();
    }
    
    if(location.y>ofGetHeight()){
        location.y=0;
    }
    else if(location.y<0){
        location.y=ofGetHeight();
    }
}
