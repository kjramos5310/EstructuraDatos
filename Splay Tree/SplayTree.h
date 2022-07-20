#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include "Node.h"
#pragma warning(disable : 4996)
#include <algorithm>
#include <bits/stdc++.h>
#include <graphics.h>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
//template <class T >
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
	void splay(Node* );
	void insertar(int valor);
	void imprimir(Node* R);
	Node* buscar(int valor);
	bool borrar(int valor);
	char* ingresarDatos(const char*);
	void Guardar(Node * ,ofstream &,int);
	
	
	void drawTree(Node* , int , int );
	void drawNode(Node* ,int , int ,int );
};

