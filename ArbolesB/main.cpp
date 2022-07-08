/*      UNIVERSIDAD DE LAS FUERZAS ARMADAS
*       Ordenamiento Mezcla Natural
*       Autor: Camacho Victor, Ramos Kevin
*       Fecha de creación: 07/07/2022
*       Fecha de modificación: 
*       Grupo: 16
*       Github: https://github.com/kjramos5310/EstructuraDatos
*/

#include <ctype.h>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include "arbolBB.h"
#include "Validacion.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
ABB<int> ArbolEnteros;

//Declaraciones de las funciones desarrolladas en este archivo
void menu(); //Contiene todo el menu principal, en el cual se presentan las opciones del programa.
void Recorrer_arbol(); //Presenta las tres opciones de recorrer el árbol, PostOrden, InOrdeen, PreOrden.
void Crear_Arbol(); //En esta función se invocan a las funciones respectivas para crear el árbol.
void Inserta_Elementos_Automaticamente(); //Esta función crea un tamaño de nodoa aleatorios y una lista de numero aleatoria para insertar en el árbol.

int main()
{
    system("color 1F");
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
    cout<<"\n"<<"\n2.Recorrer el arbol.";
	cout<<"\n"<<"\n3.Relizar conteo de los nodos del arbol.";
	cout<<"\n"<<"\n4.Visitar y Mostrar los nodos hojas del arbol.";	
	cout<<"\n"<<"\n5.Visitar y Mostrar los nodos internos del arbol.";
	cout<<"\n"<<"\n6.Salir.";
 

        char eleccion, val[10]; //Declaración de la variable eleccion, de tipo char, en la cual se almacenará la opción que escogió  el usuario.
        Validacion v;
		while (true) // Mientras la condición se cumpla se realizará indefinidamente, "while True".
        {
              cout<<"\n"<<"\n"<<">>>>Estimado usuario digite el numero de la operacion a realizar: "; //Se le solicita al usuario ingresar el núero de la opció que quiere realizar.
              eleccion = *(v.ingresarDatoSinMsj());
              
              system("cls"); //Se limpia la pantalla actual, para presentar la pantalla respectiva de acuerdo a lo elegido por el usuario.
              if (eleccion == '1'){ //Opción 1
                           system("cls"); //Se limpia la pantalla
                           Crear_Arbol(); //Se llama y muestra en pantalla a la función Crear_Arbol.
                           
              }  
              else if(eleccion == '2') //Opción 2
              {            system("cls");  //Se limpia la pantalla               
                           Recorrer_arbol(); //Se llama y muestra en pantalla a la función Recorrer_arbol.                   
              }
              else if (eleccion == '3'){ //Opción 3
                                /**
                                *Estos tres cout, se encargan de mostrar el título de cantidad de nodos.
                                */
                        	  cout<<"\n"<<"==============================================================================="<<"\n";
                        	  cout<<"\n"<<"                                  CANTIDAD DE NODOS                            "<<"\n";
                        	  cout<<"\n"<<"==============================================================================="<<"\n";
                        	  /**
                              *Se asigna a la variable Cantidad_nodos el numero de nodos creados en el árbol, esto se logra llamando a la función
                              *NumeroNodos previamnete ya establecida en la clase ABB.
                              */
                              int Cantidad_nodos = ArbolEnteros.NumeroNodos(); 
                              /**
                              *Mediante este pequeño bloque de desición se evalúa, si el árbol esta vacío, que retorne en pantalla al usuario
                              *que no hay una cantidad de nodos a mostar pues el árbol está vació, o bien, si el árbol no se encuentra vacío 
                              *que proceda a mostrar en pantalla
                              *la cantidad de nodos que contiene dicho árbol.
                              */
                              if (Cantidad_nodos==0){
                                             cout <<"\n"<< "No se puede mostrar la cantidad de nodos, el arbol esta vacio";
                              }
                              else{
                                   cout<<"\n"<<"La cantidad de nodos: "<< Cantidad_nodos<<" Nodos";
                                   cout<<"\n";
                              }
                              menu();//Se llama al menú principal.


              }   
              else if (eleccion == '4'){ //Opción 4
                                /**
                                *Estos tres cout, se encargan de mostrar el título de nodos hojas del árbol.
                                */              
                        	  cout<<"\n"<<"==============================================================================="<<"\n";
                        	  cout<<"\n"<<"                               NODOS HOJAS DEL ARBOL                           "<<"\n";
                        	  cout<<"\n"<<"==============================================================================="<<"\n"; 
                        	  /**
                              *Se asigna a la variable Cantidad_nodos el numero de nodos creados en el árbol, esto se logra llamando a la función
                              *NumeroNodos previamnete ya establecida en la clase ABB.
                              */
                              int Cantidad_nodos = ArbolEnteros.NumeroNodos();
                              /**
                              *Mediante este pequeño bloque de desición se evalúa, si el árbol esta vacío, que retorne en pantalla al usuario
                              *que no hay Nodos Hojas pues el árbol está vació, o bien, si el árbol no se encuentra vacío que proceda a mostrar en pantalla
                              *la cantidad de Nodos Hojas que contiene dicho árbol.
                              */
                              if (Cantidad_nodos==0){
                                             cout <<"\n"<< " No hay nodos hojas para mostrar, debido a que el arbol esta vacio\n";
                              }
                              else{
                                   cout<<"\n"<<"VISITAR NODOS HOJAS:."<<"\n";
                                   cout<<"\n"<<"Los nodos hojas han sido visitados"<<"\n";
                                   cout<<"\n"<<"MOSTRAR NODOS HOJAS:"<<"\n";
                                   cout<<"\n"<<"Los nodos hojas del arbol son: "<<"\n";
                                   cout<<"\n";
                                   cout<<">>>";ArbolEnteros.MostrarHojas(Mostrar);
                                   cout<<"\n";
                              }
                              menu(); //Se llama al menú principal.

                                         
              }    
              else if (eleccion == '5'){ //Opción 5
                                /**
                                *Estos tres cout, se encargan de mostrar el título de nodos internos del árbol.
                                */  
                        	  cout<<"\n"<<"==============================================================================="<<"\n";
                        	  cout<<"\n"<<"                               NODOS INTERNOS DEL ARBOL                           "<<"\n";
                        	  cout<<"\n"<<"==============================================================================="<<"\n"; 
                        	  /**
                              *Se asigna a la variable Cantidad_nodos el numero de nodos creados en el árbol, esto se logra llamando a la función
                              *NumeroNodos previamnete ya establecida en la clase ABB.
                              */
                              int Cantidad_nodos = ArbolEnteros.NumeroNodos();
                              /**
                              *Mediante este pequeño bloque de desición se evalúa, si el árbol esta vacío, que retorne en pantalla al usuario
                              *que no hay Nodos Internos pues el árbol está vació, o bien, si el árbol no se encuentra vacío que proceda a mostrar en pantalla
                              *la cantidad de Nodos Hojas que contiene dicho árbol.
                              */
                              if (Cantidad_nodos==0){
                                             cout <<"\n"<< " No hay nodos internos para mostrar, debido a que el arbol esta vacio\n";
                              }
                              else{
                                   cout<<"\n"<<"VISITAR NODOS INTERNOS:"<<"\n";
                                   cout<<"\n"<<"Los nodos internos han sido visitados"<<"\n";
                                   cout<<"\n"<<"MOSTRAR NODOS INTERNOS:"<<"\n";
                                   cout<<"\n"<<"Los nodos internos del arbol son: "<<"\n";
                                   cout<<"\n";
                                   cout<<">>> ";ArbolEnteros.MostrarInternos(Mostrar);
                                   cout<<"\n";
                              }
                              menu();   //Se llama al menú principal.                  
                                       
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

void Recorrer_arbol()
{
     /**
    *Estos tres cout, se encargan de mostrar el título de RECORRIDO DEL ARBOL.
    */ 
      cout<<"\n"<<"==============================================================================="<<"\n";
      cout<<"\n"<<"                                RECORRIDO DEL ARBOL                          "<<"\n";
      cout<<"\n"<<"==============================================================================="<<"\n"; 
       /**
      *Se asigna a la variable Cantidad_nodos el numero de nodos creados en el árbol, esto se logra llamando a la función
      *NumeroNodos previamnete ya establecida en la clase ABB.
      */
      int Cantidad_nodos = ArbolEnteros.NumeroNodos();
      /**
      *Mediante este bloque de desición se evalúa, si el árbol esta vacío, que retorne en pantalla al usuario
      *que no es posible realizar el recorrio pues el árbol está vació, o bien, si el árbol no se encuentra vacío que proceda a 
      *la realización del recorrido.
      */      
      if (Cantidad_nodos==0){
                     cout <<"\n"<< " No se puede mostrar el recorrido del arbol porque el mismo esta vacio.\n";
                     menu(); //Se llama al menú principal.
      }
      else
      {     
        char eleccion_ordenar;  //Declaración de la variable eleccion_ordenar, de tipo char, en la cual se almacenará la opción que escogió  el usuario para el recorrido del árbol.
        Validacion v;
		  /**
         *Todos estos cout, tiene la funcionalidad de presentar la caratula de lasmopciones del recorrido de los arboles.
        */
        cout<<"\n"<<"1.Recorrido Arbol PreOrden.\n" ;                    
        cout<<"\n"<<"2.Recorrido Arbol InOrden.\n";
        cout<<"\n"<<"3.Recorrido Arbol PostOrden.\n" ; 
        cout<<"\n"<<"4.Recorrido Arbol de las tres formas anterios.\n" ; 
        cout<<"\n"<<"5.Regresar al menu.\n" ; 
        cout<<"\n"<<"Estimado usuario digite el numero de la operacion que desea realizar.\n";                    
        eleccion_ordenar=*(v.ingresarDatoSinMsj());
        
        
        if(eleccion_ordenar=='1')//Opción 1  solamente muestra el RECORRIDO PREORDEN.
        {
                    /**
                    *Estos tres cout, se encargan de mostrar el título de RECORRIDO PREORDEN.
                    */ 
                    system("cls");        
                	cout<<"\n"<<"==============================================================================="<<"\n";
                	cout<<"\n"<<"                                RECORRIDO PREORDEN                          "<<"\n";
                	cout<<"\n"<<"==============================================================================="<<"\n";                                             
                    ArbolEnteros.PreOrden(Mostrar); //Llama a la función PreOrden y a su vez muestra el resultado del recorrido.
                    menu(); //Se llama al menú principal.
        }
        else if(eleccion_ordenar=='2') //Opción 2 solamente muestra el RECORRIDO PREORDEN.
        {
                    /**
                    *Estos tres cout, se encargan de mostrar el título de RECORRIDO PREORDEN.
                    */   
                    system("cls");                                                            
                	cout<<"\n"<<"==============================================================================="<<"\n";
                	cout<<"\n"<<"                                RECORRIDO INORDEN                         "<<"\n";
                	cout<<"\n"<<"==============================================================================="<<"\n";                          
                    ArbolEnteros.InOrden(Mostrar);//Se llama a la función InOrden y a su vez muestra el resultado del recorrido.
                    menu();//Se llama al menú princiapl.
        }
        else if(eleccion_ordenar=='3')//Opción 3 solamente muestra el RECORRIDO POSTORDEN.
        {
                    /**
                    *Estos tres cout, se encargan de mostrar el título de  RECORRIDO POSTORDEN.
                    */ 
                    system("cls");                                                 
                	cout<<"\n"<<"==============================================================================="<<"\n";
                	cout<<"\n"<<"                                RECORRIDO POSTORDEN                         "<<"\n";
                	cout<<"\n"<<"==============================================================================="<<"\n";                          
                    ArbolEnteros.PostOrden(Mostrar);//Se llama a la función PostOrden y a su vez muestra el resultado del recorrido.
                    menu();//Se llama al menú princiapl.
        }
        else if(eleccion_ordenar=='4') //Opción 4 Muestra los tres tipos de recorrido
        {
                                                
                    /**
                    *Estos tres cout, se encargan de mostrar el título de RECORRIDO PREORDEN.
                    */ 
                    system("cls");                               
                	cout<<"\n"<<"==============================================================================="<<"\n";
                	cout<<"\n"<<"                                RECORRIDO PREORDEN                          "<<"\n";
                	cout<<"\n"<<"==============================================================================="<<"\n";                                             
                    ArbolEnteros.PreOrden(Mostrar); //Llama a la función PreOrden y a su vez muestra el resultado del recorrido.
                    cout<<"\n";
                    cout<<"\n";

                    /**
                    *Estos tres cout, se encargan de mostrar el título de RECORRIDO PREORDEN.
                    */                                        
                	cout<<"\n"<<"==============================================================================="<<"\n";
                	cout<<"\n"<<"                                RECORRIDO INORDEN                         "<<"\n";
                	cout<<"\n"<<"==============================================================================="<<"\n";                          
                    ArbolEnteros.InOrden(Mostrar);//Se llama a la función InOrden y a su vez muestra el resultado del recorrido.
                    
                    cout<<"\n";
                    cout<<"\n";
                    /**
                    *Estos tres cout, se encargan de mostrar el título de  RECORRIDO POSTORDEN.
                    */                           
                	cout<<"\n"<<"==============================================================================="<<"\n";
                	cout<<"\n"<<"                                RECORRIDO POSTORDEN                         "<<"\n";
                	cout<<"\n"<<"==============================================================================="<<"\n";                          
                    ArbolEnteros.PostOrden(Mostrar);//Se llama a la función PostOrden y a su vez muestra el resultado del recorrido.
                    cout<<"\n";
                    cout<<"\n";  
                    menu(); //Se llama al menú principal.                              
        }
        else if(eleccion_ordenar=='5')//Opción 5 Regresa al menú principal.
        {
                    system("cls"); //Se limpia la pantalla.                           
                    menu();//Se llama al menú principal.
        } 
       else{
                   system("cls");               
                   cout<<"==============================================================================="<<"\n";
                   cout<<"\n"<<"             ESTIMADO USUARIO LA OPCION MARCADA ES INVALIDA                    "<<"\n";
                   cout<<"\n"<<"==============================================================================="; 
                   Recorrer_arbol();//Se llama al menú principal del recorrido de arboles.
       
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
    cout<<"\n"<<"2.Crear arbol de forma automatica.\n" ;    
    cout<<"\n"<<"3.Regresar al menu.\n" ;        
  
     char eleccion;//Declaración de la variable eleccion, de tipo char, en la cual se almacenará la opción que escogió  el usuario.
     Validacion v;
	 while (true) // Mientras la condición se cumpla se realizará ndefinidamente, "while True"
     {
              cout<<"\n"<<"\n"<<">>>>Estimado usuario digite el numero de la operacion a realizar: ";//Se le solicita al usuario ingresar el número de la opción que quiere realizar.
              eleccion=*(v.ingresarDatoSinMsj());
              
              if (eleccion == '1')  //Opción 1. Mediante este if se evalúa la operación de creación de un árbol de forma manual.
              {
                    system("cls");//Se limpia la pantalla
            
                    int n;  // numero de nodos del arbol
                    int dato; // elemento a insertar en cada nodo
                    char val[10]; /**
                    *Estos tres cout, se encargan de mostrar el título de CREAR ARBOL MANUALMENTE.
                    */ 
                	cout<<"\n"<<"==============================================================================="<<"\n";
                	cout<<"\n"<<"                                  CREAR ARBOL MANUALMENTE                      "<<"\n";
                	cout<<"\n"<<"==============================================================================="<<"\n";
                    cout << " Ingrese el numero de nodos deseados para el arbol:  ";//Se le solicita al ususario que ingrese cuantos nodos desea crear.
                    strcpy(val,v.ingresarDatoSinMsj());
        			n=atoi(val);
                    cout << endl;
                    /**
                    Mediante este for se va solicitando al usuario los números que desea ingresar al árbol, 
                    *y el for es para solicitar la cantidad de números de acuerdo a la cantidad de nodos indicada previamente.
                    */
                    char val1[10];
                    for(int i=0; i<n; i++)
                    {
                        cout << " Ingrese el numero " << i+1 << " : ";
                        strcpy(val1,v.ingresarDatoSinMsj());
        				dato=atoi(val1);
                        ArbolEnteros.Insertar(dato); //Se va insertando a cada a lod nodos el némero que el usuario va digitando.
                        cout<<endl;
                    }
                    menu();                                                         
                         
              } 
              /**
              *Opción 2. Mediante este if se evalúa la operación de creación de un árbol de forma automática.
              *NOTA:
              *Llamecé automático a la forma que el programa genera de forma aleatoria, el tamaño del árbol y la lista de números.
              */                
              else if (eleccion == '2')
              { 
                    system("cls");
                    /**
                    *Estos tres cout, se encargan de mostrar el título de  CREAR ARBOL AUTOMATICAMENTE.
                    */ 
                	cout<<"\n"<<"==============================================================================="<<"\n";
                	cout<<"\n"<<"                              CREAR ARBOL AUTOMATICAMENTE                     "<<"\n";
                	cout<<"\n"<<"==============================================================================="<<"\n";                   
                    Inserta_Elementos_Automaticamente(); //Se llama a la función Inserta_Elementos_Automaticamente la cual genera de forma aleatoria, el tamaño del árbol y la lista de números.
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

void Inserta_Elementos_Automaticamente(){
     int tamano = rand() % 100; //Genera el número de nodos de forma aleatoria en un rango de 0 a 100.
    /**
    *Estos tres cout, se encargan de mostrar el título de  LISTA DE NUMEROS A INSERTAR EN EL ARBOL.
    */     
	 cout<<"\n"<<"==============================================================================="<<"\n";
	 cout<<"\n"<<"                  LISTA DE NUMEROS A INSERTAR EN EL ARBOL                      "<<"\n";
	 cout<<"\n"<<"==============================================================================="<<"\n";
     cout<<"\n";  
     //Mediante este ciclo de for se genera de forma aleatoria los numeros a insertar en el árbol, el for es utilizado para generar la cantidad de nuemros de acuerdo al tmaño del árbol.
     for (int i = 0; i < tamano; i++){
         int numero = rand() % 100;
         cout << numero << ",";
         ArbolEnteros.Insertar(numero);//Se insertan en cada nodo, cada número que s eva generando.


     }
}

