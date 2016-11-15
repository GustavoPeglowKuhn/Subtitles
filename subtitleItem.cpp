#include "subtitleItem.h"

const void SubtitleItem::setItem(const SubtitleItem& obj){
	_t1 = obj._t1;
	_t2 = obj._t2;
	_text = obj._text;
}

const void SubtitleItem::setItem(const SubtitleTime t1, const SubtitleTime t2, const std::string text){
	_t1 = t1;
	_t2 = t2;
	_text = text;
}

std::ostream& operator<<(std::ostream& os, SubtitleItem& obj){
	os << obj._t1 << " --> " << obj._t2 << "\n";
	os << obj._text << "\n";
	return os;
}

std::istream& operator>>(std::istream& is, SubtitleItem& obj){
	is >> obj._t1;
	is.ignore(5);
	is >> obj._t2;
	is.ignore(1,'\n');

	obj._text = "";
	bool repeat = true;
	while(repeat){
		char line[256];
		is.getline(line, 256);
		if(line[0] == '\n' || line[0] == '\r' || line[0] == '\0' || is.eof()){
			repeat = false;
		}else{
			obj._text += line;
			obj._text +=  "\n";
		}
	}
	return is;
}
