#include <ctype.h>
#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

template <class TDA> class ABB;
// Clase declarada como template con las declaraciones necesarias para la creación de nodos
// El template nos permite usar cualquier tipo de dato.
template<class TDA>
class Nodo {
      public:
      // Constructor de la clase nodo:
	  Nodo(const TDA dat, Nodo<TDA> *izq=NULL, Nodo<TDA> *der=NULL) :
	  dato(dat), izquierdo(izq), derecho(der) {}
      // Miembros de la clase nodo:
      TDA dato; // El dato a almacenar
      Nodo<TDA> *izquierdo; // El puntero a la izquierda del árbol
      Nodo<TDA> *derecho; // El puntero a la derecha del árbol
      
      friend class ABB<TDA>; // Debe ser amiga de la clase lista para poder usar los nodos como parametros
                             // de las funciones
   };

// Clase declarada como template para crear árboles.
// El template nos permite usar cualquier tipo de dato.
template<class TDA>
class ABB {
  private:   
   Nodo<TDA> *raiz; // Declaración la raíz del árbol
   Nodo<TDA> *actual; // Declaracion del nodo actual del arbol
   int contador; // Variable de tipo entero para contar la cantidad de nodos del árbol

  public:
   // Constructor de la clase
   ABB() : raiz(NULL), actual(NULL) {}
   // Destructor de la clase
   ~ABB() { Podar(raiz); }
   // Inserción en un árbol ordenado:
   void Insertar(const TDA dat);
   // Retorna true si el árbol está vacío, false en caso contrario:
   bool Vacio(Nodo<TDA> *r) { return r==NULL; } 
   
  private:
  // Función auxiliar para eliminar todos los nodos del árbol a partir de uno
   void Podar(Nodo<TDA>* &); 
   //Función auxiliar para contar la cantidad de nodos del árbol
   void auxContador(Nodo<TDA>*);
};

template<class TDA>
void ABB<TDA>::Podar(Nodo<TDA>* &nodo)
{
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
      Podar(nodo->izquierdo); // Podar izquierdo
      Podar(nodo->derecho);   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}

template<class TDA>
void ABB<TDA>::Insertar(const TDA dat)
{
   Nodo<TDA> *padre = NULL;

   actual = raiz;
   // Buscar el dato en el árbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual)){ 
      padre = actual;
      if(dat >= actual->dato) actual = actual->derecho;
      else if(dat < actual->dato) actual = actual->izquierdo;

   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;
   // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
   // el nodo raiz
   if(Vacio(padre)) raiz = new Nodo<TDA>(dat);
   // Si el dato es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(dat < padre->dato) padre->izquierdo = new Nodo<TDA>(dat);
   // Si el dato es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(dat >= padre->dato) padre->derecho = new Nodo<TDA>(dat);
  
}
