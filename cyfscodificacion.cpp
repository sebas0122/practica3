#include <cyfscodificacion.h>

void nombretrada(char _enter[]){
    cout<<"ingrese el nombre del archivo de entrada: ";
    cin.getline(_enter, sizeof(_enter));
}

void nombresalida(char _out[]){
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
   while (i<8){
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
    char primero=a[lon-1];
    for (int i=lon-1; i>0;i--){
        a[i]=a[i-1];
    }
    a[0]=primero;
}

void metodo1(int _bits,int _metodo,char entrada[],char salida[]){
    int longitudentrada=0;
    int longitudsalida=0;
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
    int longitudentradamodificada=longitudentrada*8;
    while (longitudentradamodificada%_bits!=0){
        longitudentradamodificada++;
    }
    char binarios[(longitudentradamodificada)+1]={};
    char bi[9]={};
    int i=0;
    fin.seekg(0);
    while(fin.good()){
        char temp=fin.get();
        if(fin.good()){
            decbinario(temp,bi);
            for (int s=0;bi[s]!='\0';s++){
                binarios[i]=bi[s];
                i++;
            }
        }
    }
    fin.close();
    while(i<longitudentradamodificada){
        binarios[i]='0';
        i++;
    }
    int con1=0,con0=0,clave=1;
    char codi[_bits+1]={};
    int con=0;
    for (int i=0;i<longitudentradamodificada;i++){
        con++;
       if (con<=_bits && clave == 1){
          if (binarios[i]=='1'){
                binarios[i]='0';
                con1++;
            }
          else{
                 binarios[i]='1';
                 con0++;
            }
          if (con==_bits){
              con=0;
              clave=2;
          }
        }
       if (con<_bits && con>=1){
        codi[con-1]=binarios[i];
       }
       else if(con ==_bits){
           codi[con-1]=binarios[i];
           if (con==_bits && con1==con0){
               int ite=i-_bits;
               for (int s=0; s<_bits;s++){
                   ite++;
                   if (codi[s]=='1'){
                       binarios[ite]='0';
                   }
                   else{
                       binarios[ite]='1';
                   }
               }
           }

           if (con==_bits && con1<con0){
               int saltos=0;
               int ite=i-_bits;
               for (int s=0; s<_bits;s++){
                   saltos++;
                   ite++;
                   if (saltos == 2 && codi[s]=='1'){
                       binarios[ite]='0';
                       saltos=0;
                   }
                   else if(saltos == 2 && codi[s]=='0'){
                       binarios[ite]='1';
                       saltos=0;
                   }
               }
           }
           if (con==_bits && con1>con0){
               int saltos=0;
               int ite=i-_bits;
               for (int s=0; s<_bits;s++){
                   ite++;
                   saltos++;
                   if (saltos == 3 && codi[s]=='1'){
                       binarios[ite]='0';
                       saltos=0;
                   }
                   else if(saltos == 3 && codi[s]=='0'){
                       binarios[ite]='1';
                       saltos=0;
                   }
               }
           }
           con1=0;
           con0=0;
           con=0;
           for (int t=0; t<_bits;t++){
               if (codi[t]=='1'){
                   con1++;
               }
               else{
                   con0++;
               }
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

void metodo2(int _bits,int _metodo,char entrada[],char salida[]){
    int longitudentrada=0;
    int longitudsalida=0;
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
    int longitudentradamodificada=longitudentrada*8;
    while (longitudentradamodificada%_bits!=0){
        longitudentradamodificada++;
    }
    char binarios[(longitudentradamodificada)+1]={};
    char bi[9]={};
    int i=0;
    fin.seekg(0);
    while(fin.good()){
        char temp=fin.get();
        if(fin.good()){
            decbinario(temp,bi);
            for (int s=0;bi[s]!='\0';s++){
                binarios[i]=bi[s];
                i++;
            }
        }
    }
    fin.close();
    while(i<longitudentradamodificada){
        binarios[i]='0';
        i++;
    }
    int con=0;
    char separador[_bits+1]={};
    for (int i=0;i<longitudentradamodificada;i++){
        con++;
        if (con<_bits){
            separador[con-1]=binarios[i];
        }
        else{
            separador[con-1]=binarios[i];
            cambiaposicion(separador);
            for (int s=0;s<_bits;s++){
                int t=i-(_bits-1)+s;
                binarios[t]=separador[s];
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

void codi(){
    int nbits=0;
    int metodo=0;
    char entra[99]={};
    char sale[99]={};
    while (nbits<=0){
        cout<<"ingrese el numero con el que desea agrupar los bits: ";
        cin>>nbits;
    }
    while (metodo<1 || metodo>2){
        cout<<"ingrese con un 1 si desea codificar por el metodo 1 o un 2 si lo desea con el 2: ";
        cin>>metodo;
    }
    cout<<"ingrese el nombre del archivo de entrada: ";
    cin>>entra;
    cout<<"ingrese el nombre del archivo de salida: ";
    cin>>sale;
    if (metodo==1){
        metodo1(nbits,metodo,entra,sale);
    }
    else if (metodo==2){
        metodo2(nbits,metodo,entra,sale);
    }
}


