#include <codistream.h>

int spotencia(int a, int b){
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

string sdecbinario(char a,string b){
   int numero=a;
   int i=0;
   int s=7;
   while (i<8){
        if (numero>=spotencia(2,s)){
            b+='1';
            numero=numero-spotencia(2,s);
        }
        else{
           b+='0';
        }
        i++;
        s--;
    }
   return b;
}

string scambiaposicion(string a){
    int lon=a.size();
    char primero=a[lon-1];
    for (int i=lon-1; i>0;i--){
        a[i]=a[i-1];
    }
    a[0]=primero;
    return a;
}

void smetodo1(int _bits,int _metodo,string entrada,string salida){
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
    string binarios="";
    string bi="";
    fin.seekg(0);
    while(fin.good()){
        char temp=fin.get();
        if(fin.good()){
            bi=sdecbinario(temp,bi);
            binarios+=bi;
            bi="";
        }
    }
    while (binarios.size()%_bits!=0){
        binarios+='0';
    }
    fin.close();
    int con1=0,con0=0,clave=1,con=0;
    string codi="";
    while (codi.size()!=_bits){
        codi+='0';
    }
    for (int i=0;i<binarios.size();i++){
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
    fout<<binarios;
    fout.close();
}

void smetodo2(int _bits,int _metodo,string entrada,string salida){
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
    string binarios="";
    string bi="";
    fin.seekg(0);
    while(fin.good()){
        char temp=fin.get();
        if(fin.good()){
            bi=sdecbinario(temp,bi);
            binarios+=bi;
            bi="";
        }
    }
    while (binarios.size()%_bits!=0){
        binarios+='0';
    }
    fin.close();
    int con=0;
    string separador="";
    for (int i=0;i<binarios.size();i++){
        con++;
        if (con<_bits){
            separador+=binarios[i];
        }
        else{
            separador+=binarios[i];
            separador=scambiaposicion(separador);
            for (int s=0;s<_bits;s++){
                int t=i-(_bits-1)+s;
                binarios[t]=separador[s];
                con=0;
                separador="";
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
    fout<<binarios;
    fout.close();
}

void scodi(){
    int nbits=0;
    int metodo=0;
    string entra="";
    string sale="";
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
        smetodo1(nbits,metodo,entra,sale);
    }
    else if (metodo==2){
        smetodo2(nbits,metodo,entra,sale);
    }
}
