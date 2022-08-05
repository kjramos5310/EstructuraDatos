
/*****************************************************************************************************
*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE													 		 *
*Programa para implementar: problema de n reinas													 *
*Autor(es): Victor Camacho, Kevin Ramos, Esteven Nasimba											 *
*Fecha de creacion: 04/08/2022																 		 *
*Fecha de modificacion: 04/08/2022															 		 *
*Grupo #16																					 		 *
*Github del grupo: https://github.com/kjramos5310/EstructuraDatos/tree/master/Deberes%20TercerParcial*
*Version: 0.1																				 		 *
*ESTRUCTURA DE DATOS 4683																	 		 *
*																							 		 *
*****************************************************************************************************/


#include <iostream>
#include <fstream>
using namespace std;
class Alfil{
	public:
		bool **validar;
		char **tablero;
		fstream archivo;
		int contador;
		int n=8;
		int numR;
		void encerarTablero(){
			for(int i=0;i<n;i++){
				validar[i]=new bool[n];
				tablero[i]=new char[n];
				for(int j=0;j<n;j++){
					*(*(validar+i)+j)=false;
					*(*(tablero+i)+j)='*';
				}
			}
		}
	void crearArchivo(){
		archivo.open("exaustivoAlfil.txt",fstream::out);
		archivo<<"solucion"<<n<<"*"<<n<<endl<<endl;
		contador=0;
	}
	Alfil(int n1){
		numR=n1;
		validar=new bool *[n];
		tablero=new char *[n];
		encerarTablero();
		crearArchivo();
	}
	void bloquear(int x, int y){
		int aux1,aux2;
		aux2=y;
		aux1=0;
		while(aux1<n){//vertical
			*(*(validar+aux1)+aux2)=false;
			aux1++;
		}
		aux2=0;
		aux1=x;
		while(aux2<n){
			*(*(validar+aux1)+aux2)=false;
			aux2++;
		}
		aux2=y;//diagonal
		aux1=x;
		while(aux1>0&&aux2>0){
			aux1--;
			aux2--;
		}
		aux2=y;
		aux1=x;
		while(aux1<n && aux2>0){
			aux1++;
			aux2--;
		}
		aux1--;
		aux2++;
		while(aux1>=0 && aux2<n){
			*(*(validar+aux1)+aux2)=true;
			aux1--;
			aux2++;
		}
	}
	
	void mostrar(){
		contador++;
		archivo<<"solucion N "<<contador <<endl;
		//cout<<"solucion N "<<contador<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				archivo<<*(*(tablero+i)+j)<<" ";
				//cout<<*(*(tablero+i)+j)<<" ";
			}
			archivo<<endl;
			//cout<<endl;
		}
		archivo<<endl;
		//cout<<endl;
	}
	void mostrarCMD(){
		//contador1++;
		cout<<"solucion N "<<contador <<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<*(*(tablero+i)+j)<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	
	void quitarRelleno(int x, int y){
		*(*(tablero +x)+y)='*';
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				*(*(validar +i)+j)=false;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(*(*(tablero +i)+j)=='R')
				bloquear(i,j);
			}	
		}
	}

	
	void solucion(int x, int y, int n1){
		*(*(tablero +x)+y)='A';
		bloquear(x,y);
		if(n1==numR){
			mostrar();
			mostrarCMD();
		}else{
			for(int i=0;i<n;i++){
				if(*(*(validar +i )+ y+1)==false){
					solucion(i,y+1,n1+1);
				}
			}
		}
		quitarRelleno(x,y);
	}
	void solucionAlfils(){
		for(int i=0;i<n;i++){
			solucion(i,0,1);
		}
		archivo.close();	
	}
};
int main(int argc, char** argv) {
	int n;
	cout<<"\tIngrese el numero de Alfils"<<endl;
	cin>>n;
	Alfil *obj=new Alfil(n);
	obj->solucionAlfils();
	cout<<"Se creo el archivo txt"<<endl;
	return 0;
}