#include "sampleTrigger.h"

//--------------------------------------------------------------
void sampleTrigger::setup(){
	XML.loadFile("mySettings.xml") ;

	prepareSamples();
	// listen on the given port
	int inport = XML.getValue("osc:inport", 12345);
	cout << "listening for osc messages on port " << inport << "\n";
	receiver.setup(inport);

	string outhost = XML.getValue("osc:outhost", "");
	int outport = XML.getValue("osc:outport", 12346);
	cout << "sending osc messages on " << outhost << ":" << outport << "\n";
	sender.setup(outhost,outport);


	current_msg_string = 0;
}

//--------------------------------------------------------------
void sampleTrigger::update(){
	// check for waiting messages
	while(receiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(&m);
		if(m.getAddress() == "/sampleTrigger/down"){
			// both the arguments are int32's
			int index = m.getArgAsInt32(0);
			//if(!samples[index].getIsPlaying()){

				samples[index]->play();
			//}
		}
		else if(m.getAddress() == "/sampleTrigger/up"){
			int index = m.getArgAsInt32(0);
		//	cout << index << '\n';
			samples[index]->stop();
		}
		else if(m.getAddress() == "/sampleTrigger/0"){
			ofLogVerbose("prueba");
			float param = m.getArgAsFloat(0);
			if(param == 0){
			  samples[0]->stop();
			} else {
				//TODO: velocity from param
			  samples[0]->play();
			}
		}
		else if(m.getAddress() == "/sampleTrigger/1"){
			float param = m.getArgAsFloat(0);
			if(param == 0){
			  samples[1]->stop();
			} else {
				//TODO: velocity from param
			  samples[1]->play();
			}
		}
		else if(m.getAddress() == "/sampleTrigger/0"){
			float param = m.getArgAsFloat(0);
			if(param == 0){
			  samples[0]->stop();
			} else {
				//TODO: velocity from param
			  samples[0]->play();
			}
		}
		else if(m.getAddress() == "/sampleTrigger/1"){
			float param = m.getArgAsFloat(0);
			if(param == 0){
			  samples[1]->stop();
			} else {
				//TODO: velocity from param
			  samples[1]->play();
			}
		}
		else if(m.getAddress() == "/sampleTrigger/2"){
			float param = m.getArgAsFloat(0);
			if(param == 0){
			  samples[2]->stop();
			} else {
				//TODO: velocity from param
			  samples[2]->play();
			}
		}
		else if(m.getAddress() == "/sampleTrigger/3"){
			float param = m.getArgAsFloat(0);
			if(param == 0){
			  samples[3]->stop();
			} else {
				//TODO: velocity from param
			  samples[3]->play();
			}
		}


		else if(m.getAddress() == "/sampleTrigger/numsamples"){
			cout << ">> /sampleTrigger/numsamples\n";
			//cout << "numSamples: " << numSamples << "\n";
			ofxOscMessage output;
			output.setAddress("/sampleTrigger/numsamples");
			output.addIntArg(numSamples);
			sender.sendMessage(output);
		}
	}
}

//--------------------------------------------------------------
void sampleTrigger::draw(){

}

//--------------------------------------------------------------
void sampleTrigger::keyPressed(int key){

}

//--------------------------------------------------------------
void sampleTrigger::keyReleased(int key){

}

//--------------------------------------------------------------
void sampleTrigger::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void sampleTrigger::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void sampleTrigger::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void sampleTrigger::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void sampleTrigger::windowResized(int w, int h){

}

//--------------------------------------------------------------
void sampleTrigger::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void sampleTrigger::dragEvent(ofDragInfo dragInfo){

}

void sampleTrigger::prepareSamples(){
	int numSampleGroups = XML.getNumTags("samples:sample");
	if(numSampleGroups > 0){
		XML.pushTag("samples", numSampleGroups-1);
		//cout << "num samples: " << numSamples << "\n";

		numSamples = XML.getNumTags("sample");

		for(int i = 0;i < numSamples; i++){
			string sampleSrc = XML.getValue("sample","default.wav",i);

			cout << "loading: " << sampleSrc;

			int type = XML.getAttribute("sample","type",0,i);
			cout << " as: " << type << "\n" ;
            int mode =  XML.getAttribute("sample","mode",0,i);
			/*ofSoundPlayer sample;
			sample.loadSound(sampleSrc);
			if(type == 1){
				sample.setLoop(true);
			}*/

            //sampleTriggerSample sample;
            //sample =  new sampleTriggerSample(sampleSrc,type);
			sampleTriggerSample* sample = new sampleTriggerSample(sampleSrc,type,mode);

			samples.push_back(sample);
		}
		XML.popTag();
	}

}
