/*      UNIVERSIDAD DE LAS FUERZAS ARMADAS
*       Ordenamiento Mezcla Natural
*       Autor: NRC 4683
*       Fecha de creación: 21/06/2022
*       Fecha de modificación: 29/06/2022
*       Grupo: 4,16
*       Github: https://github.com/cfidrobo/Estructura_de_Datos_TallerGrupal
*/


#include  <iostream> 
#include "ShellSort.h"

using namespace std;


int main()
{
	ShellSort ss;
	int dim, val;

	cout << "Ingrese tamanio del arreglo: ";
	cin >> dim;
	
	//int *arr
	//arr=(int *)malloc(dim * sizeof(int))
	//if(arr=NULL){
	//	printf("No hay memoria disponible");
	//	return;
	//}
	//

	int* arr = new int[dim];

	ss.ingresar(arr, dim);

	cout << "\nArreglo igresado:" << endl;
	ss.imprimir(arr, dim);

	//Aplicamos ShellSort
	ss.shellSort(arr, dim);

	cout << "\n\nArreglo luego de shell sort:" << endl;
	ss.imprimir(arr, dim);

	return 0;
}
