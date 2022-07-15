#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "SplayTree.h"

using namespace std;


int main()
{
	char dato[10];
	int opc, t;
	SplayTree st;

	do {
		system("cls");
		cout << "Splay Tree" << endl;
		cout << "1.- Insertar elmento " << endl;
		cout << "2.- Buscar elemento " << endl;
		cout << "3.- Eliminar elemento " << endl;
		cout << "4.- Salir" << endl;
		strcpy(dato, st.ingresarDatos("Ingrese una opcion: "));
		opc = atoi(dato);
		switch (opc) {
		case 1:
			strcpy(dato, st.ingresarDatos("\nIngrese elemento: "));
			t = atoi(dato);
			st.insertar(t);
			if (st.getRoot())
			{
				system("cls");
				cout << "Elemento insertado" << endl;
				cout << endl;
				cout << "Raiz: " << st.getRoot()->getValor() << endl;
			}
			st.imprimir(st.getRoot());
			cout << endl;
			system("pause");
			break;
		case 2:
			strcpy(dato, st.ingresarDatos("\nIngrese elemento a buscar: "));
			t = atoi(dato);
			if (!st.buscar(t))
			{
				system("cls");
				cout << "No existe elemnto" << endl;
				system("pause");
			}
			else {
				if (st.getRoot())
				{
					system("cls");
					cout << "Elemento encotnrado" << endl;
					cout << endl;
					cout << "Raiz: " << st.getRoot()->getValor() << endl;
				}
				st.imprimir(st.getRoot());
				cout << endl;
				system("pause");
			}
			break;
		case 3:
			strcpy(dato, st.ingresarDatos("\nIngrese elemento a borrar: "));
			t = atoi(dato);
			if (st.borrar(t))
			{
				if (st.getRoot())
				{
					system("cls");
					cout << "Elemento eliminado" << endl;
					cout << endl;
					cout << "Raiz: " << st.getRoot()->getValor() << endl;
				}
				st.imprimir(st.getRoot());
				cout << endl;
				system("pause");
			}
			else {
				system("cls");
				cout << "No existe elemnto" << endl;
				system("pause");
			}
			break;
		case 4:
			exit(1);
			break;
		}
	} while (opc != 4);
}