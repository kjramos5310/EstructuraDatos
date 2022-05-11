/*********************************************************************************************
*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE													 *
*Programa para implementar: TDA																 *
*Autor(es): Victor Camacho, Kevin Ramos														 *
*Fecha de creacion: 09/05/2022																 *
*Fecha de modificacion: 10/05/2022															 *
*Grupo #																					 *
*Github del grupo: https://github.com/kjramos5310/EstructuraDatos/tree/master/Programa%20TDA *
*Version: 0.1																				 *
*ESTRUCTURA DE DATOS 4683																	 *
*																							 *
**********************************************************************************************/
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
	
	
