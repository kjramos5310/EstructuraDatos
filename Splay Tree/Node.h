#pragma once
class Node
{
private:
	Node* izqueirda;
	Node* derecha;
	Node* p;
	int valor;
public:
	Node* getIzquierda();
	void setIzquierda(Node* izquierda);
	Node* getDerecha();
	void setDerecha(Node* derecha);
	Node* getP();
	void setP(Node* p);
	int getValor();
	void setValor(int valor);
};

