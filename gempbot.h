/**
	gempbot.h
	gempbot Project
	By: Robert F. (Phantom139)
**/

#include "include.h"
#include "TwitchIRC/TwitchIRC.h"

#ifndef PHANTOM_BOT_H
#define PHANTOM_BOT_H

class gempbot {
	public:
		gempbot();
		~gempbot();

		static gempbot &fetchInstance();
		void init(vector<string> &config);

	private:
		void run();

		bool initialized;
		bool wantsQuit;

		TwitchIRC *irc;
};

#endif //PHANTOM_BOT_H