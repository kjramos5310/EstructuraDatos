/*******************************
*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE													 *
*Programa para implementar: Sobrecargado de Operador +										 *
*Autor(es): Victor Camacho, Kevin Ramos														 *
*Fecha de creacion: 15/05/2022																 *
*Fecha de modificacion: 16/05/2022															 *
*Grupo #16																					 *
*Github del grupo: https://github.com/kjramos5310/EstructuraDatos/tree/master/Programa%20TDA *
*Version: 0.1																				 *
*ESTRUCTURA DE DATOS 4683																	 *
*																							 *
********************************/

#include <iostream>
using namespace std;

class Pareja {
public:
    double a, b;

    // constructor parametrizado
    Pareja(const double a,const double b)
    {
        this->a = a;
        this->b = b;
    }
};

// Sobrecarga del operador +
Pareja operator +(const Pareja &p1,const Pareja &p2)
{
    Pareja res( p1.a + p2.a, p1.b + p2.b );
    return res;
}

int main()
{
    Pareja A(50, 75 );
    Pareja B(150, 175 );
    Pareja C = A + B;

    cout << "A = " << A.a << ',' << A.b << "\n";
    cout << "B = " << B.a << ',' << B.b << "\n";
    cout << "C = " << C.a << ',' << C.b << "\n";

    return 0;
}
