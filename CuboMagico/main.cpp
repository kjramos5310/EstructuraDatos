/*****************************************************************************************************
*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE													 		 *
*Programa para implementar: Cubo Magico													 *
*Autor(es): Kevin Ramos										 *
*Fecha de creacion: 10/08/2022																 		 *
*Fecha de modificacion: 10/08/2022															 		 *
*Grupo #16																					 		 *
*Github del grupo: https://github.com/kjramos5310/EstructuraDatos/tree/master/Deberes%20TercerParcial*
*Version: 0.1																				 		 *
*ESTRUCTURA DE DATOS 4683																	 		 *
*																							 		 *
*****************************************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "CuboMagico.h""
#include <iostream>

int main(int argc, char** argv) {
	int **cuadrado, dim,num, ceni,sec;
	do{
		printf("Ingrese la dimension [impares] :");
		scanf("%d",&dim);
		printf("Ingrese el centinela inicial :  ");
		scanf("%d",&ceni);
		printf("Ingrese el patron de secuencia : ");
		scanf("%d",&sec);
	}while(dim%2==0);//{
		//printf("Datos ingresados correctamente...");
	//};
	
	num=2*dim-1;
	cuadrado=(int**)calloc(num,sizeof(int*));
	for(int i=0;i<num;i++){
		*(cuadrado+i)=(int *)calloc(num,sizeof(int));
	}
	CuboMagico cubo=CuboMagico(cuadrado);
	cubo.llenar(num,num,ceni,sec);
	cubo.mostrar(num,num,dim);
	system("pause");
	return 0;
}