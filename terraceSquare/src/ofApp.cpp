#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetFullscreen(true);
    ofHideCursor();
    ofSetBackgroundAuto(false);
    ofBackground(21);
    setParticle();
    alphaNoise=0;
    alpha=ofMap(alphaNoise,0,1,10,75);
    deg=0;
    
    //FFTのセットアップ
    // FFTのサンプル数(2の累乗)を指定して初期化
    fft.setup(pow(2.0,17.0));
    
    resolution=20;
    incr=0;
}

//--------------------------------------------------------------
void ofApp::update(){
    alpha=ofMap(alphaNoise,0,1,10,75);
    alpha+=0.01;
    
    mesh.clearVertices();
    mesh.clearColors();
    
    fft.update(); //FFT更新
    vector<float> buffer;
    buffer = fft.getBins();
    
    
    //store mesh inform
    for(int i=0;i<num;i++){
        if(buffer.size()==num){
            particles[i]->update(&buffer[i]);
        }else{
            particles[i]->update();

        }
        particles[i]->warp();
        mesh.addVertex(ofVec3f(particles[i]->location.x,particles[i]->location.y,0));
        float adj=ofMap(particles[i]->location.y, 0, ofGetHeight(),225, 0);
        ofColor c;
        if(deg>=0&&deg<120){
            c=ofColor(40,adj,255);
        }else if (deg>120&&deg<240){
            c=ofColor(adj,225,40);
        }else{
            c=ofColor(225,40,adj);
        }
        mesh.addColor(c);
    }
    
    cout<<ofGetFrameRate()<<endl;
    
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
        particles[i]=new Particle(x,y);
    }
}
//--------------------------------------------------------------
void ofApp::fadeout(){
    cols=int(ofGetWidth()/resolution);
    rows=int(ofGetHeight()/resolution);
    for (int i=0; i<cols; i++) {
        for(int j=0;j<rows;j++){
            alpha=ofMap(ofNoise(i,j,incr),0,1,10,255);
            ofSetColor(21, 21, 21, alpha);
            ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        }
    }
    incr+=0.01;
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key=='a'){
        deg=2;
    }
    
    if(key=='s'){
        deg=123;
    }
    
    if(key=='d'){
        deg=244;
    }
}
