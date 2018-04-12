#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(30);
    ofEnableSmoothing();
    
    ofSetSphereResolution(24);
    
    //3D Obj
    float width     = ofGetWidth() * .15;
    float height    = ofGetHeight() * .15;
    
    sphere.setRadius( width );


    
    //Sound
    ofSoundStreamSetup(0, 1, this, 44100, beat.getBufferSize(), 4);
}

//--------------------------------------------------------------
void testApp::update(){
    
  beat.update(ofGetElapsedTimeMillis());
}

//--------------------------------------------------------------
void testApp::draw(){
    
    float spinX = sin(ofGetElapsedTimef()*.35f);
    float spinY = cos(ofGetElapsedTimef()*.075f);
    
    easyCam.begin();
    // draw sphere
    sphere.setPosition(ofGetWidth()*.5f, ofGetHeight()*.5, 0);
    sphere.rotate(spinX, 1.0, 0.0, 0.0);
    sphere.rotate(spinY, 0, 1.0, 0.0);
    
    sphere.setMode( OF_PRIMITIVE_TRIANGLES );
    triangles = sphere.getMesh().getUniqueFaces();
    //Returns: the mesh as a vector of unique ofMeshFaces a list of triangles that do not share vertices or indices
    
    material.begin();
    ofFill();
    
    float kickDetection = beat.kick();
//    cout << kinkDetection << endl;
//    float strength = ofMap(kickDetection, 0, 1, -30 , 30);
//        cout << strength << endl;

    float angle = ofGetElapsedTimef()*3.2;
    float strength = (sin( angle ) * ofMap(kickDetection, 0, 1, -20 , 10));
//    cout << strength << endl;

    ofVec3f faceNormal;
    
    for(int i = 0; i < triangles.size(); i++ ) {
        // store the face normal here.
        // we change the vertices, which makes the face normal change
        // every time that we call getFaceNormal //
        faceNormal = triangles[i].getFaceNormal();
        for(int j = 0; j < 3; j++ ) {
            triangles[i].setVertex( j, triangles[i].getVertex(j) + faceNormal * strength);
        }
    }
    sphere.getMesh().setFromTriangles( triangles );
    sphere.draw();
    material.end();
    easyCam.end();
    
    
    ofSetColor(0, 139, 139);
//    float kick = beat.kick();
//    float kickRadious = ofMap(kick, 0, 1, 0, 100);
//    ofDrawCircle(150, 200, kickRadious);
//    ofDrawBitmapString("kick", 150 - 20, 50);
//    float snare = beat.snare();
//    float snareRadious = ofMap(snare, 0, 1, 0, 100);
//    ofDrawCircle(400, 200, snareRadious);
//    ofDrawBitmapString("snare", 400 - 20, 50);
//    float hihat = beat.hihat();
//    float hihatRadious = ofMap(hihat, 0, 1, 0, 100);
//    ofDrawCircle(650, 200, hihatRadious);
//    ofDrawBitmapString("hihat", 650 - 20, 50);
//
//    ofDrawBitmapString("fft", 100, 330);
//    for(int i = 0; i < 32; i++){
//        float band = beat.getBand(i);
//        float height = band * 100 < 300 ? band * 100: 300;
//        ofDrawRectangle(80 + i * 20, 650 - height, 20, height);
//    }
}


void testApp::audioReceived(float* input, int bufferSize, int nChannels) {
  beat.audioReceived(input, bufferSize, nChannels);
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
