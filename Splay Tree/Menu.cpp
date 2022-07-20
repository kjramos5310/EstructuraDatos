#include "Menu.h"
using namespace std;

#define pow2(n) (1 << (n))
const int x = 600;
const int y = 100;

void Menu::Menu1(){
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
		cout << "4.- Imprimir " << endl;
		cout << "5.- Salir" << endl;
		
		
		cout<<"\nIngrese una opcion: ";
		cin>>dim;
		switch (dim) {
		case 1:
			char val1[10];
			cout<<"Ingrese un elemetno: ";
			cin>>m;
			st.insertar(m);
			
			cleardevice();
			settextstyle(10, HORIZ_DIR, 3);

			st.drawTree(st.getRoot(),x,y);
			system("cls");
			break;
		case 2:	
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
		case 3:
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
		case 4:	
			//exit(1);
			 ofstream file;
			 file.open("C:/Users/USER/OneDrive/Documentos/GitHub/EstructuraDatos/Splay Tree/Grafico_Arbol.txt");
             file<<"Arbol invertido: "<<endl;
             st.Guardar(st.getRoot(),file,cont);
             file.close();
			break;	
		}
		}while(dim != 5);

}