#include "subtitle.h"

void Subtitle::delay_ms(const long int ms){
    //for(SubtitleItem item : _itens){  //item.delay_ms(ms);
//    for(unsigned int i=0; i<_itens.size(); i++){
//        _itens[i].delay_ms(ms);
//    }
    for(unsigned int i=0; i<size(); i++){
        at(i).delay_ms(ms);
    }
}

bool Subtitle::load(const std::string name){
    //name = addBar(name);
    //std::ifstream fin( "\"" + name + "\"" );
    std::ifstream fin( name );
    if(!fin)
        return false;
    fin >> *this;
    fin.close();
    return true;
}

bool Subtitle::save(const std::string name){
    //name = addBar(name);
    //std::ofstream fout( "\"" + name + "\"" );
    std::ofstream fout( name );
    if(!fout)
        return false;
    fout << *this;
    fout.close();
    return true;
}

std::string Subtitle::addBar(const std::string& path){
    if(path.length()<3)
        return path;
    std::string res = path;

    std::size_t i = res.find('\\', 0);
    while( i<res.length()-1){
        if(res[i+1]!='\\')
            res.insert(i, "\\");
        i = res.find('\\', i+=2);
    }
    return res;
}

std::ostream& operator<<(std::ostream& os, Subtitle& obj){
	//for(unsigned int i=0; i<obj._itens.size(); i++){
	for(unsigned int i=0; i<obj.size(); i++){
		os << i+1 << "\n";
		//os << obj._itens[i];
		os << obj[i];
	}
	return os;
}
std::istream& operator>>(std::istream& is, Subtitle& obj){
	//obj.clear();
	int n;
	is >> n;
	while(!is.eof()){
		SubtitleItem i;
		is >> i;
		is >> n;
		//obj._itens.push_back(i);
		obj.push_back(i);
	}
	return is;
}
