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
   // Retorna true si el nodo es hoja, false en caso contrario:
   bool EsHoja(Nodo<TDA> *r) { return !r->derecho && !r->izquierdo; }
   // Cuenta el número de nodos del árbol y retorna dicho número:
   const int NumeroNodos();
   // Retorna el valor que contiene el nodo actual:
   TDA &ValorActual() { return actual->dato; }
   // Mueve actual a la raíz:
   void Raiz() { actual = raiz; }
   // Recorre el árbol en InOrden
   void InOrden(void (*func)(TDA&) , Nodo<TDA> *nodo=NULL, bool r=true);
   // Recorre el árbol en PreOrden
   void PreOrden(void (*func)(TDA&) , Nodo<TDA> *nodo=NULL, bool r=true);
   // Recorre el árbol en PostOrden
   void PostOrden(void (*func)(TDA&) , Nodo<TDA> *nodo=NULL, bool r=true);
   // Muestra las hojas del árbol
   void MostrarHojas(void (*func)(TDA&) , Nodo<TDA> *nodo=NULL, bool r=true);
   // Muestra los nodos internos del árbol
   void MostrarInternos(void (*func)(TDA&) , Nodo<TDA> *nodo=NULL, bool r=true);
   
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

template<class TDA>
void ABB<TDA>::PreOrden(void (*func)(TDA&), Nodo<TDA> *nodo, bool r)
{
   if(r) nodo = raiz;
   func(nodo->dato);
   if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

template<class TDA>
void ABB<TDA>::PostOrden(void (*func)(TDA&), Nodo<TDA> *nodo, bool r)
{
   if(r) nodo = raiz; // Si r es true, el nodo es la raiz
   if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);// Se recorre la izquierda del nodo padre
   if(nodo->derecho) PostOrden(func, nodo->derecho, false);// Se recorre la derecha del nodo padre
   func(nodo->dato);// Se muestra el valor del nodo
}

template<class TDA>
void ABB<TDA>::InOrden(void (*func)(TDA&) , Nodo<TDA> *nodo, bool r)
{
   if(r) nodo = raiz; // Si r es true, el nodo es la raiz
   if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false); // Se recorre la izquierda del nodo padre
   func(nodo->dato); // Se muestra el valor del nodo
   if(nodo->derecho) InOrden(func, nodo->derecho, false); // Se recorre la derecha del nodo padre
}

template<class TDA>
void ABB<TDA>::MostrarHojas(void (*func)(TDA&), Nodo<TDA> *nodo, bool r)
{

   if(r) nodo = raiz; // Si r es true, el nodo es la raíz 
   if (EsHoja(nodo)) {func(nodo->dato);} // Si el nodo es hoja, se muestra su valor
   if(nodo->izquierdo) MostrarHojas(func, nodo->izquierdo, false); // Se recorre a la izquierda del nodo padre
   if(nodo->derecho) MostrarHojas(func, nodo->derecho, false); // Se recorre a la derecha del nodo padre
}

template<class TDA>
void ABB<TDA>::MostrarInternos(void (*func)(TDA&), Nodo<TDA> *nodo, bool r)
{

   if(r) nodo = raiz; // Si r es true, el nodo es la raíz
   if(!EsHoja(nodo)) {  func(nodo->dato);} // Si el nodo NO es hoja, se muestra su valor
   if(nodo->izquierdo) MostrarInternos(func, nodo->izquierdo, false); // Se recorre a la izquierda del nodo padre
   if(nodo->derecho) MostrarInternos(func, nodo->derecho, false); // Se recorre a la derecha del nodos padre
}

template<class TDA>
const int ABB<TDA>::NumeroNodos()
{
   contador = 0;
   if (raiz != NULL){ //Si se ha creado un árbol retorna la cantidad de nodos que contiene
            auxContador(raiz); // Función auxiliar de contador para realizar el conteo de los nodos

            return contador;  //retorna la cantidad de nodos que tiene el árbol
   } 
   else{ //Si no se ha creado ningún árbol retorna q la cantidad de nodos es cero
        return 0;
   }  
}

template<class TDA>
void ABB<TDA>::auxContador(Nodo<TDA> *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo); //recorrido por la izquierda
   if(nodo->derecho)   auxContador(nodo->derecho);//recorrido por la derecha
}

/*
  Función para mostrar el árbol.
*/
template <class TDA>
void Mostrar(const TDA dat)
{
     cout << dat << ","; //Imprime el dato y coloca una coma para separar cada dato.
}
