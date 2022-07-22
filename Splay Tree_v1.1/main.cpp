/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
INGENIERIA DE SOFTWARE y TICS            
	AUTORES: ALEJANDRO CAMACHO, KEVIN RAMOS
        GRUPOS: 16
    FECHA DE CREACION:        Domingo, 17 de julio de 2022 
	FECHA DE MODIFICACION:    Jueves, 22 de julio de 2022 
    DESCRIPCION: Proyecto Segundo Parcial === SPLAYTREE
*/



#pragma once
#include "Login.h"

#include <iostream>
#include <thread>


#include <stdlib.h>
void marquesina(std::string text) {
HANDLE conhandler = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int ancho, alto;
    GetConsoleScreenBufferInfo(conhandler, &csbi);
    ancho = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    SetConsoleCursorPosition(conhandler, { 0, 4 });

    while (true) {
        std::string temp = text;
        text.erase(0, 1);
        text += temp[0];
        CHAR_INFO* buff = (CHAR_INFO*)calloc(ancho, sizeof(CHAR_INFO));

        for (int i = 0; i < text.length(); i++) {
            buff[i].Char.AsciiChar = text.at(i);
            buff[i].Attributes = 15;
        }

        SMALL_RECT pos = { 0, 0, ancho, 1 };
        WriteConsoleOutputA(conhandler, buff, { (SHORT)ancho, 1 }, { 0, 0 }, &pos);
        free(buff);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

}


int main()
{
	std::string texto = "UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE 100 ANIVERSARIO ----ESTRUCTURA DE DATOS  ";
	std::thread t2(marquesina, texto);
	t2.detach();
	system("cls");
	cout << "\n";
	Login l;
	l.inicio();

}