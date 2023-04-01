#include <cyfscodificacion.h>

void codificacion::nombretrada(char _enter[]){
    cout<<"ingrese el nombre del archivo de entrada: ";
    cin.getline(_enter, sizeof(_enter));
}

void codificacion::nombresalida(char _out[]){
    cout<<"ingrese el nombre del archivo de salida: ";
    cin.getline(_out, sizeof(_out));
}

int potencia(int a, int b){
    int i=2;
    int pot=a;
    if (b==0){
        return 1;
    }
    while (i<=b){
        pot*=a;
        i++;
    }
    return pot;
}

int conversorcharint(char num[]){
    int mult=lon-1;
    int mult2=0;
    int numero=0;
    int numint=0;
    for (int i; i!='\0';i++){
        numero=static_cast<int>(num[i]) - 48;
        mult2=potencia(10,mult);
        numint+=numero*mult2;
        mult--;
    }
    return numint;
}

void decbinario(char a,char b[]){
   int numero=conversorcharint(a);
   int i=0;
   s=7;
   while (numero>=1){
        if (numero>=potencia(2,s)){
            b[i]='1';
            numero=numero-potencia(2,s);
        }
        else{
           b[i]='0';
        }
        i++;
        s--;
    }
}

void codificacion::metodo1(int _bits,int _metodo,char entrada[],char salida[]){
    int longitudentrada=0;
    int longitudsalida=0;
    char *binarios;
    ifstream fin;
    ofstream fout;
    try{
        fin.open(entrada);
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
    // Obtener la posición actual en el archivo
    streampos inicio = fin.tellg();

    // Mover la posición actual al final del archivo
    fin.seekg(0, ios::end);
    streampos fin2 = fin.tellg();

    // Calcular el número de caracteres en el archivo
    longitudentrada = static_cast<int>(fin2 - inicio);
    int con=0;
    int longitudentradamodificada=longitudentrada*8;
    while (longitudentradamodificada%_bits!=0){
        con++;
        longitudentradamodificada=longitudentradamodificada+con;
    }
    binarios=new char[(longitudentradamodificada)+1];
    char bi[9]={};
    int i=0;

    while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
        char temp=fin.get();
        if(fin.good()){
            decbinario(temp,bi);
            for (int s=0;bi[s]!='\0';s++){
                *(binario+i)=bi[s];
                i++;
            }
        }
    }
    i++;
    while(i<longitudentradamodificada){
        *(binario+i)='0';
    }

    fin.close();                //Cierra el archivo de lectura.
}
