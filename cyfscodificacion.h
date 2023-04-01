#ifndef CYFSCODIFICACION_H
#define CYFSCODIFICACION_H
#include <iostream>
#include <fstream>

using namespace std;
class codificacion{
public:
    int bits=0;                  //numero que le nos dira en cuantos bits hay que dividir el binario
    int metodo=0;                //nos dira que metodo usaramos para codificar
    char enter[100]="";          //nombre del archivo de entrada
    char out[100]="";            //archivo de salida
    void nombretrada(char _enter[]);
    void nombresalida(char _out[]);
    void metodo1(int _bits,int _metodo,char entrada[],char salida[]);
    void metodo2(int _bits,int _metodo,char entrada[],char salida[]);
};
int potencia(int a, int b);
int conversorcharint(char num[]);
void decbinario(char a,char b[]);
int longitud(char a[]);
#endif // CYFSCODIFICACION_H
