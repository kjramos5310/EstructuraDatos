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
#ifndef CUBOMAGICO_H
#define CUBOMAGICO_H
	class CuboMagico{
		public:
			CuboMagico();
			CuboMagico(int **);	
			void setCuboMagicoCuadrado(int **);
			int **getCuboMagicoCuadrado();
			void mostrar(int, int, int);
			void llenar(int, int, int , int);
		protected:	
		private:
			int **cuadrado;
	};
#endif 