#ifndef	_SUBTITLE_H_
#define	_SUBTITLE_H_

#include <iostream>
#include <fstream>
#include <vector>

#include "subtitleItem.h"

class Subtitle : public std::vector<SubtitleItem>{
private:
//	std::vector<SubtitleItem> _itens;

public:
    Subtitle(){};
//	Subtitle(std::vector<SubtitleItem> itens) : _itens(itens) {}

//	const inline int size(){ return _itens.size(); }
//	const inline void clear(){ _itens.clear(); }
//  const inline void add(const SubtitleItem item){ _itens.push_back(item); }
    //const inline void sort(){ _itens.sort(); }

    void delay_ms(const long int ms);

    bool load(const std::string);
    bool save(const std::string);

	friend std::ostream& operator<<(std::ostream&, Subtitle&);
	friend std::istream& operator>>(std::istream&, Subtitle&);

	static std::string addBar(const std::string&);  //para windows precisa ser '\\' no lugar de '\'
};

#endif	//_SUBTITLE_H_

