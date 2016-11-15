#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

#include "subtitle.h"

using namespace std;

int main(){
    Subtitle subtitle;
    SubtitleItem item;
    string arquivo;
    char c[256];
    long int delay = 0;

    cout << "digite o nome do arquivo:" << endl;

    cin.getline(c, 256);
    arquivo = c;

    cout << endl;

    if( subtitle.load( arquivo+".srt" ) ){
        cout << "\"" << Subtitle::addBar(arquivo+".srt") << "\" importado com sucesso!"  << endl;
        cout << "o arquivo possui: " << subtitle.size() << " itens de legenda." << endl << endl;
    }else{
        cout << "erro ao abrir " << Subtitle::addBar(arquivo+".srt") << endl;
        cout << "verifique a ortografia, evite acentos e espaços"  << endl;
        system("pause");
        return -1;
    }

    cout << "digite o tempo de atrazo, em milisegundos, desejado:" << endl;
    cout << "(para atrazar a legenda entre com um numero negativo)" << endl;
    cin >> delay;
    subtitle.delay_ms(delay);

    if( subtitle.save( arquivo+"2.srt" ) ){
        cout << "\"" << Subtitle::addBar(arquivo+"2.srt") << "\" salvo com sucesso" << endl;
        delay>0?cout<<delay<<" ms adiantado":cout<<delay*-1<<" ms atrazado";
        cout << endl;
    }else{
        cout << "erro ao salvar " << Subtitle::addBar(arquivo+"2.srt") << "\n\rverifique a ortografia, evite acentos e espaços"  << endl;
        system("pause");
        return -2;
    }

    system("pause");

    return 0;
}
