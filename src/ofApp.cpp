#include "ofApp.h"

const int padding = 20;
const int segment_count = 8;
const int dy = 100;
const int line_count = 10;

float frame_count = 0;


int rangeBottom = 100;
int rangeTop = 700;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 150);
//    ofSetBackgroundAuto(false);
    ofSetColor(255);
    ofSetCircleResolution(100);
    mFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    mFbo.begin();
//    ofClear(255,255,255, 0);
    
    ofSetColor(0, 3);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(255);
    
    for(int i = 0 ; i < line_count ; i++) {
        
        float rBottom = ofGetHeight()/2 - i*30;
        float rTop = ofGetHeight()/2 + i*30;
        
        ofPolyline line;
        float dx = (ofGetWidth() - padding*2) / (segment_count);
        for(int j = 0 ; j <= segment_count ; j++) {
            float x = padding + j*dx;
            float y_pos = ofGetHeight()/2;
            if(j > 0 && j < segment_count) {
                float n = ofNoise(frame_count);
                y_pos = ofMap(ofNoise(frame_count/200 + i, j*100),0,1,rBottom, rTop);
                line.curveTo(x,y_pos);
            } else {
                line.curveTo(x,y_pos);
                line.curveTo(x,y_pos);
            }
            
            
        }
        
        line.draw();
    }
    
    
    mFbo.end();
    mFbo.draw(0, 0);
    

    
    frame_count++;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's') {
        ofSaveScreen(ofToString(ofGetFrameNum())+".png");
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
