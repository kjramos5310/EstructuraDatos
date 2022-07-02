/*      UNIVERSIDAD DE LAS FUERZAS ARMADAS
*       Ordenamiento Mezcla Natural
*       Autor: NRC 4683
*       Fecha de creación: 01/07/2022
*       Fecha de modificación: ../07/2022
*       Grupo: 4
*       Github: https://github.com/kjramos5310/EstructuraDatos
*/
#include <ctype.h>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include "arbolBB.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
ABB<int> ArbolEnteros;

//Declaraciones de las funciones desarrolladas en este archivo
void menu(); //Contiene todo el menu principal, en el cual se presentan las opciones del programa.
void Crear_Arbol(); //En esta función se invocan a las funciones respectivas para crear el árbol.

int main()
{
    system("color 0F");
    menu();
    system("PAUSE");
    return 0;
}

//**********************************************************************************************************************************//

/**
*Entradas: No recibe ninguna entrada
*Salida: Como salida se obtiene todas las opciones del menú principal asi como la ejecución de cada opción que el ususario desee realizar.
*Restricciones: No se presenta ninguna restricción.
*/

//Esta función contiene todo el menu principal, en el cual se presentan las opciones del programa.
void menu()
{
     /**
     *Todos estos cout, tiene la funcionalidad de presentar la caratula del menú.
     */
	cout<<"\n"<<"==============================================================================="<<"\n";
	cout<<"\n"<<"                                     ARBOL BINARIO                             "<<"\n";
	cout<<"\n"<<"==============================================================================="<<"\n";
	cout<<"\n"<<"\n1.Crear arbol.";
	cout<<"\n"<<"\n6.Salir.";
 

        char eleccion; //Declaración de la variable eleccion, de tipo char, en la cual se almacenará la opción que escogió  el usuario.
        while (true) // Mientras la condición se cumpla se realizará indefinidamente, "while True".
        {
              cout<<"\n"<<"\n"<<">>>>Estimado usuario digite el numero de la operacion a realizar: "; //Se le solicita al usuario ingresar el núero de la opció que quiere realizar.
              cin>>eleccion;
              system("cls"); //Se limpia la pantalla actual, para presentar la pantalla respectiva de acuerdo a lo elegido por el usuario.
              if (eleccion == '1'){ //Opción 1
                           system("cls"); //Se limpia la pantalla
                           Crear_Arbol(); //Se llama y muestra en pantalla a la función Crear_Arbol.                           
              }
              else if(eleccion == '6') //Opción 6
              {
                   exit(0); //Sale del programa
              }
              /**
              *Este else cumple la función de informarle al usuario que la opcion que ha marcado es incorrecta para que él mismo
              *marque de nuevo una opción válida.
              *NOTA: 
              *    Llamece opción inválida al digitar un numero que no sea del 1 al 6 ó algúna letra o caracter.
              */
              else{
            	   cout<<"==============================================================================="<<"\n";
            	   cout<<"\n"<<"             ESTIMADO USUARIO LA OPCION MARCADA ES INVALIDA                    "<<"\n";
            	   cout<<"\n"<<"==============================================================================="; 
                   menu();
                   
              }
        }     
}


//En esta función se invocan a las funciones respectivas para crear el árbol, además esta función presenta dos formas de crear el árbol.
void Crear_Arbol()
{
    ArbolEnteros.~ABB(); //Se llama al destructor para de la clase ABB para que destruya todos los valores y se generen de nuevo cada vez que se crea un árbol
    /**
   *Todos estos cout, tiene la funcionalidad de presentar la caratula del menú crear árbol.
   */
    cout<<"\n";
	cout<<"\n"<<"==============================================================================="<<"\n";
	cout<<"\n"<<"                                     CREAR ARBOL                               "<<"\n";
	cout<<"\n"<<"==============================================================================="<<"\n";
    cout<<"\n"<<"1.Crear arbol de forma manual.\n";
    cout<<"\n"<<"2.Regresar al menu.\n" ;        
  
     char eleccion;//Declaración de la variable eleccion, de tipo char, en la cual se almacenará la opción que escogió  el usuario.
     while (true) // Mientras la condición se cumpla se realizará ndefinidamente, "while True"
     {
              cout<<"\n"<<"\n"<<">>>>Estimado usuario digite el numero de la operacion a realizar: ";//Se le solicita al usuario ingresar el número de la opción que quiere realizar.
              cin>>eleccion;
              
              if (eleccion == '1')  //Opción 1. Mediante este if se evalúa la operación de creación de un árbol de forma manual.
              {
                    system("cls");//Se limpia la pantalla
            
                    int n;  // numero de nodos del arbol
                    int dato; // elemento a insertar en cada nodo
                     /**
                    *Estos tres cout, se encargan de mostrar el título de CREAR ARBOL MANUALMENTE.
                    */ 
                	cout<<"\n"<<"==============================================================================="<<"\n";
                	cout<<"\n"<<"                                  CREAR ARBOL MANUALMENTE                      "<<"\n";
                	cout<<"\n"<<"==============================================================================="<<"\n";
                    cout << " Ingrese el numero de nodos deseados para el arbol:  ";//Se le solicita al ususario que ingrese cuantos nodos desea crear.
                    cin >> n;
                    cout << endl;
                    /**
                    Mediante este for se va solicitando al usuario los números que desea ingresar al árbol, 
                    *y el for es para solicitar la cantidad de números de acuerdo a la cantidad de nodos indicada previamente.
                    */
                    for(int i=0; i<n; i++)
                    {
                        cout << " Ingrese el numero " << i+1 << " : ";
                        cin >> dato;
                        ArbolEnteros.Insertar(dato); //Se va insertando a cada a lod nodos el némero que el usuario va digitando.
                    }
                    menu();                                                         
                         
              } 
              else if(eleccion == '3') //Opció 3
              {
                   system("cls"); //Limpia la pantalla
                   menu(); //Llama al menú principal
              }
              /**
              *Este else cumple la función de informarle al usuario que la opcion que ha marcado es incorrecta para que él mismo
              *marque de nuevo una opción válida.
              *NOTA: 
              *    Llamece opción inválida al digitar un numero que no sea del 1 al 6 ó algúna letra o caracter.
              */
              else{
            	   cout<<"==============================================================================="<<"\n";
            	   cout<<"\n"<<"             ESTIMADO USUARIO LA OPCION MARCADA ES INVALIDA                    "<<"\n";
            	   cout<<"\n"<<"==============================================================================="; 
            	   system("cls");
                   Crear_Arbol();//Se llama al menú principal.
                   
              }
     } 
     
       
}
