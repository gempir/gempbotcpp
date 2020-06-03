/**
	linuxTime.h
	gempbot Project
	By: Robert F. (Phantom139)
**/

#if defined(gempbot_LINUX)

	#ifndef LINUX_TIME_H
	#define LINUX_TIME_H

		class Time : public GTime { 
			public:

				static time_t makeGMTime(TimeVars &c) {
					struct tm tm;
					memset(&tm, 0, sizeof(tm));

					tm.tm_year = c.years - 1900;
					tm.tm_mon = c.months - 1;
					tm.tm_mday = c.dayNum;
					tm.tm_hour = c.hours;
					tm.tm_min = c.minutes;
					tm.tm_sec = c.seconds;
					tm.tm_isdst = -1;

					return mktime(&tm);
				}

		};

	#endif //LINUX_TIME_H

#endif //gempbot_LINUX
