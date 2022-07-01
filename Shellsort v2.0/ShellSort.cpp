#include "ShellSort.h"
#include "Validacion.cpp"

void ShellSort::ingresar(int* arr, int dim) {
	Validacion v;
	int valu;
	char val[10];//Solo para capturar lo que se introduce en teclado
	for (int i = 0; i < dim; i++) {
		cout <<endl<< "Ingrese elemento " << i + 1 << ": ";
		strcpy(val,v.ingresarDatoSinMsj());
        valu=atoi(val);
		*(arr + i) = valu;
	}
}

void ShellSort::shellSort(int* arr, int dim) {
	for (int gap = dim / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < dim; i += 1)
		{
			int temp = *(arr + i);

			int j;
			for (j = i; j >= gap && *(arr + (j - gap)) > temp; j -= gap) {
				*(arr + j) = *(arr + (j - gap));
			}

			*(arr + j) = temp;
		}
	}
}
