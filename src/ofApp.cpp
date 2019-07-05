#include "ofApp.h"

using namespace ofxCv;
//--------------------------------------------------------------
void ofApp::setup(){

    filesize=0;
    k=0;

}

//--------------------------------------------------------------
void ofApp::update(){


    if(k <filesize) {
            img1.load(filePath[k]);
        //img1.setImageType(OF_IMAGE_COLOR);
            img1.update();
        
        cv::Mat before= toCv(img1);
        cv::Mat after= before.clone();
        cv::flip(before, after, 1);     // 0< h, 0= v, 0> h+v
        toOf(after, img2);
        img2.update();
        // save
        string filename = ofGetTimestampString()+".png";
        img2.save(filename);
    }
    k += 1;
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(50, 50, 50);
    ofSetColor(0, 0, 0);
    ofDrawBitmapStringHighlight("Drag and Drop a image file",
                                ofGetWidth()/2-100,
                                ofGetHeight()-20);
    
    if(img1.getWidth() !=0 ) {
    //fBackground(0);
    ofSetColor(255);
    img1.draw(0,0, 512, 512);
    img2.draw(512,0, 512, 512);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
    
    if( dragInfo.files.size() > 0 ){
        
        filesize= dragInfo.files.size();
        
        img1.load(dragInfo.files[0]);


        // all file
        for(int i = 0; i < dragInfo.files.size(); i++){
            //ofLog() << i << "files, " << dragInfo.files[i] << endl;
            filePath[i] = dragInfo.files[i];
        }
    }

}
