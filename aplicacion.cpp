#include <aplicacion.h>

int apotencia2(int a, int b){
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

int abindecimal(string a){
   int i=0;
   int s=7;
   int sum=0;
   while (i<8){
        if (a[i]=='1'){
            sum+=apotencia2(2,s);
        }
        i++;
        s--;
    }
   return sum;
}

string acambiaposicioninverso(string a){
    int lon=a.size();
    char primero=a[0];
    for (int i=0; i<lon-1;i++){
        a[i]=a[i+1];
    }
    a[lon-1]=primero;
    return a;
}

string adeco2(int _bits,string entrada){
    ifstream fin;
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
    string letras="";
    fin.seekg(0);
    while(fin.good()){
        char temp=fin.get();
        if(fin.good()){
            binarios+=temp;
        }
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
            separador=acambiaposicioninverso(separador);
            for (int s=0;s<_bits;s++){
                int t=i-(_bits-1)+s;
                binarios[t]=separador[s];
                con=0;
            }
            separador="";
        }
    }
    string le="";
    con=0;
    int nletra=0;
    for (int i=0;i<binarios.size();i++){
        con++;
        if(con<8){
            le+=binarios[i];
        }
        else if(con==8){
            le+=binarios[i];
            nletra=abindecimal(le);
            char let=nletra;
            letras+=let;
            con=0;
            le="";
        }
    }
    return letras;
}

void menusuario(int n,int &sa){
    if (n==1 && sa>=1000){
        sa=sa-1000;
        cout<<"su saldo es: "<<sa<<endl<<" recuerde que la consulta tiene un valor de 1000CP."<<endl;
    }
    else if(n==2 && sa>=1000){
        sa=sa-1000;
        int control=0;
        int retiro=0;
        cout<<"ingrese el valor que desea retirar: ";
        cin>>retiro;
        if (retiro<=sa && retiro>0){
            sa=sa-retiro;
            cout<<"se retiraron "<<retiro<<" pesos con exito."<<endl;
            control=1;
        }
        if (retiro>sa && control==0){
            while (retiro>sa && sa>0){
                cout<<"la cantidad que desea retirar supera su saldo, por favor ingrese una cantidad que tenga en la cuenta o marque 0 si ya no desea retirar: ";
                cin>>retiro;
                if (retiro<=sa && retiro>0){
                    sa=sa-retiro;
                }
            }
        }
    }
    else if (sa<1000){
        cout<<"usted ya no tiene saldo en su cuenta"<<endl;
    }
}

void menuadmi(int n){
    if (n==1){
        ofstream fout;
        try{
            fout.open("usuarios.txt",ios::app);
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
        string agg="";
        string atxt="\n";
        cout<<"ingrese la cedula: ";
        cin>>agg;
        atxt=atxt+agg+'\n';
        cout<<"ingrese la contraseña: ";
        cin>>agg;
        atxt=atxt+agg+'\n';
        cout<<"ingrese el saldo: ";
        cin>>agg;
        atxt=atxt+agg;
        fout<<atxt;
        fout.close();
    }
}

void comprousuario (string a,string b){
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
    string ce="";
    string co="";
    string salstring="";
    int con=2;
    int opcion=0;
    int clave=0;
    while(fin.good()){
        con++;
        getline(fin,ce);
        if (con==3){
            if(ce==a){
                getline(fin,co);
                if (b==co){
                    getline(fin,salstring);
                    int sal=stoi(salstring);
                    while (opcion!=3){
                        cout<<"si desea consultar su saldo marque 1.\nSi desea retirar marque 2.\nSi desea salir del menu marque 3: ";
                        cin>>opcion;
                        menusuario(opcion,sal);
                    }
                    salstring=to_string(sal);
                    clave=1;
                    break;
                }
            }
            else{
                con=0;
            }
        }
        if(fin.eof()){
            cout<<"usted no esta registrado o se equivoco en uno de los datos.";
        }
    }
    con=0;
    string linea;
    string txt="";
    fin.seekg(0);
    int control=0;
    if (clave == 1){
        while(fin.good()){
            getline(fin,linea);
            if (con>0){
                if (a==linea){
                    txt=txt+'\n'+linea;
                    getline(fin,linea);
                    if (b==linea && control==0){
                        txt=txt+'\n'+linea;
                        getline(fin,linea);
                        txt=txt+'\n'+salstring;
                        control=1;
                    }
                }
                else{
                    txt=txt+'\n'+linea;
                }
            }
            else if(a==linea && con==0){
                txt=linea;
                con=1;
                getline(fin,linea);
                if (b==linea){
                    txt=txt+'\n'+linea;
                    getline(fin,linea);
                    txt=txt+'\n'+salstring;
                }
            }
            else if(con==0){
                txt+=linea;
                con=1;
            }
        }
        fin.close();
        ofstream fout;
        try{
            fout.open("usuarios.txt");
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
        fout<<txt;
        fout.close();
    }
}

void aplicacion(){
    int ingreso=0;
    cout<<"bienvenid@ al sistema.\nSi desea entrar como administrador marque 1.\nSi desea entrear como usuario marque 2: ";
    cin>>ingreso;
    if (ingreso==2){
        string cedula="";
        string contraseña="";
        cout<<"ingrese su cedula: ";
        cin>>cedula;
        cout<<"ingrese su contraseña: ";
        cin>>contraseña;
        comprousuario(cedula,contraseña);
    }
    else if(ingreso==1){
        string clave="";
        cout<<"ingrese la clave de administrador: ";
        cin>>clave;
        string archivo="sudo.txt";
        int num=4;
        string sudo=adeco2(num,archivo);
        int agregar=0;
        if (clave==sudo){
            while(agregar!=2){
                cout<<"marque 1 si desea agregar personas al banco.'\nmarque 2 para salir: ";
                cin>>agregar;
                menuadmi(agregar);
            }
        }
        else{
            cout<<"contraseña incorrecta.";
        }
    }
}
