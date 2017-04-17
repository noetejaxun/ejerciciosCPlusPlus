//	BUFFER DE ENTRADA
//	Error al momento de ingresar un numero y luego una linea de texto.

//	ERROR DE ENTRADA

#include <iostream>

using namespace std;

int main () {
	int cheque;
	char nombre[30];
	cout << "Ingrese numero de cheque: ";
	cin >> cheque;
	cout << "Ingrese nombre: ";
	cin.getline(nombre, 30); // Esta linea de codigo, causa un error

	cout << "Los datos ingresados son: " << endl << endl;
	cout << "Numero de cheque: " << cheque << endl;
	cout << "Nombre: " << nombre << endl;
	//system(pause);
	return 0;
}