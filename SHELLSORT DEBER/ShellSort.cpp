#include "ShellSort.h"

void ShellSort::ingresar(int* arr, int dim) {
	int val;
	for (int i = 0; i < dim; i++) {
		cout << "Ingrese elemento " << i + 1 << ": ";
		cin >> val;
		*(arr + i) = val;
	}
}

void ShellSort::shellSort(int* arr, int dim) {
	for (int gap = dim / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < dim; i += 1)
		{
			//sort sub lists created by applying gap 
			int temp = *(arr + i);

			int j;
			for (j = i; j >= gap && *(arr + (j - gap)) > temp; j -= gap) {
				*(arr + j) = *(arr + (j - gap));
			}

			*(arr + j) = temp;
		}
	}
}

void ShellSort::imprimir(int* arr, int dim) {
	for (int i = 0; i < dim; i++) {
		cout << *(arr + i) << " ";
	}
}
