#include <iostream>
#include "Menu.cpp"
#include "Validacion.cpp"
#include "ShellSort.cpp"
 
 Menu::Menu(){
 }
 
 void Menu::menu(){
 	char val[10];// Para capturar lo que se ingresa por teclado
    char* op;
    int dim;
    Validacion v;
    ShellSort ss;
    
    char* mensaje = (char*) "\nIngrese tamanio del arreglo: ";
    strcpy(val,v.ingresarDato(mensaje));
        dim=atoi(val);
    cout<<endl;
    int* arr = new int[dim];
    ss.ingresar(arr, dim);

	cout << "\nArreglo igresado:" << endl;
	ss.imprimir(arr, dim);
    
    //Aplicamos ShellSort
	ss.shellSort(arr, dim);

	cout << "\n\nArreglo ordenado por shell sort:" << endl;
	ss.imprimir(arr, dim);


 }