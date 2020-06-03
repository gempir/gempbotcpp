/**
    gempbot.cpp
    gempbot Project
    By: Robert F. (Phantom139)
**/

#include "gempbot.h"


/*
 gempbot Class
*/
gempbot::gempbot() : irc(NULL) {
	initialized = false;
	wantsQuit = false;
}

gempbot::~gempbot() {

}

gempbot &gempbot::fetchInstance() {
	if (managedSingleton<gempbot>::instance() == NULL) {
		managedSingleton<gempbot>::createInstance();
	}
	return *(managedSingleton<gempbot>::instance());
}


void gempbot::init(vector<string> &conf) {
	if (initialized) {
		return;
	}
	//Initialize IRC Module and Input Module
	irc = new TwitchIRC(conf[0].c_str(), conf[0].c_str(), conf[4].c_str(), conf[1].c_str(), (U32)atoi(conf[2].c_str()), conf[3].c_str());
	initialized = true;
	run();
}

void gempbot::run() {
	while (irc->SocketActive()) {
		irc->Update();
	}
}

/*

 MAIN METHOD
 ENTRY POINT

*/

int main(void) {
	srand((U32)time(NULL));
	//read the config
	ACHAR line[512];
	vector<string> config;
	fstream f("botconfig.txt", ios::in);
	while(!f.eof()) {
		f.getline(line, 512);
		config.push_back(line);
		memset(&line[0], 0, sizeof(line));
	}
	//Set stuff up...
	if(config.size() >= 5) {
		gempbot::fetchInstance().init(config);
	}
	else {
		cout << "There was an error in your 'botconfig.txt' file, contact Phantom139 for support" << endl;
	}
	cout << "Closing program..." << endl;
	return 0;
}
