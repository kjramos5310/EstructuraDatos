#include <iostream>
#include "Ingresar.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Ingresar* dato1 = new Ingresar();
	string dato;
	cout<<"Ingresar Dato: "<<endl;
	cin>>dato;
	cout<< dato1->ingresarDato(dato);
	return 0;
	}