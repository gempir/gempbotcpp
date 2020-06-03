/**
	windowsTime.h
	gempbot Project
	By: Robert F. (Phantom139)
**/

#if defined(gempbot_WINDOWS)

	#ifndef WINDOWS_TIME_H
	#define WINDOWS_TIME_H

		class Time : public GTime {
			public:
				static void sysTime(TimeVars &c);
				static void utcTime(TimeVars &c);
				static time_t makeGMTime(TimeVars &c);
		};

	#endif //WINDOWS_TIME_H

#endif //gempbot_WINDOWS