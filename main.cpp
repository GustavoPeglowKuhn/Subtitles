//#include <cstdio>
//#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

#include "subtitle.h"

using namespace std;

int main(int argc, char** argv){
    Subtitle subtitle;
    SubtitleItem item;
    string arquivo;
    char c[256];
    long int delay = 0;

    /*if(argc == 2){
        arquivo = argv[0];
        int a = itoa(argv[1]);
    }else{*/

        cout << "digite o nome do arquivo: " << endl;

        cin.getline(c, 256);
        arquivo = c;

        cout << endl;

        if( subtitle.load( arquivo ) ){
            cout << "\"" << Subtitle::addBar(arquivo) << "\" importado com sucesso!"  << endl;
            cout << "o arquivo possui: " << subtitle.size() << " itens de legenda." << endl << endl;
        }else{
            cout << "erro ao abrir " << Subtitle::addBar(arquivo) << endl;
            cout << "verifique a ortografia, evite acentos e espaços"  << endl;
            cout << "(nao esqueca de inserir a extensão do arquivo, geralmente \".srt\")" << endl;
            //system("pause");
            return -1;
        }

        cout << "digite o tempo de atrazo, em milisegundos, desejado:" << endl;
        cout << "(para atrazar a legenda entre com um numero negativo)" << endl;
        cin >> delay;
        subtitle.delay_ms(delay);

        cout << endl;

        if( subtitle.save( arquivo ) ){
            cout << "\"" << Subtitle::addBar(arquivo) << "\" salvo com sucesso" << endl;
            delay>0?cout<<delay<<" ms adiantado":cout<<delay*-1<<" ms atrazado";
            cout << endl;
        }else{
            cout << "erro ao salvar " << Subtitle::addBar(arquivo) << endl;
            cout << "verifique a ortografia, evite acentos e espaços"  << endl;
            //system("pause");
            return -2;
        }
    //}
    return 0;
}
