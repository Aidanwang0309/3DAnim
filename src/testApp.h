#pragma once

#include "ofMain.h"
#include "ofxBeat.h"
#include "ofxPostProcessing.h"


#define NUM 50
#define SIZE 10

class testApp : public ofBaseApp{
  
	public:
		void setup();
		void update();
		void draw();
 
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
// Audio
        void audioReceived(float*, int, int);
        ofxBeat beat;
// 3D Obj
        ofSpherePrimitive sphere;
    
        ofSpherePrimitive stars[NUM];
        ofMaterial material;
    
        ofLight light1;
        ofLight light2;
        ofLight light3;
    
        ofTexture mTex;
        vector<ofMeshFace> triangles;
        ofEasyCam easyCam;
// shader
        ofShader shader;

};
