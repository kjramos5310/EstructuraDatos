#include <iostream>
#include "Menu.cpp"
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Menu *obj = new Menu();
    obj->menu();
	return 0;
}