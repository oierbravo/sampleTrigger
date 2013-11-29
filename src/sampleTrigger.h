#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxXmlSettings.h"
#include "sampleTriggerSample.h"

// listen on port 12345
#define PORT 12345
#define NUM_MSG_STRINGS 20

class sampleTrigger : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxOscSender sender;
		ofxOscReceiver receiver;

		int current_msg_string;
		string msg_strings[NUM_MSG_STRINGS];
		float timers[NUM_MSG_STRINGS];

		ofxXmlSettings XML;

		int numSamples;
		vector<sampleTriggerSample*> samples;
	private:
		//vector<ofSoundPlayer> samples;

		void prepareSamples();

};
