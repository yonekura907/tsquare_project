#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofHideCursor();
    ofSetBackgroundAuto(false);
    ofBackground(21);
    setParticle();
    alphaNoise=0;
    alpha=ofMap(alphaNoise,0,1,10,75);
    
    //store mesh color inform
    for(Particle* p:particles){
        mesh.addColor(p->c);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    alpha=ofMap(alphaNoise,0,1,10,75);
    alpha+=0.01;
    
    mesh.clearVertices();
    //store mesh inform
    for(int i=0;i<num;i++){
        particles[i]->update();
        particles[i]->warp();
        mesh.addVertex(ofVec3f(particles[i]->location.x,particles[i]->location.y,0));
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //fade out
    
    ofSetColor(21, 21, 21, alpha);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    
    //draw location of vertex
    glPointSize(1.0);
    glEnable(GL_POINT_SMOOTH);
    mesh.drawVertices();
    
}

//--------------------------------------------------------------
void ofApp::setParticle(){
    for (int i=0; i<num; i++) {
        float x=ofRandom(ofGetWidth());
        float y=ofRandom(ofGetHeight());
        float adj=ofMap(y, 0, ofGetHeight(),225, 0);
        ofColor c=ofColor(40,adj,255);
        particles[i]=new Particle(x,y,c);
        //particles[i].init(x, y, c);
    }
}

