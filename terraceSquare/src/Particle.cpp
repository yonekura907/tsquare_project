//
//  Particle.cpp
//  DHoF01
//
//  Created by 引田祐樹 on 2018/11/26.
//

#include "Particle.hpp"

Particle::Particle(float* xIn,float* yIn, ofColor* cIn){
    PosX=*xIn;
    PosY=*yIn;
    c=*cIn;
    insr=1;
    lifeSpan=100;
    //cout<<"init"<<endl;
}

Particle::~Particle(){
    
}

void Particle::update(){
    insr+=0.008;
    theta=ofNoise(PosX*0.0015,PosY*0.0010,insr)*TWO_PI;
    PosX+=2*cos(theta);
    PosY+=2*sin(theta);
    //cout<<PosX<<endl;
    lifeSpan-=0.1;
}

void Particle::warp(){
    if(PosX>ofGetWidth()){
        PosX=0;
    }
    else if(PosX<0){
        PosX=ofGetWidth();
    }
    
    if(PosY>ofGetHeight()){
        PosY=0;
    }
    else if(PosY<0){
        PosY=ofGetHeight();
    }
}
