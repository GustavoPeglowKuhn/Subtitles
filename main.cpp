//#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <conio.h>

#include "subtitle.h"
#include "mensagens.h"

using namespace std;

bool abrir(Subtitle&, const string);
bool salvar(Subtitle&, const string, const long int);

int main(int argc, char** argv){
    Subtitle subtitle;
    SubtitleItem item;
    string arquivo;
    char c[256];
    long int delay = 0;

    //ASCII ART
    //cout << endl << THOR << endl << endl;

//    for(unsigned int i=0; i<argc; i++)
//        cout << "debug: argv[" <<i<< "] = " << argv[i] << endl;

    if(argc == 2 && (string)argv[1] == "-help"){
        cout << endl << HELP << endl;
    }else if(argc == 2){
        arquivo = Subtitle::addBar( (string)argv[1] );
        if( !abrir(subtitle, arquivo) )
            return -1;
        cout << "\"" << arquivo << "\" " << LOAD_OK << endl;
        cout << FILE_INFO1 << subtitle.size() << FILE_INFO2 << endl << endl;

        cout << ASK_DELAY << endl;
        cin >> delay;
        subtitle.delay_ms(delay);
        cout << endl;
        if( !salvar(subtitle, arquivo, delay) ){
            getch();//system("pause");
            return -2;
        }
        cout << "\"" << arquivo << "\" " << SAVE_OK << endl;
        delay>0? cout<<delay<<ADIANTADO : cout<<-delay<<ATRAZADO;
        getch();
        return 0;
    }else if(argc == 3){
        arquivo = Subtitle::addBar( (string)argv[1] );
        istringstream ss(argv[2]);
        ss >> delay;
        if( !abrir(subtitle, arquivo) )
            return -1;
        subtitle.delay_ms(delay);
        if( !salvar(subtitle, arquivo, delay) )
            return -2;
    }else{

        cout << ASK_FILE << endl;

        cin.getline(c, 256);
        arquivo = Subtitle::addBar( (string)c );

        cout << endl;

        if( !abrir(subtitle, arquivo) )
            return -1;
        cout << "\"" << arquivo << "\" " << LOAD_OK << endl;
        cout << FILE_INFO1 << subtitle.size() << FILE_INFO2 << endl << endl;

        cout << ASK_DELAY << endl;
        cin >> delay;
        subtitle.delay_ms(delay);

        cout << endl;

        if( !salvar(subtitle, arquivo, delay) )
            return -2;
    }
    cout << "\"" << arquivo << "\" " << SAVE_OK << endl;
    delay>0? cout<<delay<<ADIANTADO : cout<<-delay<<ATRAZADO;
    cout << endl;
    return 0;
}

bool abrir(Subtitle& subtitle, const string nome){
    if( subtitle.load( nome ) ){
        return true;
    }else{
        cout << LOAD_ERROR1 << "\"" << nome << "\"" << endl;
        cout << LOAD_ERROR2 << endl;
        return false;
    }
}

bool salvar(Subtitle& subtitle, const string nome, const long int delay){
    if( subtitle.save( nome ) ){
        return true;
    }else{
        cout << SAVE_ERROR1 << "\"" << nome << "\"" << endl;
        cout << SAVE_ERROR2 << endl;
        cout << SAVE_ERROR3 << endl;
        return false;
    }
}
