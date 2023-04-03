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

int longitud(char a[]){
    int i = 0;
    int con;
    for (i=0;a[i] != '\0';i++){
        con++;
    }
    return i;
}

int conversorcharint(char num){
    int numint=num;
    return numint;
}

void decbinario(char a,char b[]){
   int numero=conversorcharint(a);
   int i=0;
   int s=7;
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

void cambiaposicion(char a[]){
    int lon=longitud(a);
    char primero=a[0];
    for (int i=1; i<lon;i++){
        a[i-1]=a[i];
    }
    a[lon-1]=primero;
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
                *(binarios+i)=bi[s];
                i++;
            }
        }
    }
    fin.close();
    i++;
    while(i<longitudentradamodificada){
        *(binarios+i)='0';
    }
    int con1=0,con0=0,clave=1;
    char codi[_bits+1]={};
    con=0;
    for (int i=0;i<longitudentradamodificada;i++){
        con++;
       if (con<=_bits && clave == 1){
          if (*(binarios+i)=='1'){
                *(binarios+i)='0';
            }
          else{
                 *(binarios+i)='1';
            }
          if (con==_bits){
              con=0;
              clave=0;
          }
        }
       else if(con<=_bits){
           codi[con-1]=*(binarios+i);
           if (*(binarios+i)=='1'){
               con1++;
           }
           else{
               con0++;
           }
           if (con==_bits && con1==con0){
               for (int s=0; s<_bits;s++){
                   int ite=i-s;
                   if (codi[s]=='1'){
                       codi[s]='0';
                       *(binarios+ite)=codi[s];
                   }
                   else{
                       codi[s]='1';
                       *(binarios+ite)=codi[s];
                   }
               }
           }
           if (con==_bits && con1<con0){
               int saltos=0;
               for (int s=0; s<_bits;s++){
                   int ite=i-s;
                   saltos++;
                   if (saltos == 2 && codi[s]=='1'){
                       codi[s]='0';
                       *(binarios+ite)=codi[s];
                       saltos=0;
                   }
                   else if(saltos == 2 && codi[s]=='0'){
                       codi[s]='1';
                       *(binarios+ite)=codi[s];
                       saltos=0;
                   }
               }
           }
           if (con==_bits && con1>con0){
               int saltos=0;
               for (int s=0; s<_bits;s++){
                   int ite=i-s;
                   saltos++;
                   if (saltos == 3 && codi[s]=='1'){
                       codi[s]='0';
                       *(binarios+ite)=codi[s];
                       saltos=0;
                   }
                   else if(saltos == 3 && codi[s]=='0'){
                       codi[s]='1';
                       *(binarios+ite)=codi[s];
                       saltos=0;
                   }
               }
           }
           con=0;
           con1=0;
           con0=0;
       }

    }
    try{
        fout.open(salida);
        if(!fout.is_open()){
            throw '2';

        }
    }
    catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='2'){
            cout<<"Error al abrir el archivo para lectura.\n";
        }
    }
    fout.write(binarios,longitudentradamodificada);
    fout.close();
}

void codificacion::metodo2(int _bits,int _metodo,char entrada[],char salida[]){
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
                *(binarios+i)=bi[s];
                i++;
            }
        }
    }
    fin.close();
    i++;
    while(i<longitudentradamodificada){
        *(binarios+i)='0';
    }
    con=0;
    for (int i=0;i<longitudentradamodificada;i++){
        con++;
        char separador[_bits];
        if (con<_bits){
            separador[con-1]=*(binarios+i);
        }
        else{
            separador[con-1]=*(binarios+i);
            cambiaposicion(separador);
            for (int s=0;s<_bits;s++){
                int t=i-(_bits-1)+s;
                *(binarios+t)=separador[s];
                con=0;
            }
        }
    }
    try{
        fout.open(salida);
        if(!fout.is_open()){
            throw '2';

        }
    }
    catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='2'){
            cout<<"Error al abrir el archivo para lectura.\n";
        }
    }
    fout.write(binarios,longitudentradamodificada);
    fout.close();
}


