#include "SplayTree.h"





SplayTree::SplayTree() {
	root = NULL;
}

Node* SplayTree::getRoot() {
	return this->root;
}

void SplayTree::drawNode(Node* root,
					int x, int y,
					int noderatio)
{
	
	setcolor(15);
		circle(x, y, 25);
		setfillstyle(SOLID_FILL, 15);
		floodfill(x, y, WHITE);
	
	
	
	char arr[5];
	itoa(root->getValor(), arr, 10);
	outtextxy(x, y, arr);

	if (root->getIzquierda() != NULL) {
		line(x, y, x - 20 * noderatio, y + 70);
		drawNode(root->getIzquierda(), x - 20 * noderatio, y + 70,
				noderatio - 2);
	}
	if (root->getDerecha() != NULL) {
		line(x, y, x + 20 * noderatio, y + 70);
		drawNode(root->getDerecha(), x + 20 * noderatio, y + 70,
				noderatio - 2);
	}
}

void SplayTree::drawTree(Node* root, int x, int y){
		settextstyle(10, HORIZ_DIR, 2);
	drawNode(root, x, y, 8);
}


   
void SplayTree::setRoot(Node* root) {
	this->root = root;
}

void SplayTree::rotacionDerecha(Node* P) {
	Node* T = P->getIzquierda();
	Node* B = T->getDerecha();
	Node* D = P->getP();
	if (D)
	{
		if (D->getDerecha() == P) D->setDerecha(T);
		else D->setIzquierda(T);
	}
	if (B)
		B->setP(P);
	T->setP(D);
	T->setDerecha(P);

	P->setP(T);
	P->setIzquierda(B);
}

void SplayTree::rotacionIzquierda(Node* P) {
	Node* T = P->getDerecha();
	Node* B = T->getIzquierda();
	Node* D = P->getP();
	if (D)
	{
		if (D->getDerecha() == P) D->setDerecha(T);
		else D->setIzquierda(T);
	}
	if (B)
		B->setP(P);
	T->setP(D);
	T->setIzquierda(P);

	P->setP(T);
	P->setDerecha(B);
}

void SplayTree::splay(Node* T) {
	while (true)
	{
		Node* p = T->getP();
		if (!p) break;
		Node* pp = p->getP();
		if (!pp)//Zig
		{
			if (p->getIzquierda() == T)
				rotacionDerecha(p);
			else
				rotacionIzquierda(p);
			break;
		}
		if (pp->getIzquierda() == p)
		{
			if (p->getIzquierda() == T)
			{//ZigZig
				rotacionDerecha(pp);
				rotacionDerecha(p);
			}
			else
			{//ZigZag
				rotacionIzquierda(p);
				rotacionDerecha(pp);
			}
		}
		else
		{
			if (p->getIzquierda() == T)
			{//ZigZag
				rotacionDerecha(p);
				rotacionIzquierda(pp);
			}
			else
			{//ZigZig
				rotacionIzquierda(pp);
				rotacionIzquierda(p);
			}
		}
	}
	root = T;
}

void SplayTree::insertar(int valor) {
	if (!root)
	{
		root = (Node*)malloc(sizeof(Node));
		root->setIzquierda(NULL);
		root->setDerecha(NULL);
		root->setP(NULL);
		root->setValor(valor);
		return;
	}
	Node* P = root;
	while (true)
	{
		if (valor < (P->getValor()))
		{
			if (P->getIzquierda()) P = P->getIzquierda();
			else
			{
				P->setIzquierda((Node*)malloc(sizeof(Node)));
				P->getIzquierda()->setP(P);
				P->getIzquierda()->setDerecha(NULL);
				P->getIzquierda()->setIzquierda(NULL);
				P->getIzquierda()->setValor(valor);
				P = P->getIzquierda();
				break;
			}
		}
		else
		{
			if (P->getDerecha()) P = P->getDerecha();
			else
			{
				P->setDerecha((Node*)malloc(sizeof(Node)));
				P->getDerecha()->setP(P);
				P->getDerecha()->setDerecha(NULL);
				P->getDerecha()->setIzquierda(NULL);
				P->getDerecha()->setValor(valor);
				P = P->getDerecha();
				break;
			}
		}
	}
	splay(P);
}

void SplayTree::imprimir(Node* R) {
	if (!R) return;
	imprimir(R->getIzquierda());
	cout << "Nodo: " << R->getValor();
	if (R->getIzquierda()) {
		cout << " ; Izquierda: " << R->getIzquierda()->getValor();
	}
	if (R->getDerecha()) {
		cout << " ; Derecha: " << R->getDerecha()->getValor();
	}
	puts("");
	imprimir(R->getDerecha());
}

Node* SplayTree::buscar(int valor) {
	if (!root) return NULL;
	Node* P = root;
	while (P)
	{
		if (P->getValor() == valor)
			break;
		if (valor < (P->getValor()))
		{
			if (P->getIzquierda())
				P = P->getIzquierda();
			else
				break;
		}
		else
		{
			if (P->getDerecha())
				P = P->getDerecha();
			else
				break;
		}
	}
	splay(P);
	if (P->getValor() == valor) return P;
	else return NULL;
}

bool SplayTree::borrar(int valor) {
	Node* N = buscar(valor);
	if (!N) return false;
	Node* P = N->getIzquierda();
	if (!P)
	{
		root = N->getDerecha();
		root->setP(NULL);
		free(N);
		return true;
	}
	while (P->getDerecha()) P = P->getDerecha();
	if (N->getDerecha())
	{
		P->setDerecha(N->getDerecha());
		N->getDerecha()->setP(P);
	}
	root = N->getIzquierda();
	root->setP(NULL);
	free(N);
	return true;
}

char* SplayTree::ingresarDatos(const char* msg) {
	char dato[10];
	char c;
	int i = 0;
	printf("%s\n", msg);
	while ((c = getch()) != 13) {
		if (c >= '0' && c <= '9') {
			printf("%c", c);
			dato[i++] = c;
		}
		else if (c == '\b') {
			printf("\b \b");
			dato[i--] = c;
		}
	}
	dato[i] = '\0';
	return dato;

}
