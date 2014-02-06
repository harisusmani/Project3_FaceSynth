#pragma once

#include "ofMain.h"
#include "ofxCv.h"

#include "ofxFaceTracker.h"
#include "ofxOsc.h"
#include "ofxXmlSettings.h"

//ofxMIDI
#include "ofMain.h"
#include "../../src/ofxMidi.h"

class testApp : public ofBaseApp {
public:
	void loadSettings();

	void clearBundle();
	template <class T>
	void addMessage(string address, T data);
	void sendBundle();

	void setup();
	void update();
	void draw();
	void exit(); //ofxMIDI
	void keyPressed(int key);

	void setVideoSource(bool useCamera);

	bool bUseCamera, bPaused;

	int camWidth, camHeight;
	int movieWidth, movieHeight;
	int sourceWidth, sourceHeight;

	string host;
	int port;
	ofxOscSender osc;
	ofxOscBundle bundle;

	ofVideoGrabber cam;
	ofVideoPlayer movie;
	ofBaseVideoDraws *videoSource;

	ofxFaceTracker tracker;
	float scale;
	ofMatrix4x4 rotationMatrix;

	bool bDrawMesh;

	//ofxMIDI
	ofxMidiOut midiOut;
	int channel;

	unsigned int currentPgm;
	int note, velocity;
	int pan, bend, touch, polytouch;
};
