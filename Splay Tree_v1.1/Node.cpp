#include "Node.h"

Node* Node::getIzquierda() {
	return this->izqueirda;
}

void Node::setIzquierda(Node* izquierda) {
	this->izqueirda = izquierda;
}

Node* Node::getDerecha() {
	return this->derecha;
}

void Node::setDerecha(Node* derecha) {
	this->derecha = derecha;
}

Node* Node::getP() {
	return this->p;
}

void Node::setP(Node* p) {
	this->p = p;
}

int Node::getValor() {
	return this->valor;
}

void Node::setValor(int valor) {
	this->valor = valor;
}