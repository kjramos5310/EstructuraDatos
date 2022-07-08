#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <cstring>
#include <istream>
#include "Validacion.h"
using namespace std;

char* Validacion::ingresarDato(char *msj){
	char *dato=new char[10],c;
	int i=0;
	printf("%s ",msj);
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
				}
		else if(c==8||c==127){
			printf("\b \b");
			dato[i--]=0;
		}
	}
	dato[i]='\0';
	return dato;
}

char* Validacion::ingresarDatoSinMsj(){
	char *dato=new char[10],c;
	int i=0;
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
				}
		else if(c==8||c==127){
			printf("\b \b");
			dato[i--]=0;
		}
	}
	dato[i]='\0';
	return dato;
}


