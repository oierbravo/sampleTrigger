#ifndef _SAMPLE_TRIGGER_SAMPLE
#define _SAMPLE_TRIGGER_SAMPLE

#include "ofMain.h"

class sampleTriggerSample //: public ofSoundPlayer
{
public:
	sampleTriggerSample();
	sampleTriggerSample(string file, int type, int mode);
	~sampleTriggerSample(void);

    void play();
    void play(int launch_mode);
	void stop();

	int type;
	int mode;
	string file;
    ofSoundPlayer player;
};

#endif
