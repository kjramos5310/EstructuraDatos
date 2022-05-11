#include <iostream>
#include "Ingreso.h"
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stoi;
using namespace std;

class Ingresar : public Ingreso{
	public:
		int ingresarDato(string dato){
			int numero;
			numero = stoi(dato);
			return numero;
		}
};