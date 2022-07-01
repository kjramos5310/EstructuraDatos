//#pragma once
#include <iostream>
#include "Validacion.cpp"

using namespace std;

class ShellSort
{
public:
	void ingresar(int* arr, int dim);
	void shellSort(int* arr, int dim);
	void imprimir(int* arr, int dim);
};

