#include "Login.h"

void Login::inicio(){
	int choice;
        cout<<"***********************************************************************\n\n\n";
        cout<<"                      Welcome to login page                               \n\n";
        cout<<"*******************        MENU        *******************************\n\n";
        cout<<"1.LOGIN"<<endl;
        cout<<"2.REGISTRARSE"<<endl;
        cout<<"3.OLVIDE MI CONTRASENA (o) USERNAME"<<endl;
        cout<<"\nEnter your choice :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        login();
                        break;
                case 2:
                        registr();
                        break;
                case 3:
                        forgot();
                        break;
                default:
                        system("cls");
                        cout<<"A ocurrido un error, porfavor intente de nuevo.\n"<<endl; 
                        inicio();
        }
}
void Login::forgot(){
	int ch;
        system("cls");
        cout<<"Aquí te ayudamos\n";
        cout<<"1.Busca tu id por tu username"<<endl;
        cout<<"2.Busca tu id por tu password"<<endl;
        cout<<"3.Main menu"<<endl;
        cout<<"Ingrese tu opcion :";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\nIngresa tu username recordado :";
                        cin>>searchuser;
                        
                        ifstream searchu("database.txt");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\nCuenta encontrada!\n";
                                cout<<"\nTu contraseña es: "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                inicio();
                        }
                        else
                        {
                                cout<<"\nPerdon, tu ID no se ha encontrado en la base de datos\n";
                                
                                cin.get();
                                cin.get();
                                inicio();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nIngresa tu password recordada :";
                        cin>>searchpass;
                        
                        ifstream searchp("database.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }       
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nTu password se encontró en la base de datos! \n";
                                cout<<"\nTu Id es : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                                inicio();
                        }
                        else
                        {
                                cout<<"Perdon, tu password no se ha encontrado en la base de datos \n";
                               
                                cin.get();
                                cin.get();
                                inicio();
                        }
                
                        break;
                }
                
                case 3:
                {
                        cin.get();
                        inicio();
                }
                default:
                        cout<<"Intenta de nuevo"<<endl;
                        forgot();
        }
}
void Login::login(){
	int count;
        string user,pass,u,p;
        system("cls");
        cout<<"Porfavor ingrese los siguientes detalles"<<endl;
        cout<<"USERNAME :";
        cin>>user;
        cout<<"PASSWORD :";
        cin>>pass;
        
        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)
        
                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
        	Menu m;
                cout<<"\nBienvenido "<<user<<"\nLOGIN SUCESS\n";
                cin.get();
                cin.get();
                system("cls");
                m.Menu1();
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPorfavor chequea tu username y password\n";
                inicio();
        }
}

void Login::registr(){
	string reguser,regpass,ru,rp;
        system("cls");
        cout<<"Ingrese el username :";
        cin>>reguser;
        cout<<"\nIngrese el password :";
        cin>>regpass;
        
        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nRegistro Correcto\n";
        inicio();
	
}