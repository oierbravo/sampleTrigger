#include "sampleTriggerSample.h"

sampleTriggerSample::sampleTriggerSample(void)
{
}
sampleTriggerSample::~sampleTriggerSample(void)
{
}
sampleTriggerSample::sampleTriggerSample(string file, int type, int mode){
	this->type = type;
	this->file = file;
	this->mode = mode;
	//ofLog(OF_LOG_NOTICE,"Loading file " + file + "as:" + type);

	this->player.loadSound(file);
	if(type == 1){
		this->player.setLoop(true);
	}
}



void sampleTriggerSample::play(int launch_mode){
	switch(launch_mode){
        case 0:
            this->player.play();
            break;
        case 1:
            this->player.play();
            break;
        case 2:
            if(this->player.getIsPlaying()){
              this->player.stop();

            } else {
              this->player.play();
            }
            break;
        default:
            this->player.play();
            break;
	}
}
void sampleTriggerSample::play(){
    this->play(this->mode);
}
void sampleTriggerSample::stop(){
	switch(this->mode){
        case 0:
            break;
        case 1:
            this->player.stop();
            break;
        case 2:
            break;
        default:
            this->player.stop();
            break;
	}

}
