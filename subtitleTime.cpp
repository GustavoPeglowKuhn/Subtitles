#include "subtitleTime.h"

std::ostream& operator<<(std::ostream& os, SubtitleTime& obj){
    long int aux = obj._time;
	short int h, m, s;
	int ms;
	bool neg;
	if(aux<0){
        neg = true;
        aux*=-1;
	}else{
	    neg = false;
	}

	ms = aux%1000;
	aux /= 1000;
	s = aux%60;
	aux /= 60;
	m = aux%60;
	aux /= 60;
	h = aux;

    if(neg)     os << "-";
	if(h<10)	os << "0";
	os << h << ":";
	if(m<10)	os << "0";
	os << m << ":";
	if(s<10)	os << "0";
	os << s << ",";
	if(ms<10)	os << "00";
	else if(ms<100)	os << "0";
	os << ms;

	return os;
}

std::istream& operator>>(std::istream& is, SubtitleTime& obj){
	short int h, m, s;
	int ms;
	is >> h;
	is.ignore(1,':');
	is >> m;
	is.ignore(1,':');
	is >> s;
	is.ignore(1,',');
	is >> ms;
	obj._time = ((h*60+m)*60+s)*1000+ms;
	return is;
}
