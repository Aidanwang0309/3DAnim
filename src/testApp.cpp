#include "testApp.h"
//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(30);
    ofEnableSmoothing();
    ofDisableAlphaBlending();
    ofEnableDepthTest();
    
//---------Shader Loading

    shader.load("shadersGL2/shader");

//---------Lights Enable
    light1.enable();
    light1.setPosition(ofVec3f(-50,0,100));
    light1.lookAt(ofVec3f(0,0,0));
    
    light2.setDiffuseColor( ofFloatColor( 238.f/255.f, 57.f/255.f, 135.f/255.f ));
    light2.setSpecularColor(ofFloatColor(.8f, .8f, .9f));
    
    light3.setDiffuseColor( ofFloatColor(19.f/255.f,94.f/255.f,77.f/255.f) );
    light3.setSpecularColor( ofFloatColor(18.f/255.f,150.f/255.f,135.f/255.f) );
    
//---------Texture loading
    ofDisableArbTex();
    ofLoadImage(mTex, "test.jpg");
    
//---------3D Obj Parameter
    float width     = ofGetWidth() * .35;
    float height    = ofGetHeight() * .35;
    sphere.setRadius( width );
    ofSetSphereResolution(24);
    
//---------Object Drawing
    for (int i=0; i<NUM; i++) {
        stars[i].setPosition(ofRandom(-500,500), ofRandom(-500,500), ofRandom(-500,500));
        stars[i].set(ofRandom(5,20), 10);
    };
    
//---------Sound Setup
    ofSoundStreamSetup(0, 1, this, 44100, beat.getBufferSize(), 4);
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){

//---------Beats Detection
  beat.update(ofGetElapsedTimeMillis());
    
//---------Light Update
light2.setPosition((ofGetWidth()*.5)+ cos(ofGetElapsedTimef()*.15)*(ofGetWidth()*.3),
                    ofGetHeight()*.5 + sin(ofGetElapsedTimef()*.7)*(ofGetHeight()), -300);
    
light3.setPosition( cos(ofGetElapsedTimef()*1.5) * ofGetWidth()*.5,
                    sin(ofGetElapsedTimef()*1.5f) * ofGetWidth()*.5,
                    cos(ofGetElapsedTimef()*.2) * ofGetWidth()
                   );
}

//--------------------------------------------------------------
void testApp::draw(){
    
//---------Object Auto Rotating
    float spinX = sin(ofGetElapsedTimef()*.35f);
    float spinY = cos(ofGetElapsedTimef()*.075f);
    
    
//---------easyCam Init
    easyCam.begin();

//---------Planet Drawing
    sphere.setPosition(ofGetWidth()*.5f, ofGetHeight()*.5, 0);
    sphere.rotate(spinX, 1.0, 0.0, 0.0);
    sphere.rotate(spinY, 0, 1.0, 0.0);
    
    sphere.setMode( OF_PRIMITIVE_TRIANGLES );
    triangles = sphere.getMesh().getUniqueFaces();
    material.begin();
    ofFill();
    
    ofVec3f faceNormal;
    float kickDetection = beat.kick();
    float angle = ofGetElapsedTimef()*3.2;
    float strength = (sin( angle ) * ofMap(kickDetection, 0, 1, -3 , 3));
    
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
    mTex.bind();
    sphere.draw();
    mTex.unbind();
    material.end();
    
    //---------Debug
    //    cout << strength << endl;
    //    cout << kinkDetection << endl;
    //    float strength = ofMap(kickDetection, 0, 1, -30 , 30);
    //    cout << strength << endl;
    
//---------Star Drawing
    shader.begin();
    ofPushMatrix();
    ofSetColor(255, 255, 0);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateY(ofGetElapsedTimef() * strength / 5);
    for (int i=0; i< NUM; i++) {
        stars[i].draw();
    }
    ofPopMatrix();
    shader.end();
//---------easyCam End
    easyCam.end();


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
