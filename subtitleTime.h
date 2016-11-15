#ifndef _SUBTITLE_TIME_H
#define _SUBTITLE_TIME_H

#include <iostream>

class SubtitleTime{
private:
	long int _time;

public:
	SubtitleTime() : _time(0) {}
	SubtitleTime(const long int time) : _time(time) {}
	SubtitleTime(const short int h, const short int m, const short int s, const int ms) : _time( ((h*60+m)*60+s)*1000+ms ) {}

	const inline void setTime(SubtitleTime& obj){ _time = obj.getTime(); }
	const inline void setTime(const short int h, const short int m, const short int s, const int ms){ _time = ((h*60+m)*60+s)*1000+ms; }
	const inline void setTime(const int time){ _time = time; }
	const inline long int getTime(){ return _time; }

	const inline bool operator> (const SubtitleTime& obj){ return _time> obj._time; }
	const inline bool operator< (const SubtitleTime& obj){ return _time< obj._time; }
	const inline bool operator>=(const SubtitleTime& obj){ return _time>=obj._time; }
	const inline bool operator<=(const SubtitleTime& obj){ return _time<=obj._time; }
	const inline bool operator==(const SubtitleTime& obj){ return _time==obj._time; }

	const inline void operator+=(SubtitleTime& obj){ _time+=obj._time; }
	const inline void operator-=(SubtitleTime& obj){ _time-=obj._time; }
	const inline void operator+=(int valor){ _time+=valor; }
	const inline void operator-=(int valor){ _time-=valor; }

	const inline SubtitleTime operator+(SubtitleTime obj){ return SubtitleTime(_time+obj._time); }
	const inline SubtitleTime operator-(SubtitleTime obj){ return SubtitleTime(_time-obj._time); }
	const inline SubtitleTime operator+(int valor){ return SubtitleTime(_time+valor); }
	const inline SubtitleTime operator-(int valor){ return SubtitleTime(_time-valor); }

	friend std::ostream& operator<<(std::ostream&, SubtitleTime&);
	friend std::istream& operator>>(std::istream&, SubtitleTime&);
};

#endif	//_SUBTITLE_TIME_H

