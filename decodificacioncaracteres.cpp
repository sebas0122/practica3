#include <decodificacioncaracteres.h>

int potencia2(int a, int b){
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

int longitud2(char a[]){
    int i = 0;
    int con;
    for (i=0;a[i] != '\0';i++){
        con++;
    }
    return i;
}

int bindecimal(char a[]){
   int i=0;
   int s=7;
   int sum=0;
   while (i<8){
        if (a[i]=='1'){
            sum+=potencia2(2,s);
        }
        i++;
        s--;
    }
   return sum;
}

void cambiaposicioninverso(char a[]){
    int lon=longitud2(a);
    char primero=a[0];
    for (int i=0; i<lon-1;i++){
        a[i]=a[i+1];
    }
    a[lon-1]=primero;
}

void deco1(int _bits,int _metodo,char entrada[],char salida[]){
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
    int longitudentrada = static_cast<int>(fin2 - inicio);
    int con=0;
    char binarios[(longitudentrada)+1]={};
    char letras[(longitudentrada/8)+1]={};
    int i=0;
    fin.seekg(0);
    while(fin.good()){
        char temp=fin.get();
        if(fin.good()){
            binarios[i]=temp;
            i++;
        }
    }
    fin.close();
    int con1=0,con0=0,clave=1;
    char codi[_bits+1]={};
    con=0;
    for (int i=0;i<longitudentrada;i++){
        con++;
       if (con<=_bits && clave == 1){
          if (binarios[i]=='1'){
                binarios[i]='0';
                con0++;
            }
          else{
                 binarios[i]='1';
                 con1++;
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
                       codi[s]='0';
                       binarios[ite]=codi[s];
                   }
                   else{
                       codi[s]='1';
                       binarios[ite]=codi[s];
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
                       codi[s]='0';
                       binarios[ite]='0';
                       saltos=0;
                   }
                   else if(saltos == 2 && codi[s]=='0'){
                       codi[s]='1';
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
                       codi[s]='0';
                       binarios[ite]='0';
                       saltos=0;
                   }
                   else if(saltos == 3 && codi[s]=='0'){
                       codi[s]='1';
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
    char le[9]={};
    con=0;
    int nletra=0;
    int y=0;
    for (int i=0;i<longitudentrada;i++){
        con++;
        if(con<8){
            le[con-1]=binarios[i];
        }
        else if(con==8){
            le[con-1]=binarios[i];
            nletra=bindecimal(le);
            char let=nletra;
            letras[y]=let;
            y++;
            con=0;
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
    fout.write(letras,longitudentrada/8);
    fout.close();
}

void deco2(int _bits,int _metodo,char entrada[],char salida[]){
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
    int longitudentrada = static_cast<int>(fin2 - inicio);
    int con=0;
    char binarios[(longitudentrada)+1]={};
    char letras[(longitudentrada/8)+1]={};
    int i=0;
    fin.seekg(0);
    while(fin.good()){
        char temp=fin.get();
        if(fin.good()){
            binarios[i]=temp;
            i++;
        }
    }
    fin.close();
    con=0;
    char separador[_bits+1]={};
    for (int i=0;i<longitudentrada;i++){
        con++;
        if (con<_bits){
            separador[con-1]=binarios[i];
        }
        else{
            separador[con-1]=binarios[i];
            cambiaposicioninverso(separador);
            for (int s=0;s<_bits;s++){
                int t=i-(_bits-1)+s;
                binarios[t]=separador[s];
                con=0;
            }
        }
    }
    char le[9]={};
    con=0;
    int nletra=0;
    int y=0;
    for (int i=0;i<longitudentrada;i++){
        con++;
        if(con<8){
            le[con-1]=binarios[i];
        }
        else if(con==8){
            le[con-1]=binarios[i];
            nletra=bindecimal(le);
            char let=nletra;
            letras[y]=let;
            y++;
            con=0;
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
    fout.write(letras,longitudentrada/8);
    fout.close();
}

void deco(){
    int nbits=0;
    int metodo=0;
    char entra[99]={};
    char sale[99]={};
    while (nbits<=0){
        cout<<"ingrese el numero con el que se agrupo los bits: ";
        cin>>nbits;
    }
    while (metodo<1 || metodo>2){
        cout<<"ingrese con un 1 si se codifico por el metodo 1 o un 2 si fue con el 2: ";
        cin>>metodo;
    }
    cout<<"ingrese el nombre del archivo de entrada: ";
    cin>>entra;
    cout<<"ingrese el nombre del archivo de salida: ";
    cin>>sale;
    if (metodo==1){
        deco1(nbits,metodo,entra,sale);
    }
    else if (metodo==2){
        deco2(nbits,metodo,entra,sale);
    }
}
