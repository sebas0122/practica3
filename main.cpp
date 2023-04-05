#include <iostream>
#include "cyfscodificacion.h"
#include "decodificacioncaracteres.h"

using namespace std;
void prueba();

int main()
{
    deco();
    return 0;
}


void prueba(){
    ifstream fin;
    try{
        fin.open("caracteres.txt");
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
    while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
        char temp=fin.get();
    }
}
