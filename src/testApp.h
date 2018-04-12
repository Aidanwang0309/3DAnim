#pragma once

#include "ofMain.h"
#include "ofxBeat.h"

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
        ofMaterial material;
        vector<ofMeshFace> triangles;
        ofEasyCam easyCam;


    
};
