#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //grid();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    grid.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  //grid.doMove(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch(key){
        case 'w':
            grid.doMove((Directions)0);
            break;
        case 'd':
 grid.doMove((Directions)1);
            break;
        case 's':
 grid.doMove((Directions)2);
            break;
        case 'a':
 grid.doMove((Directions)3);
            break;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    grid.clickOn(x, y);
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
