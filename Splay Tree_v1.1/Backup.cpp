/*#include "Backup.h"
using namespace std;
Backup::Backup()
{
}

Backup::~Backup()
{
}

void Backup::generarBackup(){
	FILE * archivo; 
	string ruta="C:/Users/HP/Documents/ESPE/SEGUNDO SEMESTRE/SEGUNDA/Programacion/Estructura de Datos/PROYECTOU2/ele/Ahorita si sale/EstructuraDatos/Splay Tree/Grafico_Arbol.txt";
	string destino="C:/Users/HP/Documents/ESPE/SEGUNDO SEMESTRE/SEGUNDA/Programacion/Estructura de Datos/PROYECTOU2/ele/Ahorita si sale/EstructuraDatos/Splay Tree/Backups/_BackupArbol.txt";;
 	string cadena; 
 if (archivo = fopen(ruta.c_str(), "r"))
 {
  cadena = "copy " + ruta + " " + destino;   
  system(cadena.c_str());    
  fclose(archivo);    
 }
 else
 {
   cout << "El archivo no existe" << endl;  
 }  
    time_t t;
    t=time(NULL);
    struct tm *f;
    f=localtime(&t);

    int dia,mes,anio,hora,min;
    dia=f->tm_mday;
    mes=f->tm_mon+1;
    anio=f->tm_year+1900;
    hora=f->tm_hour;
    min=f->tm_min;

    std::string linea;
    std::string texto,texto1,texto2, texto3;
    string fecha;
	string direccion;
    std::string anio1=(std::to_string(anio));
    std::string mes1=(std::to_string(mes));
    std::string dia1=(std::to_string(dia));
    std::string hora1=(std::to_string(hora));
    std::string min1=(std::to_string(min));
    //fecha = "C:\\Users\\Juan F. Reyes\\Desktop\\Proyecto_Arboles_B\\Backups\\"+dia1+"-"+mes1+"-"+anio1+"-"+hora1+"h"+min1+"m"+"_Backupnumeros"+".txt";
    fecha= "C:\Users\HP\Documents\ESPE\SEGUNDO SEMESTRE\SEGUNDA\Programacion\Estructura de Datos\PROYECTOU2\ele\Ahorita si sale\EstructuraDatos\Splay Tree\Backups\"+dia1+"-"+mes1+"-"+anio1+"-"+hora1+"h"+min1+"m"+"_BackupArbol"+".txt";
	ifstream original("Grafico_Arbol.txt");
    while (getline(original,linea))
    {
        texto=texto+linea+"\n";
    }
    original.close();
    ofstream backup;
    backup.open(fecha);
    backup<<texto;
    backup.close();
    
    ifstream original2("database.txt");
    fecha = "C:\Users\HP\Documents\ESPE\SEGUNDO SEMESTRE\SEGUNDA\Programacion\Estructura de Datos\PROYECTOU2\ele\Ahorita si sale\EstructuraDatos\Splay Tree\Backups\"+dia1+"-"+mes1+"-"+anio1+"-"+hora1+"h"+min1+"m"+"_BackupUsuarios"+".txt";
    while (getline(original2,linea))
    {
        texto2=texto2+linea+"\n";
    }
    original2.close();
    ofstream backup2;
    backup2.open(fecha);
    backup2<<texto2;
    backup2.close();
    
}*/
/*
void Backup::recuperarBackup(string nombre){
	time_t t;
    t=time(NULL);
    struct tm *f;
    f=localtime(&t);

    int dia,mes,anio,hora,min;
    dia=f->tm_mday;
    mes=f->tm_mon+1;
    anio=f->tm_year+1900;
    hora=f->tm_hour;
    min=f->tm_min;

    std::string linea;
    std::string texto,texto1,texto2, texto3;
    string fecha;
	string direccion;
    std::string anio1=(std::to_string(anio));
    std::string mes1=(std::to_string(mes));
    std::string dia1=(std::to_string(dia));
    std::string hora1=(std::to_string(hora));
    std::string min1=(std::to_string(min));
	direccion = "C:\Users\HP\Documents\ESPE\SEGUNDO SEMESTRE\SEGUNDA\Programacion\Estructura de Datos\PROYECTOU2\ele\Ahorita si sale\EstructuraDatos\Splay Tree\\Backups\\" + nombre;
	ifstream original("Grafico_Arbol.txt");
    while (getline(original,linea))
    {
        texto=texto+linea+"\n";
    }
    original.close();
	ofstream rec;
	rec.open(direccion);
	rec <<texto;
	rec.close(); 
	
    
    ifstream original2("database.txt");
    while (getline(original2,linea))
    {
        texto2=texto2+linea+"\n";
    }
    original2.close();
    ofstream rec2;
    rec2.open(direccion);
    rec2<<texto2;
    rec2.close();
}
*/