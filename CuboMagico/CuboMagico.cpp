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
#include "CuboMagico.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
CuboMagico::CuboMagico(){
}
CuboMagico::CuboMagico( int **_cuadrado){
	cuadrado=_cuadrado;
}
void CuboMagico::setCuboMagicoCuadrado(int **_cuadrado){
	cuadrado=_cuadrado;
}
int **CuboMagico::getCuboMagicoCuadrado(){
	return cuadrado;
}
void CuboMagico::llenar(int a, int b,int c, int pa){
	int x=0,t=0,s=0,d=0,p=c,k=0,j=0;
	x=(b-1)/2;
	t=((a+1)/2);
	s=(a-x-1)/2;
	d=x;
	for(int g=0;g<((a+1)/2);g++){
		j=g;
		k=g;
		for(int i=x;i>=j;i--){
			*(*(cuadrado+i)+k)=p;
			if(k<(d-s)){
				*(*(cuadrado+i)+(k+t))=p;
			}
			if(k>(d+s)){
				*(*(cuadrado+i)+(k-t))=p;
			}
			if(i>(d+s)){
				*(*(cuadrado+(i-t))+k)=p;
			}
			if(i<(d-s)){
				*(*(cuadrado+(i+t))+k)=p;
			}
			k++;
			p+=pa;
		}
		x++;
	}
}
void CuboMagico::mostrar(int a, int b, int c){
	system("cls");
	int x=0,t=0,s=0;
	x=(b-1)/2;
	t=((a+1)/2);
	s=(a-x-1)/2;
	printf("\n\t M A T R I Z ---G E N E R A D A %d*%d",c,c);
	for(int g=0;g<a;g++){
		printf("\n\t");
		for(int h=0;h<b;h++){
				
			if(h>=(x-s)&&h<=(x+s)&&g<=(x+s)&&g>=(x-s)){
				printf("\t%d",*(*(cuadrado+g)+h));	
			}
		}
	}
}