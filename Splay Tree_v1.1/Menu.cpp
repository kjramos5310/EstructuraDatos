#include "Menu.h"

using namespace std;

#define pow2(n) (1 << (n))
const int x = 600;
const int y = 100;

void Menu::Menu1(){
	//Backup b;
	//system("color A8");
	//Grafico
	int gd = DETECT;
	int gm;
	initwindow(1200, 700, "AVL Tree Graphics",
			0, 0, false, true);


int opc, m;
	int dim, cont=0;
	char val[10];
	SplayTree st;


	do {
		system("cls");
		cout << "Splay Tree" << endl;
		cout << "1.- Insertar elemento " << endl;
		cout << "2.- Buscar elemento " << endl;
		cout << "3.- Eliminar elemento " << endl;
		cout << "4.- Imprimir .txt" << endl;
		//cout << "5.- Generar Backup" << endl;
		//cout << "6.- Recuperar Backup" << endl;
		cout << "7.- C-DOCS " << endl;
		cout << "8.- Ayuda " << endl;
		cout << "10.- Salir" << endl;
		
		
		cout<<"\nIngrese una opcion: ";
		cin>>dim;
		switch (dim) {
		case 1:{
			char val1[10];
			cout<<"Ingrese un elemetno: ";
			cin>>m;
			st.insertar(m);
			
			cleardevice();
			settextstyle(10, HORIZ_DIR, 3);

			st.drawTree(st.getRoot(),x,y);
			system("cls");
			break;
		}
		case 2:{
			int t1;
			cout<<"\nIngrese un elemento a buscar: ";
			cin>>t1;
			
			if (!st.buscar(t1))
			{
				system("cls");
				cout << "No existe ese elemnto" << endl;
				system("pause");
			}
			else {
				if (st.getRoot())
				{
				cleardevice();
				settextstyle(10, HORIZ_DIR, 3);
				st.drawTree(st.getRoot(),x,y);
				}

			}
			break;
		}
		case 3:{
			int t2;
			cout<<"\nElemento a borrar: ";
			cin>>t2;
			if (st.borrar(t2))
			{
				if (st.getRoot())
				{
					cleardevice();
				settextstyle(10, HORIZ_DIR, 3);

				st.drawTree(st.getRoot(),x,y);
				}
			}
			else {
				system("cls");
				cout << "No existe elemnto" << endl;
				system("pause");
			}
			break;
		}
		case 4:{
			//exit(1);
			 std::ofstream file;
			 file.open("C:/Users/HP/Documents/ESPE/SEGUNDO SEMESTRE/SEGUNDA/Programacion/Estructura de Datos/PROYECTOU2/ele/Ahorita si sale/EstructuraDatos/Splay Tree/Grafico_Arbol.txt");
             file<<"Arbol invertido: "<<endl;
             st.Guardar(st.getRoot(),file,cont);
             file.close();
			break;
		}
		case 5:{
			//b.generarBackup();
			//cout << "=====Backup realizado con exito=====" << endl;
			//system("pause");
			break;
		}
		case 6:{
			/*string nombre;
            cout << "\n\n\nIntroduzca el nombre: "; cin >> nombre;
            b.recuperarBackup(nombre);
            cout<<"=====Backup recuperado con exito =====\n\n";
            system("pause");*/
			break;
		}
		case 7:{
			system("cd html && index.html");
			cout << "C++ docs en CHROME" << endl;
			break;
		}
		case 8:{
			system("SplayTree_Help.chm");
			break;
		}
		}
		}while(dim != 10);

}