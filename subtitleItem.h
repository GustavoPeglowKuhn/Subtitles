#ifndef	_SUBTITLE_ITEM_H
#define	_SUBTITLE_ITEM_H

#include <String>

#include "subtitleTime.h"

class SubtitleItem{
private:
	SubtitleTime _t1, _t2;
	std::string _text;

public:
	SubtitleItem() : _t1(0,0,0,0), _t2(0,0,0,0), _text("\n\r") {}
	SubtitleItem(const SubtitleTime t1, const SubtitleTime t2, const std::string text) : _t1(t1), _t2(t2), _text(text) {}

	const void setItem(const SubtitleItem&);
	const void setItem(const SubtitleTime, const SubtitleTime, const std::string);

	const void delay_ms(const long int valor){ _t1+=valor; _t2+=valor; };
	const void operator+=(const long int valor){ delay_ms(valor); };
	const void operator-=(const long int valor){ delay_ms(-valor); };

	const inline void setText(const std::string text){ _text=text; };
	const inline std::string getText(){ return _text; };

	const inline void setTime1(const SubtitleTime t1){ _t1=t1; };
	const inline void setTime2(const SubtitleTime t2){ _t2=t2; };
	const inline SubtitleTime getTime1(){ return _t1; };
	const inline SubtitleTime getTime2(){ return _t2; };

	const inline bool operator> (const SubtitleItem& obj){ return _t1> obj._t1; };
	const inline bool operator< (const SubtitleItem& obj){ return _t1< obj._t1; };
	const inline bool operator>=(const SubtitleItem& obj){ return _t1>=obj._t1; };
	const inline bool operator<=(const SubtitleItem& obj){ return _t1<=obj._t1; };
	const inline bool operator==(const SubtitleItem& obj){ return _t1==obj._t1 && _t2==obj._t2 && _text==obj._text; };

	friend std::ostream& operator<<(std::ostream&, SubtitleItem&);
	friend std::istream& operator>>(std::istream&, SubtitleItem&);	//melhorar esse metodo posteriormente
};

#endif	//_SUBTITLE_ITEM_H

