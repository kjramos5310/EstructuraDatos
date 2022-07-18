#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "SplayTree.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <graphics.h>
#include <sstream>
#include <string>

#include <conio.h>
#include <windows.h>
#include <stdio.h>
//#include "marquesina.cpp"

using namespace std;

#define pow2(n) (1 << (n))
const int x = 600;
const int y = 100;

void gotoxy(int x1, int y1)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x1, y1 };  
  SetConsoleCursorPosition(h,c);
}

int main()
{
	//Grafico
	int gd = DETECT;
	int gm;
	initwindow(1200, 700, "AVL Tree Graphics",
			0, 0, false, true);
	//Marquesina
	int a=0, b=56, c=0, n=0;
char t[25] ="Bienvenido a Splay Tree";


for (a=1;a<=56;a++)
{
system("cls");
gotoxy(a,1);
cout<<t;
Sleep (50);
}
for (b=56;b>=1;b--)
{
system("cls");
gotoxy(b,1);
std::cout<<t;
Sleep (50);
}

int opc, m;
	int dim;
	char val[10];
	SplayTree st;

	do {
		system("cls");
		cout << "Splay Tree" << endl;
		cout << "1.- Insertar elmento " << endl;
		cout << "2.- Buscar elemento " << endl;
		cout << "3.- Eliminar elemento " << endl;
		cout << "4.- Salir" << endl;
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
			exit(1);
			break;
		}
	} while (dim != 4);










/*
	//Grafico
	int gd = DETECT;
	int gm;
	initwindow(1200, 700, "AVL Tree Graphics",
			0, 0, false, true);
	
	
	//char dato[10];
	int opc, m;
	int dim;
	char val[10];
	SplayTree st;

	do {
		system("cls");
		cout << "Splay Tree" << endl;
		cout << "1.- Insertar elmento " << endl;
		cout << "2.- Buscar elemento " << endl;
		cout << "3.- Eliminar elemento " << endl;
		cout << "4.- Salir" << endl;
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
			exit(1);
			break;
		}
	} while (dim != 4);*/
}