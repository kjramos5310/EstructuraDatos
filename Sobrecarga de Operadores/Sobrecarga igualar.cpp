/*******************************
*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE													 *
*Programa para implementar: TDA																 *
*Autor(es): Victor Camacho, Kevin Ramos														 *
*Fecha de creacion: 15/05/2022																 *
*Fecha de modificacion: 16/05/2022															 *
*Grupo # 16																					 *
*Github del grupo: https://github.com/kjramos5310/EstructuraDatos/tree/master/Programa%20TDA *
*Version: 0.2																				 *
*ESTRUCTURA DE DATOS 4683																	 *
*																							 *
********************************/

#include <iostream>
#include <string>

class Car
{
private:
    std::string m_make;
    std::string m_model;

public:
    Car(const std::string& make, const std::string& model)
        : m_make{ make }, m_model{ model }
    {
    }

    friend bool operator== (const Car& c1, const Car& c2);
    friend bool operator!= (const Car& c1, const Car& c2);
};

bool operator== (const Car& c1, const Car& c2)
{
    return (c1.m_make == c2.m_make &&
            c1.m_model == c2.m_model);
}

bool operator!= (const Car& c1, const Car& c2)
{
    return (c1.m_make != c2.m_make ||
            c1.m_model != c2.m_model);
}

int main()
{
    Car corolla{ "Toyota", "Corolla" };
    Car camry{ "Toyota", "Camry" };

    if (corolla == camry)
        std::cout << "a Corolla y Camry son iguales.\n";

    if (corolla != camry)
        std::cout << "a Corolla and Camry no son iguales.\n";

    return 0;
}
