#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include "Node.h"
#pragma warning(disable : 4996)

using namespace std;

class SplayTree
{
private:
	Node* root;
public:
	Node* getRoot();
	void setRoot(Node* root);
	SplayTree();
	void rotacionDerecha(Node* P);
	void rotacionIzquierda(Node* P);
	void splay(Node* T);
	void insertar(int valor);
	void imprimir(Node* R);
	Node* buscar(int valor);
	bool borrar(int valor);
	char* ingresarDatos(const char*);
};

