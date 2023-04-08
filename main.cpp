#include <iostream>
#include "codistream.h"
#include "decodificacioncaracteres.h"
#include "decostream.h"
#include "aplicacion.h"
#include "cyfscodificacion.h"

using namespace std;
void prueba();

int main()
{
    aplicacion();
    return 0;
}


void prueba(){
    ifstream fin;
    try{
        fin.open("usuarios.txt");
        if(!fin.is_open()){
            throw '1';

        }
    }
    catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='1'){
            cout<<"Error al abrir el archivo para escritura.\n";
        }
    }
    string a="";
    string b="";
    while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
        getline(fin,a);
        b=b+'\n'+a;
    }
    cout<<b;
}
