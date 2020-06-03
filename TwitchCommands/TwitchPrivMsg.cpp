/**
    TwitchPrivMsg.cpp
    gempbot Project
    By: Robert F. (Phantom139)
**/

#include "TwitchCommandProcess.h"

bool TwitchPrivMsg::Process(const string incoming) {
    string name, message;
    //Strip the username and their message
	Lib::stripMessage(incoming, name, message);
    //Push to log / console
    cout << "Chat: " << name << ": " << message << endl;
    Lib::writeToLog("gempbotLog.txt", "{Chat} " + name + ": " + message);	    
    
    if(!Admin::fetchInstance().CheckAdminStatus(name)) {
        //Out of luck, kill here...
        return true;
    }

    TwitchCommandLimit::fetchInstance().AddCommand(Lib::formatChatMessage("Yeah but bttv is like a 3rd party thing and idk"));

	return true;
}

TwitchPrivMsg &TwitchPrivMsg::fetchInstance() {
	if(managedSingleton<TwitchPrivMsg>::instance() == NULL) {
		managedSingleton<TwitchPrivMsg>::createInstance();
	}
	return *(managedSingleton<TwitchPrivMsg>::instance());
}
